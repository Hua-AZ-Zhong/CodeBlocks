## set Github private keys
cd ~/.ssh

## install C/C++ compiler
sudo apt install gcc
sudo apt install g++

## set vim format
sudo vi /etc/vim/vimrc
set ts=4
set expandtab

## set common env
vi ~/.profile
export PATH=$PATH:.
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
set -o vi