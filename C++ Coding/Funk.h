#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <forward_list>
#include <algorithm>

using namespace std;

//9.4
bool iter_search(vector <int>::iterator a, vector <int>::iterator b, int for_search)
{
	vector <int>::iterator curr = a;
	while (curr < b)
	{
		if (*curr == for_search)
			return true;
		curr++;
	}
	return false;
}

//9.5
vector <int>::iterator iter_search_back(vector <int>::iterator a, vector <int>::iterator b, int for_search)
{
	vector <int>::iterator curr = a;
	while (curr < b)
	{
		if (*curr == for_search)
			return curr;
		curr++;
	}
	return vector <int>::iterator();
}

//9.14
void char_to_str(list <const char*> words, vector <string>& str_to_paste)
{
	str_to_paste.assign(words.cbegin(), words.cend());
}

//Technical

template < typename T >
void print_list(list <T> words)
{
	typename list <T>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << " " << *it << " ";
		it++;
	}
	cout << "\n";
}

//void print_list_char(list <const char*> words)
//{
//	list <const char*>::iterator it = words.begin();
//	while (it != words.end())
//	{
//		cout << " " << *it << " ";
//		it++;
//	}
//	cout << "\n";
//}
//
//void print_list_int(list <int> words)
//{
//	list <int>::iterator it = words.begin();
//	while (it != words.end())
//	{
//		cout << " " << *it << " ";
//		it++;
//	}
//	cout << "\n";
//}
//
//void print_list_str(list <string> words)
//{
//	list <string>::iterator it = words.begin();
//	while (it != words.end())
//	{
//		cout << " " << *it << " ";
//		it++;
//	}
//	cout << "\n";
//}

template < typename T > 
void print_vec(vector <T> words)
{
	for (int i = 0; i < words.size(); i++)
	{
		cout << " " << words[i] << " ";
	}
	cout << "\n";
}

//void print_vec_str(vector <string> words)
//{
//	for (int i = 0; i < words.size(); i++)
//	{
//		cout << " " << words[i] << " ";
//	}
//	cout << "\n";
//}
//
//void print_vec_int(vector <int> words)
//{
//	for (int i = 0; i < words.size(); i++)
//	{
//		cout << " " << words[i] << " ";
//	}
//	cout << "\n";
//}

void print_deq_str(deque <string> words)
{
	deque <string>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << " " << *it << " ";
		it++;
	}
	cout << "\n";
}

void print_deq_int(deque <int> words)
{
	deque <int>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << " " << *it << " ";
		it++;
	}
	cout << "\n";
}

void print_fwl_int(forward_list <int> words)
{
	forward_list <int>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << " " << *it << " ";
		it++;
	}
	cout << "\n";
}

void print_fwl_str(forward_list <string> words)
{
	forward_list <string>::iterator it = words.begin();
	while (it != words.end())
	{
		cout << " " << *it << " ";
		it++;
	}
	cout << "\n";
}


//9.15
bool vec_equal(vector <int> v1, vector <int> v2)
{
	if (v1.size() != v2.size())
		return false;
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}

//9.16
bool vec_list_equal(list <int> l1, vector <int> v2)
{
	list <int>::iterator it = l1.begin();
	if (l1.size() != v2.size())
		return false;
	for (int i = 0; i < v2.size(); i++)
	{
		if (*it != v2[i])
			return false;
		it++;
	}
	return true;
}

//9.18
void deq_fill(vector <string> words, deque <string>& fo_fill)
{
	int i = 0;
	deque <string>::iterator d_it = fo_fill.begin();
	for (; d_it < fo_fill.end(); d_it++)
	{
		*d_it = words[i];
		i++;
	}
}

//9.19
void list_fill(vector <string> words, list <string>& fo_fill)
{
	int i = 0;
	list <string>::iterator it = fo_fill.begin();
	while (it != fo_fill.end())
	{
		*it = words[i];
		i++;
		it++;
	}
}

//9.20
void list_from_deqs(list <int> orig, deque <int>& f1, deque <int>& f2)
{
	bool i = 0; //0,2,4,6... - 0
	list <int>::iterator it = orig.begin();
	while (it != orig.end())
	{
		(i) ? f1.push_back(*it) : f2.push_back(*it);
		it++;
		i = !i;
	}
}

//9.24
void vec_at(vector <int> s)
{
	cout << "9.24: At: " << s.at(0) << endl;
	cout << "Front: " << s.front() << endl;
	cout << "Begin: " << *(s.begin()) << endl;
	cout << "[]: " << s[0] << endl;

}

//9.26
void mass_sep(vector <int>& v1, list <int>& l1)
{
	auto l_it = l1.begin();

	while (l_it != l1.end())
		(*l_it % 2) ? l_it = l1.erase(l_it) : l_it++;

	auto it = v1.cbegin();

	while (it != v1.end())
		(!(*it % 2)) ? it = v1.erase(it) : it++;


}

//9.27
void forward_list_del (forward_list <int>& f1)
{
	forward_list <int>::iterator prev = f1.before_begin();
	forward_list <int>::iterator curr = f1.begin();
	while (curr != f1.end())
	{
		if (*curr % 2)
			(curr = f1.erase_after(prev));
		else
		{
			prev = curr;
			curr++;
		}
	}
}

//9.28
void forward_list_search(forward_list <string>& f1, string where_ins, string what)
{
	forward_list <string>::iterator curr = f1.begin();
	while (curr != f1.end())
	{
		if (*curr == where_ins)
		{
			f1.insert_after(curr, what);
			break;
		}
		curr++;
	}
}

//9.41
string v_char_str(vector <char> vec)
{
	string res;
	for (int i = 0; i < vec.size(); i++)
	{
		res.push_back(vec[i]);
	}
	return res;
}

//9.43
string edit_str(string orig, string remove, string paste)
{
	string::iterator curr, start = paste.begin(), stop = paste.end();
	int index = 0;
	while ((index = orig.find(remove, index)) != string::npos)
	{
		curr = orig.begin() + index;
		orig.erase(index, remove.size());
		orig.insert(curr, start, stop);
		index += paste.size();
	}
	return orig;
}

//9.44

string edit_str_replace(string orig, string remove, string paste)
{
	int index = 0, len = remove.size();
	while ((index = orig.find(remove, index)) != string::npos)
	{
		orig.replace(index, len, paste);
	}
	return orig;
}

//10.11

bool isShorter(const string& s1, const string& s2)
{
	return s1.size() < s2.size();
}

void elimdups(std::vector<std::string>& v)
{
	sort(v.begin(), v.end());
	auto EndUnique = unique(v.begin(), v.end());

	v.erase(EndUnique, v.end());
}


//10.12
class Sales
{
public: int id;
public: Sales(int idn): id(idn) {}

	  friend ostream& operator<<(std::ostream& out, const Sales& s);
};
ostream& operator<<(std::ostream& out, const Sales& s)
{
	out << " " << s.id << " ";
	return out;
}

bool compare_class(Sales s1, Sales s2)
{
	return s1.id < s2.id;
}

//10.27
vector <string> unique_dupp(vector <string>& words)
{
	vector <string> res;
	sort(words.begin(), words.end());
	auto un_copy = unique_copy(words.begin(), words.end(),back_inserter(res));
	return res;
}

//10.28
