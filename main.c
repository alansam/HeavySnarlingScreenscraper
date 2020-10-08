
#define NDEBUG
#undef NDEBUG

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void type_sizes(void);
void string_length_calc(void);
size_t lengthString(char s[]);

int main() {

  type_sizes();
  string_length_calc();

  return 0;
}

void type_sizes(void) {
  printf("%s\n\n", __func__);

  typedef struct fv fv; 
  struct fv {
    char name[20];
    size_t sz;
  };
  fv types[] = {
    { "char",         sizeof(char), },
    { "short",        sizeof(short), },
    { "int",          sizeof(int), },
    { "long",         sizeof(long), },
    { "long long",    sizeof(long long), },
    { "float",        sizeof(float), },
    { "double",       sizeof(double), },
    { "long double",  sizeof(long double), },
  };
  size_t types_s = sizeof(types);
  size_t types_e = types_s / sizeof(*types);

  for (size_t e_ = 0; e_ < types_e; ++e_) {
    char * name = types[e_].name;
    size_t size = types[e_].sz;
    printf("size of %16s %2zu\n", name, size);
  }

  return;
}
void string_length_calc(void) {
  printf("%s\n\n", __func__);

  char a1[6] = { '1', '2', '3', '4', '5', '\0', };
  char a2[5] = { 'a', 'b', 'c', 'd', 'e', };
  char a3[4] = { 'A', 'B', 'C', '\0', };

  printf("%zu\n", lengthString(a1));
  printf("%zu\n", lengthString(a3));
  printf("%zu\n\n", lengthString(a2));

  printf("%zu\n", strlen(a1));
  printf("%zu\n", strlen(a3));
  printf("%zu\n\n", strlen(a2));

  return;
}

size_t lengthString(char s[]) {
#ifndef NDEBUG
  printf("%1$s, '%2$c' %2$#x\n", __func__, *s);
#endif

  if (*(s + 0) == '\0') {
    return 0;
  }

  return lengthString(s + 1) + 1L;
}
