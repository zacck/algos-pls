#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



/*Prototypes*/
bool check_if_symmetric(char *my_string);
int *convert_to_numbers_dyn(char *some_string);

/*End Prototypes*/

int main() {
	printf("Hello world!\n");
	char my_string[] = "abba";

	check_if_symmetric(my_string);

	char my_new_string[] = "my next one"; 

	check_if_symmetric(my_new_string);


	char number_test[]  = "a cat";

	int *num_arr = convert_to_numbers_dyn(number_test); 

	if(num_arr) {
		free(num_arr);
	}


}

int *convert_to_numbers_dyn(char *some_string) {
	int length = strlen(some_string);
	
	printf("The String: %s of length: %d\n", some_string, length);

	int *my_nums = malloc(length);
	if(!my_nums) 
		return NULL;

	int character;

	printf("[");
	for(int i = 0; i < length; i++) {
		// cast character to integer
		character = some_string[i];
		if(character == 32) {
			my_nums[i] = 0;
			printf("%d,", my_nums[i]);
		} else {
			/* use lower case letters 
			 * minus position of 'a' plus 1
			 */
			my_nums[i] = (character - 97) + 1 ;
			printf("%d,", my_nums[i]); 
		}
	}
	printf("]");
	return my_nums;
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
