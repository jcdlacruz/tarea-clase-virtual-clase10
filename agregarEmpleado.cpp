#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

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
};

void reporte(){
    ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     empleado lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].codigo
                >>lista[i].nombre
                >>lista[i].departamento
                >>lista[i].puesto
                >>lista[i].salario;
	 }
	 archivo.close();

	 double total = 0;

	 system("CLS");
	 cout<<"        Reporte         "<<endl;
     cout<<"------------------------"<<endl;
     cout<<" Listado de empleados "<<endl;
     cout<<"------------------------"<<endl;
     cout<<"| Codigo | Nombre | Puesto | Departamento | Salario | "<<endl;
     cout<<"------------------------------------------------------"<<endl;
	 for(int i = 0; i < lineas; i++){
        cout<<"| "<<lista[i].codigo<<" | "<<lista[i].nombre<<" | "
            <<lista[i].puesto<<" | "<<lista[i].departamento<<" | "<<lista[i].salario<<" |"<<endl;
        total += (double)lista[i].salario;
        cout<<"--------------------------------------------------------"<<endl;
	 }
     cout<<"------------------------"<<endl;
	 cout<<"El total de la planilla es: "<<total<<endl;
	 system("Pause");
};
