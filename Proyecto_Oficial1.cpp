#include<iostream>
using namespace std;

int const filas=4;
int const columnas=5;

int puertos(int n, string nombre[]);
void limpiarVector (int cantidadContenedores [], int n);
void limpiarMatriz(float peso[filas][columnas], bool Cdisponibles [filas][columnas]);
void mostrarDisponibilidad(bool Cdisponibles[filas][columnas]);
void llenarMatrices (int &Cfila, int &Ccolumna, bool Cdisponibles[filas][columnas], float peso[filas][columnas], string marca[filas][columnas], string tipo[filas][columnas]);
void porcentajeOcupacion (int porcentaje, int cantidadContenedores[], int n, string nombre[]);
int totalRecaudo(string nombre, string nombres[filas][columnas], int sumaTotalPuerto);
int contenedoresBarco(bool Cdisponibles[filas][columnas], int contador);
void totalPorcentajeAndRecaudo(bool Cdisponibles[filas][columnas]);
void ordenamiento(int n, int cantidadContenedores[], string nombre[]);
void marcasPremiumYEconomicas(string marca[filas][columnas]);
void reporteEmpresa (string marca[filas][columnas], string marcaBuscada);
float promedioMayor (float peso[filas][columnas], bool Cdisponibles[filas][columnas]);
int buscarFilaPesada (float peso[filas][columnas]);
int buscarColumnaLivina (float peso[filas][columnas]);
void reporteTipo (string tipo[filas][columnas], string tipoBuscado);
float Promediopuertoingresado(float peso[filas][columnas], string nombres[filas][columnas], string puertopedido);
void empresaPesoMayor (string marca [filas][columnas], float peso [filas][columnas]);
void empresaPesoMenor (string marca [filas][columnas], float peso [filas][columnas]);

