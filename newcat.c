#include <stdio.h>
#define BUFFERSIZE 5096

int main(int argc, char *argv[]);
int readFile(int argc, char *argv[]);
int readAddr(int argc, char *argv[]);

int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-f") == 0){
        return readFile(argc, argv);
    }
    else{
        printf("No valid options expressed \n");
        return 0;
    }
}

int readFile(int argc, char *argv[]){
    FILE *file;
    char tempLine[BUFFERSIZE] = {'\0'};
    char lastline[BUFFERSIZE] = {'\0'};
    
    if(argc < 2){
        printf("No such file \n");
        return 0;
    }
    if(argc > 2){
        file = fopen(argv[2], "r");
        for(int i=2;i<=argc;i++){
            while(fgets(tempLine, sizeof(tempLine), file)){
                if(tempLine != lastline){
                    printf(tempLine);
                }
                *lastline = &tempLine;    
            }
            if(i < argc){
                file = fopen(argv[i], "r");
            }
        }
    }
    return 1;
}

int readAddr(int argc, char *argv[]){


    return 1;
}
