//
//  main.cpp
//  CSV_SQL
//
//  Created by Tatane on 17/05/2018.
//  Copyright © 2018 Tatane. All rights reserved.
//

#include "Result.hpp"

int main(int argc, const char * argv[])
{
	bool display;
	char delimiter;
	Result R1;

	if(argc<2)
	{
		cout << "Error : Mandatory arguments absent.\n";
	}
	else
	{
		string name = string(argv[1]);

		if(argc>=3)
			(strcmp(argv[2],"true")==0) ? display=true : display=false;

		if(argc>=4)
			delimiter = *argv[3];

		switch (argc)
		{
			case 2 : R1.make(name);
				break;
			case 3 : R1.make(name, display);
				break;
			case 4 : R1.make(name, display, delimiter);
				break;
		}

		R1.add();
	}

	return 0;
}
