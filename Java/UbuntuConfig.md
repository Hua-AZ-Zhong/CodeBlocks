.vimrc
set fileencodings=utf-8,zh_CN.utf-8
set termencoding=utf-8
set encoding=utf-8

.profile
# ~/.profile: executed by the command interpreter for login shells.
# This file is not read by bash(1), if ~/.bash_profile or ~/.bash_login
# exists.
# see /usr/share/doc/bash/examples/startup-files for examples.
# the files are located in the bash-doc package.

# the default umask is set in /etc/profile; for setting the umask
# for ssh logins, install and configure the libpam-umask package.
#umask 022

# if running bash
if [ -n "$BASH_VERSION" ]; then
    # include .bashrc if it exists
    if [ -f "$HOME/.bashrc" ]; then
        . "$HOME/.bashrc"
    fi
fi

# set PATH so it includes user's private bin directories
PATH="$HOME/bin:$HOME/.local/bin:$PATH"

set -o vi

export LC_ALL=C
export LANG=zh_CN.utf8

echo "sudo mount -t vboxsf -o uid=1000,gid=1000 istdoc /srv/istdoc"
echo "sudo mount -t vboxsf -o uid=33,gid=33 istsvn ~/host"
echo "sudo mount -t vboxsf -o uid=1000,gid=1000 logs /srv/logs"


echo "run moni server first"
echo "cd moni"
echo "nohup ./moni &"
echo "run gitbook serve"
echo "    cd /srv/istdoc; "
echo "    nohup gitbook serve & 2>/dev/null 1>/dev/null"


echo "run redmine server"
echo " cd /srv/redmine; "
echo " nohup  bundle exec rails server webrick -e production -b0.0.0.0 & "



export PATH=$PATH:/usr/local/go/bin
#export GOROOT=$HOME/go
#export PATH=$PATH:$GOROOT/bin

#export GOROOT=/usr/lib/go-1.10
#export GOPATH=/home/ist/go






/etc/apache2/apache2.conf
/etc/apache2/sites-available/gitbook.conf