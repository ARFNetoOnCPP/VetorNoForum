#include <iostream>
#include <stdlib.h>

using namespace std;

class MeuVetor
{
public:

	int quantos;
	float delta;
	float * vetor = NULL;	/* na construcao do objeto vai ser alocado o tamanho correto */

	/* construtor com dois parametros */
	MeuVetor(int n, float dx)
	{
		cout << "    +++++ Construtor: construindo vetor com " << n << " valores e delta = " << dx << endl;
		quantos = n;
		delta = dx;
		vetor = new float[n];
		vetor[0] = 0;
		for (int i = 0; i < (quantos-1); i++)
		{
			vetor[i + 1] = vetor[i] + delta;
		}	// end for
	}	// end constructor

	/* destrutor nao tem parametros */
	~MeuVetor()
	{
		cout << "    ----- Destrutor: fim da vida para um vetor com " << quantos << " valores e delta = " << delta << endl;
		delete[] vetor;	/* eis o que importa: liberar a a memoria alocada quanto da construcao */
	}	// end destructor

	/* construtor de copia: essencial porque precisa alocar memoria e copiar tudo */
	MeuVetor(const MeuVetor& original)
	{
		cout << 
			"    copia Construindo uma copia: copiando vetor com " <<
		    original.quantos << 
			" valores e delta = " << 
			original.delta << 
			endl;

		quantos = original.quantos;
		delta = original.delta;
		vetor = new float[quantos];	
		/* criado. Agora copia os valores */
		for (int i = 0; i < quantos; i++)
		{
			vetor[i] = original.vetor[i];
		}	// end for
	}	// end copy constructor

	/* claro que vamos querer ver o que tem dentro */
	void Mostra()
	{
		cout <<
			endl << "----------\n" <<
			"Vetor com " << quantos << " valores. Delta = " <<
			delta << endl;
		for (int i = 0; i < quantos; i++)
		{
			cout << 
				"Pos: " << i <<
				" Valor: " << vetor[i] <<
				endl;
		}	// end for
	}
};	// end Mostra()

int main()
{
	cout << "Criando v1 com 4 valores e delta = 3.14159" << endl;
	MeuVetor v1(4, 3.14159);
	cout << "Criando v2 com 3 valores e delta = 2.0" << endl;
	MeuVetor v2(3, 2.0);
	cout << "copiando v1 em v3" << endl;
	MeuVetor v3 = v1;
	cout << "copiando v2 em v4" << endl;
	MeuVetor v4 = v2;

	cout << endl << "Mostrando v1" << endl;
	v1.Mostra();
	cout << endl << "Mostrando v2" << endl;
	v2.Mostra();
	cout << endl << "Mostrando v3 = v1" << endl;
	v3.Mostra();
	cout << endl << "Mostrando v2 = v4" << endl;
	v4.Mostra();
	exit(0);	// fim
}
