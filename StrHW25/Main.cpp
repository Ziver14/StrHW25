#include<iostream>
#include<string>

template <typename T>
bool palindrom(T variable) {
	bool answer = true;
	
	for (int i = 0; i < variable.length(); i++) 
		variable[i] = std::tolower(variable[i]);
	for (int i = 0; i < variable.length() / 2; i++) 
		if (variable[i] != variable[variable.length() - i - 1])
			answer = false;
	return answer;
}

template<typename T>
int search(T str) {
	int counter = 0;
	char sym[] = { '!',' ',',','?','.' };
	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < sizeof(sym); j++)
			if (str[i] == sym[j])
				counter++;
	return counter;

}

std::string sym_str(std::string str, char sym) {
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym)
			return str.substr(str.rfind(sym));
	str.erase();
	return str;
}



int main() {
	setlocale(LC_ALL, "ru");

	//Задача 1.

	std::string str;
	std::cout << "Введите строку -> ";
	std::getline(std::cin, str);

	std::cout << "Введите символ который есть в строке -> ";
	char sym;
	std::cin >> sym;

	std::string str2;

	for (int i = 0; i < str.length(); i++) {
		if (sym == str[i])
			str2 += sym;
	}
	std::cout << "Новая строка -> " << str2 << std::endl;
	std::cout << "\n\n";

	//Задача 2
	std::cin.ignore();
	std::cout << "Введите строку ->";
	std::getline(std::cin, str);

	palindrom(str);
	if (palindrom(str))
		std::cout << "Строка " << str << " является палиндромом!";
	else
		std::cout << "Строка " << str << " не является палиндромом!";
	std::cout << "\n\n"; 


	//Задача 3
	
	std::cout << "Введите строку -> ";
	std::getline(std::cin, str);
	std::cout << search(str);
	std::cout << "\n\n";


	//Задача 4

	std::cout << "Введите строку -> ";
	std::getline(std::cin, str);
	char sym1;
	std::cout << "Введите символ -> ";
	std::cin >> sym1;
	std::cout << sym_str(str, sym1);

	return 0;
}