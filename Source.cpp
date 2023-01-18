#include "Trie.h"
#include <iostream>
#include <string>
int main()
{
	setlocale(LC_ALL, "");
	struct TrieNode* root = getNewNode();
	std::string words[] = {"meet", "metal", "metallica", 
		"drive", "drum", "drummer",
		"end", "engine", "engineer"};
	for (auto& w : words)
		insert(root, w);
	bool exit = false;
	char operation;
	int res;
	std::string prefix;
	while (!exit)
	{
		bool Valid = true;
		std::cout << "Выберите операцию: " << std::endl;
		std::cout << "1 - Введите слово: " << std::endl;
		std::cout << "2 - Выход" << std::endl;
		std::cin >> operation;
		switch (operation)
		{
		case '1':
			std::cout << "Введите префикс:" << std::endl;
			std::cin >> prefix;
			for (size_t i = 0; i < prefix.length(); i++)
			{
				if (prefix[i] < 'a' || prefix[i] > 'z')
				{
					std::cout << "Не верно введен префикс. Попробуйте еще раз." << std::endl;
					Valid = false;
					break;
				}
			}
			if (Valid)
			{
				std::cout << "Автозаполнение" << std::endl;
				res = findWordbyPref(root, prefix);
				if (res == 0)
					std::cout << "Других слов с этим префиксом не найдено" << std::endl;
				else if (res == -1)
					std::cout << "Не найдено слов" << std::endl;
			}
			break;
		case '2':
			exit = true;
			break;
		default:
			std::cout << "Неверный код операции! Пробовать снова." << std::endl;
			break;
		}
	}
	return 0;
}