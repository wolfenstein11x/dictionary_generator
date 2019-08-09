#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int term_count = 0;		//use this if you want to make sure the number of permutations is correct

std::vector<std::string> perms;		// store the terms in a vector so we can later write it to a text file

std::ofstream myfile;		// make object for writing to a file

void write_to_file(std::vector<std::string> words) {		// helper function to write terms to a text document
	myfile.open("dictionary.txt");
	for (int i = 0; i < words.size(); i++) {
		myfile << words[i] << "\n";
	}
	myfile.close();		// close the file AFTER you have written ALL the terms to it
}

// This permutation function code is contributed by rathbhupendra 
// Function to print permutations of string  
// This function takes three parameters:  
// 1. String  
// 2. Starting index of the string  
// 3. Ending index of the string.  
void permute(std::string a, int l, int r)
{
	// Base case  
	if (l == r) {
		term_count += 1;	// Count number of permutations to make sure number is correct
		//std::cout << a << std::endl;		//Print each permutation on the terminal		
		perms.push_back(a);
		}
	else
	{
		// Permutations made  
		for (int i = l; i <= r; i++)
		{

			// Swapping done  
			std::swap(a[l], a[i]);

			// Recursion called  
			permute(a, l + 1, r);

			//backtrack  
			std::swap(a[l], a[i]);
		}
	}
}

// Driver Code  
int main()
{
	std::string str = "0123456789";
	int n = str.size();
	permute(str, 0, n - 1);
	std::cout << "Permutations: " << term_count << "\n";
	write_to_file(perms);
	return 0;
}

