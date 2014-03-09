#include <iostream>

usign namespace std;


class MaquinaEstados 
{
public:
	MaquinaEstados() {
		numerito = 4;
		cout << "ok construye la maquina de estados" << endl;
		tmp = new ParserMaquina();
	}

	void nada() {
		cout << "nada en la Maquina" << endl;
		tmp->nada(this);
	}


private:
	/* Clase que construye la maquina de estados */
	class ParserMaquina {
	public:	
		int value;

		void nada( MaquinaEstados* punt){ 
			cout << "nada en el parser" << endl;
			cout << punt->numerito;
		}

		ParserMaquina() { cout << "ok construye ParserMaquina" << endl; }
	};

	ParserMaquina* tmp;
	int numerito;

};

int main()
{
	MaquinaEstados x;
	x.nada();
	cout << "end" << endl;

	return 0;
}
