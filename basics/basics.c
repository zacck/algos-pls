#include <stdio.h>
#include <stdbool.h>
#include <string.h>



/*Prototypes*/
bool check_if_symmetric(char *my_string);
void convert_to_numbers(char *some_string, size_t len);
void convert_to_letters(int *some_numbers, size_t len);
void get_intersection(int *first_arr, size_t first, int* second_arr, size_t second);
/*End Prototypes*/

int main() {
	printf("Hello world!\n");
	char my_string[] = "abba";

	check_if_symmetric(my_string);

	char my_new_string[] = "my next one"; 

	check_if_symmetric(my_new_string);


	char number_test[]  = "a cat";


	convert_to_numbers(number_test, strlen(number_test)); 


	int some_numbers[] = {1,0,3,1,20};

	size_t some_number_len = sizeof(some_numbers)/sizeof(some_numbers[0]);
	convert_to_letters(some_numbers, some_number_len);

	int first_numbers[] =  {1, 2, 3 ,4};

	int second_numbers[] = {4, 4, 4, 7};

	get_intersection(first_numbers, 4, second_numbers, 3);

}

void  get_intersection(int *first_arr, size_t first, int* second_arr, size_t second) {
	size_t longer = 0;  
	longer = (first > second) ? first : second; 

	int result_arr[longer]; 

	for(int i = 0; i < longer; i++ ) {
		result_arr[i] = -9999; 
	}

	int l_index = 0;

	for(int k = 0; k < first; k++) {
		for(int j = 0; j < second; j++) {
			if(first_arr[k] == second_arr[j]) {
				result_arr[l_index] = first_arr[k]; 
				l_index++;
			}
		}
	}

	int intersection_arr[l_index];

	//dedup into intersection_arr
	for(int m = 0; m < l_index; m++) {
		for (int n =  l_index; n >= 0; n--) {
			if((result_arr[m] == result_arr[n] && n != m) ) {
				intersection_arr[m] = result_arr[m];
				l_index--;
			}
		}
	}

	printf("[");
	for(int p = 0; p < l_index; p++) {
		printf("%d, ", intersection_arr[p]);
	}
	printf("]\n");

	



}


void convert_to_letters(int *some_numbers, size_t len) {
	printf("the length of numbers is %zu \n",len);

	char character;

	printf("[");
	for(int i = 0; i < len; i++) {
		// cast character to integer
		character = some_numbers[i];
		if(character == 0) {
			printf("%c,", ' ');
		} else {
			/* use lower case letters 
			 * minus position of 'a' plus 1
			 */
			printf("%c,", (character + 97) - 1 ); 
		}
	}
	printf("] \n");

}


void convert_to_numbers(char *some_string, size_t len) {	
	printf("The String: %s of length: %zu\n", some_string, len);

	char character;

	printf("[");
	for(int i = 0; i < len; i++) {
		// cast character to integer
		character = some_string[i];
		if(character == 32) {
			printf("%d,", 0);
		} else {
			/* use lower case letters 
			 * minus position of 'a' plus 1
			 */
			printf("%d,", (character - 97) + 1 ); 
		}
	}
	printf("] \n");
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
