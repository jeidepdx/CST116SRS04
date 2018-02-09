// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
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
	double a1deg_alt{};
	double a2deg_alt{};
	double a3deg_alt{};
	double a1rad{};
	double a2rad{};
	double a3rad{};
	double s1{0};
	double s2{0};
	double s3{0};


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

			//calculate proportional side length values for the AAA case
			s1 = 1;
			s2 = (sin(a2rad)/sin(a1rad)); 
			s3 = (sin(a3rad)/sin(a1rad)); 
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

			if ((s1 + s2) <= 0) InvalidData = 1;

			a3deg = 180 - (a1deg + a2deg);

			a1rad = ((a1deg * PI) / 180);
			a2rad = ((a2deg * PI) / 180);
			a3rad = ((a3deg * PI) / 180);

			switch (SideSelect) // calculating side lengths based on which side the user input the data for
			{
			case 1:
				s2 = (sin(a2rad) / sin(a1rad))*s1;
				s3 = (sin(a3rad) / sin(a1rad))*s1;
				break;

			case 2:
				s1 = (sin(a1rad) / sin(a2rad))*s2;
				s3 = (sin(a3rad) / sin(a2rad))*s2;
				break;

			default:
				break;
			}
		}
		break;

	case 3: // ASA solver
		std::cout << "Enter a value for angle 1 in degrees: " << std::endl;
		std::cin >> a1deg;

		std::cout << "Enter a value for angle 2 in degrees: " << std::endl;
		std::cin >> a2deg;

		std::cout << "Enter a value for the length of the side between angle 1 and angle 2: " << std::endl;
		std::cin >> s3; // side 3 connects angle 1 and 2.

		if (s3 <= 0 || (a1deg + a2deg) >= 180 || a1deg <= 0 || a2deg <= 0 || a1deg >= 180 || a2deg >= 180)
		{
			InvalidData = 1;
		}
		else
		{
			a3deg = 180 - (a1deg + a2deg);

			a1rad = ((a1deg * PI) / 180);
			a2rad = ((a2deg * PI) / 180);
			a3rad = ((a3deg * PI) / 180);

			s1 = (sin(a1rad) / sin(a3rad))*s3;
			s2 = (sin(a2rad) / sin(a3rad))*s3;
		}
		break;

	case 4: // SAS solver
		std::cout << "Enter a value for the length of side 1: " << std::endl;
		std::cin >> s1;

		std::cout << "Enter a value for the length of side 2 " << std::endl;
		std::cin >> s2;

		std::cout << "Enter a value for the angle between side 1 and side 2 in degrees: " << std::endl;
		std::cin >> a3deg; // angle 3 is the angle between sides 1 and 2

		if (s1 <=0 || s2 <= 0 || a3deg <= 0 || a3deg >= 180)
		{
			InvalidData = 1;
		}
		else
		{
			a3rad = ((a3deg * PI) / 180);

			double RootToFind{ (s1 * s1) + (s2 * s2) - ((2 * s1 * s2) * cos(a3rad)) };
			s3 = sqrt(RootToFind);
			
			double sina3{ sin(a3rad) };
			if (s1 < s2) // finding the smaller side to make sure asin() returns valid data. If they are equal length it does not matter.
			{
				double sina1{ (s1*sina3) / s3 };
				a1rad = asin(sina1);
				a1deg = (a1rad * 180) / PI;
				a2deg = 180 - (a1deg + a3deg); // a2rad not calculated because it is not needed in this case
			}
			else // s2 must be greater than s1 or the sides are equal length.
			{
				double sina2{ (s2*sina3) / s3 };
				a2rad = asin(sina2);
				a2deg = (a2rad * 180) / PI;
				a1deg = 180 - (a2deg + a3deg); // a1rad not calculated because it is not needed in this case
			}

		}
		break;

	case 5: // SSA solver
		std::cout << "Enter a value for the length of side 1: " << std::endl;
		std::cin >> s1;

		std::cout << "Enter a value for the length of side 2 " << std::endl;
		std::cin >> s2;

		std::cout << "Which side do you know the value of the opposing angle for (1 or 2)?" << std::endl;
		std::cin >> SideSelect;

		if (SideSelect <= 0 || SideSelect > 2 || s1 <= 0 || s2 <=0)
		{
			InvalidData = 1;
		}
		else
		{
			std::cout << "Enter a numeric value between 0 and 180 degrees for the known angle: " << std::endl;

			switch (SideSelect) // get the angle for the appropriate side from the user
			{
			case 1:
				std::cin >> a1deg;
				a1rad = (a1deg * PI) / 180;

				double sina2{ (s2 * sin(a1rad)) / s1 };

				a2rad = asin(sina2);
				a2deg = (a2rad * 180) / PI;
				a2deg_alt = (180 - a2deg);

				break;

			case 2:
				std::cin >> a2deg;
				a2rad = (a2deg * PI / 180);

				double sina1{ (s1 * sin(a2rad)) / s2 };

				a1rad = asin(sina1);
				a1deg = (a1rad * 180) / PI;
				a1deg_alt = (180 - a1deg);


				break;

			default:
				break;
			}

			if ((a1deg + a2deg) <= 0) InvalidData = 1; // check if the user entered a negative value

			// START HERE.
			// NEED ALTERNATE VALUES FOR THE OTHER ANGLES.
			// GET SIDE CALCULATIONS FROM ABOVE,
			// DONT FORGET TO CALCULATE ALTERNATE SIDE LENGTH FOR THE ALTERNATE ANGLE DUE TO SIN-1.


		}
	default:
		break;
	}

	if (InvalidData == 1)
	{
		std::cout << "Unsolvable" << std::endl;
	}

	else
	{
		std::cout << "Angle Values" << std::endl;
		std::cout << "Angle 1: " << a1deg << " degrees" << std::endl;
		std::cout << "Angle 2: " << a2deg << " degrees" << std::endl;
		std::cout << "Angle 3: " << a3deg << " degrees" << std::endl;
		std::cout << "\n\nLength of sides opposite the corresponding angle: " << std::endl;
		if (MenuChoice == 1) std::cout << "Note: For the AAA case, side lengths are proportional values only." << std::endl;
		std::cout << "Side 1 Length: " << s1 << std::endl;
		std::cout << "Side 2 length: " << s2 << std::endl;
		std::cout << "Side 3 Length: " << s3 << std::endl;
	}
	return 0;
}

