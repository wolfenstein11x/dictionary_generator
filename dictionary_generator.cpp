#include "stdafx.h"
#include <iostream>
#include <vector>

std::vector<int> all_options = { 1,2,3,4,5 };
std::vector<int> combo;
std::vector<std::vector<int>> combos;

int n = all_options.size();
int k = 3;	//the size of the group you choose
int j = -1;

void print_combo(std::vector<int> vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

void go(int offset, int k) {
	
	if (k == 0) {
		j += 1;
		combos.push_back(combo);
		print_combo(combos[j]);
		return;
	}
	for (int i = offset; i <= n - k; i++) {
		combo.push_back(all_options[i]);
		go(i + 1, k - 1);
		combo.pop_back();
	}
}

int main()
{
	go(0, k);

    return 0;
}

