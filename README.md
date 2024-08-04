# pokemon-quests
pokemon firered based rom hack game for gba (Gameboy advance)


# guide:
## For Ubuntu
1. step 1: clone agbcc, poryscript, and porymap from their respositories
```
git clone https://github.com/huderlem/porymap
```
```
git clone https://github.com/huderlem/poryscript.git
```
```
git clone https://github.com/pret/agbcc
```
put all in respositories in the same directory where pokequests is in.
2. step 2: install agbcc:
```
cd agbcc
```
```
./build.sh
```
```
./install.sh ../pokequests
```
execute in the same order as it here...
3. step 3: install porymap:
```
sudo apt-get install qt6-declarative-dev
# if your distro does not have qt6-declarative-dev, try sudo apt-get install qtdeclarative5-dev
qmake
make
./porymap
```
4. step 4: install poryscript:
```
# you need to install go before installing poryscript
go build 
```
```
./install.sh ../pokequests
```
*If something goes wrong follow the instructions in the links for each software package.*
# links to external repositories:
porymap: https://github.com/huderlem/porymap/  
poryscript: https://github.com/huderlem/poryscript  
pokefirered (this project based on): https://github.com/pret/pokefirered  