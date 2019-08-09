#include "stdafx.h"
#include <iostream>
#include <string>

int perms = 0;

// Function to print permutations of string  
// This function takes three parameters:  
// 1. String  
// 2. Starting index of the string  
// 3. Ending index of the string.  
void permute(std::string a, int l, int r)
{
	// Base case  
	if (l == r) {
		perms += 1;	// Count number of permutations to make sure number is correct
		std::cout << a << std::endl;
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
	std::string str = "123abc";
	int n = str.size();
	permute(str, 0, n - 1);
	std::cout << "Permutations: " << perms << "\n";
	return 0;
}

// This is code is contributed by rathbhupendra 