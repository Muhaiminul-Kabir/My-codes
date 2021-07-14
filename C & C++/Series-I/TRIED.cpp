#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

#define E <<endl;

/*Maria has just started as graduate student in a medical school and she's needing your help to organize a laboratory experiment which she is responsible about. She wants to know, at the end of the year, how many animals were used in this laboratory and the percentage of each type of animal is used at all.

This laboratory uses in particular three types of animals: frogs, rats and rabbits. To obtain this information, it knows exactly the number of experiments that were performed, the type and quantity of each animal is used in each experiment.

Input
The first line of input contains an integer N indicating the number of test cases that follows. Each test case contains an integer Amount (1 ≤ Amount ≤ 15) which represents the amount of animal used and a character Type ('C', 'R' or 'S'), indicating the type of animal:
- C: Coelho (rabbit in portuguese)
- R: Rato (rat  in portuguese)
- S: Sapo (frog in portuguese)

Output
Print the total of animals used, the total of each type of animal and the percentual of each one in relation of the total of animals used. The percentual must be printed with 2 digits after the decimal point.

Input Sample	Output Sample
10
10 C
6 R
15 S
5 C
14 R
9 C
6 R
8 S
5 C
14 R

Total: 92 cobaias
Total de coelhos: 29
Total de ratos: 40
Total de sapos: 23
Percentual de coelhos: 31.52 %
Percentual de ratos: 43.48 %
Percentual de sapos: 25.00 %

*/

using namespace std;

struct data
{
	int quantity;
	char type;
};

typedef struct data data;

int coelhos = 0;
int ratos = 0;
int sapos  = 0;
int cobaias = 0;
double ratosP = 0.0;
double coelhosP = 0.0;
double saposP = 0.0;

int main() {
	int n;
	cin>>n;
	data *anim;
	anim = (data*)malloc(n*sizeof(struct data));


	int i = 0,j=0;
	while(i < n){
		cin>>anim[i].quantity;

			cin>>anim[i].type;
			
			i++;
	}

	i =0 ;
	while(i < n){
		if(anim[i].type == 'R'){
			ratos += anim[i].quantity;
		}

		else if(anim[i].type == 'S'){
			sapos += anim[i].quantity;
		}

		else if(anim[i].type == 'C'){
			coelhos += anim[i].quantity;
		}
		i++;
	}
	cobaias = coelhos + sapos + ratos;
	coelhosP = (double)(100*(coelhos/cobaias));
	ratosP = (double)(100*(ratos/cobaias));
	saposP = (double)(100*(sapos/cobaias));
	cout<< "Total: "<<cobaias<<" cobaias" E
	cout<< "Total de coelhos: "<<coelhos E
	cout<< "Total de ratos: "<<ratos E
	cout<< "Total de sapos: "<<sapos E
	cout<<"Percentual de coelhos: "<<coelhosP <<" %" E
	cout<<"Percentual de ratos: "<<ratosP<<" %" E
	cout<<"Percentual de sapos: "<<saposP <<" %" E

	free(anim);
	return 0;
}


