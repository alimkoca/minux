#include <std/string.h>
#include <std/type.h>

void *memset(void *a, int b, u32 c){
        unsigned char *ptr = a;

        while (c-- > 0)
                *ptr++ = b;

        return a;
}


char* strconv(u32 n, u32 b) {
	static char keys[] = "0123456789abcdef";
	static char buf[50];
	char *p;

	p = &buf[49];
	*p = '\0';

	do {
		*--p = keys[n % b];
		n /= b;
	} while (n != 0);

	return p;
}

int memcmp(const void *a, const void *b, size_t n){
        const unsigned char *ac = (unsigned char*)a;
        const unsigned char *bc = (unsigned char*)b;

        while (n-- > 0){
                if (*ac++ != *bc++)
                        return ac[-1] < bc[-1] ? -1 : 1;
        }

        return 0;
}

/*
 * strlen() minux implementation:
 * Taking length of string,
 * returns -1 in failure, else
 * normally returns length of
 * string as expected.
 */
size_t strlen(const char *a){
        size_t len = 0;
        while (a[len]) len++;
        if (!len) return 0;
        return len;
}

/*
 * isspace() minux implementation:
 * Detecting char if is space or not
 * returns 1 if true, else 0
 */
bool isspace(char a){
        return a == ' ' ? 1 : 0;
}

/*
 * strcat() minux implementation:
 * Concatenating the strings,
 * returns -1 in failure, else
 * will return character number
 */

// Example: a is "GNU/" and b is "Linux"
// length of a is 4 without null byte(s)
// and x is 0 at start, then we are start-
// ing loop with first element of b, so
// b[x] = b[0], then we are increasing x
// so that means:
// a[4+0+1] = 'L';
// a[4+1+1] = 'i';
// a[4+2+1] = 'n';
// a[4+3+1] = 'u';
// a[4+4+1] = 'x';
// and last:
// a[4+5+1] = '\0'; so, a is "GNU/Linux",
// Congratulations! You did it!
int strcat(const void *a, const void *b){
        unsigned char *ac = (unsigned char*)a;
        unsigned char *bc = (unsigned char*)b;
        int al, x;

        if ((al = strlen(ac)) == 0)
                return 0;

        for (x = 0; bc[x] != '\0'; x++)
                ac[al+x+1] = bc[x];

        ac[al+x+1+1] = '\0';

        return al+x+1+1;
}
