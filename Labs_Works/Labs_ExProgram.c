#include "Labs_ExInterface.h"

//week5
void get_data(student *p2s,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("enter name of student num %d= ",i+1);
        scanf("%s",p2s[i].name);
        printf("enter grade= ");
        scanf("%d",&(p2s[i].grade));
        printf("enter id= ");
        scanf("%d",&(p2s[i].id));
    }
}

void average_highest_lowest_grade(student *p2s,int size,float* avg,student* max,student* min)
{
    *max = p2s[0];
    *min = p2s[0];

    for(int i=0;i<size;i++)
    {
        *avg+=p2s[i].grade;
        if(p2s[i].grade > max->grade)
        {
            *max = p2s[i];
        }else if(p2s[i].grade < min->grade)
        {
            *min = p2s[i];
        }

    }
    *avg/=size;
}

int rising_edge_counter(char signal)
{
    static char PreviseValue = 0,count =0;
    //printf("i'm in c%d s%d p%d\n",count,signal,PreviseValue);
    if(PreviseValue ==0&& signal==1)
    {
        count++;
    }
    PreviseValue = signal;
    return count;
}

///////////////////////////////
int abs(int x)
{
    return (x>0)?x:x*-1;
}

void SimpleCalc (float x,float y)
{
    printf("%.2f + %.2f = %.2f\n",x,y,x+y);
    printf("%.2f - %.2f = %.2f\n",x,y,(float)abs(x-y));
    printf("%.2f * %.2f = %.2f\n",x,y,x*y);
    if(y == 0 ){
        printf("can't div by zero.");
    }else{
    printf("%.2f / %.2f = %.2f",x,y,x/y);
    }
}

unsigned char IsPerfect(int num)
{
    int sum=0;
    if(num <= 0)
    {
        printf("wrong input Number");
        return 0;
    }
    for (int i=1;i<num;i++)
    {
        if(num% i==0)
        {
            sum+=i;
        }
    }
    return (sum == num)?1:0;
}
unsigned char IsArmStrong(unsigned int num)
{
    int sum=0,test= num,count=0,arr[20];
    if(num <= 0)
    {
        printf("wrong input Number");
        return 0;
    }
    while(test !=0)
    {
        arr[count]=(test%10);
        test/=10;
        count++;
    }
    for(int i =0;i<count;i++)
    {
        sum+=pow(arr[i],count);
    }
    return (sum == num)?1:0;
}

void swap(int *x, int *y)
{

    int temp;
    temp = *x;  /// save the value at address x
    *x = *y;    ///put y into x
    *y = temp;  ///put temp into y
}
void BubbleSort(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j =i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
                swap(&arr[i],&arr[j]);
        }
    }
}

void TheNum(int num,int *x, int *y,float *z)
{
    *x = pow(num,2);
    *y = pow(num,3);
    *z = sqrt(num);
}

/////////////////////////////////////////
void GetArr(int arr[3][4])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           scanf("%d",&arr[i][j]);
        }
    }
}
void PrintArr(int arr[3][4])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
void AddTwoArr(int arr1[3][4],int arr2[3][4],int res[3][4])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           res[i][j] = arr1[i][j] +arr2[i][j];
        }
    }
}
void MaxInArr(int arr[3][4])
{
    int max = arr[0][0],min;
    min= max;
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           if(max < arr[i][j])
            max = arr[i][j];
           if(min > arr[i][j])
            min = arr[i][j];
        }
    }
    printf("the max = %d, Min = %d",max,min);
}

unsigned char AreArrTheSame(int arr1[3][4],int arr2[3][4])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           if(arr1[i][j] != arr2[i][j])
           {
               printf("it is not Equal");
               return 0;
           }
        }
    }
    printf("it is Equal");
    return 1;
}
void MultTwoArr(int arr1[][4],int arr2[][4],int res[][4])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<4;j++)
        {
           res[i][j] = arr1[i][j] *arr2[i][j];
        }
    }
}
///////////////
unsigned char IsEven(int x)
{
    return ((x%2==0)?1:0);
}
int CountCharInString(char *p2arr,int max_size)
{
    int count=0;
    for(int i=0;i<max_size;i++)
    {
        if(p2arr[i]== NULL)
        {
            return count;
        }
        count++;
        printf("%d-%c\n",i,p2arr[i]);
    }
}

