This repo was built with examples from ff links:
* https://developers.eos.io/eosio-nodeos/docs/getting-the-code

* https://steemit.com/devs/@eos-asia/eos-smart-contracts-part-1-getting-started-ping-equivalent-in-eos

* https://medium.com/@TeaSea1/how-to-install-eos-on-windows-ac1b6c7d8369

# Instructions:

* this is not the only way to install an eos node and may be outdated by the time you read this. Do checkout other tutorials if you get stuck. 
* For Windows (using Ubuntu CLI), create a directory in C://. The path for this directory in Ubuntu CLI is /mnt/c/<DirectoryName>.

### Setup EOS Node (follow: https://developers.eos.io/eosio-nodeos/docs/install-nodeos or https://medium.com/@TeaSea1/how-to-install-eos-on-windows-ac1b6c7d8369)

1. git clone https://github.com/EOSIO/eos --recursive

2. cd eos

3. ./eosio_build.sh

On Windows: ./eosio_build.sh ubuntu full

4. Validate Build

On Linux platforms:
~/opt/mongodb/bin/mongod -f ~/opt/mongodb/mongod.conf &

On MacOS:
/usr/local/bin/mongod -f /usr/local/etc/mongod.conf &

Followed by this on all platforms:
cd build
make test

5. Build nodeos (https://developers.eos.io/eosio-nodeos/docs/local-single-node-testnet) 
cd build/programs/nodeos ./nodeos -e -p eosio --plugin eosio::chain_api_plugin --plugin eosio::history_api_plugin

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
