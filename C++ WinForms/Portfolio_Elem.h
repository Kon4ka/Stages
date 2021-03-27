#pragma once
#include <iostream>
#include <string>
#include <fstream>

class P_Elem
{
public:
	std::string id = "\0";
	std::string title = "\0";
	std::string number = "\0";
	std::string cost = "\0";
	std::string payer = "\0";
public:
	P_Elem() {}
	P_Elem(std::string i, std::string t, std::string n, std::string c, std::string p)
	{
		id = i;
		title = t;
		number = n;
		cost = c;
		payer = p;
	}

	void change_info(int i, std::string t, int n, int c, std::string p)
	{
		id = i;
		title = t;
		number = n;
		cost = c;
		payer = p;
	}
	std::string words_to_std_str()
	{
		std::string tmp;
		tmp = id + ". \t " + title + " \t\t" + number + " \t\t" + cost + " \t\t" + payer + "\n";
		return tmp;
	}

	std::string words_to_std_str_file()
	{
		std::string tmp;
		tmp = id + "  " + title + "  " + number + "  " + cost + "  " + payer;
		return tmp;
	}

	bool Name_to_del(std::string ToDelete)
	{
		if (ToDelete == title) return 1;
		else return 0;
	}

	void print_to_file(std::ofstream& file)
	{
		file << (this->words_to_std_str_file()).c_str();
	}
};

//=============== Find Comparators =======================//
bool find_id(P_Elem curr, std::string param)
{
	if (curr.id.rfind(param) == std::string::npos)
		return 0;
	else return 1;
}
bool find_title(P_Elem curr, std::string param)
{
	if (curr.title.rfind(param) == std::string::npos)
		return 0;
	else return 1;
}
bool find_number(P_Elem curr, std::string param)
{
	if (curr.number.rfind(param) == std::string::npos)
		return 0;
	else return 1;
}
bool find_cost(P_Elem curr, std::string param)
{
	if (curr.cost.rfind(param) == std::string::npos)
		return 0;
	else return 1;
}
bool find_payer(P_Elem curr, std::string param)
{
	if (curr.payer.rfind(param) == std::string::npos)
		return 0;
	else return 1;
}

//=============== Sort Comparators =======================//

int comp_id(const void* p1, const void* p2)
{
	P_Elem* a = (P_Elem*)p1;
	P_Elem* b = (P_Elem*)p2;

	if (std::stoi(a->id) > std::stoi(b->id)) return 1;
	else return 0;
}
int comp_title(const void* p1, const void* p2)
{
	P_Elem* a = (P_Elem*)p1;
	P_Elem* b = (P_Elem*)p2;

	if (a->title > b->title) return 1;
	else return 0;
}
int comp_number(const void* p1, const void* p2)
{
	P_Elem* a = (P_Elem*)p1;
	P_Elem* b = (P_Elem*)p2;

	if (std::stoi(a->number) > std::stoi(b->number)) return 1;
	else return 0;
}
int comp_cost(const void* p1, const void* p2)
{
	P_Elem* a = (P_Elem*)p1;
	P_Elem* b = (P_Elem*)p2;

	if (std::stoi(a->cost) > std::stoi(b->cost)) return 1;
	else return 0;
}
int comp_payer(const void* p1, const void* p2)
{
	P_Elem* a = (P_Elem*)p1;
	P_Elem* b = (P_Elem*)p2;

	if (a->payer > b->payer) return 1;
	else return 0;
}
