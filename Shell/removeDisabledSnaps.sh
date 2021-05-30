############################
# Author: zhong hua        #
# Date : 2021-05-30        #
# Desc: 清理低版本的应用   #
############################
#!/bin/ksh
echo "正在清理低版本的应用(snaps)"
sudo snap list --all | grep -w disabled
sudo snap list --all | grep -w disabled | awk '{printf "sudo snap remove %s --revision %s\n", $1, $3 }' > snapToRemove.list
SNAPLIST=snapToRemove.list
while read LINE
do
    echo "$LINE"
    $LINE
done < $SNAPLIST
echo "已清理低版本的应用(snaps)"
rm -f snapToRemove.list
