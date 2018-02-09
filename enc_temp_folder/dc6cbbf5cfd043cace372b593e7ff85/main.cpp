// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>



int main()
{
	int MenuChoice{};
	bool InvalidData{ 0 };

	const double PI{ 3.14159 };
	
	double a1deg{};
	double a2deg{};
	double a3deg{};
	double a1rad{};
	double a2rad{};
	double a3rad{};
	double s1{};
	double s2{};
	double s3{};


	std::cout << "Enter the number corresponding with the triangle type to solve.\n" << std::endl;
	std::cout << "1. AAA\n2. AAS\n3. ASA\n4. SAS\n5. SSA\n6. SSS" << std::endl;
	std::cin >> MenuChoice;

	switch (MenuChoice)
	{
	case 1:
		std::cout << "Enter values between 0 and 180 for the first two angles, seperated by a space." << std::endl;
		std::cin >> a1deg >> a2deg;

		if (((a1deg + a2deg) >= 180) || a1deg <= 0 || a2deg <= 0 || a1deg >= 180 || a2deg >= 180)
		{
			InvalidData = 1;
		}
		else
		{
			a3deg = 180 - (a1deg + a2deg);

			a1rad = ((a1deg * PI) / 180);
			a2rad = ((a2deg * PI) / 180);
			a3rad = ((a3deg * PI) / 180);


			s1 = 1;
			s2 = sin(a2rad)/sin(a1rad); 
			s3 = sin(a3rad)/sin(a1rad); 
			
			std::cout << "Angle Values" << std::endl;
			std::cout << "Angle 1:" << a1deg << " degrees" << std::endl;
			std::cout << "Angle 2:" << a2deg << " degrees" << std::endl;
			std::cout << "Angle 3:" << a3deg << " degrees" << std::endl;
			std::cout << "\n\nSide lengths (Proportions Only)" << std::endl;
			std::cout << "Side 1 Length: " << s1 << std::endl;
			std::cout << "Side 2 length: " << s2 << std::endl;
			std::cout << "Side 3 Length: " << s3 << std::endl;
		}

		break;
	default:
		break;
	}
		if (InvalidData == 1) std::cout << "Unsolvable." << std::endl;

	return 0;
}

