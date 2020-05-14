#include <stdio.h>

int menu(){
    int order = 0;
    do {
        printf("请选择你的操作(输入命令前的数字后回车):\n");
        if (1==scanf("%d",&order))
            break;
        while (getchar()!='\n'); //消化掉多余输入
    }while (1);
}

int main() {
    printf("Hello, World!\n");
    menu();
    return 0;
}
