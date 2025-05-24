#include <iostream>
#include <string>
//Основная функция
int maint()
{
	std::string name;//Переменная которая хранит имя пользователя
	std::cout<<"ВВедите свое имя";//Запрос имени
	std::cin>>name;//Ввод имени пользователя
	std::cout<<"Hello world from:"<<name<<std::endl;//Вывод сообщения
	return 0;
}

