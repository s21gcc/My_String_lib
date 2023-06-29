#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(memchr_1) {
  int f1 = 5;
  const int *str = &f1;
  int c = ' ';
  s21_size_t n = 3;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  int f1 = 5;
  const int *str = &f1;
  int c = ' ';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  const char *str = "Bla bla blu";
  int c = 'u';
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  const char *str = "123456";
  int c = '1';
  s21_size_t n = 1;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  const char *str = "Hola Mundo!";
  int c = 'o';
  s21_size_t n = 11;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  const char *str = "Hola Mundo";
  int c = 'a';
  s21_size_t n = -10;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memchr_7) {
  const char *str = "Hola\n Mundo";
  int c = '\n';
  s21_size_t n = 7;
  ck_assert_str_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

START_TEST(memcmp_1) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  const char *str1 = "Hola!";
  const char *str2 = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  const char *str1 = "Hola";
  const char *str2 = "Hola";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  const char *str1 = "Hola!";
  const char *str2 = "Hola!";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcpy_1) {
  char dest[] = "Hola";
  const char src[] = "aloH";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_2) {
  char *dest = "";
  const char *src = "_Good_";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_3) {
  char dest[] = "\n\n\n";
  const char src[] = "_Good_1234..//,,";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_4) {
  char dest[] = "Hello\0world";
  const char src[] = "Kelly\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(dest, src, n), memcpy(dest, src, n));
}
END_TEST

START_TEST(memmove_1) {
  char *dest = "Hello";
  const char *src = "world";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_2) {
  char dest[] = "Hello";
  const char src[] = "world";
  s21_size_t n = 2;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_3) {
  char dest[] = "Hello";
  const char src[] = "world";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_4) {
  char dest[] = "Hello";
  const char src[] = "world";
  s21_size_t n = 6;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}
END_TEST

START_TEST(memmove_5) {
  char dest[] = "Hello_1235";
  const char src[] = "----\\\\\\\\---/////////-------";
  s21_size_t n = 11;
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(dest, src, n));
}
END_TEST

START_TEST(memset_1) {
  char str[] = "Hello_1235";
  int c = ' ';
  s21_size_t n = 11;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str[] = "";
  int c = '1';
  s21_size_t n = 1;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str[] = "";
  int c = '2';
  s21_size_t n = 0;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str[] = "Hello.111_ boy!";
  int c = '-';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str[] = "Hello.111_ boy!";
  int c = '-';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(memset_6) {
  int f = 5;
  int *str = &f;
  int c = '-';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str, c, n), memset(str, c, n));
}
END_TEST