void callArr1D(int a[],int size,int *NumOfOnes,int *NumOfNeg)
{
    for(int i=0;i<size;i++)
    {

        if(a[i]==1)
        {
            *NumOfOnes+=1;
        }
        if(a[i]<0)
        {
            *NumOfNeg+=1;
        }
    }
}

void arr2D(int **p,int rows,int cols,int *max,int* min,float*avrg)
{
    *max =p[0][0];
    *min = *max;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",p[i][j]);
            if(*max<p[i][j])
                *max=p[i][j];
            if(*min >p[i][j])
                *min =p[i][j];
            *avrg+=(float)p[i][j];
        }
        printf("\n");
    }
    *avrg/=(float)(rows*cols);
}

int WhoIsBiggest(int x,int y,int z)
{
    return (x>y)?((x>z)?x:z):((y>z)?y:z);
}


unsigned long long int Fac(int x)
{
    unsigned long long res=1;
    for (int i=1;i<=x;i++)
    {
        res*=i;
    }
    return res;
}


long long int SeriSum(int x)
{
    long long int sum=0;
    for(int i=1;i<=x;i++)
    {
        sum+=Fac(i)/i;
    }
    return sum;
}


unsigned char IsPrime(int x)
{
    if (x ==1 || x==0)
        return 0;

    for(int i = 2;i<=x/2;i++)
    {
        if(x%i==0)
            return 0;
    }
    return 1;
}


char* DecToBin(int x)
{
    static char bin[8];
    for(int i =7;i>=0;i--)
    {
        bin[i]=(x%2!=0)?'1':'0';
        x/=2;
    }
    return bin;
}



void FizzBuzz(int x)
{
    for(int i =1;i<=x;i++)
    {
        if(i %3 ==0 && i%5 ==0)
        {
            printf("FIZZBUZZ\n");
        }else if(i % 3 ==0)
        {
            printf("FIZZ\n");
        }else if(i % 5 ==0)
        {
            printf("BUZZ\n");
        }else{
            printf("%d\n",i);
        }
    }
}


char* DecToHex(int x)
{
    static char Hexa[2]=" ";

    for(int i =2;x!=0;i--)
    {
        if(x%16 == 15)
        {
            Hexa[i]='F';
        }else if(x%16 == 14)
        {
            Hexa[i]='E';
        }else if(x%16 == 13)
        {
            Hexa[i]='D';
        }else if(x%16 == 12)
        {
            Hexa[i]='C';
        }else if(x%16 == 11)
        {
            Hexa[i]='B';
        }else if(x%16 == 10)
        {
            Hexa[i]='A';
        }else
        {
            Hexa[i] = x%16 +'0';
        }
        x/=16;
    }
    return Hexa;
}

char* DecToOct(int x)
{
    static char Octa[4]=" ";
    for(int i =3;i!=0;i--)
    {
        Octa[i]=x%8+'0';
        x/=8;
    }
    return Octa;
}


///////////////////////////////////////////////
float add(float x,float y)
{
    return x+y;
}
float sub(float x,float y)
{
    return x-y;
}
float mul(float x,float y)
{
    return x*y;
}
float div_fn(float x,float y)
{
    if(y ==0)
    {
        printf("can't make it");
    }
    return x/y;
}
int mod(int x,int y)
{
    return x%y;
}

void print()
{
    for(int i=0;i<5;i++)
    {
        printf("Hello ");
    }
}


float avr(int i, int x, int y, int z, int j)
{
    return (i+x+y+z+j)/5.0;
}

float Average()
{
    int n ,sum;
    printf("Enter Number of Numbers you want there average = ");
    scanf("%d",&n);
    for(int i =0;i < n;i++)
    {
        int j;
        scanf("%d",&j);
        sum +=j;
    }
    return sum/(float)n;
}
