README
# Lab02
```Лабораторная работа №2```

**Часть 1**

   1. Создание пустого репозитория на GitHub.
   
```Создал пустой репозиторий репозиторий```

   2. Первый коммит(через терминал).
```Повторил предложенные команды и в облачном репозитории появился первый комит с файлом README.md```
   3. Создание файла hello_world.cpp.
```В той же папке репозитория создал файл:nano hello_world.cpp```

Вставил следующий код с плохим стилем:

```
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
```

4. Добавил файл в репозиторий

```git add hello_world.cpp```

5. Создал коммит изменения

```git commit -m "Код с плохим стилем"```

6. Изменение программы (удаление usingnamespace, уже заметил после выполнение что нужно делать это во второй части)

``Отредактировал файл: nano hello_world.cpp```

Изменил код на:

```
#include <iostream>

int main() {
    std::cout << "Hello world from " << std::endl;
    return 0;
}
```

7. Коммит изменений без git add

```
git commit -a -m Убрал usingnamespace std
```

Почему не нужно снова делать git add? Потому что флаг -a в git commit -a автоматически добавляет все измененные отслеживаемые файлы перед коммитом. Файл hello_world.cpp уже был добавлен в репозиторий ранее (на шаге 4), поэтому git знает о нем и может автоматически включить изменения.

8. Отправка изменений на GitHub

```git push```

9. Проверка истории коммитов

```git log --oneline```

![image](https://github.com/user-attachments/assets/2dd20f43-922e-4ec0-abdc-9877d55285ef)

**Часть2**

1. Создание локальной ветки patch1

```cd ~/projects/hello-world-cpp```
```git checkout -b patch1```

2. Исправление кода (Добавил имя пользователя)
   
Открыл файл hello_world.cpp в редакторе:

```nano hello_world.cpp```
Изменил код на:

```
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Введите имя пользователя: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

3. Коммит и пуш изменений в ветке patch1

```
git add hello_world.cpp
git commit -m "Добавил ввод имени пользователя"
git push -u origin patch1  # -u устанавливает upstream ветку
```
4. Проверка доступности ветки на GitHub
```
Нажмал на список "Branch: main"
Убедился, что в списке есть ветка "patch1"
```

5. Создание Pull Request (patch1 → main)

Создал pull Request

6. Добавление комментариев в код (в ветке patch1)

```nano hello_world.cpp```

Добавил комментарии:

```
#include <iostream>
#include <string>

// Основная функция, которая приветствует пользователя
int main() {
    std::string name;  // Переменная для хранения имени пользователя
    std::cout << "Enter your name: ";// Запросить у пользователя ввод данных
    std::cin >> name; //Ввод имени
    std::cout << "Hello world from " << name << std::endl; // Вывод приветственного сообщения
    return 0;
}
```

7. Коммит и пуш изменений с комментариями

```
git add hello_world.cpp
git commit -m "Добавил комментарии"
git push
```

8. Проверка обновлений в Pull Request

```
Убедился, что новые изменения появились в PR
```

9. Слияние PR и удаление ветки patch1 на GitHub

```
Подтвердил слияние
```

10. Локальное обновление (pull)

```
git checkout main
git pull
```

11. Просмотр истории коммитов

```
git log --oneline --graph
```

12. Удаление локальной ветки patch1

```
git branch -d patch1
git branch -D patch1
```

Часть 3

1. Создание новой локальной ветки patch2

```
git checkout main
git checkout -b patch2
```

2. Изменение code style с помощью clang-format

```
sudo apt-get install clang-format
```

Применил форматирование:

```
clang-format -style=Mozilla -i hello_world.cpp
git diff
```

3. Коммит и пуш изменений, создание Pull Request

```
git add hello_world.cpp
git commit -m "Переформатировал код"
git push -u origin patch2
```

Создал Pull Request на GitHub:

4. Изменение комментариев в ветке main на GitHub

Изменил комментарии (перевел на английский):

```
// Main function that greets the user
// Variable to store user's name
// Prompt user for input
// Output greeting message
```
5. Проверка конфликтов в Pull Request

6. Решение конфликтов локально (pull + rebase)

```
git fetch origin
git rebase origin/main
```

Во время rebase возникнут конфликты. Исправим их:

```
nano hello_world.cpp
```

Вручную объединим изменения, сохранив:
Новое форматирование из patch2
Новые комментарии из main
Сохраним файл и добавим его:

```
git add hello_world.cpp
```

Продолжим rebase:

```
git rebase --continue
```

7. Force push в ветку patch2

```
git push -f origin patch2
```

8. Проверка отсутствия конфликтов в Pull Request

Убедился, что сообщение о конфликтах исчезло
Проверил, что изменения содержат:
Новое форматирование (Mozilla style)
Обновленные комментарии


9. Слияние Pull Request

```
На странице Pull Request нажал "Merge pull request"
Подтвердил слияние
Нажал "Delete branch" для удаления patch2 на GitHub
```
