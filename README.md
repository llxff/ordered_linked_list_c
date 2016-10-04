# Контрольная работа 2

[![Build Status](https://travis-ci.org/llxff/ordered_linked_list_c.svg?branch=master)](https://travis-ci.org/llxff/ordered_linked_list_c)

Разработать программу для реализации основных действий с упорядоченным динамическим списком

### Описание задачи

Разработать программу для реализации основных действий с упорядоченным динамическим списком:

- проход по списку с выводом на экран информационных частей элементов
- поиск элемента с заданной информационной частью
- добавление нового элемента
- удаление заданного элемента.

Все действия оформляются как подпрограммы.

Программная реализация выполняется в среде Windows в виде консольного или оконного приложения. Язык программирования Delphi или C/C++.

### Реализация

Я выполнил задачу с использованием языка C и компилятора gcc.

### Список методов

`OLList *ollist_new_list()` - создание структуры списка.

`OLLEntry *ollist_new_entry(int value)` - создание элемента списка с информационной частью (я выбрал тип `int`).

`void ollist_inspect(OLList *list)` - вывод информации о списке.

`void ollist_append(OLList *head, OLLEntry *entry)` - добавить элемент в список.

`OLLEntry *ollist_search(OLList *list, int guess)` - поиск элемента списка с заданной информационной частью.

`void ollist_remove(OLList *list, OLLEntry *entry)` - удалить элемент из списка.

`OLLEntry *ollist_shift(OLList *list)` - удалить первый элемент из списка.

### Запуск

Мной так же реализовано 3 задачи:

`make` - сборка исполняемого файла в `bin/main`.

`make run` - сборка и запуск исполняемого файла.

`make tests` - запуск юнит тестов.

### Демонстрация работы программы

[![asciicast](https://asciinema.org/a/818u929yiky1lzf8m6hih46uz.png)](https://asciinema.org/a/818u929yiky1lzf8m6hih46uz)

### Демонстрация запуска тестов

[![asciicast](https://asciinema.org/a/514s8w2kioj74gyzmgjc366nr.png)](https://asciinema.org/a/514s8w2kioj74gyzmgjc366nr)
