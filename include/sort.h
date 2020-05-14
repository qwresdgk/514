#ifndef INC_514_SORT_H
#define INC_514_SORT_H

static int filterDot(const struct dirent * dir) {
    if (strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name, "..") == 0) {
        // 过滤掉 "."和".."
        return 0;
    } else {
        return 1;
    }
}
static void print_dir(const char * dirPath, DIR * dir) {
    struct dirent * file;
    while ((file = readdir(dir)) != NULL) {
        if(strcmp(file->d_name, ".") == 0
           || strcmp(file->d_name, "..") == 0) {
            continue;
        }
        printf("dir position=%ld ", telldir(dir));
        printf("sub file:%s  ", file->d_name);
        printf("\n");
    }
}



void sort(){

    struct dirent *ptr,**namelist;
    if(access(SCHOOLFOLDERS,0)!=F_OK)
        mkdir(SCHOOLFOLDERS,S_IRWXU);

    DIR *dir;
    dir = opendir("/");
    print_dir("/",dir);
//    dir = opendir("/home/vcinex/Works/514/cmake-build-debug/data/school");
//    int n = scandir(dir,&namelist,filterDot,alphasort);
//    if(n<0){
//        printf("scandir() fail:%s \n", strerror(errno));
//    } else{
//        for (int i = 0; i < n; ++i) {
//            printf("idx=%d suf file:%20s \n", i, namelist[i]->d_name);
//        }
//    }
//    printf("%s\n",namelist[0]->d_name);


//    while((ptr = readdir(dir)) != NULL)
//        if((strcmp(".",ptr->d_name)==0)||(strcmp("..",ptr->d_name)==0))
//            break;
//        printf("d_type:%d d_name: %s\n", ptr->d_type,ptr->d_name);
}

#endif //INC_514_SORT_H