int main (){
	//definir variables 
	int n=0;
	string nombres[filas][columnas];
    float peso[filas][columnas];
	string marca[filas][columnas];
    string tipo[filas][columnas];
    bool Cdisponibles[filas][columnas];
    int porcentaje=-1;
    int sumaTotalPuerto = 0;
	int Cfila=0;
	int Ccolumna=0;
	string marcaBuscada="";
	string tipoBuscado="";
	string puertoBuscado="";
	int contador=0;
	//procesos
	cout<<"ingrese el numero de puertos"<<endl;
	cin>>n;
	string nombre[n];
	puertos(n, nombre);
	int cantidadContenedores[n];
	limpiarVector(cantidadContenedores, n);
	limpiarMatriz(peso, Cdisponibles);
	bool opcion=0;
	for (int i = 0; i < n; i++) {
        cout << endl;
        cout << "\t" << "\t" << "Bievenido al puerto " << nombre[i] << endl;
        cout << endl;
        cout << "ingrese 1, si desea ingresar algun contenedor en el puerto " << nombre[i] << endl;
        cout<<endl;
        cout << "ingrese 0, si no desea ingresar algun contenedor en el puerto " << nombre[i] << endl;
        cin >> opcion;
        if (opcion == 1) {
            cout << endl;
            cout << "Puerto " << nombre[i] << " Cuantos contenedores desea ingresar " << endl;
            cin >> cantidadContenedores[i];
            cout<<endl;
        	for (int j = 1; j <= cantidadContenedores[i]; j++){
        		cout<<"Contenedor "<<j<<endl;
        		mostrarDisponibilidad(Cdisponibles);
        		llenarMatrices (Cfila, Ccolumna, Cdisponibles, peso, marca, tipo);
    			nombres[Cfila][Ccolumna] = nombre[i];
    			cout << endl;
    		}
		}
		porcentajeOcupacion ( porcentaje, cantidadContenedores, n, nombre);
    	sumaTotalPuerto = totalRecaudo(nombre[i], nombres, sumaTotalPuerto);
    }
    totalPorcentajeAndRecaudo(Cdisponibles);
	contador = contenedoresBarco(Cdisponibles, contador);
    cout << "La cantidad de contenedores es "<<contador<<endl;
    cout << endl;
    if (contador!=0){
    	cout<<"\t"<<"Si hay informacion para listar"<<endl;
    	cout<<endl;
    	ordenamiento(n, cantidadContenedores, nombre);
		marcasPremiumYEconomicas(marca);
    	bool opcion1 = 1;
    	do{
    		cout<<"Ingrese la marca de la cual desea obtener informacion"<<endl;
    		cin>>marcaBuscada;
    		reporteEmpresa (marca, marcaBuscada);
    		cout<<"Desea obtener informacion de otra marca"<<endl;
    		cin>>opcion1;
		}while (opcion1 != 0);
		promedioMayor (peso, Cdisponibles);
    	buscarFilaPesada (peso);
    	buscarColumnaLivina (peso);
    	bool opcion2 = 1;
    	do{
    		cout<<"Ingrese el tipo de la cual desea obtener informacion"<<endl;
    		cin>>tipoBuscado;
    		reporteTipo (tipo, tipoBuscado);
    		cout<<"Desea obtener informacion de otro tipo"<<endl;
    		cin>>opcion2;
		}while (opcion2 != 0);
    	bool opcion3 = 1;
    	do{
    		cout<<"Ingrese el puerto de la cual desea obtener informacion"<<endl;
    		cin>>puertoBuscado;
    		Promediopuertoingresado(peso, nombres, puertoBuscado);
    		cout<<"Desea obtener informacion de otro puerto"<<endl;
    		cin>>opcion3;
		}while (opcion3 != 0);
		empresaPesoMayor (marca, peso);
		empresaPesoMenor (marca, peso);
	}else{
		cout<<"No hay contenedores, por lo tanto no hay informacion para listar"<<endl;
	}
	return 0;
}
//Funcion puertos
int puertos(int n, string nombre[]){
    for (int i = 0; i < n; i++){
        cout << endl;
        cout << "ingrese el nombre del puerto " << i << endl;
        cin >> nombre[i];
    }
}
//Procedimiento limpiar vector de contenedores
void limpiarVector (int cantidadContenedores [], int n){
	for (int i = 0; i < n; i++){
		cantidadContenedores[i]=0;
	}
}
//Procedimiento limpiar matriz de peso y disponibilidad
void limpiarMatriz(float peso[filas][columnas], bool Cdisponibles [filas][columnas]){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            peso[i][j] = 0.0;
            Cdisponibles[i][j] = 1;
        }
    }
}
//Procedimiento mostrar la disponibilidad
void mostrarDisponibilidad(bool Cdisponibles[filas][columnas]) {
	cout<<"Matriz de disponibilidad"<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << Cdisponibles[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "las posiciones que se encuentran disponibles son" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (Cdisponibles[i][j] == 1) {
                cout << i << ", " << j << endl;
            }
        }
    }
}
//Procedimiento de llenado de matrices
void llenarMatrices (int &Cfila, int &Ccolumna, bool Cdisponibles[filas][columnas], float peso[filas][columnas], string marca[filas][columnas], string tipo[filas][columnas]){
	bool valido=0;
	do {
		cout << "Tenga en cuenta que las coordenadas (1,1), (1,2), (1,3), (2,1), (2,2), (2,3) pertenecen a la zona premium"<<endl;
		cout<<endl;
		cout<<"Ingrese la coordenada de la fila"<<endl;
		cin>>Cfila;
		cout<<"Ingrese la coordenada de la columna"<<endl;
		cin>>Ccolumna;
		if (Cfila >= 0 && Cfila < filas && Ccolumna >= 0 && Ccolumna < columnas) {
            if (Cdisponibles[Cfila][Ccolumna] == 1) {
                Cdisponibles[Cfila][Ccolumna] = 0;
                cout << "La coordenada que ingreso es valida" << endl;
                valido = 1;
            } else {
                cout << "La coordenada que ingreso no es valida" << endl;
                valido = 0;
            }
        } else {
            cout << "La coordenada que ingreso no es valida" << endl;
            valido = 0;
        }
	} while (valido==0);
	cout << endl;
    cout << "Ingrese la marca del contenedor " << endl;
    cin >> marca[Cfila][Ccolumna];
    cout << endl;
    cout << "\t"<< "Tipo A -> alimentos"<< "\t"<< "Tipo B -> dispositivos electronicos"<< "\t"<< "Tipo C -> ropa y demas textiles" << endl;
    cout << endl;
    bool valido1=0;
    string tipoAnalizar="";
    while (valido1==0) {
		cout << "Ingrese el tipo del contenedor " << endl;
    	cin >> tipoAnalizar;
    	if (tipoAnalizar=="A" || tipoAnalizar=="B" || tipoAnalizar=="C"){
			tipo[Cfila][Ccolumna]=tipoAnalizar;
			valido1=1;
		}else{
			cout<<endl;
			cout<<"El tipo que ingreso no es valido"<<endl;
			valido1=0;
		}
	} 
	cout<<endl;
    cout << "Ingrese el peso del contenedor " << endl;
    cin >> peso[Cfila][Ccolumna];
}
//Porcentaje de ocupacion por puerto 
void porcentajeOcupacion (int porcentaje, int cantidadContenedores[], int n, string nombre[]){
	for (int i = 0; i < n; i++){
		porcentaje = (cantidadContenedores[i] * 100) / (filas * columnas);
    	cout << "El porcentaje de ocupacion del barco en el puerto "<<nombre[i]<< " es " << porcentaje << "%" << endl;
    	cout << endl;
    }
}
//Procedimiento del total reacudo por puerto
int totalRecaudo(string nombre, string nombres[filas][columnas], int sumaTotalPuerto) {
    int sumaPremium = 0;
    int sumaEconomica = 0;
	int contadorE=0;
	int contadorP=0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (nombres[i][j] == nombre) {
                if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                	contadorP=contadorP+1;
                	sumaPremium = (contadorP*300);
                } else {
                	contadorE=contadorE+1;
                	sumaEconomica = (contadorE*100);
            	}
        	}
        }
    }
    cout << "El valor total a pagar en la zona economica es de " << sumaEconomica << " US" << endl;
    cout << "El valor total a pagar en la zona premium es de " << sumaPremium << " US" << endl;
	cout << endl;
	sumaTotalPuerto = sumaEconomica + sumaPremium;
    cout << "La suma total a pagar por el puerto es de " << sumaTotalPuerto << " US" << endl;
    cout << endl;
    return sumaTotalPuerto;
}
// Procedimiento cantidad de contenedores ingresados por cada puerto (1)
int contenedoresBarco(bool Cdisponibles[filas][columnas], int contador){
	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (Cdisponibles[i][j] == 0) {
                contador=contador+1;
            }
        }
    }
    return contador;
}
//Procedimiento, porcentaje y totalidad del barco
void totalPorcentajeAndRecaudo(bool Cdisponibles[filas][columnas]){
	int porcentajeTotal=0;
	int contadorOcupacion=0;
    int sumaTotalBarco=0;
    int sumaE=0;
    int sumaP=0;
	for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (Cdisponibles[i][j]==0){
            	contadorOcupacion=contadorOcupacion+1;
            	if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                	sumaP = (sumaP+300);
                } else {
                	sumaE = (sumaE+100);
            	}
    			sumaTotalBarco = sumaE + sumaP;
			}
        }
    }
	porcentajeTotal = (contadorOcupacion*100)/(filas*columnas);
    cout << "el porcentaje de ocupacion total del barco es de " << porcentajeTotal << "%" << endl;
    cout << endl;
    cout << "La suma total a pagar por el barco es de " << sumaTotalBarco << " US" << endl;
    cout << endl;
}
//Procedimiento de ordenamiento (2)
void ordenamiento(int n, int cantidadContenedores[], string nombre[]){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (cantidadContenedores[i]>cantidadContenedores[j]){
				int auxC =cantidadContenedores[i];
				cantidadContenedores[i]=cantidadContenedores[j];
				cantidadContenedores[j]=auxC;
				string auxN = nombre[i];
				nombre[i]=nombre[j];
				nombre[j]=auxN;
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout<< "El puerto " << nombre[i] << " tiene " << cantidadContenedores[i] << " contenedores"<< endl;
	}
	cout<<endl;
}
//Marcas economicas y premium (3, 4)
void marcasPremiumYEconomicas(string marca[filas][columnas]){
    string ZonaEconomica = "";
    string ZonaPremium = "";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (marca[i][j] != "") {
                if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                    ZonaPremium = ZonaPremium + "\t" + marca[i][j];
                } else {
                    ZonaEconomica = ZonaEconomica + "\t" + marca[i][j];
                }
			}
        }
    }
    cout << "Las marcas que pertenecen a la zona economica son  " << ZonaEconomica << endl; 
    cout<<endl;
    cout << "las marcas que pertenecen a la zona premium son  " << ZonaPremium << endl; 
    cout<<endl;
}
//Procedimiento reporte de empresas (5)
void reporteEmpresa (string marca[filas][columnas], string marcaBuscada){
	int contadorE = 0;
	int contadorP = 0;
	int sPremium = 0;
	int sEconomica = 0;
	int sTotal = 0;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (marca[i][j]==marcaBuscada){
				if ((i == 1 || i == 2) && (j == 1 || j == 2 || j == 3)) {
                	contadorP = (contadorP+1);
                } else {
                	contadorE = (contadorE+1);
            	}
            	sPremium=contadorP*300;
            	sEconomica=contadorE*100;
			}
		}
	}
	sTotal = sPremium + sEconomica;
	cout<<"La empresa "<<marcaBuscada<<" tiene "<<contadorP<<" contenedores en la zona Premium"<<endl;
	cout<<endl;
	cout<<"La empresa "<<marcaBuscada<<" tiene "<<contadorE<<" contenedores en la zona economica"<<endl;
	cout<<endl;
	cout<<"La empresa "<<marcaBuscada<<" debe de pagar "<<sTotal<<" US"<<endl;
	cout<<endl;
}
//Funcion del promedio (6)
float promedioMayor (float peso[filas][columnas], bool Cdisponibles[filas][columnas]){
	float promedio = 0.0;
	int acumulador = 0;
	int contador2 = 0;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (Cdisponibles[i][j]==0){
				acumulador = acumulador + peso[i][j];
				contador2 = contador2 + 1;
			}
		}
	}
	promedio= (acumulador/contador2);
	cout << "El promedio de los pesos del barco es "<<promedio<<endl;
	cout<<endl;
}
//Funcion de la fila más pesada (7)
int buscarFilaPesada (float peso[filas][columnas]){
	int filaPesada = -1;
	int pesoMayor = INT_MIN;
	int acumulador2 = 0;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			acumulador2 = acumulador2 + peso[i][j];
			if (acumulador2>pesoMayor){
				pesoMayor=acumulador2;
				filaPesada=i;
			}
		}
		acumulador2=0;
	}
	cout<<"La fila mas pesada es "<<filaPesada<<endl;
	cout<<endl;
}
//Funcion de la columna más liviana (8)
int buscarColumnaLivina (float peso[filas][columnas]){
	int columnaLiviana = -1;
	int pesoMenor = INT_MAX;
	int acumulador3 = 0;
	for (int j = 0; j < columnas; j++){
		for (int i = 0; i < filas; i++){
			acumulador3 = acumulador3 + peso[i][j];
		}
		if (acumulador3<pesoMenor && acumulador3!=0){
			pesoMenor=acumulador3;
			columnaLiviana=j;
		}
		acumulador3=0;
	}
	cout<<"La columna mas liviana es "<<columnaLiviana<<endl;
	cout<<endl;
}
//Procedimiento reporte tipo (9)
void reporteTipo (string tipo[filas][columnas], string tipoBuscado){
	int contadorT = 0;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (tipo[i][j]==tipoBuscado){
				contadorT = (contadorT+1);
			}
		}
	}
	cout<<"El tipo "<<tipoBuscado<<" tiene "<<contadorT<<" contenedores en el barco"<<endl;
	cout<<endl;
}
//Funcion promedio por puerto dado (10)
float Promediopuertoingresado(float peso[filas][columnas], string nombres[filas][columnas], string puertoBuscado){
    int ACUMULADORP=0;
    float promedio=0.0;
    int contadorp=0;
    for(int i=0; i<filas; i++) {
        for(int j=0; j<columnas; j++){
            if (nombres[i][j]==puertoBuscado){
                ACUMULADORP=ACUMULADORP+peso[i][j];
                contadorp=contadorp+1;
            }
        }
    }
    promedio=ACUMULADORP/contadorp;
    cout<< "El promedio de peso del puerto "<<puertoBuscado<<" es de "<<promedio<<endl; 
    return promedio;
}
//Funcion de empresa con más peso (11)
void empresaPesoMayor (string marca [filas][columnas], float peso [filas][columnas]){
	int pesoMayor=INT_MIN;
	string marcaMayor="";
	int pesoMenor=INT_MAX;
	string marcaMenor="";
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (peso[i][j]>pesoMayor){
				pesoMayor=peso[i][j];
				marcaMayor=marca[i][j];
			}
		}
	}
	cout << "La marca donde esta el peso mayor es "<<marcaMayor<<" ya que tiene un contenedor que pesa "<<pesoMayor<<endl;
	cout<<endl;
}
//Funcion de empresa con menos peso (12)
void empresaPesoMenor (string marca [filas][columnas], float peso [filas][columnas]){
	int pesoMenor=INT_MAX;
	string marcaMenor="";
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas; j++){
			if (peso[i][j]<pesoMenor && peso[i][j]!=0){
				pesoMenor=peso[i][j];
				marcaMenor=marca[i][j];
			}
		}
	}
	cout << "La marca donde esta el peso menor es "<<marcaMenor<<" ya que tiene un contenedor que pesa "<<pesoMenor<<endl;
	cout<<endl;
}
