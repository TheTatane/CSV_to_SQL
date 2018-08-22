//
//  Result.cpp
//  CSV_SQL
//
//  Created by Tatane on 17/05/2018.
//  Copyright © 2018 Tatane. All rights reserved.
//

#include "Result.hpp"

Result::Result()
{

}

Result::Result(string csv) : _CSVname(csv), _nbElements(0)
{
	init_config();
	cout << "Starting creation of the object result..."<<endl;
	displayTab();
	concat();
}

Result::~Result() { }

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
	cout <<"Recupération du fichier config..."<<endl;
	string line;
	string champ;
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
	{
		if(i+1==_tabChamp.size())
			_contatChamp+=_tabChamp[i];
		else
			_contatChamp+=_tabChamp[i]+",";
	}
	_contatChamp+=")";
}

void Result::add()
{
	//cout<<"Debut de la convertion ...\n";
	//cout<<"chaine concat: "<<_contatChamp<<endl;
	string ligneN;
	string ligneF;
	string champ;
	string id;
	bool okFirst;
	ifstream fichier(_CSVname+".txt", ios::in | ios::binary);

	while (getline(fichier,ligneN))
	{
		okFirst=true;
		istringstream fic2(ligneN);
		while (getline(fic2,champ,',') && okFirst && _systemOK)
		{
					//cout << champ<<endl;
			okFirst=false;
			id=champ;
		}
		ligneF+=ligneN;
		_resul+="\n INSERT IGNORE INTO "+_tabChamp[0]+""+_contatChamp+"VALUES ("+ligneF+");";
		/*	if (_systemOK)
				_resul+="\n UPDATE "+_tabChamp[0]+" SET last_int_dt=\""+_date+"\" WHERE system_id="+id+";";*/
			ligneF="";
	}

	ofstream fichierOut(""+_CSVname+"_INSERT.sql", ios::out);
	fichierOut << _resul;
	fichier.close();

	//cout<<"Convertion terminé ...\n";

}
