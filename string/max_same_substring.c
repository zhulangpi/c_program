#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Q:寻找两个字符串的最长公共字串
//A:
//s1 abcde
//s2 bces  
//  \s1 0 1 2 3 4
// s2
//  0   0 1 0 0 0
//  1   0 0 2 0 0
//  2   0 0 0 0 1
//  3   0 0 0 0 0
int max_same_substring(const char* s1, const char* s2)
{
    int len1=0,len2=0;
    int i=0,j=0,imax=0,jmax=0,max=0;;
    char *same;

    if(!s1||!s2)
        return -1;

    len1 = strlen(s1);
    len2 = strlen(s2);

    same = (char*)malloc(len1*len2*sizeof(char));
    if(!same)
        return -1;
    memset(same, 0, len1*len2*sizeof(char));

    //矩阵元素不为零，表示对应s1,s2元素相同
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if( s1[i] == s2[j] ){
                if(i>=1 && j>=1){
                    *(same + i*len1 + j) = *(same + (i-1)*len1 + j-1 ) + 1;
                }else
                    *(same + i*len1 + j) = 1;
            }
            //同时遍历出矩阵最大元素
            if(*(same + i*len1 + j ) >= max ){
                imax = i;
                jmax = j;
                max = *(same + i*len1 + j);
            }
        }
    }
    free(same);
    for(i=0;i<max;i++){
        printf("%c", s1[imax - max + 1 + i]);
    }
    printf("\n");

    return 0;
}


int main(int argc, char* argv[])
{
    char str1[] = "aaaaadsaqwerzxc";
    char str2[] = "aaaaadsaaqwerlzxc";

    if(argc>=3){
        strcpy(str1,argv[1]);
        strcpy(str2,argv[2]);
    }

    max_same_substring(str1,str2);

}

