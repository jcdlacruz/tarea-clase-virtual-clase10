#include <iostream>
#include <fstream>
using namespace std;

struct empleado{
	int codigo;
	string nombre;
	string puesto;
	string departamento;
	float salario;
};

void agregarEmpleado(){
	Empleados:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout << "Indique nombre del archivo: ";
		getline(cin, nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);
		
		if(archivo.fail()){
			archivo.close();
			cout << "Error al abrir el archivo";
			exit(1);
		}
		system("CLS");
		archivo.close();
		
		int codigo;
		string nombre;
  		string puesto;
		string departamento;
		float salario;
		int opcion;
		
		cout << "Ingrese codigo de empleado: "<<endl;
		cin >> codigo;
		
		fflush(stdin);
		cout << "Ingrese nombre del empleado: "<<endl;
		getline(cin, nombre, '\n');
		
		cout << "Ingrese puesto del empleado: "<<endl;
		getline(cin, puesto, '\n');
		
		cout << "Seleccione el departamento al que pertenece el empleado:"<<endl;
		cout << "1.- Gerencia"<<endl;
		cout << "2.- Administracion"<<endl;
		cout << "3.- Produccion"<<endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				 departamento = "Gerencia";
				 break;
			case 2:
				 departamento = "Administracion";
				 break;
			case 3:
				 departamento = "Produccion";
				 break;
			default:
				 cout<<"No existe la opcion, vuelva a intentar. "<<endl;
				 system("Pause");
				 goto Empleados;
				 break;	
		}
		
		cout << "Ingrese salario del empleado: "<<endl;
		cin >> salario;
		
		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			cout <<"Error al abrir el archivo";
			archivo.close();
			exit(1);
		}
		system("CLS");
		
		archivo <<codigo<<"\t"<<nombre<<"\t"<<puesto<<"\t"<<departamento<<"\t"<<salario<<endl;	
		archivo.close();
		
		cout <<"Registro agregado exitosamente."<<endl;
}
