#include <iostream>



// Normal function
// function to add two numbers
int addNumbers(int a, int b) {
	int sum = a + b;
	return sum;
}

int main2() {
	int num1 = 5, num2 = 10;
	int result = addNumbers(num1, num2); // calling the function
	std::cout << "The sum is: " << result << std::endl;
	return 0;
}



// Function prototypes
int multiplyNumbers(int x, int y);

int main() {
	int num1 = 3, num2 = 7;
	int result = multiplyNumbers(num1, num2); // calling the function
	std::cout << "The product is: " << result << std::endl;
	return 0;
}

int multiplyNumbers(int x, int y) {
	int product = x * y;
	return product;
}



// Lambda functions
// Lambda function with no capture, parameters or return type
auto printHello = []() {
	std::cout << "Hello, World!" << std::endl;
};


// Lambda function with parameters.
auto add = [](int a, int b) {
	return a + b;
};
int result = add(3, 4);


// Lambda function with capture-by-value.
int multiplier = 3;
auto times = [multiplier](int a) {
	return a * multiplier;
	};
int result = times(5); // result = 15

// Lambda function with capture-by-reference
int expiresInDays = 45;
auto updateDays = [&expiresInDays](int newDays) {
	expiresInDays = newDays;
	};
updateDays(30); // expiresInDays = 30