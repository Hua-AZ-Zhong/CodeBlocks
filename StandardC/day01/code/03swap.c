/*
    交换两个变量中数字的练习
*/
int main() {
    int shu_zi_1 = 3, shu_zi_2 = 7;
    /*
        使用临时变量完成两个变量
        数字的交换
    */
    /*int shu_zi = shu_zi_1;
    shu_zi_1 = shu_zi_2;
    shu_zi_2 = shu_zi;*/
    /*
        不使用中间变量完成两个变量中
        数字的交换
    */
    shu_zi_1 = shu_zi_1 + shu_zi_2;
    shu_zi_2 = shu_zi_1 - shu_zi_2;
    shu_zi_1 = shu_zi_1 - shu_zi_2;
    return 0;
}



