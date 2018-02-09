// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>



int main()
{
	int MenuChoice{};
	bool InvalidData{ 0 };
	int SideSelect{};
	int AngleSelect{};

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
	case 1: // AAA Solver
		std::cout << "Enter a value for angle 1 in degrees: " << std::endl;
		std::cin >> a1deg;

		std::cout << "Enter a value for angle 2 in degrees: " << std::endl;
		std::cin >> a2deg;

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

			s2 = (sin(a2rad)/sin(a1rad)); 
			s3 = (sin(a3rad)/sin(a1rad)); 
			
			std::cout << "Angle Values" << std::endl;
			std::cout << "Angle 1:" << a1deg << " degrees" << std::endl;
			std::cout << "Angle 2:" << a2deg << " degrees" << std::endl;
			std::cout << "Angle 3:" << a3deg << " degrees" << std::endl;
			std::cout << "\n\nLength of sides opposite the corresponding angle " << std::endl;
			std::cout << "Side 1 Length: " << s1 << std::endl;
			std::cout << "Side 2 length: " << s2 << std::endl;
			std::cout << "Side 3 Length: " << s3 << std::endl;
		}

		break;

	case 2: // AAS solver
		std::cout << "Enter a value for angle 1 in degrees: " << std::endl;
		std::cin >> a1deg;

		std::cout << "Enter a value for angle 2 in degrees: " << std::endl;
		std::cin >> a2deg;

		std::cout << "Which side do you know the length of (1 or 2)?" << std::endl;
		std::cin >> SideSelect;

		if (SideSelect <= 0 || SideSelect > 2 || (a1deg + a2deg) >= 180 || a1deg <= 0 || a2deg <= 0 || a1deg >= 180 || a2deg >= 180)
		{
			InvalidData = 1;
		}
		else
		{
			std::cout << "Enter a numeric value for the length of the known side: " << std::endl;
			
			switch (SideSelect) // get the appropriate side length from the user
			{
			case 1:
				std::cin >> s1;
				break;
			case 2:
				std::cin >> s2;
				break;
			default:
				break;
			}
	
			a3deg = 180 - (a1deg + a2deg);

			a1rad = ((a1deg * PI) / 180);
			a2rad = ((a2deg * PI) / 180);
			a3rad = ((a3deg * PI) / 180);

			switch (SideSelect)
			{
			case 1:
				s2 = (sin(a2rad) / sin(a1rad))*s1;
				s3 = (sin(a3rad) / sin(a1rad))*s1;
				break;

			case 2:
				s1 = (sin(a1rad) / sin(a2rad))*s2;
				s3 = (sin(a3rad) / sin(a1rad))*s2;
				break;

			default:
				break;
			}

			std::cout << "Angle Values" << std::endl;
			std::cout << "Angle 1:" << a1deg << " degrees" << std::endl;
			std::cout << "Angle 2:" << a2deg << " degrees" << std::endl;
			std::cout << "Angle 3:" << a3deg << " degrees" << std::endl;
			std::cout << "\n\nSide Lengths" << std::endl;
			std::cout << "Side 1 Length: " << s1 << std::endl;
			std::cout << "Side 2 length: " << s2 << std::endl;
			std::cout << "Side 3 Length: " << s3 << std::endl;
		}

	default:
		break;
	}
		if (InvalidData == 1) std::cout << "Unsolvable" << std::endl;

	return 0;
}

