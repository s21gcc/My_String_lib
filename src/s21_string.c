#include "s21_string.h"

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
//байтах строки, на которую указывает аргумент str, игнорируя символы конца
//строки
void *s21_memchr(const void *str, int c, size_t n) {
  void *res = s21_NULL;
  char *temp =
      (char *)str;  // создаем локальную переменную для обхода типа const
  int break_for = 1;
  for (s21_size_t i = 0; i < n && break_for; i++) {
    if (*(char *)(temp + i) == c) {  // используем явное приведение указателя
      res = temp + i;
      break_for = 0;
    }
  }
  return res;
}

//Сравнивает первые n байтов str1 и str2, игнорируя символы конца строки
int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int res = 0, break_for = 1;
  char *temp1 = (char *)str1, *temp2 = (char *)str2;
  for (s21_size_t i = 0; i < n && break_for; i++) {
    if (*(temp1 + i) != *(temp2 + i)) {
      break_for = 0;
      res += *(temp1 + i) - *(temp2 + i);
    }
  }
  return res;
}

//НЕ ОБРАБОТАН СЛУЧАЙ, ЕСЛИ В ДЕСТ НЕДОСТАТОЧНО ЭЛЕМЕНТОВ ДЛЯ ЗАПИСИ N (illegal
// hardware instruction) Копирует n символов из src в dest, игнорируя символы
//конца строки
void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *temp = (char *)src;
  if ((char *)dest != temp &&
      n) {  // Если указатели указывают на разные переменные и копировать нужно
            // не 0 символов
    for (s21_size_t i = 0; i < n; i++) {
      *(char *)(dest + i) = *(temp + i);
    }
  }
  return dest;
}

//Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, size_t n) {
  char *temp = (char *)src;
  if (n && (char *)dest < temp) {  // Если указатели указывают на разные
                                   // переменные, пересечения не произойдет и
                                   // копировать нужно не 0 символов
    dest = s21_memcpy(dest, src, n);
  } else if ((char *)dest > temp) {  // Если пересечение возможно
    for (s21_size_t i = n; i > 0; i--)  // копируем с n до 0, т,к, при прямом
                                        // копировании будет искажение данных
      *(char *)(dest + i - 1) = *(temp + i - 1);
  }
  return dest;
}

//НЕ ОБРАБОТАН СЛУЧАЙ, ЕСЛИ В STR НЕДОСТАТОЧНО ЭЛЕМЕНТОВ ДЛЯ ЗАПИСИ N (illegal
// hardware instruction) Копирует символ c (беззнаковый тип) в первые n символов
//строки, на которую указывает аргумент str.
void *s21_memset(void *str, int c, size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(char *)(str + i) = c;
  }
  return str;
}

//Добавляет строку, на которую указывает src, в конец строки, на которую
//указывает dest.
char *s21_strcat(char *dest, const char *src) {
  char *temp = (char *)src;
  s21_size_t i = 0, j = 0;
  while (*(dest + i) != '\0') i++;
  while (*(temp + j) != '\0') {
    *(dest + i++) = *(temp + j++);
  }
  *(dest + i) = '\0';
  return dest;
}

//Добавляет строку, на которую указывает src, в конец строки, на которую
//указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, size_t n) {
  char *temp = (char *)src;
  s21_size_t i = 0, j = 0;
  while (*(dest + i) != '\0') i++;
  while (*(temp + j) != '\0' && j < n) {
    *(dest + i++) = *(temp + j++);
  }
  *(dest + i) = '\0';
  return dest;
}

//Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
//которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
  char *temp = (char *)str;
  void *res = ((char)c == '\0') ? "\0" : s21_NULL;
  s21_size_t i = 0;
  while (*(temp + i) != '\0' && *(temp + i) != c)
    i++;  // пока не достигли конца строки или не нашли совпадение
  if (*(temp + i) != '\0') res = temp + i;
  return res;
}

//Сравнивает строку, на которую указывает str1, со строкой, на которую указывает
// str2.
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0, break_for = 1;
  char *temp1 = (char *)str1, *temp2 = (char *)str2;
  for (s21_size_t i = 0; break_for; i++) {
    if (*(temp2 + i) == '\0' || *(temp1 + i) == '\0' ||
        *(temp1 + i) != *(temp2 + i)) {
      break_for = 0;
      res += *(temp1 + i) - *(temp2 + i);
    }
  }
  return res;
}

//Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, size_t n) {
  int res = 0, break_for = 1;
  char *temp1 = (char *)str1, *temp2 = (char *)str2;
  for (s21_size_t i = 0; i < n && break_for; i++) {
    if (*(temp2 + i) == '\0' || *(temp1 + i) == '\0' ||
        *(temp1 + i) != *(temp2 + i)) {
      break_for = 0;
      res += *(temp1 + i) - *(temp2 + i);
    }
  }
  return res;
}

//Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
  char *temp = (char *)src;
  int break_for = 1;
  if (dest != temp) {  // Если указатели указывают на разные переменные
    for (s21_size_t i = 0; break_for; i++) {
      *(dest + i) = *(temp + i);
      if (*(dest + i) == '\0') break_for = 0;
    }
  }
  return dest;
}

//Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *temp = (char *)src;
  int break_for = 1;
  if (dest != temp && n) {  // Если указатели указывают на разные переменные и
                            // нужно копировать не 0 символов
    for (s21_size_t i = 0; i < n && break_for; i++) {
      *(dest + i) = *(temp + i);
      if (*(dest + i) == '\0') break_for = 0;
    }
  }
  return dest;
}

//Вычисляет длину начального сегмента str1, который полностью состоит из
//символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  char *str = (char *)str1, *pattern = (char *)str2;
  s21_size_t i = 0;
  int break_for = 1;
  for (; *(str + i) != '\0' && break_for; i++) {  // идем по символам строки 1
    for (s21_size_t j = 0; *(pattern + j) != '\0' && break_for; j++) {
      if (*(str + i) == *(pattern + j)) {  // сравниваем каждый символ строки 1
                                           // со вм=семи символами стр 2
        break_for = 0;
        i--;  // так как на текущей позиции находимся на элементе, который есть
              // в строке 2
      }
    }
  }
  return i;
}

//Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
//указатель на строку с сообщением об ошибке. Нужно объявить макросы, содержащие
//массивы сообщений об ошибке для операционных систем mac и linux. Описания
//ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с
//помощью директив.
char *s21_strerror(int errnum) {
  char *res = s21_NULL;
  if (errnum >= 0 && errnum <= MAXERROR) {
    res = (char *)(*(ERRORS + errnum));
  } else {
    static char err[40] = "Unknown error: ";
    int temp = errnum, pow_num = 0;
    s21_size_t i = 0;
    while (*(err + i) != '\0') i++;
    if (errnum < 0) *(err + i++) = '-';
    while (temp > 10) {
      temp /= 10;
      pow_num++;
    }
    while (pow_num) {
      *(err + i) = (char)(errnum / (int)pow(10, pow_num) + 48);
      errnum %= (int)pow(10, pow_num);
      pow_num--;
      i++;
    }
    *(err + i++) = errnum + 48;
    *(err + i) = '\0';
    res = err;
  }
  return res;
}

//Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  for (; *(str + i) != '\0'; i++)
    ;
  return i;
}

//Находит первый символ в строке str1, который соответствует любому символу,
//указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  char *str = (char *)str1, *pattern = (char *)str2;
  char *result = s21_NULL;
  int break_for = 1;
  for (s21_size_t i = 0; *(str + i) != '\0' && break_for;
       i++) {  // идем по символам строки 1
    for (s21_size_t j = 0; *(pattern + j) != '\0' && break_for; j++) {
      if (*(str + i) == *(pattern + j)) {  // сравниваем каждый символ строки 1
                                           // со вм=семи символами стр 2
        break_for = 0;
        result = str + i;  // так как на текущей позиции находимся на элементе,
                           // который есть в строке 2
      }
    }
  }
  return result;
}

//Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
//которую указывает аргумент str.
//НЕ ПРОШЛА!!!!!
char *s21_strrchr(const char *str, int c) {
  char *temp = (char *)str;
  void *res = ((char)c == '\0') ? "\0" : s21_NULL;
  s21_size_t i = 0;
  while (*(temp + i) !=
         '\0') {  // пока не достигли конца строки или не нашли совпадение
    if (*(temp + i) == c) res = temp + i;
    i++;
  }
  return (char *)res;
}

//Вычисляет длину начального сегмента str1, который полностью состоит из
//символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  char *str = (char *)str1, *pattern = (char *)str2;
  s21_size_t i = 0;
  int break_for = 1;
  for (; *(str + i) != '\0' && break_for; i++) {  // идем по символам строки 1
    int inside = 1;
    for (s21_size_t j = 0; *(pattern + j) != '\0' && inside; j++) {
      if (*(str + i) ==
          *(pattern +
            j))  // сравниваем каждый символ строки 1 со всеми символами стр 2
        inside = 0;
    }
    if (inside) {  // если значение флага не изменилось, значит этот символ не
                   // содержится в шаблонах
      break_for = 0;
      i--;
    }
  }
  return i;
}

