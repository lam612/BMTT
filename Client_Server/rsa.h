#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXNUMBER 1000000000000
#define MAXLEIGHT 10
#define MAXBINARY 100

#define NISTOOSMALLERRORMES "N is too small !!!\n\n"

int check;
int binaryNum[MAXBINARY];

int isPrimeNumber(long double num);
void analysisToTwoPrime(long double num, long double *num1, long double *num2);
void euclid(long double n, long double e, long double *d);
long double gcd(long double a, long double b);
int decToBinary(long double n);
char* decToAlpha(long double num);
long double stringToDb(char *input);
void printTokList(char *tokList);
void getInput(long double n, long double e, long double* p, long double* q, long double* fi, long double* d);
char* crypPlainText(char *pt, long double y, long double n);
char* crypto(char *monoPt, long double y, long double n);
