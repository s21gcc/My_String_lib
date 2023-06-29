#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>

#define s21_buf_size 1000

typedef struct format_token {
  int minus;
  int plus;
  int space;
  int zero;
  int hash;
  int width;
  int prec;
  char length;
  char spec;
  int count;
  int star;
} format_token;

#define s21_NULL ((void *)0)
#if defined(__APPLE__)
#define ERRORS                                                         \
  ((const char *[]){"Undefined error: 0",                              \
                    "Operation not permitted",                         \
                    "No such file or directory",                       \
                    "No such process",                                 \
                    "Interrupted system call",                         \
                    "Input/output error",                              \
                    "Device not configured",                           \
                    "Argument list too long",                          \
                    "Exec format error",                               \
                    "Bad file descriptor",                             \
                    "No child processes",                              \
                    "Resource deadlock avoided",                       \
                    "Cannot allocate memory",                          \
                    "Permission denied",                               \
                    "Bad address",                                     \
                    "Block device required",                           \
                    "Resource busy",                                   \
                    "File exists",                                     \
                    "Cross-device link",                               \
                    "Operation not supported by device",               \
                    "Not a directory",                                 \
                    "Is a directory",                                  \
                    "Invalid argument",                                \
                    "Too many open files in system",                   \
                    "Too many open files",                             \
                    "Inappropriate ioctl for device",                  \
                    "Text file busy",                                  \
                    "File too large",                                  \
                    "No space left on device",                         \
                    "Illegal seek",                                    \
                    "Read-only file system",                           \
                    "Too many links",                                  \
                    "Broken pipe",                                     \
                    "Numerical argument out of domain",                \
                    "Result too large",                                \
                    "Resource temporarily unavailable",                \
                    "Operation now in progress",                       \
                    "Operation already in progress",                   \
                    "Socket operation on non-socket",                  \
                    "Destination address required",                    \
                    "Message too long",                                \
                    "Protocol wrong type for socket",                  \
                    "Protocol not available",                          \
                    "Protocol not supported",                          \
                    "Socket type not supported",                       \
                    "Operation not supported",                         \
                    "Protocol family not supported",                   \
                    "Address family not supported by protocol family", \
                    "Address already in use",                          \
                    "Can't assign requested address",                  \
                    "Network is down",                                 \
                    "Network is unreachable",                          \
                    "Network dropped connection on reset",             \
                    "Software caused connection abort",                \
                    "Connection reset by peer",                        \
                    "No buffer space available",                       \
                    "Socket is already connected",                     \
                    "Socket is not connected",                         \
                    "Can't send after socket shutdown",                \
                    "Too many references: can't splice",               \
                    "Operation timed out",                             \
                    "Connection refused",                              \
                    "Too many levels of symbolic links",               \
                    "File name too long",                              \
                    "Host is down",                                    \
                    "No route to host",                                \
                    "Directory not empty",                             \
                    "Too many processes",                              \
                    "Too many users",                                  \
                    "Disc quota exceeded",                             \
                    "Stale NFS file handle",                           \
                    "Too many levels of remote in path",               \
                    "RPC struct is bad",                               \
                    "RPC version wrong",                               \
                    "RPC prog. not avail",                             \
                    "Program version wrong",                           \
                    "Bad procedure for program",                       \
                    "No locks available",                              \
                    "Function not implemented",                        \
                    "Inappropriate file type or format",               \
                    "Authentication error",                            \
                    "Need authenticator",                              \
                    "Device power is off",                             \
                    "Device error",                                    \
                    "Value too large to be stored in data type",       \
                    "Bad executable (or shared library)",              \
                    "Bad CPU type in executable",                      \
                    "Shared library version mismatch",                 \
                    "Malformed Mach-o file",                           \
                    "Operation canceled",                              \
                    "Identifier removed",                              \
                    "No message of desired type",                      \
                    "Illegal byte sequence",                           \
                    "Attribute not found",                             \
                    "Bad message",                                     \
                    "EMULTIHOP (Reserved)",                            \
                    "No message available on STREAM",                  \
                    "ENOLINK (Reserved)",                              \
                    "No STREAM resources",                             \
                    "Not a STREAM",                                    \
                    "Protocol error",                                  \
                    "STREAM ioctl timeout",                            \
                    "Operation not supported on socket",               \
                    "Policy not found",                                \
                    "State not recoverable",                           \
                    "Previous owner died",                             \
                    "Interface output queue is full"})
