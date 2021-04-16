#pragma once
#include <iostream>
using namespace std;
class TrustedTime
{

	TrustedTime();
	~TrustedTime();
	static TrustedTime* pInstance;
	static void DestroyInstance();
	int				zi;
	int				luna;
	int				an;
	int				minut;
	int				ora;
public:

	static TrustedTime* GetInstance();
	void					afisare_ora();
	int						get_ora() { return ora; };
	int						get_zi() { return zi; };
	int						get_luna() { return luna; };
	int						get_an() { return an; };
	void					adauga_ore();
	string					get_ora_exacta();
	string					get_time();
};
