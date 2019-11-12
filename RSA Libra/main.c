#include "rsa.h"

int main(int argc, char const *argv[]) {

  long double n, e = 37, d, p, q, fi;
  char plainText[MAXBINARY];
  char plain_text[MAXBINARY];
  char *plainText1, *plainText0;
  char *cryptoText;
  printf("Enter n : ");
  scanf("%Lf%*c", &n);
  getInput(n, e, &p, &q, &fi, &d);

  printf("Plaintext : [");
  fgets(plainText, MAXBINARY, stdin);
  plainText[strlen(plainText) - 1] = '\0';

  strcat(plainText0, plainText);

  printf("%s]\n", plainText);
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

  printf("pl : %s - pl1 : %s\n", plainText0, plainText1);

  if(strcmp(plainText0, plainText1) == 0) {
    printf("[$]Successfly!!!\n");
  } else {
    printf("[#]Failed ...\n");
  }

  printf("\n------------View RSA KEY----------\n");
  printf("[+]Plaintext %s\n", plainText);
  printf("[+]n = p.q : p - %.1Lf & q - %.1Lf\n", p, q);
  printf("[+]Fi : %.1Lf\n", fi);
  printf("[+]Public Key (n, e) : %.1Lf - %.1Lf\n", n, e);
  printf("[+]Primary Key d  : %.1Lf\n", d);

  return 0;
}
