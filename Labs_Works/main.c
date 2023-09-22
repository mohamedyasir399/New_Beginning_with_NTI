#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_struct.h"
int main()
{
    char inputWprd[50],res[50];
    int count =0;
    gets(inputWprd);
    queue_t *Qu = init_queue(strlen(inputWprd));
    for(int i =0;i<strlen(inputWprd);i++)
    {
        //printf("iam %d  %c\n",i,inputWprd[i]);
        if(inputWprd[i]=='*')
        {
            deQueue(Qu,&res[count]);
           // printf("iam pop - %c \n",res[count]);
            count++;
        }else if(inputWprd[i]==' ')
        {
            continue;
        }else{
            enQueue(Qu,inputWprd[i]);
        }
    }
    printf("the EnQueue word %s\n",res);
    free_queue(Qu);
   return 0;
}
