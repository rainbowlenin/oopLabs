// list.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "pch.h"
#include "Queue.h"
#include "QueueElement.h"
#include "Queue.h"
#include <iostream>
#include <fstream>

int main()
{
	std::cout << "Queue size" << std::endl;
	int q_size;
	std::cin >> q_size;
	Queue *list = new Queue(q_size);
	
	int choice = 1;
	
	while ( choice )
	{
		std::cout << "------------menu------------" << std::endl
			<< " 1 - add _list type QE " << std::endl
			<< " 2 - add second type QE " << std::endl
			<< " 3 - del last elm " << std::endl
			<< " 4 - del by index " << std::endl
			<< " 5 - find by num " << std::endl
			<< " 6 - show elm by index " << std::endl
			<< " 7 - show full " << std::endl
			<< " 8 - write" << std::endl
			<< " 9 - read" << std::endl
			<< " 0 - exit" << std::endl 
			<< "----------------------------" << std::endl;
		std::cin >> choice;
		std::cout << "--------end of menu---------" << std::endl;

		switch ( choice )
		{
			case 1: 
			{
				QueueElement *elm_1 = new QueueElement;
				std::cout << " input num: ";
				int num;
				std::cin >> num;
				list->Add(elm_1, num);

				break;
			}
			case 2:
			{
				QueueElementChild *elm_2 = new QueueElementChild;
				std::cout << " input num: ";
				int num;
				std::cin >> num;
				list->Add(elm_2, num);
				break;
			}
			case 3:
			{
				list->Del();
				break;
			}
			case 4:
			{
				int num;
				std::cin >> num;
				list->DelByIndex( num );
				break;
			}
			case 10:
			{
				QueueElement *elm_1 = new QueueElement;
				int num, index;
				std::cin >> num;
				std::wcin >> index;
				list->AddByIndex(elm_1, index, num);
				break;
			}
			case 5:
			{
				std::cout << " input num to find: ";
				int num;
				std::cin >> num;
				int *arr = list->Find(num);
				for( int i = 0; i < arr[0]; i++)
					list->ShowElement(arr[i+1]);
				break;
			}
			case 6:
			{
				int num;
				std::cout << "Input index: " << std::endl;
				std::cin >> num;
				list->ShowElement( num );
				break;
			}
			case 7:
			{
				list->ShowFull();
				break;
			}
			case 8:
			{
				std::ofstream stream("cl.bin");
				binWrite(stream, list);
				break;
			}
			case 9:
			{
				std::ifstream stream("cl.bin");
				binRead(stream, list);
				break;
			}
			default:
				break;
		}
	}

	return 0;
}

