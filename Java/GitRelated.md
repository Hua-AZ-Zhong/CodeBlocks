## Step to install Gitlab on Ubuntu

sudo apt-get update

oasisadm@oasisadm-virtual-machine:~$ sudo apt-get install -y curl openssh-server ca-certificates
Reading package lists... Done
Building dependency tree       
Reading state information... Done
ca-certificates is already the newest version (20180409).
openssh-server is already the newest version (1:7.6p1-4).
The following additional packages will be installed:
  libcurl4
The following NEW packages will be installed:
  curl libcurl4
0 upgraded, 2 newly installed, 0 to remove and 18 not upgraded.
Need to get 373 kB of archives.
After this operation, 1,036 kB of additional disk space will be used.
Get:1 http://cn.archive.ubuntu.com/ubuntu bionic-updates/main amd64 libcurl4 amd64 7.58.0-2ubuntu3.5 [214 kB]
Get:2 http://cn.archive.ubuntu.com/ubuntu bionic-updates/main amd64 curl amd64 7.58.0-2ubuntu3.5 [159 kB]
Fetched 373 kB in 4s (105 kB/s)
Selecting previously unselected package libcurl4:amd64.
(Reading database ... 160495 files and directories currently installed.)
Preparing to unpack .../libcurl4_7.58.0-2ubuntu3.5_amd64.deb ...
Unpacking libcurl4:amd64 (7.58.0-2ubuntu3.5) ...
Selecting previously unselected package curl.
Preparing to unpack .../curl_7.58.0-2ubuntu3.5_amd64.deb ...
Unpacking curl (7.58.0-2ubuntu3.5) ...
Setting up libcurl4:amd64 (7.58.0-2ubuntu3.5) ...
Processing triggers for libc-bin (2.27-3ubuntu1) ...
Processing triggers for man-db (2.8.3-2ubuntu0.1) ...
Setting up curl (7.58.0-2ubuntu3.5) ...

oasisadm@oasisadm-virtual-machine:~$ curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ee/script.deb.sh | sudo bash
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100  5933    0  5933    0     0   1907      0 --:--:--  0:00:03 --:--:--  1907
Detected operating system as Ubuntu/bionic.
Checking for curl...
Detected curl...
Checking for gpg...
Detected gpg...
Running apt-get update... done.
Installing apt-transport-https... done.
Installing /etc/apt/sources.list.d/gitlab_gitlab-ee.list...done.
Importing packagecloud gpg key... done.
Running apt-get update... done.

The repository is setup! You can now install packages.



oasisadm@oasisadm-virtual-machine:~$ sudo EXTERNAL_URL="http://127.0.0.1" apt-get install gitlab-ee
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following NEW packages will be installed:
  gitlab-ee
0 upgraded, 1 newly installed, 0 to remove and 18 not upgraded.
Need to get 521 MB of archives.
After this operation, 1,634 MB of additional disk space will be used.
Err:1 https://packages.gitlab.com/gitlab/gitlab-ee/ubuntu bionic/main amd64 gitlab-ee amd64 11.4.4-ee.0
  Could not wait for server fd - select (11: Resource temporarily unavailable) [IP: 54.230.84.105 443]
E: Failed to fetch https://packages-gitlab-com.s3-accelerate.amazonaws.com/7/11/ubuntu/package_files/42136.deb?AWSAccessKeyId=AKIAJ74R7IHMTQVGFCEA&Signature=CxO1Xm67A5YE2UMLHmA6PLEVe9U=&Expires=1541389821  Could not wait for server fd - select (11: Resource temporarily unavailable) [IP: 54.230.84.105 443]
E: Unable to fetch some archives, maybe run apt-get update or try with --fix-missing?



oasisadm@oasisadm-virtual-machine:~$ sudo vi /etc/apt/sources.list.d/gitlab-ce.list
添加以下内容
deb https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu xenial main

oasisadm@oasisadm-virtual-machine:~$ sudo vi /etc/gitlab/gitlab.rb
添加或替换
external_url 'http://172.16.81.91/'
其中IP可以填写为本机 127.0.0.1

