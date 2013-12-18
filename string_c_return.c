#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * SomeFunction(void)
{
char *str = malloc(sizeof(char *) * 100);
strcpy(str, "Hello this is testing "); 

//str="Love that jesus ";
return str;
}
int main (){

char* str = SomeFunction();
printf("%s\n", str);
free (str);

}
