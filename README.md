This repo was built with examples from ff links:
* https://developers.eos.io/eosio-nodeos/docs/docker-quickstart

* https://steemit.com/devs/@eos-asia/eos-smart-contracts-part-1-getting-started-ping-equivalent-in-eos


# Instructions:


### Setup EOS Node


1. docker pull eosio/eos-dev 

- from (https://developers.eos.io/eosio-nodeos/docs/docker-quickstart)

2. sudo docker run --rm --name eosio -d -p 8888:8888 -p 9876:9876 -v /tmp/work:/work -v /tmp/eosio/data:/mnt/dev/data -v /tmp/eosio/config:/mnt/dev/config eosio/eos-dev  /bin/bash -c "nodeos -e -p eosio --plugin eosio::wallet_api_plugin --plugin eosio::wallet_plugin --plugin eosio::producer_plugin --plugin eosio::history_plugin --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin --plugin eosio::http_plugin -d /mnt/dev/data --config-dir /mnt/dev/config --http-server-address=0.0.0.0:8888 --access-control-allow-origin=* --contracts-console"

 - from (https://developers.eos.io/eosio-nodeos/docs/docker-quickstart)

3. Edit config.ini: sudo docker exec -i -t eosio /bin/bash

4. vi mnt/dev/config/config.ini

5. change *"http-validate-host = 1"* to *"http-validate-host = 0"*

6. View node outputs: docker attach eosio

### Clone EOS Spore contract, marvel at the code/get confused


7. Open new terminal

8. mkdir eos-contract

9. cd eos-contract

10. git clone https://github.com/MNLBlockDevs/eos-simplepacman-contract

11. cd eos-simplepacman-contract/eosspore/contracts

### Compile (generate ABI and WAST files)


12. eosiocpp -o ./spore/spore.wast spore.cpp

13. eosiocpp -g ./spore/spore.abi spore.cpp

### Create your wallet on the EOS node, so we can test it out!


14. cleos wallet create -n TEXT=chris

15. cleos wallet unlock -n TEXT=chris

16. cleos create key

17. store the password, public key and private keys

18. cleos wallet import [private key]

### Deploy to the single node test net


19. cleos create account eosio spore.ctr [public key] [public key]

20. cleos set contract spore.ctr ./spore -p spore.ctr

21. cleos create account eosio tester [public key] [public key]

### Try it out!

22. cleos push action spore.ctr createentity '["tester", 0, "blue", 0]' -p tester

23. cleos push action spore.ctr moveentity '["tester", 0, 10, 10]' -p tester

24. cleos push action spore.ctr killentity '["tester", 0, 0]' -p tester




## Next: Build the web app!

### Notes:
* Python 2.7
* Latest Node

### cd back to eosspore
cd ..

### install dependencies
npm install

### serve with hot reload at localhost:8080
npm run dev

### build for production with minification
npm run build

### serve your production build at localhost:5000
npm run serve