START_TEST(strcat_1) {  // конкатенация, объединение строк (добавляет строку, на
                        // которую указывает src, в конец строки, на которую
                        // указывает dest)
  char dest_1[100] = "Punta_";
  char dest_2[100] = "Punta_";
  const char *src = "Cana";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_2) {
  char dest_1[100] = "";
  char dest_2[100] = "";
  const char *src = "dominicana";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_3) {
  char dest_1[100] = "Hola";
  char dest_2[100] = "Hola";
  const char *src = "";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_4) {
  char dest_1[100] = " Hablo_un_poco";
  char dest_2[100] = " Hablo_un_poco";
  const char *src = " DeEspanol\n\0";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_5) {
  char dest_1[100] = " \0";
  char dest_2[100] = " \0";
  const char *src = "AbCdEfG__82382t2t2tk84jga g egr 33twg ";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_6) {
  char dest_1[100] = "Hola ";
  char dest_2[100] = "Hola ";
  const char *src = "AbCdEfG__82382t2t//../....,m, 2tk84jga g egr 33twg ";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_7) {
  char dest_1[100] = " Hola";
  char dest_2[100] = " Hola";
  const char *src = "AbCdEfG__82382\nt2t/\t/../\0....,m, 2tk84jga g egr 33twg ";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_8) {
  char dest_1[100] = "Hola\n\t\0 ";
  char dest_2[100] = "Hola\n\t\0 ";
  const char *src = "AbCdEfG__82382\nt2t/\t/../\0....,m, 2tk84jga g egr 33twg ";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strcat_9) {
  char dest_1[100] = " Hola ";
  char dest_2[100] = " Hola ";
  const char src[] = "1";
  s21_strcat(dest_1, src);
  strcat(dest_2, src);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_1) {  // добавляет n символов к строке (добавляет строку, на
                         // которую указывает src, в конец строки, на которую
                         // указывает dest, длиной до n символов)
  char dest_1[] = "";
  char dest_2[] = "";
  const char src[] = "";
  s21_size_t n = 0;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_2) {
  char dest_1[5] = "Hola";
  char dest_2[5] = "Hola";
  const char src[] = "";
  s21_size_t n = 2;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_3) {
  char dest_1[20] = "Hola";
  char dest_2[20] = "Hola";
  const char src[] = "Como estas?";
  s21_size_t n = 9;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_4) {
  char dest_1[10] = "";
  char dest_2[10] = "";
  const char src[] = "Hola";
  s21_size_t n = 3;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_5) {
  char dest_1[10] = "Hola\n";
  char dest_2[10] = "Hola\n";
  const char src[] = "\0!";
  s21_size_t n = 3;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_6) {
  char dest_1[10] = "Hola";
  char dest_2[10] = "Hola";
  const char src[] = "\n!";
  s21_size_t n = 5;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strncat_7) {
  char dest_1[10] = "Hola";
  char dest_2[10] = "Hola";
  const char src[5] = "GM!";
  s21_size_t n = -3;
  s21_strncat(dest_1, src, n);
  strncat(dest_2, src, n);
  ck_assert_str_eq(dest_1, dest_2);
}
END_TEST

