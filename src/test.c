#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

int main() {
  //    char *str = "aaaaa 32a42X-";
  //    int a, b;
  //
  //    char format[] = "%d %d %d";
  //    char str[] = "13 +137 -8 354 5";
  //    char str2[] = "3240";
  //   int d1, d2;
  //    int q1, q2;
  //    int z1, z2;
  //   int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  //    int res2 = sscanf(str, format, &d2, &q2, &z2);
  //    printf("My scanf:\n Values: %hi %hi %hi Res: %d\n", d1, q1, z1, res1);
  //    printf("AntiMy scanf:\n Values: %hi %hi %hi Res: %d\n", d2, q2, z2,
  //    res2);

  // int x, y, z = 0;  // ints
  //   int x1, y1, z1 = 0;
  //   int res = s21_sscanf("+12243 -23 54", "%3d %1d %d", &x, &y, &z);
  //   int res1 = sscanf("+12243 -23 54", "%3d %1d %d", &x1, &y1, &z1);

  //   // int x, y, z;  // ints
  //   // int x1, y1, z1 = 0;

  //   // int res = s21_sscanf("+0775 1-0x1324--123", " %i %*i %i- %i", &x, &y,
  //   &z);
  //   // int res1 = sscanf("+0775 1-0x1324--123", " %i %*i %i- %i", &x1, &y1,
  //   &z1);

  //   printf("%d  %d  %d  %d\n",x ,y ,z, res);
  //   printf("%d  %d  %d  %d\n",x1 ,y1 ,z1, res1);

  // char format[] = "%3o %3o %3o";
  //   char str[] = "01236 +04 -3723";
  //   unsigned int d1 = 0, d2 = 0;
  //   unsigned int q1 = 0, q2 = 0;
  //   unsigned int z1 = 0, z2 = 0;

  //   int res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  //   int res2 = sscanf(str, format, &d2, &q2, &z2);

  //   printf("%d  %d  %d  %d\n",d1 ,q1 ,z1 , res1);
  //   printf("%d  %d  %d  %d\n",d2 ,q2 ,z2 , res2);

  char format[] = "%f %f %f %1f";
  char str[] = "34.5+6e3 83.2e-4 .43 +2.43e3";
  float d1, d2;
  float q1, q2;
  float z1, z2;
  float w1 = 0, w2 = 0;

  int res2 = sscanf(str, format, &d2, &q2, &z2, &w2);
  int res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);

  printf("%f %f %f %f %d\n", d1, q1, z1, w1, res1);
  printf("%f %f %f %f %d\n", d2, q2, z2, w2, res2);

  return 0;
}
