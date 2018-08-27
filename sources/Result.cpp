//
//  Result.cpp
//  CSV_SQL
//
//  Created by Tatane on 17/05/2018.
//  Copyright © 2018 Tatane. All rights reserved.
//

#include "Result.hpp"

Result::Result() : _nbElements(0) { }

Result::~Result() { }

void Result::make(string csv)
{
	_CSVname=csv;
	init();
}

void Result::make(string csv, bool display)
{
	_CSVname=csv;
	_display=display;
	init();
}

void Result::make(string csv, bool display,  char delimiter)
{
	_CSVname=csv;
	_display=display;
	_delimiter=delimiter;
	init();
}

void Result::init()
{
	init_config();
	if(_display)
	{
		cout << "Starting creation of the object result..."<<endl;
		displayTab();
	}
	concat();
}

void Result::init_date()
{
	char format[12];

	time_t temps;
	struct tm date;

	time(&temps);
	date=*localtime(&temps);

	strftime(format, 12, "%Y-%m-%d", &date);
	_date=format;
}

void Result::init_config()
{
	if(_display)
		cout <<"Recupération du fichier config..."<<endl;

	string line, champ;
	bool okEnd=true,okFirst=true;
	int cpt=0;
	ifstream(fic2);
	ifstream fic("config.txt", ios::in | ios::binary);
	if(fic)
	{
		while (getline(fic,line)&&okEnd)
		{
			cpt=0;
			okFirst=true;
			istringstream fic2(line);
			while (getline(fic2,champ,',')&&okFirst)
			{
				if(cpt==0)
				{
					if (champ.compare(_CSVname)!=0)
						okFirst=false;
					else if (champ.compare(_CSVname)==0)
						okEnd=false;
				}

				if(okFirst)
				{
					_tabChamp.insert(_tabChamp.begin()+_nbElements,champ);
					_nbElements++;
					cpt++;
				}
			}
		}
	}
	else
		cout <<"Erreur ouverture fichier...";
}

void Result::displayTab() const
{
	for(int i = 0; i < _tabChamp.size(); i++)
    cout << _tabChamp[i] << endl;
}

void Result::concat()
{
	_contatChamp+="(";
	for(int i = 1; i < _tabChamp.size(); i++)
		(i+1==_tabChamp.size()) ?	_contatChamp+=_tabChamp[i] : _contatChamp+=_tabChamp[i]+",";
	_contatChamp+=")";
}

void Result::add()
{
	if(_display)
	{
		cout<<"Debut de la convertion ...\n";
		cout<<"chaine concat: "<<_contatChamp<<endl;
	}

	string lineTemp,lineFinal;
	ifstream fichier(_CSVname+".txt", ios::in | ios::binary);

	while (getline(fichier,lineTemp))
	{
		lineFinal+=lineTemp;
		_resul+="\n INSERT INTO "+_tabChamp[0]+""+_contatChamp+"VALUES ("+lineFinal+");";
		lineFinal="";
	}

	ofstream fichierOut(""+_CSVname+"_INSERT.sql", ios::out);
	fichierOut << _resul;
	fichier.close();

		cout<<"Done.\n";

}
