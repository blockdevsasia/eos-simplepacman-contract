This repo was built with examples from ff links:
https://developers.eos.io/eosio-nodeos/docs/docker-quickstart
https://steemit.com/devs/@eos-asia/eos-smart-contracts-part-1-getting-started-ping-equivalent-in-eos


Instructions:

docker pull eosio/eos-dev

sudo docker run --rm --name eosio -d -p 8888:8888 -p 9876:9876 -v /tmp/work:/work -v /tmp/eosio/data:/mnt/dev/data -v /tmp/eosio/config:/mnt/dev/config eosio/eos-dev  /bin/bash -c "nodeos -e -p eosio --plugin eosio::wallet_api_plugin --plugin eosio::wallet_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --plugin eosio::http_plugin -d /mnt/dev/data --config-dir /mnt/dev/config --http-server-address=0.0.0.0:8888 --access-control-allow-origin=* --contracts-console"

*need to change config.ini*
sudo docker exec -i -t eosio /bin/bash
vi mnt/dev/config/config.ini
change "http-validate-host = 1" to "http-validate-host = 0" 

docker attach eosio

*open new terminal*

mkdir eos-contract
cd eos-contract
git clone https://github.com/MNLBlockDevs/eos-simplepacman-contract
cd eosspore/contracts

*read README.md (this file)*

eosiocpp -o ./spore/spore.wast spore.cpp
eosiocpp -g ./spore/spore.abi spore.cpp

cleos wallet create -n TEXT=chris
cleos wallet unlock -n TEXT=chris
cleos create key
*store the password, public key and private keys*
cleos wallet import [private key]

cleos create account eosio spore.ctr [public key] [public key]
cleos set contract spore.ctr ./spore -p spore.ctr

cleos create account eosio tester [public key] [public key]

TRY IT OUT:
cleos push action spore.ctr createentity '["tester", 0, "blue", 0]' -p tester
cleos push action spore.ctr moveentity '["tester", 0, 10, 10]' -p tester
cleos push action spore.ctr killentity '["tester", 0, 0]' -p tester



