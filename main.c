#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void middle(char *s,int n){
    int i;
    if(n%2==1){
        for(i=(n-1)/2;i<n-1;i++){
            s[i]=s[i+1];
    }
    s[n-1]=' ';
    }
}
int main()
{
    char *str,*temp,*last;
    setlocale(LC_ALL,"Rus");
    FILE *f1,*f2;
    char s[100];
    char prob[100];
    char lastword[100];
    char m[100];
    printf("Запишите строку в файл in.txt,проверьте в файле out.txt");
    prob[0]='\0';
    lastword[0]='\0';
    m[0]='\0';
    f1=fopen("in.txt","r");
    fgets(&s,100,f1);
    fclose(f1);
    str=strtok(s," .");
while(str!=NULL){
    strcat(prob,str);
    temp=str;
    str=strtok(NULL," .");
    if(str!=NULL){
    strcat(prob," ");
    }else{
    last=temp;
    }

}
f2=fopen("out.txt","a+");
    fprintf(f2,"%s\n",prob);
    str=strtok(prob," ");
    while(str!=NULL){
        if(strcmp(str,last)!=0){
            strcat(lastword,str);
            strcat(lastword," ");
        }
        str=strtok(NULL," ");
    }
    fprintf(f2,"%s\n",lastword);
    str=strtok(lastword," ");
    while(str!=NULL){
        if(strlen(str)%2==1){
               temp=str;
            middle(temp,strlen(str));
            strcat(m,temp);
        }else{
        strcat(m,str);
        strcat(m," ");
        }
        str=strtok(NULL," ");
    }
    fprintf(f2,"%s\n",m);
    fclose(f2);
    return 0;
}