START_TEST(strchr_1) {  // выполняет поиск первого вхождения символа c
                        // (беззнаковый тип) в строке, на которую указывает
                        // аргумент str или возвращает NULL , если c не найден
  const char *str = "";
  int c = 'a';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  const char *str = "r";
  int c = 'r';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  const char *str = "Reina";
  int c = 'n';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  const char *str = "Reina";
  int c = '\0';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  const char *str = "Como estas?";
  int c = ' ';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  const char *str = "Como\0 estas?";
  int c = ' ';
  ck_assert_pstr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  const char *str = "Hdjj028 fkrlf,8188..//10..,";
  int c = '/';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strchr_8) {
  const char str[] = {'p', 'r', 'i', 'v', 'e', 't', '\0'};
  int c = 't';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(strcmp_1) {  // cравнивает строку, на которую указывает str1, со
                        // строкой, на которую указывает str2
  const char str1[] = "Hola! Como estas?";
  const char str2[] = "Hola! Como estas?";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_2) {
  const char str1[] = "\nok";
  const char str2[] = "\nokj";
  int a, b;
  a = s21_strcmp(str1, str2);
  if (a < 0)
    a = -1;
  else if (a > 0)
    a = 1;
  b = strcmp(str1, str2);
  if (b < 0)
    b = -1;
  else if (b > 0)
    b = 1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strcmp_3) {
  const char str1[] = " \0";
  const char str2[] = " \0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_4) {
  const char str1[] = "\0";
  const char str2[] = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_5) {
  const char *str1 = "Buenas Tardes!\n";
  const char str2[] = "Buenas Tardes!\n";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_6) {
  const char *str1 = "";
  const char str2[] = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp_7) {
  const char str1[] = "\0";
  const char str2[] = "4\0";
  int a, b;
  a = s21_strcmp(str1, str2);
  if (a < 0)
    a = -1;
  else if (a > 0)
    a = 1;
  b = strcmp(str1, str2);
  if (b < 0)
    b = -1;
  else if (b > 0)
    b = 1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strcmp_8) {
  const char str1[] = "\n\0";
  const char str2[] = "\0\n";
  int a, b;
  a = s21_strcmp(str1, str2);
  if (a < 0)
    a = -1;
  else if (a > 0)
    a = 1;
  b = strcmp(str1, str2);
  if (b < 0)
    b = -1;
  else if (b > 0)
    b = 1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strcmp_9) {
  const char *str1 = "a\n\0";
  const char str2[] = "a\n\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strncmp_1) {  // сравнивает не более первых n байтов двух строк -
                         // str1 и str2
  const char str1[] = "Todo_esta_bien";
  const char str2[] = "Todo_esta_bien";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  const char str1[] = "Todo_esta_bien";
  const char str2[] = "Todo_esta_bien";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  const char str1[] = "muy_bien";
  const char str2[] = "i\0muy_bien";
  s21_size_t n = 3;
  int a, b;
  a = s21_strncmp(str1, str2, n);
  if (a < 0)
    a = -1;
  else if (a > 0)
    a = 1;
  b = strncmp(str1, str2, n);
  if (b < 0)
    b = -1;
  else if (b > 0)
    b = 1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strncmp_4) {
  const char str1[] = "blablabla";
  const char str2[] = "blablablab";
  s21_size_t n = -3;
  int a, b;
  a = s21_strncmp(str1, str2, n);
  if (a < 0)
    a = -1;
  else if (a > 0)
    a = 1;
  b = strncmp(str1, str2, n);
  if (b < 0)
    b = -1;
  else if (b > 0)
    b = 1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strcpy_1) {  // копирует нуль-терминированную строку (включая
                        // нулеввой символ) в dest
  char dest_1[] = "Quiero volar a un pais calido";
  char dest_2[] = "Quiero volar a un pais calido";
  const char *src = "\0";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_2) {
  char dest_1[] = "";
  char dest_2[] = "";
  const char src[] = "";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_3) {
  char dest_1[] = " 123456789";
  char dest_2[] = " 123456789";
  const char src[] = " 10 ";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_4) {
  char dest_1[] = "81 ";
  char dest_2[] = "81 ";
  const char src[] = "88";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_5) {
  char dest_1[] = "87598775 \n\0";
  char dest_2[] = "87598775 \n\0";
  const char src[] = "000000\000";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_6) {
  char dest_1[] = "23r4trrhj,...+/-\n";
  char dest_2[] = "23r4trrhj,...+/-\n";
  const char src[] = " Ki ";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strcpy_7) {
  char dest_1[] = "123456\0";
  char dest_2[] = "123456\0";
  const char src[] = "789";
  ck_assert_str_eq(s21_strcpy(dest_1, src), strcpy(dest_2, src));
}
END_TEST

START_TEST(strncpy_1) {  // копирование строки c ограничением длины
  char dest_1[] = " Madrid_es_la_capital_de_Espana ";
  char dest_2[] = " Madrid_es_la_capital_de_Espana ";
  const char src[] = "Moscu_es_la_capital_de_Rusia";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char dest_1[] = "Buenos\0Aire";
  char dest_2[] = "Buenos\0Aire";
  const char src[] = "s\n";
  s21_size_t n = 4;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  char dest_1[] = "gv,maw,gbn ...../../.. 3....fg;l bkdvaalmsv";
  char dest_2[] = "gv,maw,gbn ...../../.. 3....fg;l bkdvaalmsv";
  const char src[] = "=/\\/\\/\\/\\/\\=";
  s21_size_t n = 6;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  char dest_1[] = "Hola\0";
  char dest_2[] = "Hola\0";
  const char src[] = " kk\n";
  s21_size_t n = 4;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  char dest_1[] = "L.N. Tolstoy was born in 1828)";
  char dest_2[] = "L.N. Tolstoy was born in 1828)";
  const char src[] = "e = 2,718281828";
  s21_size_t n = 11;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strcspn_1) {  // поиск первого вхождения в строку str1 любого из
                         // символов строки str2, и возвращает количество
                         // символов до найденного первого вхождения
  const char str1[] = "";
  const char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  const char str1[] = "Hola";
  const char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  const char str1[] = "Hola";
  const char str2[] = "l";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  const char str1[] = "";
  const char str2[] = "amor";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  const char str1[] = "G0ogle";
  const char str2[] = "0oo";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  const char str1[] = "0123";
  const char str2[] = "123";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  const char str1[] = "01erg78f on w4 pmv../j./...,,,.l";
  const char str2[] = " .";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  const char str1[] = "\n";
  const char str2[] = "01erg78fonw4pmv../j./...,,,.l";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  const char str1[] = "MY: name is 'S', 'T', 'R', 'C', 'S', 'P', 'N' - 1";
  const char str2[] = "01erg78fonw4pmv../j./...,,,.l";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  const char str1[] = "Quiero volar a un pais calido";
  const char str2[] = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(
    strerror_1) {  // выполняет поиск во внутреннем массиве номера ошибки errnum
                   // и возвращает указатель на строку с сообщением об ошибке
  int errnum = 7;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(strerror_2) {
  int errnum = 1;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(strerror_3) { ck_assert_pstr_eq((s21_strerror(44)), strerror(44)); }
END_TEST

START_TEST(strerror_4) { ck_assert_str_eq((s21_strerror(100)), strerror(100)); }
END_TEST

START_TEST(strerror_5) {
  int errnum = 0;
  ck_assert_pstr_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(strlen_1) {  // вычисляет длину строки str, не включая завершающий
                        // нулевой символ
  const char str[] = {""};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  const char str[] = {"abcdefg"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  const char str[] = {"0123456789"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  const char str[] = {"0123456789ABCDEFGabcdefg\0"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  const char str[] = {"ABCDEFGab\0cdefg"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_6) {
  const char str[] = {"ABCDEFG_ab(54321)..//,\n"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_7) {
  const char str[] = {"First_line\nSecond_line"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_8) {
  const char str[] = {"\n"};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_9) {
  const char str[] = {" "};
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strlen_10) {
  char str[] = {"x"};
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] == '\0') str[i] = '\n';
  }
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(strpbrk_1) {  // выполняет поиск первого вхождения в строку str1
                         // любого из символов строки str2, и возвращает
                         // указатель на найденный символ
  const char str1[] = {'q', 'r', 's', 't', 'w', '\0'};
  const char str2[] = {'q', 'r', 's', 't', 'w', '\0'};
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  const char str1[] = "Bla bla bla";
  const char str2[] = "l";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  const char str1[] = " Bla bla bla";
  const char str2[] = " ";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  const char str1[] = "Bla bla bla";
  const char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  const char str1[] = "Bla bla bla";
  const char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  const char str1[] = "Bla bla bla";
  const char str2[] = "\n";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(
    strrchr_1) {  // выполняет поиск последнего вхождения символа c (беззнаковый
                  // тип) в строке, на которую указывает аргумент str
  const char str[] = "jhgfd/.,mn.b5;5";
  int c = '\0';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  const char str[] = "j8888888888j";
  int c = 'j';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  const char str[] = "";
  int c = 'j';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  const char str[] = "123456781556155615";
  int c = '1';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strspn_1) {  // поиск символов строки str2 в строке str1. Возвращает
                        // длину начального участка строки str1, который состоит
                        // только из символов строки str2
  const char str1[] = "123456789l";
  const char str2[] = "234567";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_2) {  //
  const char str1[] = "";
  const char str2[] = "rkdieyjwwe";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_3) {
  const char str1[] = "bla bla bla bla bla";
  const char str2[] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn_4) {
  const char str1[] = ".....\t....,,,,§/ds\\//";
  const char str2[] = "45oi.";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(
    strstr_1) {  // функция ищет первое вхождение подстроки str2 в строке str1
  const char haystack[] = "opjbqajknp'qbjk";
  const char needle[] = "8op";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  const char haystack[] = "[piojhicyfg'0iuj[pl]";
  const char needle[] = "\0";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  const char haystack[] = "yfkud7d7tdyug8yg";
  const char needle[] = "yg";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  const char haystack[] = "wtf";
  const char needle[] = "qtjnamywrnswynwrysfqthas";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  const char *haystack = "zb./../.../ghrrwsnbnbb";
  const char *needle = "/";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strtok_1) {  // разбивает строку str на ряд токенов/лексем,
                        // разделенных delim
  char str[] = "Como estas";
  const char delim[] = "estas";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str[] = "Comoestas";
  const char delim[] = "estas";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str[] = "Como estas";
  const char delim[] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str[] = "Como estas";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_5) {
  char str[] = "Como estas";
  const char delim[] = "\0";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_6) {
  char str[] = "";
  const char delim[] = "Como_estas 95645";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_7) {
  char str[] = "1";
  const char delim[] = "1";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

int main(void) {
  int number_failed = 0;  //для хранения количества неудачных тестов
  Suite *s;  //указатель на suite
  s = suite_create(
      "string");  //вызываем функцию, чтобы создать и вернуть test suite
  SRunner *sr;    //указатель на srunner
  sr = srunner_create(
      s);  //используем test suite и передаем их функции srunner_create, чтобы
           //получить указатель на test suite runner
  TCase *tc_memchr = tcase_create("memchr");
  suite_add_tcase(s, tc_memchr);
  tcase_add_test(tc_memchr, memchr_1);
  tcase_add_test(tc_memchr, memchr_2);
  tcase_add_test(tc_memchr, memchr_3);
  tcase_add_test(tc_memchr, memchr_4);
  tcase_add_test(tc_memchr, memchr_5);
  tcase_add_test(tc_memchr, memchr_6);
  tcase_add_test(tc_memchr, memchr_7);

  TCase *tc_memcmp = tcase_create("memcmp");
  suite_add_tcase(s, tc_memcmp);
  tcase_add_test(tc_memcmp, memcmp_1);
  tcase_add_test(tc_memcmp, memcmp_2);
  tcase_add_test(tc_memcmp, memcmp_3);
  tcase_add_test(tc_memcmp, memcmp_4);

  TCase *tc_memcpy = tcase_create("memcpy");
  suite_add_tcase(s, tc_memcpy);
  tcase_add_test(tc_memcpy, memcpy_1);
  tcase_add_test(tc_memcpy, memcpy_2);
  tcase_add_test(tc_memcpy, memcpy_3);
  tcase_add_test(tc_memcpy, memcpy_4);

  TCase *tc_memmove = tcase_create("memmove");
  suite_add_tcase(s, tc_memmove);
  tcase_add_test(tc_memmove, memmove_1);
  tcase_add_test(tc_memmove, memmove_2);
  tcase_add_test(tc_memmove, memmove_3);
  tcase_add_test(tc_memmove, memmove_4);
  tcase_add_test(tc_memmove, memmove_5);

  TCase *tc_memset = tcase_create("memset");
  suite_add_tcase(s, tc_memset);
  tcase_add_test(tc_memset, memset_1);
  tcase_add_test(tc_memset, memset_2);
  tcase_add_test(tc_memset, memset_3);
  tcase_add_test(tc_memset, memset_4);
  tcase_add_test(tc_memset, memset_5);
  tcase_add_test(tc_memset, memset_6);

  TCase *tc_strcat = tcase_create("strcat");
  suite_add_tcase(s, tc_strcat);
  tcase_add_test(tc_strcat, strcat_1);
  tcase_add_test(tc_strcat, strcat_2);
  tcase_add_test(tc_strcat, strcat_3);
  tcase_add_test(tc_strcat, strcat_4);
  tcase_add_test(tc_strcat, strcat_5);
  tcase_add_test(tc_strcat, strcat_6);
  tcase_add_test(tc_strcat, strcat_7);
  tcase_add_test(tc_strcat, strcat_8);
  tcase_add_test(tc_strcat, strcat_9);

  TCase *tc_strncat = tcase_create("strncat");
  suite_add_tcase(s, tc_strncat);
  tcase_add_test(tc_strncat, strncat_1);
  tcase_add_test(tc_strncat, strncat_2);
  tcase_add_test(tc_strncat, strncat_3);
  tcase_add_test(tc_strncat, strncat_4);
  tcase_add_test(tc_strncat, strncat_5);
  tcase_add_test(tc_strncat, strncat_6);
  tcase_add_test(tc_strncat, strncat_7);

  TCase *tc_strchr = tcase_create("strchr");
  suite_add_tcase(s, tc_strchr);
  tcase_add_test(tc_strchr, strchr_1);
  tcase_add_test(tc_strchr, strchr_2);
  tcase_add_test(tc_strchr, strchr_3);
  tcase_add_test(tc_strchr, strchr_4);
  tcase_add_test(tc_strchr, strchr_5);
  tcase_add_test(tc_strchr, strchr_6);
  tcase_add_test(tc_strchr, strchr_7);
  tcase_add_test(tc_strchr, strchr_8);

  TCase *tc_strcmp = tcase_create("strcmp");
  suite_add_tcase(s, tc_strcmp);
  tcase_add_test(tc_strcmp, strcmp_1);
  tcase_add_test(tc_strcmp, strcmp_2);
  tcase_add_test(tc_strcmp, strcmp_3);
  tcase_add_test(tc_strcmp, strcmp_4);
  tcase_add_test(tc_strcmp, strcmp_5);
  tcase_add_test(tc_strcmp, strcmp_6);
  tcase_add_test(tc_strcmp, strcmp_7);
  tcase_add_test(tc_strcmp, strcmp_8);
  tcase_add_test(tc_strcmp, strcmp_9);

  TCase *tc_strncmp = tcase_create("strncmp");
  suite_add_tcase(s, tc_strncmp);
  tcase_add_test(tc_strncmp, strncmp_1);
  tcase_add_test(tc_strncmp, strncmp_2);
  tcase_add_test(tc_strncmp, strncmp_3);
  tcase_add_test(tc_strncmp, strncmp_4);

  TCase *tc_strcpy = tcase_create("strcpy");
  suite_add_tcase(s, tc_strcpy);
  tcase_add_test(tc_strcpy, strcpy_1);
  tcase_add_test(tc_strcpy, strcpy_2);
  tcase_add_test(tc_strcpy, strcpy_3);
  tcase_add_test(tc_strcpy, strcpy_4);
  tcase_add_test(tc_strcpy, strcpy_5);
  tcase_add_test(tc_strcpy, strcpy_6);
  tcase_add_test(tc_strcpy, strcpy_7);

  TCase *tc_strncpy = tcase_create("strncpy");
  suite_add_tcase(s, tc_strncpy);
  tcase_add_test(tc_strncpy, strncpy_1);
  tcase_add_test(tc_strncpy, strncpy_2);
  tcase_add_test(tc_strncpy, strncpy_3);
  tcase_add_test(tc_strncpy, strncpy_4);
  tcase_add_test(tc_strncpy, strncpy_5);

  TCase *tc_strcspn = tcase_create("strcspn");
  suite_add_tcase(s, tc_strcspn);
  tcase_add_test(tc_strcspn, strcspn_1);
  tcase_add_test(tc_strcspn, strcspn_2);
  tcase_add_test(tc_strcspn, strcspn_3);
  tcase_add_test(tc_strcspn, strcspn_4);
  tcase_add_test(tc_strcspn, strcspn_5);
  tcase_add_test(tc_strcspn, strcspn_6);
  tcase_add_test(tc_strcspn, strcspn_7);
  tcase_add_test(tc_strcspn, strcspn_8);
  tcase_add_test(tc_strcspn, strcspn_9);
  tcase_add_test(tc_strcspn, strcspn_10);

  TCase *tc_strerror = tcase_create("strerror");
  suite_add_tcase(s, tc_strerror);
  tcase_add_test(tc_strerror, strerror_1);
  tcase_add_test(tc_strerror, strerror_2);
  tcase_add_test(tc_strerror, strerror_3);
  tcase_add_test(tc_strerror, strerror_4);
  tcase_add_test(tc_strerror, strerror_5);

  TCase *tc_strlen = tcase_create("strlen");
  suite_add_tcase(s, tc_strlen);
  tcase_add_test(tc_strlen, strlen_1);
  tcase_add_test(tc_strlen, strlen_2);
  tcase_add_test(tc_strlen, strlen_3);
  tcase_add_test(tc_strlen, strlen_4);
  tcase_add_test(tc_strlen, strlen_5);
  tcase_add_test(tc_strlen, strlen_6);
  tcase_add_test(tc_strlen, strlen_7);
  tcase_add_test(tc_strlen, strlen_8);
  tcase_add_test(tc_strlen, strlen_9);
  tcase_add_test(tc_strlen, strlen_10);

  TCase *tc_strpbrk = tcase_create("strpbrk");
  suite_add_tcase(s, tc_strpbrk);
  tcase_add_test(tc_strpbrk, strpbrk_1);
  tcase_add_test(tc_strpbrk, strpbrk_2);
  tcase_add_test(tc_strpbrk, strpbrk_3);
  tcase_add_test(tc_strpbrk, strpbrk_4);
  tcase_add_test(tc_strpbrk, strpbrk_5);
  tcase_add_test(tc_strpbrk, strpbrk_6);

  TCase *tc_strrchr = tcase_create("strrchr");
  suite_add_tcase(s, tc_strrchr);
  tcase_add_test(tc_strrchr, strrchr_1);
  tcase_add_test(tc_strrchr, strrchr_2);
  tcase_add_test(tc_strrchr, strrchr_3);
  tcase_add_test(tc_strrchr, strrchr_4);

  TCase *tc_strspn = tcase_create("strspn");
  suite_add_tcase(s, tc_strspn);
  tcase_add_test(tc_strspn, strspn_1);
  tcase_add_test(tc_strspn, strspn_2);
  tcase_add_test(tc_strspn, strspn_3);
  tcase_add_test(tc_strspn, strspn_4);

  TCase *tc_strstr = tcase_create("strstr");
  suite_add_tcase(s, tc_strstr);
  tcase_add_test(tc_strstr, strstr_1);
  tcase_add_test(tc_strstr, strstr_2);
  tcase_add_test(tc_strstr, strstr_3);
  tcase_add_test(tc_strstr, strstr_4);
  tcase_add_test(tc_strstr, strstr_5);

  TCase *tc_strtok = tcase_create("strtok");
  suite_add_tcase(s, tc_strtok);
  tcase_add_test(tc_strtok, strtok_1);
  tcase_add_test(tc_strtok, strtok_2);
  tcase_add_test(tc_strtok, strtok_3);
  tcase_add_test(tc_strtok, strtok_4);
  tcase_add_test(tc_strtok, strtok_5);
  tcase_add_test(tc_strtok, strtok_6);
  tcase_add_test(tc_strtok, strtok_7);

  srunner_run_all(sr, CK_NORMAL);  //распечатывает все неудачные тесты
  number_failed =
      srunner_ntests_failed(sr);  //вызываем srunner_ntests_failed чтобы
                                  //получить количество неудачных тестов
  srunner_free(sr);
  return (number_failed == 0)
             ? EXIT_SUCCESS
             : EXIT_FAILURE;  //успешно возвращаемся, если количество неудачных
                              //тестов равно 0, иначе мы не проходим тест
}
