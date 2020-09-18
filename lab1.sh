#!/bin/bash

# if [ -n !"$1" ]
# then
# 	echo "Параметр отсутсвует , используйте команду --help|-h"
# 	exit 1
# fi
read word


case $word in

		--help | -h )
			echo "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав"
			echo "Все доступные аргументы: "
			echo -e "\n--help\t-h\tИнформация\n"
			echo "Примеры запуска: "
			echo "--help | -h"
			echo -e "\n--output\t-o\tВывод всех сетевых интерфейсов\n"
			echo "Примеры запуска: "
			echo "--output | -o"
			echo -e "\n--up\t-u\tВключение заданных интерфейсов\n"
			echo "Примеры запуска: "
			echo "--up | -u"
			echo -e "\n--down\t-d\tОтключение заданных интерфейсов заданных интерфейсов\n"
			echo "Примеры запуска: "
			echo "--down | -d"
			echo -e "\n--ip\t-i\tУстановка IP\n"
			echo "Примеры запуска: "
			echo "--ip | -i"
			echo -e "\n--mask\t-m\tУстановка Mask\n"
			echo "Примеры запуска: "
			echo "--mask | -m"
			echo -e "\n--gateway\t-g\tУстановка Gateway\n"
			echo "Примеры запуска: "
			echo "--gateway | -g"
			;;
		--output | -o)
			echo "Вывод всех сетевых интерфейсов: "
			ifconfig
			;;
		--up | -u) 
			echo "Включение заданных интерфейсов: "

esac