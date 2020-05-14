#ifndef INC_514_UTILS_H
#define INC_514_UTILS_H

int menuInput(){
    int order = 0;
    do {
        printf("请选择你的操作(输入命令前的数字后回车):\n");
        if (1==scanf("%d",&order))
            break;
        while (getchar()!='\n'); //消化掉多余输入
    }while (1);
}


int inputMultiString(char *arg[],int n,char *description[]){
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        do {
            printf("请输入%s(以空白符号结束%s):\n",description[i],i>0?"输入Edit编辑上一次输入的数据":"");
            if(1==scanf("%s",arg[i]))
                flag=1;
            while (getchar()!='\n');
            if(0==strcmp(arg[i],"Edit")){
                i-=2;
                break;
            }
        }while (flag==0);
    }
    return n;
}

int inputMultiInt(int *arg[],int n,char *description[]){
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        do {
            printf("请输入%s(以空白符号结束%s):\n",description[i],i>0?"输入9527编辑上一次输入的数据":"");
            if(1==scanf("%d",arg[i]))
                flag=1;
            while (getchar()!='\n');
            if (9527==arg[i]){
                i-=2;
                break;
            }
        }while (flag==0);
    }
    return n;
}

int inputInt(int *arg,char *desc){
    int flag = 0;
    do {
        printf("请输入%s:\n",desc);
        if (1 == scanf("%d",arg))
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);
}

int inputMultiFloat(float *arg[],int n,char *description[]){
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        do {
            printf("请输入%s(以空白符号结束%s):\n",description[i],i>0?"输入9527编辑上一次输入的数据":"");
            if(1==scanf("%f",arg[i]))
                flag=1;
            while (getchar()!='\n');
            if (9527==arg[i]){
                i-=2;
                break;
            }
        }while (flag==0);
    }
    return n;
}

int inputFloat(float *arg,char *desc){
    int flag = 0;
    do {
        printf("请输入%s:\n",desc);
        if (1 == scanf("%f",arg))
            flag = 1;
        while (getchar()!='\n');
    }while (flag == 0);
}
#endif //INC_514_UTILS_H
