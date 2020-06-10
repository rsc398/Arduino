#include <stdio.h>
#include <math.h>
int main(void)
{
  float radius;
  float area;
  float length;
 
  printf("ENHANKEINYURYOKU: r = ");
  scanf("%f", &radius);
  area = M_PI * radius * radius;
  printf("ENMENSEKI: S = %.3f\n", area);
  
  length =  2 * M_PI * radius;
  printf("ENNAGASA: L = %.3f\n", length);
 
  return 0;
}
