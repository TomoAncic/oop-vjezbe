#include <iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;

int ponavljanje(string& str1, string& str2)
{
	int br = 0;
	int nastavak = 0;
	while ((nastavak = str1.find(str2, nastavak)) != string::npos)
	{
		br++;
		nastavak += str2.length();
	}
	return br;
}

void ispravak(string& s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && s[i + 1] == ',')
		{
			char temp = s[i];
			s[i] = s[i + 1];
			s[i + 1] = temp;
		}
	}
}

vector<string> sortiranje()
{
	vector<string> vektor_stringova;
	string unos;

	cout << "Unesi string" << endl;
	while (true)
	{
		getline(cin, unos);
		if (unos.empty())
		{
			break;
		}
		else
		{
			vektor_stringova.push_back(unos);
		}
	}
	for (string& a : vektor_stringova)
	{
		reverse(a.begin(), a.end());
	}
	sort(vektor_stringova.begin(), vektor_stringova.end());
	return vektor_stringova;
}

bool provjera(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void prijevod(string& str)
{
	string prijevod;
	string rijec;

	for (char a : str)
	{
		if (isalpha(a))
		{
			rijec.push_back(a);
		}
		else {
			if (!rijec.empty())
			{
				string suglasnici;
				int i = 0;
				while (i < rijec.length() && !provjera(rijec[i]))
				{
					suglasnici.push_back(rijec[i]);
					i++;
				}
				if (provjera(rijec[0]))
				{
					prijevod += rijec + "hay";
				}
				else {
					prijevod += rijec.substr(i) + suglasnici + "ay";
				}
				rijec.clear();
			}
			prijevod += a;
		}
	}
	str = prijevod;
}

int main()
{
	string str1 = "ovo ono ovo ono ovo";
	string str2 = "ovo";
	string str3 = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno.";
	string str4 = "What time is it?";

	//int a = ponavljanje(str1, str2);
	//cout << "Broj ponavljanja: " << a << endl;

	//ispravak(str3);
	//cout << str3 << endl;

	//vector<string> str = sortiranje();
	//for (string& a : str)
	//{
	//	cout << a << endl;
	//}

	prijevod(str4);
	cout << str4 << endl;

}
