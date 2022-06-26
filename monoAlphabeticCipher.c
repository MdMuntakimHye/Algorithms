#include <stdio.h>

void caesar (char cipher[], int shift);

int main () {

  char cipher[50];
  int shift;

  printf("Plaintext (Caps only): ");
  scanf("%s", cipher);

  printf("Shift: ");
  scanf("%d", &shift);

  caesar (cipher, shift);

  return 0;
}

void caesar (char cipher[], int shift) {

  for(int i=0; cipher[i] != '\0'; i++)
    cipher[i] = 65 + (cipher[i]-65+shift)%26;
  printf("Cipher text: %s\n", cipher);
}
