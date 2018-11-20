## How to use git command in Ubuntu/Other Terminal

### Clone a repository
HTTPS: git clone https://github.com/Hua-AZ-Zhong/CodeBlocks.git GitHub/CodeBlocks
SSH:   git clone git@github.com:Hua-AZ-Zhong/CodeBlocks.git GitHub/CodeBlocks

### Commit changes
What I do in ubuntu command line:
git status
git add Java
git commit -m "some example"

> encountered some error:
> *** Please tell me who you are.
>
> Run

>  git config --global user.email "you@example.com"
>  git config --global user.name "Your Name"

> to set your account's default identity.
> Omit --global to set the identity only in this repository.

git config --global user.name "zhonghua"
git config --global user.email "253729119@qq.com"

git commit -m "some example"

oasisadm@oasisadm-virtual-machine:~/GitHub$ git commit -m "some example"
[master f99eedb] some example
 6 files changed, 25 insertions(+)
 create mode 100644 Java/Array.class
 create mode 100644 Java/Array.java
 create mode 100644 Java/GitCommand.md
 create mode 100644 Java/Person.class
 create mode 100644 Java/TestDemo.class
 create mode 100644 Java/TestDemo.java

git push -u origin master

oasisadm@oasisadm-virtual-machine:~/GitHub$ git push -u origin master
Username for 'https://github.com': 253729119@qq.com
Password for 'https://253729119@qq.com@github.com': 
Counting objects: 9, done.
Compressing objects: 100% (9/9), done.
Writing objects: 100% (9/9), 1.97 KiB | 134.00 KiB/s, done.
Total 9 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/Hua-AZ-Zhong/CodeBlocks.git
   7e69041..f99eedb  master -> master
Branch 'master' set up to track remote branch 'master' from 'origin'.

## Other command
git checkout
git pull

### Check if the ssh key is active
Command: ssh -T git@github.com
oasisadm@oasisadm-virtual-machine:~/.ssh$ ssh -T git@github.com
Hi Hua-AZ-Zhong! You've successfully authenticated, but GitHub does not provide shell access.

# Problem encountered
## No.1 You've successfully authenticated, but GitHub does not provide shell access.
What I do: Replace https mode to ssh mode
1. git remote -v     to comfirm https is used.
origin	https://github.com/Hua-AZ-Zhong/CodeBlocks.git (fetch)
origin	https://github.com/Hua-AZ-Zhong/CodeBlocks.git (push
2. git remote rm origin
3. git remote add origin git@github.com:Hua-AZ-Zhong/CodeBlocks.git
4. git remote -v
origin	git@github.com:Hua-AZ-Zhong/CodeBlocks.git (fetch)
origin	git@github.com:Hua-AZ-Zhong/CodeBlocks.git (push)
5. update some file, git add/commit
6. git push
fatal: The current branch master has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin master
7.git push --set-upstream origin master
oasisadm@oasisadm-virtual-machine:~/GitHub/Java$ git push --set-upstream origin master
Counting objects: 4, done.
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 445 bytes | 222.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0)
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To github.com:Hua-AZ-Zhong/CodeBlocks.git
   f8a7758..fbbd814  master -> master
8. update some file again, git push is okay.

## No.2 When execute "ssh-add ~/.ssh/id_rsa", occured "Could not open a connection to your authentication agent."
What I do: use command "ssh-agent bash"
2018年 10月 27日 星期六 00:16:27 CST
