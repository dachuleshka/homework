#include <iostream>
#define border_1 65 
#define border_2 90 
#define border_3 97 
#define border_4 122 
#define space ' '

class String
{
private:
	char* string;
	int size;
public:
	void memory(int size) {
		string = new char[size];
	}

	char* getReturn()
	{
		return string;
	}

	String(int size_)
	{
		size = size_;
		memory(size);
		std::cout << "Enter a string" << std::endl;
		std::cin >> string;
	}

	void change();

	void outputCodes();

	void insert_symbol();

	int length();

	void concatenation();
	void bigRegister();
	void smallRegister();


	~String()
	{
		delete[] string;
	}
};

void String::change()//предусматривает ТОЛЬКО замену символа, можно заменить существующий символ
{
	int number;
	char symbol;
	do {
		std::cout << "Enter number of the changing symbol in string: ";
		std::cin >> number;
	} while (number == 0 || number > strlen(string));
	do {
		std::cout << "Enter a replacement symbol: ";
		std::cin >> symbol;
	} while (symbol < border_1 || (symbol > border_2 && symbol < border_3) || symbol > border_4);
	string[number - 1] = symbol;
}

void String::outputCodes()
{
	int i = 0;
	while (i < strlen(string)) {
		std::cout << string[i] << " - " << (int)string[i] << std::endl;
		++i;
	}
}

void String::insert_symbol()//Предусматривает вставку символа в любую позицию перед первым, в середине, в конце и т.д.
{
	char* str = string;
	memory(size);
	int number;
	char symbol;
	do {
		std::cout << "Enter the number symbol you want to insert a string: ";
		std::cin >> number;
	} while (number == 0 || number > strlen(string));
	do {
		std::cout << "Enter a replacement symbol: ";
		std::cin >> symbol;
	} while (symbol < border_1 || (symbol > border_2 && symbol < border_3) || symbol > border_4);
	for (int i = 0; i < strlen(string) + 1; ++i) {
		if (i < number - 1)
			string[i] = str[i];
		else if (i == number - 1)
			string[i] = symbol;
		else if (i > number - 1)
			string[i] = str[i - 1];
	}
	string[strlen(str) + 1] = '\0';
	delete[] str;
}

int String::length()
{
	return strlen(string);
}

void String::concatenation()
{
	char* str = string;
	const char* str1 = "Mamama";
	memory(size);
	for (int i = 0; i < (strlen(str) + strlen(str1)); ++i) {
		if (i < (strlen(str)))
			string[i] = str[i];
		else
			string[i] = str1[i - strlen(str)];
	}
	string[strlen(str) + strlen(str1)] = '\0';
}

void String::bigRegister()
{
	int i = 0;
	while (i < strlen(string)) {
		if (string[i] >= border_3 && string[i] <= border_4)
			string[i] = string[i] - space;
		++i;
	}
}

void String::smallRegister()
{
	int i = 0;
	while (i < strlen(string)) {
		if (string[i] >= border_1 && string[i] <= border_2)
			string[i] = string[i] + space;
		++i;
	}
}

int main()
{
	String string(30);
	std::cout << string.getReturn() << std::endl;
	std::cout << "Length of string: " << string.length() << std::endl;
	string.change();
	std::cout << "Change of a string: " << string.getReturn() << std::endl;
	string.concatenation();
	std::cout << "String concatenation: " << string.getReturn() << std::endl;
	string.bigRegister();
	std::cout << "String with big register: " << string.getReturn() << std::endl;
	string.smallRegister();
	std::cout << "String with small register: " << string.getReturn() << std::endl;
	std::cout << "Output codes ASCII: " << std::endl;
	string.outputCodes();
	string.insert_symbol();
	std::cout << "String with the inserted symbol: " << string.getReturn() << std::endl;
	return 0;
}

