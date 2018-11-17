/*通过消息队列的msgget（key,flag|mode）创建一消息队列创建一个结构用于存储要发送的信息，发送的信息从键盘上读取*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
typedef struct {
 long type;
 char name[20];
 int age;
 long score;

}msg;

int main(){

int id=  msgget(0x8888,IPC_CREAT|0666);
 
   msg m;
while(1){
puts("请输入类型，姓名，年龄，成绩");
scanf("%ld%s%d%ld",&m.type,m.name,&m.age,&m.score);
msgsnd(id,&m,sizeof(m)-sizeof(long),0);
 }
//msgctl(id,IPC_RMID,NULL);

}
