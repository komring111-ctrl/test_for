#include<stdio.h>
#include<math.h>
#include<string.h>
int octalToDecimal(const char *octalNumber);
int main(){
    char octalNumber[100];
    printf("请输入一个八进制数: ");
    scanf("%s",octalNumber);
    int decimalNumber=octalToDecimal(octalNumber);
    printf("八进制数%s转化为十进制数是: %d\n",octalNumber,decimalNumber);
    return 0;
}
int octalToDecimal(const char *octalNumber){
    int decimalNumber=0;
    int length=strlen(octalNumber);
    for(int i=0;i<length;i++){
        int digit=octalNumber[i]-'0';
        decimalNumber+=digit*pow(8,length-i-1);
    }
    return decimalNumber;
}//oct2dec