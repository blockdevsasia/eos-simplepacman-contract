#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <map>
//#include <eosio.nft.cpp>//TODO: implement spores as nft

namespace eosio {
    class spore : public eosio::contract {
        public:
            //using eosio::contract::contract;
            
            //constructor
            spore(account_name self)
            :eosio::contract(self),
            entities(_self, _self), coordinates(_self, _self)
            {}

            // @abi action
            void createentity(account_name author, const uint32_t id, const std::string& colorSeed
                , const uint32_t entityType
                )
            {
                // create a new entity
                entities.emplace(author, [&](auto& new_entity) {
                    new_entity.id  = id;
                    new_entity.color = colorSeed;
                    new_entity.type = entityType;
                });

                // create corresponding starting coordinate on screen for entity
                coordinates.emplace(author, [&](auto& new_coordinate) {
                    new_coordinate.id = id;
                    //new_coordinate.entityId = id;
                    new_coordinate.x = 0;
                    new_coordinate.y = 0;
                });

                eosio::print("createEntity: entity #", id, " created");
            }

            // @abi action
            // record entity's new location on screen
            void moveentity(account_name author, const uint32_t id, 
                const uint32_t x, const uint32_t y){

                // make sure entity exists
                auto entity_lookup = entities.find(id);
                auto coordinates_lookup = coordinates.find(id);
                bool exists = entity_lookup != entities.end() && coordinates_lookup != coordinates.end();
                eosio_assert(exists, 
                    "moveEntity: Either entity or Coordinate does not exist");

                if(exists) {
                    coordinates.modify(coordinates_lookup, author, [&](auto& modifiable_coordinate) {
                        modifiable_coordinate.x = x;
                        modifiable_coordinate.y = y;
                    });

                    eosio::print("coordinate#", id, " moved to ", x, ",", y);
                }else {
                    eosio::print("coordinate#", id, " failed to move");
                }
            }

            // @abi action
            void killentity(account_name author, const uint32_t id, const uint32_t entityType){
                auto entity_lookup = entities.find(id);
                entities.erase(entity_lookup);
                eosio::print("killEntity: entity#", id, " destroyed");

                auto coordinates_lookup = coordinates.find(id);
                coordinates.erase(coordinates_lookup);
                eosio::print("killEntity: coordinate#", id, " destroyed");
            }

            void entityexists(const uint32_t id) {
                auto entity_lookup = entities.find(id);
                eosio_assert(entity_lookup != entities.end(), 
                    "entityexists: Entity does not exist");
            }
            void coordexists(const uint32_t id) {
                auto coordinate_lookup = coordinates.find(id);
                eosio_assert(coordinate_lookup != coordinates.end(), 
                    "coordinateexists: Coordinate does not exist");
            }

        private:
            // entity can be either food or spore
            /*enum EntityType{
                Food, Spore
            };*/
            // @abi table Spore i64
            struct entity {
                uint64_t id;
                std::string color;
                uint64_t type;

                uint64_t primary_key() const { return id; }
                EOSLIB_SERIALIZE(entity, (id)(color)(type) )
            };
            typedef eosio::multi_index<N(entities), entity> entity_table;
            entity_table entities;

            struct Coordinate {
                uint64_t id;
                //uint64_t entityId;
                uint64_t x;
                uint64_t y;

                uint64_t primary_key() const { return id; }
                EOSLIB_SERIALIZE(Coordinate, (id)(x)(y) )
            };
            typedef eosio::multi_index<N(coordinates), Coordinate> coordinate_table;
            coordinate_table coordinates;
    };

    EOSIO_ABI( spore, (createentity)(moveentity)(killentity)(entityexists)(coordexists) )
}