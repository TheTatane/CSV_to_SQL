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
	char _delimiter;
	bool _table_arg_ok;
	bool _display;

public:

	Result();
	~Result();
	void make(string csv);
	void make(string csv, bool display);
	void make(string csv, bool display, char delimiter);
	void add();
	void init();
	void init_date();
	void init_config();
	void concat();
	void displayTab() const;
};

#endif /* Result_hpp */
