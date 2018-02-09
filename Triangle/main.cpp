// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>



int main()
{
	int MenuChoice{};
	bool InvalidData{ 0 };

	double a1{};
	double a2{};
	double a3{};
	double s1{};
	double s2{};
	double s3{};
	

	std::cout << "Enter the number corresponding with the triangle type to solve.\n" << std::endl;
	std::cout << "1. AAA\n2. AAS\n3. ASA\n4. SAS\n5. SSA\n6. SSS" << std::endl;
	std::cin >> MenuChoice;

	switch (MenuChoice)
		case 1:
			std::cout << "Enter the values for the first two angles, seperated by a space." << std::endl;
			std::cin >> a1 >> a2;

			if (((a1 + a2) >= 180) || a1 <= 0 || a2 <= 0 || a1 >= 180 || a2 >= 180) InvalidData = 1;
			else
			{
				a3 = 180 - (a1 + a2);
				
				s1 = 1;
				s2 = (sin(a2) / sin(a1));
				s3 = (sin(a3) / sin(a1));

				std::cout << "Angle Values" << std::endl;
				std::cout << "Angle 1: " << a1 << "degrees" << std::endl;
				std::cout << "Angle 2: " << a2 << "degrees" << std::endl;
				std::cout << "Angle 3: " << a3 << "degrees" << std::endl;
				std::cout << "\n\nProportional side length values:" << std::endl;
				std::cout << "Side 1 Length: " << s1 << std::endl;
				std::cout << "Side 2 length: " << s2 << std::endl;
				std::cout << "Side 3 Length: " << s3 << std::endl;

			}
			break;
		default:
			break;
		
		if (InvalidData == 1) std::cout << "Unsolvable." << std::endl;

	return 0;
}

