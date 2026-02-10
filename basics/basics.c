#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*Prototypes*/
bool check_if_symmetric(char *my_string);

/*End Prototypes*/

int main() {
	printf("Hello world!\n");
	char my_string[] = "abba";

	check_if_symmetric(my_string);

	char my_new_string[] = "my next one"; 

	check_if_symmetric(my_new_string);

}

bool check_if_symmetric(char *my_string) {
	int length = strlen(my_string);
	
	printf("The String: %s of length: %d\n", my_string, length);
	
	bool is_palindrome = true;

	for(int i = 0; i < length; i++) {
		if((length - (i +1)) >  i) {
			if(my_string[i] == my_string[length - (i + 1)]) {
				is_palindrome  = true; 
			} else {
				is_palindrome = false;
				break; 
			}
		}
	}

	printf("Palindrome status is %d \n", is_palindrome);

	return is_palindrome;
}
