/*
    栈的练习
*/
#include <stdio.h>

int shu_zi[10];
int ge_shu;

int kong() {
    if (!ge_shu) {
        return 1;
    }
    else {
        return 0;
    }
}

int man() {
    if (10 == ge_shu) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int shu) {
    shu_zi[ge_shu] = shu;
    ge_shu++;
}

int pop() {
    ge_shu--;
    return shu_zi[ge_shu];
}

int main() {
    
    return 0;
}
