// Faça um programa em C que leia uma temperatura em graus Celsius e calcule o valor correspondente em graus Fahrenheit (°F = 9/5°C + 32).
#include <stdio.h>
int main() {

  float celsius;
  float fahrenheit;

  printf("insira a temperatura em graus celsius: ");
  float ok = scanf("%f", &celsius);
  fahrenheit = (celsius * 9/5 + 32);
  
  printf("a temperatura em fahrenheit é: %f\n", fahrenheit);
  


    return 0;
}