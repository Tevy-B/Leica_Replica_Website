#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
#define DELETE1 'g'
#define DELETE2 'G'

int main(int argc, char *argv[])
{
 char fileName[100];
 char line[MAXLEN];
 int c;
 int i = 0;
 FILE *filep;

 // get file name from user
 fgets(line, MAXLEN, stdout);
 // display syntax if no arguments passed on command line
 if (argc <= 1)
 {
  printf("Syntax: %s filename\n", argv[0]);
  exit(0);
 }
 strcpy(fileName, argv[1]);
 filep = fopen(fileName, "r"); // stream
 // read the input file char by char
 c = fgetc(filep);

 while (c != EOF)
 {
  if (c == DELETE1)
  {
   putchar('g');
   putchar('r');
   putchar('e');
   putchar('m');
   putchar('l');
   putchar('i');
   c += 7; // replace the file's g(#7 of the alphabet) with 'n'(#14)
  }
  if (c == DELETE2)
  {
   putchar('G');
   putchar('R');
   putchar('E');
   putchar('M');
   putchar('L');
   putchar('I');
   c += 7; // 7 position after G
  }
  printf("%c", c);
  c = fgetc(filep);
 }

 fclose(filep);
 return 0;
}