#include "pch.h"
#include <iostream>
#include <vector>
#include "classMatrix.h"
#include "classLegacyMatrix.h"
#include "classLegacyPrMatrix.h"	

using std::cout;
using std::endl;
using std::cin;


int main()
{
	classMatrix object_1;// , object_2;
	//object.inputAll();
	//object.setOrder()
	int x4[]	{4, 7,
				6, 9};

	int x25[]
	{ 2, 0 , 0, 0, 0,
	   0, 2, 0, 0, 0,
	   0, 0, 2, 0, 0,
	   0, 0, 0, 2, 0,
	   0, 0, 0, 0, 2

	};
	int x9[]{ 11, 12, 13,
			  21, 22, 23,
			  31, 32, 34 };
	int x16[]{  11, 12, 13, 14,
				21, 22, 23, 24,
				31, 32, 33, 34,
				41, 42, 43, 44 };
	int x16_2[]{ -4, -2, -7, 8,
				  2,  7,  4, 9,
				  2,  0,  6,-3,
				  6,  4,-10,-4 };
	
	int x12[]=
	{ 
		 -4, -2, -7, 8,
		 2,  7,  4, 9,
		 2,  0,  6, -3 
	};
	

	object_1.setOrder(4);
	object_1.inputMatrix(x16_2);


	classMatrix object_2(2, x4);
	classMatrix object_3(5, x25);
	classMatrix object_4(4, x16_2);


	classMatrix objectOut_1;
	classMatrix objectOut_2;
	classMatrix objectOut_3;

	int trig;
	bool triger = true;

	while (triger)
	{
		try
		{
			cout << "----------menu------------" << endl
				<< " 1 - create matrix " << endl
				<< " 2 - traspon " << endl
				<< " 3 - deter " << endl
				<< " 4 - show " << endl << endl
				<< " 5 - operator + " << endl
				<< " 6 - operator = " << endl
				<< " 7 - operator () " << endl
				<< " 8 - operator [ ] " << endl << endl
				<< " 9 - cin by '>>' " << endl
				<< " 10 -cout by '<<' " << endl
				<< " 11 -write file by '>>' " << endl
				<< " 12 -read file by '<<' " << endl
				<< " 13 -write binfile " << endl
				<< " 14 -read binfile " << endl << endl
				<< " 15 -legacy 1 " << endl
				<< " 16 -legacy 2 " << endl
				<< " 0 - exit " << endl
				<< "--------------------------" << endl
				<< "put num:  ";
			cin >> trig;
			cout << "-------end of menu--------" << endl << endl;

			switch (trig)
			{
			case 1:
			{
				object_1.inputAll();
				break;
			}
			case 2:
			{
				cout << "transpon" << endl;
				object_1.transponMatrix();
				break;
			}
			case 3:
			{
				object_1.findDeterminant();
				cout << " deter:  " << object_1.getDet() << endl << endl;
				break;
			}
			case 4:
			{
				object_1.showMatrix();

				break;
			}
			case 5:
			{
				std::cout << "-----operator plus------" << std::endl;
				cout << *(&(object_1 + object_2));
				std::cout << "--end of operator plus--" << std::endl;
				break;
			}
			case 6:
			{
				std::cout << " -----operator = -------" << std::endl;
				object_3 = object_1; // + object_2;
				cout << object_3;
				std::cout << " ---end of operator =---" << std::endl;
				break;
			}
			case 7:
			{
				cout << "------- deter by ( ) -------" << endl;
				object_1();
				object_1.showMatrixInfo();
				cout << "----end of deter by ( )-----" << endl;
				break;
			}
			case 8:
			{
				cout << "-------index operator-------" << endl;
				cout << " matrix[ ";
				int i, j;
				cin >> i;
				cin >> j;
				cout << " ]" << endl;
				cout << object_2[i][j] << endl;
				cout << "----end ofindex operator----" << endl;
				break;
			}
			case 9:
			{
				cout << "--------cin by '>>'---------" << endl;
				cin >> object_3;
				cout << "-----end of cin by '>>'-----" << endl;
			}
			case 10:
			{
				cout << "-------cout by '<<'---------" << endl;
				cout << object_2;
				cout << "----end of cout by '<<'-----" << endl;
				break;
			}
			case 11:
			{
				cout << "-----write file by '<<'-----" << endl;
				std::ofstream obj;
				obj.open("text files/dataForClass.txt");
				obj << object_2;
				obj << object_3;
				obj << object_4;
				obj.close();

				cout << "--end of write file by '<<'-" << endl;
				break;
			}
			case 12:
			{
				cout << "------read file by '>>'-----" << endl;
				std::ifstream obj;
				obj.open("text files/dataForClass.txt");
				obj >> objectOut_1;
				obj >> objectOut_2;
				obj >> objectOut_3;
				obj.close();

				cout << "--end of read file by '>>'--" << endl;
				break;
			}
			case 13:
			{
				cout << "-------write binfile--------" << endl;
				std::ofstream obj_of;
				obj_of.open("text files/binaryDataForClass.bin", std::ios::binary | std::ios::in | std::ios::app);

				binWrite(obj_of, object_2);
				binWrite(obj_of, object_3);
				binWrite(obj_of, object_4);

				obj_of.close();
				cout << "----end of write binfile----" << endl;
				break;
			}
			case 14:
			{
				cout << "--------read binfile--------" << endl;
				std::ifstream obj;
				obj.open("text files/binaryDataForClass.bin", std::ios::binary | std::ios::out);

				binRead(obj, objectOut_1);
				binRead(obj, objectOut_2);
				binRead(obj, objectOut_3);

				obj.close();
				cout << "-----end of read binfile----" << endl;
				break;
			}
			case 15:
			{
				classLegacyMatrix *iter = nullptr;
				std::vector<classLegacyMatrix*> buff;
				int trigger = 1,
					count = 0;
				while (trigger)
				{
					std::cout
						<< "1 - create" << std::endl
						<< "2 - Find Det" << std::endl
						<< "3 - Transpon" << std::endl
						<< "4 - Show" << std::endl
						<< "5 - Peek" << std::endl
						<< "6 - Write" << std::endl
						<< "7 - Read" << std::endl
						<< "0 - Back" << std::endl
						<< "----------------------" << std::endl;
					std::cin >> trigger;
					std::cout << "----------------------" << std::endl;
					switch (trigger)
					{
					case 1:
						std::cout << "input order: " << std::endl;
						int order;
						std::cin >> order;
						buff.push_back(new classLegacyMatrix(order));
						iter = buff[count];
						count++;
						break;

					case 2:
						if (iter == nullptr)
						{
							std::cout << "Add object" << std::endl;
							trigger = 0;
						}
						iter->findDeterminant();
						break;

					case 3:
						if (iter == nullptr)
						{
							std::cout << "Add object" << std::endl;
							trigger = 0;
						}
						iter->transponMatrix();
						break;

					case 4:
						if (iter == nullptr)
						{
							std::cout << "Add object" << std::endl;
							trigger = 0;
						}
						iter->showMatrix();
						break;
					case 5:
						std::cout << "total objects: " << count << std::endl
							<< "Peek some one: " << std::endl;
						int choice;
						std::cin >> choice;
						iter = buff[choice];
						iter->showMatrix();
						break;

					case 6:
					{
						cout << "-------write binfile--------" << endl;
						std::ofstream obj_of;
						obj_of.open("text files/class_1/binaryDataForLegacyClass.bin", std::ios::binary | std::ios::in | std::ios::app);
						if (obj_of.is_open())
							for (int i = 0; i < count; i++)
								binWrite(obj_of, *buff[i]);
						else
							std::cout << "writing error" << std::endl;
						obj_of.close();
						cout << "-----end write binfile------" << endl;

						break;
					}
					case 7:
					{
						cout << "--------read binfile--------" << endl;
						std::ifstream obj;
						int readCount;
						std::cout << "How many read: ";
						std::cin >> readCount;
						obj.open("text files/class_1/binaryDataForLegacyClass.bin", std::ios::binary | std::ios::out);
						if (obj.is_open())
							while (readCount != count)
							{
								std::cout << "count: " << count << std::endl;
								buff.push_back(new classLegacyMatrix());
								binRead(obj, *buff[count]);
								buff[count]->showMatrix();
								count++;
							}
						else
							std::cout << "read error" << std::endl;
						obj.close();
						iter = buff[0];
						cout << "-----end of read binfile----" << endl;
						break;
					}
					case 0:
					default:
						break;
					}
				}
				break;
			}

			case 16:
			{
				classLegacyPrMatix *iter = nullptr;
				std::vector<classLegacyPrMatix*> buff;
				int trigger = 1,
					count = 0;
				while (trigger)
				{
					std::cout
						<< "1 - create" << std::endl
						<< "2 - Transpon" << std::endl
						<< "3 - Show" << std::endl
						<< "4 - Peek" << std::endl
						<< "5 - Write" << std::endl
						<< "6 - Read" << std::endl
						<< "0 - Back" << std::endl
						<< "----------------------" << std::endl;
					std::cin >> trigger;
					std::cout << "----------------------" << std::endl;
					switch (trigger)
					{
					case 1:
						buff.push_back(new classLegacyPrMatix());
						iter = buff[count];
						iter->inputAll();
						count++;
						break;

					case 2:
						if (iter == nullptr)
						{
							std::cout << "Add object" << std::endl;
							trigger = 0;
						}
						iter->transponMatrix();
						break;

					case 3:
						if (iter == nullptr)
						{
							std::cout << "Add object" << std::endl;
							trigger = 0;
						}
						iter->showMatrix();
						break;

					case 4:
						std::cout << "total objects: " << count << std::endl
							<< "Peek some one: " << std::endl;
						int choice;
						std::cin >> choice;
						iter = buff[choice];
						iter->showMatrix();
						break;

					case 5:
					{
						cout << "-------write binfile--------" << endl;
						std::ofstream obj_of;
						obj_of.open("text files/class_1/binaryDataForLegacyPrClass.bin", std::ios::binary | std::ios::in | std::ios::app);
						if (obj_of.is_open())
							for (int i = 0; i < count; i++)
								binWrite(obj_of, *buff[i]);
						else
							std::cout << "writing error" << std::endl;
						obj_of.close();
						cout << "-----end write binfile------" << endl;

						break;
					}
					case 6:
					{
						cout << "--------read binfile--------" << endl;
						std::ifstream obj;
						int readCount;
						std::cout << "How many read: ";
						std::cin >> readCount;
						obj.open("text files/class_1/binaryDataForLegacyPrClass.bin", std::ios::binary | std::ios::out);
						if (obj.is_open())
							while (readCount != count)
							{
								std::cout << "count: " << count << std::endl;
								buff.push_back(new classLegacyPrMatix());
								binRead(obj, *buff[count]);
								buff[count]->showMatrix();
								count++;
							}
						else
							std::cout << "read error" << std::endl;
						obj.close();
						iter = buff[0];
						cout << "-----end of read binfile----" << endl;
						break;
					}

					case 0:
					default:
						break;
					}
				}
				break;
			}

			case 0:
			{
				triger = false;
				break;
			}

			}
		}
		catch (exp_mtx &ex) {}
		
	}

	return 0;
}
