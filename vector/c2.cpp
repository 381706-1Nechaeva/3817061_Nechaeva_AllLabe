#include <iostream>

#include "vector.h"

int main()
{
	//TVector<int> D(6,2);
	//TVector<int> C,F;
	//TVector<int> Sum;
	//TVector<float> Razn;
	//TVector<float> Umn;
	//TVector<float> Del;
	//std::cout <<"Ââåäèòå ðàçìåð âåêòîðà\n";
	//std::cin >> C >> D;
	//F=C;
	//if(F!=C)
	//	cout << "neRavny\n";
	//else 
	//	cout << " ravny\n";
	//std::cout << C <<"\n" << D;// << "\n" << B << "\n" << C << "\n" << D << "\n";


	//return 0;
	TMatrix<int> D(3);
	//cout << D;
	TMatrix<int> F(D),C;
	
	cout << "Vvedite matrizy s razmerom = " << F.GetSize() << "\n";
	cin >> F;
	D = F;
	C = D * F;
	cout << C;
	//C = D * F;
	

	//C = D * F;
	//cout << C;
	if (D != F)
		cout << "net";
	else cout << "ravn";
	return 0;
}