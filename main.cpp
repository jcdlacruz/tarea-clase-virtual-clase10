#include <iostream>
using namespace std;

void mp();
void agregarEmpleado();

int main() {
	mp();
}

void mp(){
	 MenuPrincipal:
	 	int i = 0;
	 	system("CLS");
	 	cout << "----------------------------" <<endl;
	 	cout << "		Menu principal" <<endl;
	 	cout << "1.-  Agregar empleado" <<endl;
	 	cout << "2.-  Generar reporte" <<endl;
	 	cout << "3.-  Salir" <<endl;
	 	cin >> i;
	 	
	 	switch(i){
	 		case 1:
	 			{agregarEmpleado();}
	 			system("CLS");
	 			goto MenuPrincipal;
	 			break;
 			case 2:
			 	system("Pause");
	 			system("CLS");
	 			goto MenuPrincipal;
	 			break;
			case 3:
				exit(1);
			default:
				system("CLS");
				cout << "No existe la opcion, vuelva a intentarlo."<<endl;
				system("Pause");
				goto MenuPrincipal;
				break;
		 }
};