oasisadm@oasisadm-virtual-machine:~$ sudo apt-get update
Hit:1 http://security.ubuntu.com/ubuntu bionic-security InRelease                                 
Hit:2 http://cn.archive.ubuntu.com/ubuntu bionic InRelease                                        
Get:3 https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu xenial InRelease [23.3 kB]                                                                          
Hit:4 http://cn.archive.ubuntu.com/ubuntu bionic-updates InRelease                                                                                              
Ign:5 https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu xenial/main amd64 Packages                                      
Get:5 https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu xenial/main amd64 Packages [47.0 kB]                            
Hit:6 http://cn.archive.ubuntu.com/ubuntu bionic-backports InRelease                                                                   
Hit:7 https://packages.gitlab.com/gitlab/gitlab-ee/ubuntu bionic InRelease       
Fetched 70.3 kB in 3s (22.2 kB/s)                                                
Reading package lists... Done
oasisadm@oasisadm-virtual-machine:~$ sudo apt-get install gitlab-ce
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following NEW packages will be installed:
  gitlab-ce
0 upgraded, 1 newly installed, 0 to remove and 18 not upgraded.
Need to get 459 MB of archives.
After this operation, 1,453 MB of additional disk space will be used.
Get:1 https://mirrors.tuna.tsinghua.edu.cn/gitlab-ce/ubuntu xenial/main amd64 gitlab-ce amd64 11.4.4-ce.0 [459 MB]
49% [1 gitlab-ce 281 MB/459 MB 61%]                                                                                                                                                                2,364 kB/s 1min 15stFetched 459 MB in 3min 29s (2,196 kB/s)                                                                                                                                                                               
Selecting previously unselected package gitlab-ce.
(Reading database ... 160512 files and directories currently installed.)
Preparing to unpack .../gitlab-ce_11.4.4-ce.0_amd64.deb ...
Unpacking gitlab-ce (11.4.4-ce.0) ...
Setting up gitlab-ce (11.4.4-ce.0) ...
It looks like GitLab has not been configured yet; skipping the upgrade script.

       *.                  *.
      ***                 ***
     *****               *****
    .******             *******
    ********            ********
   ,,,,,,,,,***********,,,,,,,,,
  ,,,,,,,,,,,*********,,,,,,,,,,,
  .,,,,,,,,,,,*******,,,,,,,,,,,,
      ,,,,,,,,,*****,,,,,,,,,.
         ,,,,,,,****,,,,,,
            .,,,***,,,,
                ,*,.
  


     _______ __  __          __
    / ____(_) /_/ /   ____ _/ /_
   / / __/ / __/ /   / __ `/ __ \
  / /_/ / / /_/ /___/ /_/ / /_/ /
  \____/_/\__/_____/\__,_/_.___/
  

Thank you for installing GitLab!
GitLab was unable to detect a valid hostname for your instance.
Please configure a URL for your GitLab instance by setting `external_url`
configuration in /etc/gitlab/gitlab.rb file.
Then, you can start your GitLab instance by running the following command:
  sudo gitlab-ctl reconfigure

For a comprehensive list of configuration options please see the Omnibus GitLab readme
https://gitlab.com/gitlab-org/omnibus-gitlab/blob/master/README.md

oasisadm@oasisadm-virtual-machine:~$ 

重新修改/etc/gitlab/gitlab.rb文件中的external_url，可能安装过程中被覆盖了

oasisadm@oasisadm-virtual-machine:~$ sudo gitlab-ctl reconfigure


Running handlers:
Running handlers complete
Chef Client finished, 436/618 resources updated in 02 minutes 53 seconds
gitlab Reconfigured!
oasisadm@oasisadm-virtual-machine:~$
















## DigitalOcean服务器搭建Gitbook

sudo apt install npm
sudo npm install -g gitbook-cli


zhonghua@ubuntu-s-1vcpu-1gb-nyc3-01:~$ gitbook
/usr/bin/env: ‘node’: No such file or directory
zhonghua@ubuntu-s-1vcpu-1gb-nyc3-01:~$ /usr/local/lib/node_modules/gitbook-cli/bin/gitbook.js
/usr/bin/env: ‘node’: No such file or directory

解决方法：
sudo ln -s /usr/bin/nodejs /usr/bin/node





## golang的搭建
oasisadm@oasisadm-virtual-machine:~$ sudo snap install go
[sudo] password for oasisadm: 
error: This revision of snap "go" was published using classic confinement and thus may perform
       arbitrary system changes outside of the security sandbox that snaps are usually confined to,
       which may put your system at risk.

       If you understand and want to proceed repeat the command including --classic.
oasisadm@oasisadm-virtual-machine:~$ sudo snap install go --classic
Download snap "go" (3039) from channel "stable"                                                                                                                                                       2% 36.2kB/s 37.1m


Method 2
sudo apt install golang-go

oasisadm@oasisadm-virtual-machine:~$ sudo apt install golang-go
Reading package lists... Done
Building dependency tree       
Reading state information... Done
The following additional packages will be installed:
  golang-1.10-go golang-1.10-race-detector-runtime golang-1.10-src golang-race-detector-runtime golang-src pkg-config
Suggested packages:
  bzr mercurial subversion
The following NEW packages will be installed:
  golang-1.10-go golang-1.10-race-detector-runtime golang-1.10-src golang-go golang-race-detector-runtime golang-src pkg-config
0 upgraded, 7 newly installed, 0 to remove and 33 not upgraded.
Need to get 40.3 MB of archives.
After this operation, 225 MB of additional disk space will be used.
Do you want to continue? [Y/n] y
Get:1 http://cn.archive.ubuntu.com/ubuntu bionic-updates/main amd64 golang-1.10-src amd64 1.10.4-2ubuntu1~18.04.1 [11.1 MB]
Get:2 http://cn.archive.ubuntu.com/ubuntu bionic-updates/main amd64 golang-1.10-go amd64 1.10.4-2ubuntu1~18.04.1 [28.6 MB]                                                                                            


oasisadm@oasisadm-virtual-machine:~/moni$ go build .
mm.go:9:3: cannot find package "github.com/radovskyb/watcher" in any of:
	/usr/lib/go-1.10/src/github.com/radovskyb/watcher (from $GOROOT)
	/home/oasisadm/go/src/github.com/radovskyb/watcher (from $GOPATH)


oasisadm@oasisadm-virtual-machine:~/moni$ go get github.com/radovskyb/watcher
# cd .; git clone https://github.com/radovskyb/watcher /home/oasisadm/go/src/github.com/radovskyb/watcher
Cloning into '/home/oasisadm/go/src/github.com/radovskyb/watcher'...
fatal: unable to access 'https://github.com/radovskyb/watcher/': Failed to connect to github.com port 443: Connection refused
package github.com/radovskyb/watcher: exit status 128
oasisadm@oasisadm-virtual-machine:~/moni$ go get github.com/radovskyb/watcher
再次获取成功，目录在$HOME/go/src

等同于
仓库1：
https://github.com/radovskyb/watcher 
git clone https://github.com/radovskyb/watcher /home/oasisadm/go/src/github.com/radovskyb/watcher

仓库1：
https://github.com/fsnotify/fsnotify 
git clone https://github.com/fsnotify/fsnotify /home/oasisadm/go/src/github.com/fsnotify/fsnotify

oasisadm@oasisadm-virtual-machine:~/go/src/github.com$ go get github.com/fsnotify/fsnotify
package golang.org/x/sys/unix: unrecognized import path "golang.org/x/sys/unix" (https fetch: Get https://golang.org/x/sys/unix?go-get=1: dial tcp 172.217.24.209:443: connect: connection refused)




## 搭建apache服务器
sudo apt install apache2-bin
sudo apt install apache2
sudo apt install subversion
sudo apt-get install libapache2-svn 安装不了