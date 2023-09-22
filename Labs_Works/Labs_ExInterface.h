#ifndef LABS_EX_H_INCLUDED
#define LABS_EX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include<string.h>
//assignmentsweek5
typedef struct member
{
    char name[30];
    int grade;
    int id;
}student;
void get_data(student *,int );
void average_highest_lowest_grade(student *,int,float*,student*,student*);
int rising_edge_counter(char signal);
///////////////////
//assigmentsWeek4
int abs(int);
int CountCharInString(char *p2arr,int max_size);
void callArr1D(int a[],int size,int *NumOfOnes,int *NumOfNeg);
void arr2D(int **p,int rows,int cols,int *max,int* min,float*avrg);
void SimpleCalc (float ,float);
/////////////////
//assigmentsWeek3
unsigned char IsPerfect(int num);
unsigned char IsArmStrong(unsigned int num);
void swap(int *x, int *y);
void BubbleSort(int arr[],int size);
void TheNum(int num,int *x, int *y,float *z);

//////////////////////
void GetArr(int arr[3][4]);
void PrintArr(int arr[3][4]);
void AddTwoArr(int arr1[][4],int arr2[][4],int res[][4]);
void MultTwoArr(int arr1[][4],int arr2[][4],int res[][4]);
void MaxInArr(int arr[3][4]);
unsigned char AreArrTheSame(int arr1[3][4],int arr2[3][4]);

///////////////
unsigned char IsEven(int x);
int WhoIsBiggest(int x,int y,int z);
unsigned long long int Fac(int x);
long long int SeriSum(int x);
unsigned char IsPrime(int x);
char* DecToBin(int x);
void FizzBuzz(int x);


char* DecToHex(int x);
char* DecToOct(int x);

///////////////////////////////

void print();
float avr(int i, int x, int y, int z, int j);
float Average();
float add(float x,float y);
float sub(float x,float y);
float mul(float x,float y);
float div_fn(float x,float y);
int mod(int x,int y);
#endif // LAB_EX_H_INCLUDED
