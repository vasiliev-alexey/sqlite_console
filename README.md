# Консольное приложение для работы с SQLLite

Функциональные требования:
1. Работа  с уже созданной БД.
2. Выполнение комманд переданных из файла.
3. Выполнение комманд переданных с консоли.
4. Вывод на дисплей (в первой редакции в консоли результатов, возможен вывод в Файл в будущих версиях)



_Класс main_
Обязаности - является лаунчером для приложения – запускается в консоли.

_Класс ParamsManager_
Обязаности - является вспомогательным классом для проверки и трансформации параметров.



_Класс DBManager_ 
Обязаности -  отвечает за работу с БД SQLLite, зависит от библиотеки sqllite.h

_Класс DisplayManager_
Обязаности -  отвечает за работу с  абстрактным выводом.

_Класс ConsoleManager_
Обязаности -  отвечает за работу с   выводом на консоль, имплиментирует  интерфейс  DisplayManager

_Класс FileOutPutManager_
Обязаности -  отвечает за работу с   выводом в файл, использует FileManager, имплиментирует  интерфейс  DisplayManager

_Класс FileManager_
Обязаности -  отвечает за работу с   файловой системой.

На машине должна быть установлена библиотека для работы  с SQLLite
sudo apt-get install sqlite3 libsqlite3-dev 