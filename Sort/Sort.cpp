#include <iostream>
#include <vector>
#include <string>

using namespace std;


void printArray(string text, vector<int> arr) {
	cout << text << endl;
	for (int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << " ";
	}
	cout << endl << endl;;
}


vector<int> getNumbersArray(int count) {
	vector<int> input;
	bool end = false;
	for (int i = 0; i < count; i++) {
		int number;
		cin >> number;
		input.push_back(number);
	}

	return input;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

vector<int> bubbleSort(vector<int> input, bool reverse) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = i + 1; j < input.size(); j++) {
			int *a = &input.at(i);
			int *b = &input.at(j);
			if (!reverse && *a > *b) {
				swap(a, b);
			}
			else if (reverse && *a < *b) {
				swap(a, b);
			}
		}
	}

	return input;
}

vector<int> shakerSort(vector<int> input, bool reverse) {
	int left = 0;
	int right = input.size() - 1;

	while (left <= right) {
		for (int i = left; i < right; i++) {
			int *a = &input.at(i);
			int *b = &input.at(i + 1);

			if (!reverse && *a > *b) {
				swap(a, b);
			}
			else if (reverse && *a < *b) {
				swap(a, b);
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			int *a = &input.at(i-1);
			int *b = &input.at(i);

			if (!reverse && *a > *b) {
				swap(a, b);
			}
			else if (reverse && *a < *b) {
				swap(a, b);
			}
		}
		left++;
	}

	return input;
}

vector<int> combSort(vector<int> input, bool reverse) {
	int step = int(input.size() / 1.247);
	int i = 0, j = i + step;
	while (j - i > 1) {
		i = 0, j = i + step;
		while (j < input.size()) {
			int *a = &input.at(i++);
			int *b = &input.at(j++);
			if (!reverse && *a > *b) {
				swap(a, b);
			}
			else if (reverse && *a < *b) {
				swap(a, b);
			}
		}
		step /= 1.247;
	}

	return input;
}

vector<int> insertionSort(vector<int> input, bool reverse) {
	for (int i = 2; i < input.size(); i++) {
		for (int j = i; j > 0 && ((!reverse && input.at(j - 1) > input.at(j)) || (reverse && input.at(j - 1) < input.at(j))); j--) {
			swap(&input.at(j), &input.at(j - 1));
		}
	}

	return input;
}

int main()
{
	int count;
	cin >> count;

	vector<int> numbers = getNumbersArray(count);
	printArray("Input: ", numbers);

	vector<int> forwardBubbleSort = bubbleSort(numbers,false);
	printArray("Forward bubble sort: ", forwardBubbleSort);
	vector<int> reverseBubbleSort = bubbleSort(numbers, true);
	printArray("Reverse bubble sort: ", reverseBubbleSort);

	vector<int> forwardShakerSort = shakerSort(numbers, false);
	printArray("Forward shaker sort: ", forwardShakerSort);
	vector<int> reverseShakerSort = shakerSort(numbers, true);
	printArray("Reverse shaker sort: ", reverseShakerSort);

	vector<int> forwardCombSort = combSort(numbers, false);
	printArray("Forward comb sort: ", forwardCombSort);
	vector<int> reverseCombSort = combSort(numbers, true);
	printArray("Reverse comb sort: ", reverseCombSort);

	vector<int> forwardInsertionSort = insertionSort(numbers, false);
	printArray("Forward insertion sort: ", forwardInsertionSort);
	vector<int> reverseInsertionSort = insertionSort(numbers, true);
	printArray("Reverse insertion sort: ", reverseInsertionSort);
	return 0;
}
