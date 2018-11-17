/*
    计算如下5个数字
    54321
    4321
    321
    21
    1
*/
int main() {
    int shu_zi = 54321, ji_shu = 10000;
    /*shu_zi = shu_zi - 50000;
    shu_zi = shu_zi - 4000;
    shu_zi = shu_zi - 300;
    shu_zi = shu_zi - 20;*/
    shu_zi = shu_zi % ji_shu;
    ji_shu = ji_shu / 10;

    shu_zi = shu_zi % ji_shu;
    ji_shu = ji_shu / 10;

    shu_zi = shu_zi % ji_shu;
    ji_shu = ji_shu / 10;

    shu_zi = shu_zi % ji_shu;
    return 0;
}




