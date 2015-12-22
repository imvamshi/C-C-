/*
 * https://www.cs.bu.edu/teaching/cpp/string/array-vs-ptr/
 * https://www.eskimo.com/~scs/cclass/krnotes/sx8e.html
 */ 

//#include <string.h>
#include <stdio.h>

/*/ USING ARRAY
void strcpy(char s[], char t[])
{
	int i;
	for(i = 0; t[i] != '\0'; i++)
	{
		s[i] = t[i];
	}
	s[i] = '\0';
}
/*/

//USING POINTERS
void strcpy(char *s,char *t){
	while(*t!='\0')
	*s++ = *t++;
	// *s++ = *t++ may seem cryptic at first sight, but they're actually analogous to array subscript expressions ex: a[i++] a[i--]
	*s = '\0';
}
// Passing strings via pointers
void pf(char *x){
	printf("---------\n%s\n",x);
}
main()
{
	char *p = "Hello, world!";
	char label[] = "Matter";
	char *labelptr;
	labelptr = label;
	char a[24];
	strcpy(a,p);
	printf("%s",a);
	pf(labelptr);
}
