//
//  Resultat.hpp
//  CSV_SQL
//
//  Created by Tatane on 17/05/2018.
//  Copyright © 2018 Tatane. All rights reserved.
//

#ifndef Result_hpp
#define Result_hpp

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

class Result
{
private:

	vector<string>_tabChamp;
	int _nbElements;
	string _resul;
	string _tableName;
	string _CSVname;
	string _configName;
	string _contatChamp;
	string _date;
	bool _systemOK;

public:

	Result();
	Result(string csv);
	~Result();
	void add();
	void init_date();
	void init_config();
	void concat();
	void displayTab() const;
};

#endif /* Result_hpp */