#define MAXERROR 106
#elif defined(__linux__)
#define ERRORS                                                           \
  ((const char *[]){"Success",                                           \
                    "Operation not permitted",                           \
                    "No such file or directory",                         \
                    "No such process",                                   \
                    "Interrupted system call",                           \
                    "Input/output error",                                \
                    "No such device or address",                         \
                    "Argument list too long",                            \
                    "Exec format error",                                 \
                    "Bad file descriptor",                               \
                    "No child processes",                                \
                    "Resource temporarily unavailable",                  \
                    "Cannot allocate memory",                            \
                    "Permission denied",                                 \
                    "Bad address",                                       \
                    "Block device required",                             \
                    "Device or resource busy",                           \
                    "File exists",                                       \
                    "Invalid cross-device link",                         \
                    "No such device",                                    \
                    "Not a directory",                                   \
                    "Is a directory",                                    \
                    "Invalid argument",                                  \
                    "Too many open files in system",                     \
                    "Too many open files",                               \
                    "Inappropriate ioctl for device",                    \
                    "Text file busy",                                    \
                    "File too large",                                    \
                    "No space left on device",                           \
                    "Illegal seek",                                      \
                    "Read-only file system",                             \
                    "Too many links",                                    \
                    "Broken pipe",                                       \
                    "Numerical argument out of domain",                  \
                    "Numerical result out of range",                     \
                    "Resource deadlock avoided",                         \
                    "File name too long",                                \
                    "No locks available",                                \
                    "Function not implemented",                          \
                    "Directory not empty",                               \
                    "Too many levels of symbolic links",                 \
                    "Unknown error 41",                                  \
                    "No message of desired type",                        \
                    "Identifier removed",                                \
                    "Channel number out of range",                       \
                    "Level 2 not synchronized",                          \
                    "Level 3 halted",                                    \
                    "Level 3 reset",                                     \
                    "Link number out of range",                          \
                    "Protocol driver not attached",                      \
                    "No CSI structure available",                        \
                    "Level 2 halted",                                    \
                    "Invalid exchange",                                  \
                    "Invalid request descriptor",                        \
                    "Exchange full",                                     \
                    "No anode",                                          \
                    "Invalid request code",                              \
                    "Invalid slot",                                      \
                    "Unknown error 58",                                  \
                    "Bad font file format",                              \
                    "Device not a stream",                               \
                    "No data available",                                 \
                    "Timer expired",                                     \
                    "Out of streams resources",                          \
                    "Machine is not on the network",                     \
                    "Package not installed",                             \
                    "Object is remote",                                  \
                    "Link has been severed",                             \
                    "Advertise error",                                   \
                    "Srmount error",                                     \
                    "Communication error on send",                       \
                    "Protocol error",                                    \
                    "Multihop attempted",                                \
                    "RFS specific error",                                \
                    "Bad message",                                       \
                    "Value too large for defined data type",             \
                    "Name not unique on network",                        \
                    "File descriptor in bad state",                      \
                    "Remote address changed",                            \
                    "Can not access a needed shared library",            \
                    "Accessing a corrupted shared library",              \
                    ".lib section in a.out corrupted",                   \
                    "Attempting to link in too many shared libraries",   \
                    "Cannot exec a shared library directly",             \
                    "Invalid or incomplete multibyte or wide character", \
                    "Interrupted system call should be restarted",       \
                    "Streams pipe error",                                \
                    "Too many users",                                    \
                    "Socket operation on non-socket",                    \
                    "Destination address required",                      \
                    "Message too long",                                  \
                    "Protocol wrong type for socket",                    \
                    "Protocol not available",                            \
                    "Protocol not supported",                            \
                    "Socket type not supported",                         \
                    "Operation not supported",                           \
                    "Protocol family not supported",                     \
                    "Address family not supported by protocol",          \
                    "Address already in use",                            \
                    "Cannot assign requested address",                   \
                    "Network is down",                                   \
                    "Network is unreachable",                            \
                    "Network dropped connection on reset",               \
                    "Software caused connection abort",                  \
                    "Connection reset by peer",                          \
                    "No buffer space available",                         \
                    "Transport endpoint is already connected",           \
                    "Transport endpoint is not connected",               \
                    "Cannot send after transport endpoint shutdown",     \
                    "Too many references: cannot splice",                \
                    "Connection timed out",                              \
                    "Connection refused",                                \
                    "Host is down",                                      \
                    "No route to host",                                  \
                    "Operation already in progress",                     \
                    "Operation now in progress",                         \
                    "Stale file handle",                                 \
                    "Structure needs cleaning",                          \
                    "Not a XENIX named type file",                       \
                    "No XENIX semaphores available",                     \
                    "Is a named type file",                              \
                    "Remote I/O error",                                  \
                    "Disk quota exceeded",                               \
                    "No medium found",                                   \
                    "Wrong medium type",                                 \
                    "Operation canceled",                                \
                    "Required key not available",                        \
                    "Key has expired",                                   \
                    "Key has been revoked",                              \
                    "Key was rejected by service",                       \
                    "Owner died",                                        \
                    "State not recoverable",                             \
                    "Operation not possible due to RF-kill",             \
                    "Memory page has hardware error"})
