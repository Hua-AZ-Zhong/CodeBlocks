#!/bin/bash
#
a=0
userfile=user.txt
for i in `seq 10`
do
read -p "请输入登陆用户名：" USERNAME
RET=`expr match $USERNAME "[0-9]*$"`
if [ "$USERNAME" = "" ]
	then
	echo "Username can not be null !!!"
elif [ ${RET} -gt 0 ];
	then
	echo "Username can not be an number !!!"
fi
if [ "$USERNAME"  == "`grep "$USERNAME" $userfile | awk '{print $1}'`" ]
			then
			echo "用户名输入正确！！！"
			break
else
			echo "用户名输入错误！！！"
			let a++
			if [ $a -eq 3 ]
						then
						echo "对不起，用户名输入次数过多！！！"
						exit 3
			fi
fi
done
for y in `seq 10`
do
read -p "请输入登陆密码："  PASSWD
if [ "$PASSWD" = "" ]
	then
	echo "passwd can not be null !!!"
fi
			if [ "$PASSWD" == "`grep "$USERNAME" $userfile | awk '{print $2}'`" ]
						then
						echo "密码输入正确！！！"
						break
			else
						echo "密码输入错误！！！" 
						let a++
						if [ $a -eq 3 ]
							then
							echo "对不起，密码输入次数过多！！！"
							exit 3
						fi
			fi
done
echo "登陆成功！！！"
read -p "请输入要打包的目录(绝对路径)：" D
read -p "请输入要存放的位置(绝对路径)：" W
read -p "请输入打包的名字(etc.tar):" T
read -p "请输入你要以什么格式打包(gz,xz,bz2):" F
for x in `seq 4`
do
	if [ $F == "gz" ] 
		then
		tar zcvf $W/$T.gz  $D
	elif [ $F == "xz" ]
		then
		tar Jcvf $W/$T.xz $D
	elif [ $F == "bzip2" ] 
		then
		tar jcvf $W/$T.bz2 $D
	else 
		echo "您输入的格式不正确！！！"		
	fi
echo "打包已完成！！！"
done
