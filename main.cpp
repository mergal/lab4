#include <string>
#include <iostream>

using namespace std;


int Find_k(int n);
string Int_to_string(int n);


int main(int argc, char *argv[])
{
	int n=atoi(*(argv+1)),k=Find_k(n);
	cout<<"N = "<<n<<"\nslownie: "<<Int_to_string(n)<<"\n\nK = "<<k<<"\nslownie: "<<Int_to_string(k)<<"\n\nK*N = "<<n*k<<"\nslownie: "<<Int_to_string(k*n)<<"\n\n";
}


int Find_k(int n)
{
	int k=1,nk=n;
	while(nk && k<100000000)
		nk%10 && nk%10-1 ? nk=++k*n : nk/=10;
	if(nk)
		return 0;
	return k;
}


string Int_to_string(int n)
{	
	if(n==0)
		return "zero";
	if(n>=1000000)
		return "duzo";
	const string ones[]={"","jeden ","dwa ","trzy ","cztery ","piec ","szesc ","siedem ","osiem ","dziewiec "};
 	const string teens[]={"","jedenascie ","dwanascie ","trzynascie ","czternascie ","pietnascie ","szesnascie ","siedemnascie ","osiemnascie ","dziewietnascie "};
 	const string tens[]={"","dziesiec ","dwadziescia ","trzydziesci ","czterdziesci ","piecdziesiat ","szescdziesiat ","siedemdziesiat ","osiemdziesiat ","dziewiecdziesiat "};
 	const string hundreds[]={"","sto ","dwiescie ","trzysta ","czterysta ","piecset ","szescset ","siedemset ","osiemset ","dziewiecset "};
 	const string thousands[]={"tysiac ","tysiace ","tysiecy "};

 	string number="";
	int digits[6]={0};

	for(int i=0;i<6;i++)
	{
		digits[i]=n%10;
		n/=10;
	}

	number += hundreds[digits[5]];
 	if(digits[4]==1)
 	{
 		number += teens[digits[3]];
 		if(digits[3] == 0)
 			number += tens[1] ;
 		number += thousands[2];
	}
	else if(digits[5] == 0 && digits[4] == 0 && digits[3] == 1) 
		number += thousands[0];
 	else 
 	{	
 		if(digits[3]  || digits[4] || digits[5])
 		{
 		number += tens[digits[4]] + ones[digits[3]];
 		if(digits[3] > 1 && digits[3] < 5) 
 			number += thousands[1];
 		else  number += thousands[2];
 		}
 	}
 	number += hundreds[digits[2]];
 
 	if(digits[1] == 1)
 	{
 		number += teens[digits[0]];
 		if(digits[0] == 0)
 			number += tens[1];
 	}
 	else
 		number += tens[digits[1]] + ones[digits[0]];
 return number;
}