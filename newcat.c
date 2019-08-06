#include <stdio.h>
#define BUFFERSIZE 5096

int main(int argc, char *argv[]);
int readTxt(int argc, char *argv[]);


int main(int argc, char *argv[]){
    if(strcmp(argv[1], "-f") == 0){
        return readTxt(argc, argv);
    }
    else{
        printf("No valid options expressed \n");
        return 0;
    }
}

int readTxt(int argc, char *argv[]){
    FILE *file;
    char tempLine[BUFFERSIZE] = {'\0'};
    char lastline[BUFFERSIZE] = {'\0'};
    
    if(argc < 2){
        printf("No such file \n");
        return 0;
    }
    if(argc > 2){
        for(int i=2;i<=argc-1;i++){
            file = fopen(argv[i], "r");
            if(file == NULL){
                printf("No such file \n");
                return 0;
            }
            while(fgets(tempLine, sizeof(tempLine), file)){
                if(tempLine != lastline){
                    printf(tempLine);
                }
                *lastline = &tempLine;    
            }
            if(i < argc){
                printf("\n\n\n"); 
                file = fopen(argv[i], "r");
            }
        }
    }
    return 1;
}