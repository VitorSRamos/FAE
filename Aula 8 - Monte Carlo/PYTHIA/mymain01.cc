#include "Pythia8/Pythia.h"
#include <iostream>
#include <fstream>

using namespace Pythia8;

int main() {
	ofstream MyFile("mu_data.dat");
	
	Pythia pythia;
	
	pythia.readString("Charmonium:all = on");
	pythia.readString("Next:numberShowInfo = 0");
	pythia.readString("Next:numberShowProcess = 0");
	pythia.readString("Next:numberShowEvent = 0");
	pythia.readString("Beams:eCM = 14000");
	
	pythia.init();
	
	for (int iEvent = 0; iEvent < 10000; ++iEvent) {
		pythia.next();
		for (int i = 0; i < pythia.event.size(); ++i){
			if (pythia.event[i].id() == 443){
				cout << "pythia id particle: " << pythia.event[i].id() << endl;
				int d1_n = pythia.event[i].daughter1();
				int d2_n = pythia.event[i].daughter2();
				cout << "d1" << pythia.event[d1_n].id()<<endl;
				cout << "d2" << pythia.event[d2_n].id()<<endl;
				if ( abs(pythia.event[d1_n].id()) == 13 || abs(pythia.event[d2_n].id()) == 13){
					if (pythia.event[d1_n].charge()*pythia.event[d2_n].charge()<0){
					cout << "mu1_pt:" << pythia.event[d1_n].id()<<endl;
					cout << "mu2_pt:" << pythia.event[d1_n].id()<<endl;
					}
				}
				MyFile << pythia.event[d1_n].pT() << " " << pythia.event[d2_n].pT() << endl;
			}				
		}		 
	}
	pythia.stat();
	
	MyFile.close();
		
	return 0;
}
