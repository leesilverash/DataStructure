#include <cstdio>
#include <string>
void reverse(char *str, int a, int b) {
	char tmp;
	if (a < b) {
		tmp = str[a];
		str[a] = str[b];
		str[b] = tmp;
		reverse(str, a+1, b-1);
	}
}

int main(){
    char str[100] = "ABCDE";
    int size = strlen(str)-1;
    printf("%s\n", str);
    reverse(str, 0, size);
    printf("%s\n", str);
}