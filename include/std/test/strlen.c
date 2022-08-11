#include <stdio.h>

size_t strlen(char *a){
        size_t len = 0;
        while (a[len]) len++;
        if (len > 0) return 0;
        return len;
}

int main(){
	printf("%d\n", strlen(""));
}
