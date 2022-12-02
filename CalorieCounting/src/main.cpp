
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::ifstream inFile("input.txt");

	std::vector<std::string> text;
	std::vector<int> totals;
	std::string line;
	int total = 0;
	while (std::getline(inFile, line, '\n')) {
		if (!line.empty()) {
			total += stoi(line);
		} else if (line.empty()) {
			totals.push_back(total);
			total = 0;
		}
	}
    
	int x = 0;
	for (auto& i : totals) {
		std::cout << "Total Calories of Elf " << x << ": " << i << "\n";
		x++;
	}

	std::sort(totals.begin(), totals.end());
    int top3 = 0;
	for (int i = 0; i <= 2; i++) {
        int max = *std::max_element(totals.begin(), totals.end());
		std::cout << "\n" << max;
        top3 += max;
		totals.pop_back();
	}

    std::cout << "\nTop 3 max: " << top3;

	return 0;
}
