#include <stdio.h>
#include <stdlib.h>
#include "cmp.h"



int strcmp(char *str1, char *str2) {
    if (str1 == NULL || str2 == NULL) {
		return -1;
	}
    while (*str2 == *str1 && *str1 != '\0' && *str2 != '\0') {
  		str1++;
  		str2++;
   }
   if (*str1 == *str2) {
   return 0;
   }
   else {
   return 1;
   }
} 

