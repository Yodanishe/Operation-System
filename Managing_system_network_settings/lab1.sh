#!/bin/bash

echo "Введите команду, для справки используйте --help | -h"

while [[ true ]]; do
	read word
	case $word in

		--help | -h )
				echo "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав"
				echo "Все доступные аргументы: "
				echo -e "\nИнформация\n"
				echo "Примеры запуска: "
				echo "--help | -h"
				echo -e "\nВывод всех сетевых интерфейсов\n"
				echo "Примеры запуска: "
				echo "--output | -o"
				echo -e "\nВключение заданных интерфейсов\n"
				echo "Примеры запуска: "
				echo "--up | -u"
				echo "lo"
				echo -e "\nОтключение заданных интерфейсов заданных интерфейсов\n"
				echo "Примеры запуска: "
				echo "--down | -d"
				echo "lo"
				echo -e "\nУстановка IP\n"
				echo "Примеры запуска: "
				echo "--ip | -i "
				echo "lo 	127.0.0.1"
				echo -e "\nУстановка Mask\n"
				echo "Примеры запуска: "
				echo "--mask | -m"
				echo "lo 	255.0.0.0"
				echo -e "\nУстановка Gateway\n"
				echo "Примеры запуска: "
				echo "--gateway | -g"
				echo "192.168.0.1 	lo"
				echo -e "\nСтатистика использования трафика\n"
				echo "Примеры запуска: "
				echo "--stat | -s"
				echo -e "\nКарта сети\n"
				echo "Примеры запуска: "
				echo "--nmap | -n"
				echo "localhost"
				echo -e "\nВыход\n"
				echo "Примеры запуска: "
				echo "--quit| -q"
			;;
		--output | -o)
				echo "Вывод всех сетевых интерфейсов: "
				ip a
			;;
		--up | -u) 
				echo "Включение заданных интерфейсов "
				echo "Введите нужный интерфейс(для выхода ввиде q): "
				while [[ $interface != "q" ]]; 
				do	
					read interface
					sudo ip link set ${interface} up
					ip link ls up
				done
			;;
		--down | -d) 
				echo "Отключение заданных интерфейсов "
				echo "Введите нужный интерфейс(для выхода ввиде q): "
				while [[ ${interface} != "q" ]]; do
					read interface
					sudo ip link set ${interface} down
					ip link ls up
				done
			;;
		--ip | -i)
				echo "Установка IP"
				echo "Введите IP-адрес и интерфейс которые нужно установить"
				ip link ls
				read interface
				read ip_address
				sudo ip a add ${ip_address} dev ${interface}
			;;
		--mask | -m)
				echo "Установка Mask"
				echo "Введите "
				read interface
				read mask
				sudo ifconfig ${interface} netmask ${mask}
			;;
		--gateway | -g)
				echo "Установка Gateway"
				echo "Введите адрес шлюза и интерфейс, которые нужно установить"
				read interface
				read gate_address
				sudo route add default gw ${gate_address} ${interface}
			;;
		--stat | -s) 
				echo "Статистика использования трафика"
				cat /proc/net/dev
			;;
		--nmap | -n)
				echo "Карта сети"
				echo "Введите сеть"
				read target
				nmap -A ${target}
			;;
		--quit | -q) 
				echo "Выход"
				exit;
	esac	
done

# Егор Алексеевич