#define MAXERROR 133
#endif

typedef unsigned long s21_size_t;
void *s21_memchr(
    const void *str, int c,
    size_t n);  // выполняет поиск первого вхождения символа c (беззнаковый тип)
                // в первых n байтах строки, на которую указывает аргумент str
int s21_memcmp(const void *str1, const void *str2,
               size_t n);  // сравнивает первые n байтов str1 и str2
void *s21_memcpy(void *dest, const void *src,
                 size_t n);  // копирует n символов из src в dest
void *s21_memmove(void *dest, const void *src,
                  size_t n);  // копирует n символов из src в dest
void *s21_memset(
    void *str, int c,
    size_t n);  // копирует символ c (беззнаковый тип) в первые n символов
                // строки, на которую указывает аргумент str
char *s21_strcat(
    char *dest,
    const char *src);  // добавляет строку, на которую указывает src, в конец
                       // строки, на которую указывает dest
char *s21_strncat(
    char *dest, const char *src,
    s21_size_t n);  // добавляет строку, на которую указывает src, в конец
                    // строки, на которую указывает dest, длиной до n символов
char *s21_strchr(
    const char *str,
    int c);  // выполняет поиск первого вхождения символа c (беззнаковый тип) в
             // строке, на которую указывает аргумент str

int s21_strcmp(
    const char *str1,
    const char *str2);  // сравнивает строку, на которую указывает str1, со
                        // строкой, на которую указывает str2
int s21_strncmp(const char *str1, const char *str2,
                size_t n);  // сравнивает не более первых n байтов str1 и str2
char *s21_strcpy(
    char *dest,
    const char *src);  // копирует строку, на которую указывает src, в dest
char *s21_strncpy(char *dest, const char *src,
                  size_t n);  // копирует до n символов из строки, на которую
                              // указывает src, в dest
s21_size_t s21_strcspn(
    const char *str1,
    const char *str2);  // вычисляет длину начального сегмента str1, который
                        // полностью состоит из символов, не входящих в str2
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);  // вычисляет длину строки str, не
                                         // включая завершающий нулевой символ
char *s21_strpbrk(
    const char *str1,
    const char *str2);  // находит первый символ в строке str1, который
                        // соответствует любому символу, указанному в str2
char *s21_strrchr(
    const char *str,
    int c);  // выполняет поиск последнего вхождения символа c (беззнаковый тип)
             // в строке, на которую указывает аргумент str
s21_size_t s21_strspn(
    const char *str1,
    const char *str2);  // вычисляет длину начального сегмента str1, который
                        // полностью состоит из символов str2
char *s21_strstr(
    const char *haystack,
    const char *needle);  // находит первое вхождение всей строки needle (не
                          // включая завершающий нулевой символ), которая
                          // появляется в строке haystack
char *s21_strtok(char *str, const char *delim);  // разбивает строку str на ряд
                                                 // токенов, разделенных delim

void *s21_to_upper(const char *str);  // возвращает копию строки (str),
                                      // преобразованную в верхний регистр
void *s21_to_lower(const char *str);  // возвращает копию строки (str),
                                      // преобразованную в нижний регистр
void *s21_insert(
    const char *src, const char *str,
    size_t
        start_index);  // возвращает новую строку, в которой указанная строка
                       // (str) вставлена ​​в указанную
                       // позицию индекса (start_index) в заданной строке (src)
void *s21_trim(
    const char *src,
    const char *trim_chars);  // возвращает новую строку, в которой удалены все
                              // начальные и конечные вхождения набора указанных
                              // символов (trim_chars) из заданной строки (src)

int s21_sscanf(const char *str, const char *format, ...);
int s21_spec_s_scan(char **str, format_token *att, va_list args);
int s21_spec_c_scan(char **str, format_token *att, va_list args);
int s21_spec_i_scan(char **str, va_list args, format_token *att, int base);
long s21_atoi_scan(char *str, char **strlim, int base, format_token *att,
                   int sign);
