#include "rsa.h"

int main(int argc, char const *argv[]) {

  double n = 101485451, e = 37, d, p, q, fi;
  char plainText[MAXBINARY];
  char plain_text[MAXBINARY];
  char *plainText1;
  char *cryptoText;
  getInput(n, e, &p, &q, &fi, &d);

  printf("Plaintext : [");
  fgets(plainText, MAXBINARY, stdin);
  plainText[strlen(plainText) - 1] = '\0';

  printf("%s]\n", plainText);
  printf("-----------------------------\n");

  // Crypto
  printf("\n------------CRYPTO-----------\n");
  cryptoText = crypPlainText(plainText, fi, n);
  printf("[*]Cryptotext : [%s]\n", cryptoText);
  printf("-----------------------------\n");

  // // Decrypto
  // printf("\n-----------DECRYPTO----------\n");
  // plainText1 = crypPlainText(cryptoText, d, n);
  // printf("[*]Decryptotext : [%s]\n", plainText1);
  // printf("-----------------------------\n\n");
  //
  // // Check result
  //
  // printf("pl : %s - pl1 : %s\n", plainText, plainText1);
  //
  // if(strcmp(plainText, plainText1) == 0) {
  //   printf("[$]Successfly!!!\n");
  // } else {
  //   printf("[#]Failed ...\n");
  // }

  printf("\n------------View RSA KEY----------\n");
  printf("[+]Plaintext %s\n", plainText);
  printf("[+]n = p.q : p - %.1lf & q - %.1lf\n", p, q);
  printf("[+]Fi : %.1lf\n", fi);
  printf("[+]Public Key (n, e) : %.1lf - %.1lf\n", n, e);
  printf("[+]Primary Key d  : %.1lf\n", d);

  return 0;
}
