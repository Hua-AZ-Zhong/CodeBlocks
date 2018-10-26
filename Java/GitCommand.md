## How to use git command in Ubuntu/Other Terminal

### Clone a repository
> git clone https://github.com/Hua-AZ-Zhong/CodeBlocks.git GitHub

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



# Problem encountered
## No.1 You've successfully authenticated, but GitHub does not provide shell access.

## No.2 Could not open a connection to your authentication agent.
What I do: use command "ssh-agent bash"