int s21_check_spec_scan(format_token *tok, char **str, va_list ap);
void nice_symb(char **str, format_token *att);
char *s21_sputsf(char **src, format_token *att);
int s21_isspace(int c);
int s21_spec_u_scan(char **str, va_list args, format_token *att, int base);
unsigned long s21_atoul_scan(char *str, char **strlim, format_token *att,
                             int base);
int s21_spec_f_scan(char **str, format_token *att, va_list args);
float s21_atof(char *str, char **strlim, format_token *att);
double s21_atod(char *str, char **strlim, format_token *att);
long double s21_atold(char *str, char **strlim, format_token *att);
char *s21_parse_star(char *f, format_token *tok);
void s21_spec_n_scan(va_list args, format_token *att);
int s21_spec_p_scan(char **str, va_list args, format_token *att);
char *s21_parse_width_scan(char *f, format_token *tok);

// support
void s21_left_side_int(format_token att, char **str, int scale, int negative,
                       long int var_int);
void s21_right_side_int(format_token att, char **str, int scale, int negative,
                        long int var_int, unsigned long int crutch);

void s21_left_side_float(format_token att, char **str, int negative,
                         long double fractional, long double int_part,
                         int scale);
void s21_right_side_float(format_token att, char **str, int negative,
                          long double fractional, long double int_part,
                          int scale);
void s21_handle_int_part_in_float(format_token *att, char **str, int scale,
                                  long double int_part, int minus_width);
void s21_handle_fractional_part_in_float(format_token *att, char **str,
                                         int scale, double rounded_frac);
void s21_handle_zero_in_float(format_token *att, char **str, int negative);
void s21_smart_rounding(double after_point, double rounded_frac,
                        long double *int_part, long double *fractional);

void s21_left_side_uint(format_token att, char **str, int scale,
                        unsigned long int var_int);
void s21_right_side_uint(format_token att, char **str, int scale,
                         unsigned long int var_int);
// support

void s21_check_spec(format_token *tok, char **str, va_list ap, int count_for_n);
// spec
void s21_spec_c(char **str, format_token att, va_list args);
void s21_spec_i(char **str, format_token att, va_list args);
// void spec_n(char *str, format_token att, va_list args);
void s21_spec_s(char **str, format_token att, va_list args, double no_num);
void s21_spec_f(char **str, format_token att, va_list args);
void s21_uint(char **str, format_token att, va_list args);
// spec

// pars
char *s21_parse_length(char *f, format_token *tok);
char *s21_parse_flag(char *f, format_token *tok);
char *s21_parse_prec(char *f, format_token *tok, va_list args);
char *s21_parse_width(char *f, format_token *tok, va_list args);
// pars

int s21_sprintf(char *str, const char *format, ...);

void s21_init_format_token(format_token *tok);
void s21_char_format_token(format_token *tok);

void s21_empty_space_zero(char **str, format_token att, char option);

void s21_first_sym_in_str(format_token *att, char **str, int negative,
                          int count, int print);

int s21_isdigit(int ch);
int s21_atoi(char *str);

void s21_spec_eE(char **str, format_token att, va_list args);
void s21_zero_int_part(format_token *att, char **str, int negative,
                       long double fractional, long double int_part, int scale);
void s21_right_side_eE(format_token *att, char **str, int negative,
                       long double fractional, long double int_part, int scale1,
                       int minus_stepen);
void s21_left_side_eE(format_token *att, char **str, int negative,
                      long double fractional, long double int_part, int scale1,
                      int minus_stepen);
void s21_not_zero_int_part(format_token *att, char **str, long double int_part,
                           long double fractional, int negative, int scale);
void s21_print_exponent(format_token *att, char **str, int minus_stepen);
void s21_count_e(format_token *att, int *minus_stepen, int *minus_scale,
                 int *plus);
void s21_also_print_exp(format_token *att, char **str, int plus,
                        int minus_stepen, int minus_scale);

void s21_spec_p(char **str, format_token att, va_list args);
void s21_print_p(format_token *att, char **str, int count,
                 const char inverted[]);
void s21_create_output(format_token att, char inverted[], int *count,
                       unsigned long long int *var_point);
void s21_minus_prec(format_token *att);

void s21_check_round(long double *int_part, int *minus_stepen,
                     long double *rounded_frac, long double *after_point);
void s21_preparing_ex(format_token *att, char **str, int *negative,
                      long double *fractional, long double *int_part,
                      int *scale, int *minus_stepen, int *flag, int *scale1);

// int s21_sscanf(const char *str, const char *format, ...); // считывает
// форматированный ввод из строки int s21_sprintf(char *str, const char *format,
// ...); // отправляет форматированный вывод в строку, на которую указывает str

#endif  //  SRC_S21_STRING_H_
