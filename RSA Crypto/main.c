#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXNUMBER 1000000000
#define MAXLEIGHT 100
#define MAXBINARY 100

double d, p, q, fi, pText = 0, cText = 0;
int check, check_point = 1;
int binaryNum[MAXBINARY];
char plainText[MAXBINARY];
char plain_text[MAXBINARY];
char *plainText1;
char *cryptoText;
char delim[] = " ";

int isPrimeNumber(double num);
void analysisToTwoPrime(double num, double *num1, double *num2);
void euclid(double n, double e, double *d);
double gcd(double a, double b);
int decToBinary(double n);
char* decToAlpha(double num);
double stringToDb(char *input);
void printTokList(char *tokList);
void getInput(char* text, double n, double e, double* p, double* q, double* fi, double* d);
char* crypPlainText(char *pt, double y, double n);
char* crypto(char *monoPt, double y, double n);

int main(int argc, char const *argv[]) {
  // Get input
  double n = 80460899;
  double e = 37;
  char* plainText = "hello"; 
  printf("-------------BEGIN-----------\n");
  getInput(plainText, n, e, &p, &q, &fi, &d);
  printf("Plaintext : [%s]\n", plainText);
  printf("-----------------------------\n");

  // Crypto
  printf("\n------------CRYPTO-----------\n");
  cryptoText = crypPlainText(plainText, e, n);
  printf("[*]Cryptotext : [%s]\n", cryptoText);
  printf("-----------------------------\n");

  // Decrypto
  printf("\n-----------DECRYPTO----------\n");
  plainText1 = crypPlainText(cryptoText, d, n);
  printf("[*]Decryptotext : [%s]\n", plainText1);
  printf("-----------------------------\n\n");

  // Check result
  if(strcmp(plain_text, plainText1) == 0) {
    printf("[$]Successfly!!!\n");
  } else {
    printf("[#]Failed ...\n");
  }

  // View parameter
  do {
    printf("\nShow parameter ? (y - 1 : n - 0) : ");
    scanf("%d%*c", &check);
  } while(check != 0 && check != 1);
  if (check == 1) {
    printf("------------View RSA KEY----------\n");
    printf("[+]Plaintext %s\n", plainText);
    printf("[+]n = p.q : p - %.2lf & q - %.2lf\n", p, q);
    printf("[+]Fi : %.2lf\n", fi);
    printf("[+]Public Key (n, e) : %.2lf - %.2lf\n", n, e);
    printf("[+]Primary Key d  : %.2lf\n", d);
  }

  return 0;
}

int isPrimeNumber(double num) {
  for(int i = 2; i <= sqrt(num); i++){
    if(fmod(num, i) == 0){
      return 0;
    }
  }

  return 1;
}

void analysisToTwoPrime(double num, double *num1, double *num2) {
  *num1 = 1;
  *num2 = num;

  for(int i = 2; i <= sqrt(num); i++) {
    if(isPrimeNumber(i)) {
      if(fmod(num, i) == 0) {
        if(isPrimeNumber(num / i)) {
          *num1 = i;
          *num2 = num / i;
          return;
        }
      }
    }
  }
}

// Get Primary Key
void euclid(double n, double e, double *d) {
  *d = 1;
  for(int i = 0; i < MAXNUMBER; i++) {
    if(fmod(i*e - 1, n) == 0) {
      *d = i;
      return;
    }
  }
}

double gcd(double a, double b) {
  if (b == 0) return a;
  return gcd(b, fmod(a, b));
}

void getInput(char* text, double n, double e, double* p, double* q, double* fi, double* d) {
  analysisToTwoPrime(n, p, q);
  if(*p != 1) {
    // Get fi(n)
    *fi = (*p - 1) * (*q -1);

    euclid(*fi, e, d);
    if(*d == 1) {
      printf("[!]Can't find d\n");
    }
    return;
  }
}

// x ^ y mod n
char* crypto(char *monoPt, double y, double n) {
  double x = stringToDb(monoPt);
  if(check_point) printf("%s to %.2lf\n", monoPt, x);

  if(x > n) {
    printf("%.2lf is too small !!!\n\n", n);
    exit(0);
  }

  // Decimal to binary
  int loops = decToBinary(y);
  double result = 1;
  for(int i = 0; i < loops; i++) {
    printf("Loops %d : %.2lf => ", i, result);
    result = fmod((result * result), n);
    printf("%lf ", result);
    if(binaryNum[i] == 1) {
      result = fmod((result * x), n);
      printf("=> %.2lf", result);
    }
    printf("\n");

  }
  if(result < 0) {
    result += n;
  }
  char* tmp = (char *)malloc(12 * sizeof(char));

  tmp = decToAlpha(result);
    if(check_point) printf("Cryp result : %s - %.2lf\n", tmp, result);

  return tmp;
}

int decToBinary(double num) {
  int tmpBinary[MAXBINARY];

  int n = 0, tmp;
  if(check_point) printf("Dec to Binary : %.2lf\n", num);

  while(num > 0) {
    tmp = (int)fmod(num, 2);
    tmpBinary[n] = fmod(num, 2);
    num = (num - tmp) / 2;
    n++;
  }
  tmpBinary[n] = '\0';

  int j = 0;
  for(int i = n - 1; i >= 0; i--) {
    binaryNum[j++] = tmpBinary[i];
  }

  binaryNum[n] = '\0';

  if(check_point) {
    for(int i = 0; i < n; i++) {
      printf("Index %d : %d\n", i, binaryNum[i]);
    }
  }
  return n;
}
char* decToAlpha(double num) {
  int tmpAlpha[MAXBINARY];

  if(num == 0) {
    return "a";
  }

  if(check_point) printf("Dec to Alpha : %.2lf\n", num);

  int n = 0, bina;
  while(num > 0) {
    bina = (int)fmod(num, 26);
    tmpAlpha[n] = bina;
    num = (num - bina) / 26;
    n++;
  }
  tmpAlpha[n] = '\0';

  char* tmp = (char *)malloc(12 * sizeof(char));

  int j = 0;
  for(int i = n - 1; i >= 0; i--) {
    *(tmp + j++) = tmpAlpha[i] + 96;
    printf("Alpha : %d %d %c\n", tmpAlpha[i], tmpAlpha[i] + 96, tmpAlpha[i] + 96);
  }
  *(tmp + n) = '\0';

  return tmp;
}

double stringToDb(char *input) {
  double result = 0;
  for(int i = 0; i < strlen(input); i++) {
    result += (tolower(input[i]) - 96) * pow(26, strlen(input) - i - 1);
    printf("i : %d - char : %c - %d\n", i, input[i], input[i] - 96);
  }
  if(check_point) printf("Result : %.2lf\n", result);

  return result;
}

char* crypPlainText(char *pt, double y, double n) {
  char *tmp, *tmpPtList;
  char* result = (char *)malloc(MAXLEIGHT * sizeof(char));

  // slipt(pt, tmpPtList);
  tmpPtList = strtok(pt, delim);
  while (tmpPtList != NULL) {
    tmp = crypto(tmpPtList, y, n);
    strcat(result, tmp);
		tmpPtList = strtok(NULL, delim);
    if(tmpPtList != NULL) {
      strcat(result, " ");
    }
	}

  return result;
}