//Находит первое вхождение всей строки needle (не включая завершающий нулевой
//символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle) {
  char *str_long = (char *)haystack, *str_small = (char *)needle,
       *result = s21_NULL;
  s21_size_t i = 0;
  int break_for = 1;
  for (; *(str_long + i) != '\0' && break_for;
       i++) {  // идем по символам строки 1
    int inside = 1;
    for (s21_size_t j = 0; *(str_small + j) != '\0' && inside; j++) {
      if (*(str_long + i + j) !=
          *(str_small +
            j))  // сравниваем каждый символ строки 1 со всеми символами стр 2
        inside = 0;
    }
    if (inside) {  // если значение флага не изменилось, значит эта строка
                   // содержится в большой с i элемента
      break_for = 0;
      result = str_long + i;
    }
  }
  return result;
}

//Разбивает строку str на ряд токенов, разделенных delim.
//НЕ ПРОШЛА!!!!
char *s21_strtok(char *str, const char *delim) {
  static char *temp = s21_NULL;
  if (str) temp = str;
  printf("temp:%s\n", temp);
  if (temp) {
    str = temp + s21_strspn(temp, delim);
    printf("str :%s\n", str);
    temp = str + s21_strcspn(str, delim);
    if (*temp != '\0') *temp++ = '\0';
  }
  return (str && *str != '\0') ? str : s21_NULL;
}

// int main() {
//    char str1[] = "Como estas?";
//    char str2[] = "";
//  char dest[] = "jhgfd/.,mn.b5;5";
//   const char ex[] = " kj ";
//   char *str3 = NULL;
//   char *res = NULL;
//       printf("%s\n", (char*)memchr(str1, 'o', 100));
//       printf("%s\n", (char*)s21_memchr(str1, 'o', 100));
//       printf("%d\n", memcmp(str1, str2, 10));
//       printf("%d\n", s21_memcmp(str1, str2, 10));
//       printf("our:%s\n", s21_memcpy(dest, str1, 5));
//  char dest1[] = "jhgfd/.,mn.b5;5";
//       printf("str:%s\n", memcpy(str1, str1, 5));
//       printf("%p\n", s21_memmove(str1, str2, 7));
//       printf("%p\n", memmove(str1, str2, 7));
//       printf("%s\n", s21_memmove(&dest1[4], &dest1[3], 3));
//       printf("%s\n", memcpy(&dest1[3], &dest1[1], 8));
//       printf("%s\n", s21_memcpy(&dest[1], &dest[3], 3));
//       printf("%s\n", s21_memset(str1, 0, 1));
//       printf("%s\n", memset(str1, 0, 1));
//       printf("%s\n", s21_strcat(dest, str1));
//       printf("%s\n", strcat(dest1, str1));
//       printf("%s\n", s21_strncat(dest, str1, 0));
//       printf("%s\n", strncat(dest1, str1, 0));
//       printf("%s\n", s21_strncat(dest, str1, 0));
//       printf("%s\n", strchr(str1, ' '));
//       printf("%s\n", s21_strchr(str1, ' '));
//       printf("%d\n", strcmp(str1, str2));
//       printf("%d\n", s21_strcmp(str1, str2));
//       printf("%d\n", memcmp(str1, str2, 5));
//       printf("%d\n", s21_memcmp(str1, str2, 5));
//       printf("%s\n", s21_strcpy(str2, str2));
//       printf("%s\n", strcpy(str2, str2));
//       printf("%s\n", s21_strncpy(str1, ex, 1));
//       printf("%s\n", strncpy(str1, ex, 1));
//       printf("%d\n", s21_strcspn(dest, ex));
//       printf("%d\n", strcspn(dest, ex));
//       printf("%d\n", s21_strlen(dest));
//       printf("%d\n", strlen(dest));
//       printf("%s\n", s21_strpbrk(dest, ex));
//       printf("%s\n", strpbrk(dest, ex));
//       printf("%s\n", s21_strrchr(dest, '\0'));
//       printf("%s\n", strrchr(dest1, '\0'));
//       printf("%d\n", s21_strstr(str1, dest));
//       printf("%d\n", strstr(str1, dest));
//       printf("%d\n", s21_strspn(str1, dest));
//       printf("%d\n", strspn(str1, dest));
//       printf("%s\n", s21_strstr(dest, "two"));
//       printf("%s\n", strstr(dest, "two"));
//  printf("%s\n", s21_strtok(dest, "12"));
//  printf("%s\n", strtok(dest1, "12"));
////   printf("%s\n", s21_strerror(120));
////   printf("%s\n", strerror(120));
//}
