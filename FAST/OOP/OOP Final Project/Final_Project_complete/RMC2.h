
#ifndef RMC2_H_
#define RMC2_H_
#include "Headers.h"
#include "Doctor.h"
#include "Patient.h"
#include "App.h"
class RMC2 : public App
{
public:
	RMC2();
	void Dassign();
	void write(int psize, int dsize);
	void Dmenu();
	void Pmenu();
	void viewPlist() 
	{
		for (int i = 0; i < 10; i++)
			cout << Plist[i] << endl;
	}
	void viewDlist() 
	{
		for (int i = 0; i < 5; i++)
			cout << Dlist[i] << endl;
	}
	void Patset();
	void Docset();

	Doctor *&getDlist()
	{
		return Dlist;
	}

	Patient *&getPlist()
	{
		return Plist;
	}
};

#endif /* RMC2_H_ */
