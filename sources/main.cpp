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

	string name = string(argv[1]);
	Result R1(name);
	R1.add();

	return 0;
}
