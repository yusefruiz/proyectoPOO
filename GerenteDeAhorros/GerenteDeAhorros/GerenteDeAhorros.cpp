// GerenteDeAhorros.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>  // for printf
#include <cstdio>
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>




int opcion;
int contador;
int a;
int menuPrincipal(void);
int menuGruposDeAhorro(void);
int menuSocios(void);
int menuAhorro(void);
int menuPlanesDeAhorro(void);
int menuGeneracionDeEstadosDeCuenta(void);
int menuRegistrarAhorro(void);

void sqlConnection(void);
void getConnected(void);

using namespace std;
class socio {
public:
int  IdSocio;
char Nombre[50];
char Apellido1[50];
char Apellido2[50];
char TelefonoCasa[20];
char Celular[20];
char Email[50];
int  IdGrupo;
public: void ingresarSocio();
};

class grupo {
public:
	int  IdGrupo;
	char NombreGrupo[50];
	time_t FechaCreacion;
public: void ingresarGrupo();
};

class plan {
public:
	int  IdPlan;
	char NombrePlan[50];
	char Descripcion[50];
	int Plazo;
	int Cuota;
	time_t FechaInicial;
	time_t FechaFinal;
	int  Periodicidad;
public: void ingresarPlan();
};

class ahorro {
public:
	int  IdAhorro;
	int  IdSocio;
	time_t Fecha;
	int  Cuota;
	char Estado[50];

public: void ingresarAhorro();
};


char cmp[40];//Dato para comparar cadenas en busquedas
int main()
{	
	contador = 0;
	a = 0;
	system("cls");
	
	getConnected();
	int opcionMenu;
	opcionMenu = menuPrincipal();
	printf("Selecione una opcion del menu #%d\n", opcionMenu);
	printf("\n");
	return 0;
}

int menuPrincipal()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Menu****************************/" << endl;
		cout << "1) Grupos" << endl;
		cout << "2) Socios." << endl;
		cout << "3) Ahorro." << endl;
		cout << "4) Credito." << endl;
		cout << "5) Salir." << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				menuGruposDeAhorro();
				return 1;
				break;
			case 2: //Do something else
				menuSocios();
				//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			case 4: //Do something else
				menuPlanesDeAhorro();
				//Blah blah blah
				return 4;
				break;
			case 5: //Exits program
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuPrincipal();
		}
	} while (opcionMenu != 0);
}

int menuGruposDeAhorro()
{
	grupo Grupo;
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Grupos**************************/" << endl;
		cout << "1) Lista de grupo" << endl;
		cout << "2) Crear grupos de ahorro" << endl;
		cout << "3) Modificar grupos de ahorro" << endl;
		cout << "4) Eliminar grupos de ahorro" << endl;
		cout << "5) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				Grupo.ingresarGrupo();
				return 2;
				break;
			case 3: //Do something else
					//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				return 0;
				break;
			case 5: //Exits program
				menuPrincipal();
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGruposDeAhorro();
		}
	} while (opcionMenu != 0);
}

int menuSocios()
{
	system("cls");
	socio Socio;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Socios**************************/" << endl;
		cout << "1) Ver socios" << endl;
		cout << "2) Crear socios" << endl;
		cout << "3) Modificar socios" << endl;
		cout << "4) Eliminar socios" << endl;
		cout << "5) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				Socio.ingresarSocio();
				return 2;
				break;
			case 3: //Do something else
					//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				return 0;
				break;
			case 5: //Exits program
				menuPrincipal();
				return 0;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 5: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuSocios();
		}
	} while (opcionMenu != 0);
}

int menuAhorro()
{
	system("cls");
	ahorro Ahorro;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Ahorro**************************/" << endl;
		cout << "1) Planes de ahorro" << endl;
		cout << "2) Registrar ahorro" << endl;
		cout << "3) Estado de cuenta" << endl;
		cout << "4) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				menuPlanesDeAhorro();
				//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
				menuRegistrarAhorro();
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuGeneracionDeEstadosDeCuenta();
					//Blah blah blah
				return 3;
				break;
			case 4: //Exits program
				menuPrincipal();
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 4: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuAhorro();
		}
	} while (opcionMenu != 0);
}

int menuPlanesDeAhorro()
{
	system("cls");
	plan Plan;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Planes de ahorro**************************/" << endl;
		cout << "1) Nuevo plan" << endl;
		cout << "2) Listar planes" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
				Plan.ingresarPlan();
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuPlanesDeAhorro();
		}
	} while (opcionMenu != 0);
}

int menuRegistrarAhorro()
{
	system("cls");
	ahorro Ahorro;
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Registrar ahorro**************************/" << endl;
		cout << "1) Editar" << endl;
		cout << "2) Eliminar" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
				//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuRegistrarAhorro();
		}
	} while (opcionMenu != 0);
}

int menuGeneracionDeEstadosDeCuenta()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Estados de cuenta**************************/" << endl;
		cout << "1) Lista o reporte por grupo" << endl;
		cout << "2) Lista o reporte por socio" << endl;
		cout << "3) Volver a menu ahorro" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				menuAhorro();
					//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGeneracionDeEstadosDeCuenta();
		}
	} while (opcionMenu != 0);
}

int menuCredito()
{
	system("cls");
	int opcionMenu;
	int new_opcionMenu;
	char sNum[20];
	do {
		//Display menu
		cout << "/*************************Credito**************************/" << endl;
		cout << "1) Registrar credito" << endl;
		cout << "2) Pago a credito" << endl;
		cout << "3) Estado de cuenta" << endl;
		cout << "4) Volver a menu principal" << endl;
		cout << "Por favor selecione una opcion: ";
		cin >> sNum; //Get user input
		opcionMenu = atoi(sNum);
		if (opcionMenu != 0)
		{
			switch (opcionMenu) {
			case 1: //Do something
					//Blah blah blah
				return 1;
				break;
			case 2: //Do something else
					//Blah blah blah
				return 2;
				break;
			case 3: //Do something else
				//Blah blah blah
				return 3;
				break;
			case 4: //Do something else
				menuPrincipal();
					//Blah blah blah
				return 3;
				break;
			default:
				cout << "Seleccione una opcion ente 1 y 3: ";
				cin >> new_opcionMenu;
				opcionMenu = new_opcionMenu;
				break;
			}
		}
		else
		{
			printf("La opcion selecionada no es un numero\n");
			menuGeneracionDeEstadosDeCuenta();
		}
	} while (opcionMenu != 0);
}

void socio::ingresarSocio() {
	
		system("cls");
		cout << "Ingrese nombre del socio:\n";
		cin >> Nombre;
		cout << "Ingrese primer apellido:\n";
		cin >> Apellido1;
		cout << "Ingrese segundo apellido:\n";
		cin >> Apellido2;
		cout << "Ingrese telefono casa:\n";
		cin >> TelefonoCasa;
		cout << "Ingrese relefono celular:";
		cin >> Celular;
		cout << "Ingrese correo electronico:";
		cin >> Email;
		cout << "Presione Enter para continuar";
		getchar();
		menuSocios();

}

void grupo::ingresarGrupo() {

	system("cls");
	cout << "Ingrese nombre del grupo:\n";
	cin >> NombreGrupo;
	getchar();
	menuGruposDeAhorro();

}

void plan::ingresarPlan() {

	system("cls");
	cout << "Ingrese nombre del plan:\n";
	cin >> NombrePlan;
	cout << "Ingrese descripcion del plan:\n";
	cin >> Descripcion;
	cout << "Ingrese plazo:\n";
	cin >> Plazo;
	cout << "Ingrese cuota:\n";
	cin >> Cuota;
	cout << "Ingrese fecha inicial del plan:\n";
	cin >> FechaInicial;
	cout << "Ingrese fecha final del plan:\n";
	cin >> FechaFinal;
	cout << "Ingrese periodicidad:\n";
	cin >> Periodicidad;
	getchar();
	menuPlanesDeAhorro();

}

void ahorro::ingresarAhorro() {

	system("cls");
	cout << "Ingrese cuota:\n";
	cin >> Cuota;
	cout << "Ingrese estado:\n";
	cin >> Estado;
	getchar();
	menuPlanesDeAhorro();

}

void sqlConnection()
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;

	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		goto COMPLETED;

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		goto COMPLETED;

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		goto COMPLETED;

	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";

	//connect to SQL Server	
	//I am using a trusted connection and port 14808
	//it does not matter if you are using default or named instance
	//just make sure you define the server name and the port
	//You have the option to use a username/password instead of a trusted connection
	//but is more secure to use a trusted connection
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		//"DRIVER={SQL Native Client};SERVER=MyComputerName;DATABASE=MyDatabaseName;Trusted_Connection=yes;"
		(SQLWCHAR*)"DRIVER = {SQL Server}; SERVER =CR-DANIELB; DATABASE = Banco; Trusted_Connection = yes;",
		//(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=DEVSQL, 1433;DATABASE=Production;Integrated Security=SSPI;",
		//(SQLCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=Production;UID=sa;PWD=sa;",
		//Data Source = localhost; Integrated Security = SSPI; Initial Catalog = Production
		//(SQLWCHAR*)L"DRIVER={SQL Server};localhost, 1433;DATABASE=Production;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		goto COMPLETED;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		goto COMPLETED;

	default:
		break;
	}

	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		goto COMPLETED;

	//output
	cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";

	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT @@VERSION", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		goto COMPLETED;
	}
	else {

		//declare output variable and pointer
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

			//display query result
			cout << "\nQuery Result:\n\n";
			cout << sqlVersion << endl;
		}
	}

	//close connection and free resources
COMPLETED:
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

	//pause the console window - exit when key is pressed
	cout << "\nPress any key to exit...";
	getchar();
}

void getConnected()
{
	SQLHANDLE henv;
	SQLRETURN rc;
	SQLHANDLE hconn;
	SQLSMALLINT bufsize = 0;
	SQLINTEGER nativeerror = 0;
	SQLSMALLINT textlen = 0;
	unsigned char connStrOut[256];
	SQLWCHAR sqlstate[32];
	SQLWCHAR message[256];
	SQLRETURN status;

	rc = SQLAllocEnv(&henv);
	if (rc != SQL_SUCCESS)
	{
		printf("\nSQLAllocEnv call failed.");
		return;
	}

	rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hconn);
	if (rc != SQL_SUCCESS)
	{
		SQLFreeHandle(SQL_HANDLE_ENV, henv);
		printf("\nSQLAllocHandle call failed.");
		return;
	}

	rc = SQLDriverConnect(hconn, NULL, (SQLWCHAR*)TEXT("DRIVER={SQL Server};SERVER=local;DATABASE=Banco;Trusted=true;"), SQL_NTS, NULL, 256, &bufsize, SQL_DRIVER_NOPROMPT);

	if (SQL_SUCCESS != SQLExecDirect(henv,(SQLWCHAR*)"SELECT [IdAhorro], [IdSocio], [Fecha], [Cuota], [Estado] FROM [dbo].[Ahorro]", SQL_NTS))
	{
		status = SQLExecDirect(henv, (SQLWCHAR*)TEXT("SELECT [IdAhorro], [IdSocio], [Fecha], [Cuota], [Estado] FROM [dbo].[Ahorro]"), SQL_NTS);
		cout << "SQLExecDirect returned " << status << "\r\n";
		if (status == SQL_SUCCESS_WITH_INFO || status == SQL_SUCCESS)
		{
			int rec_id;
			int id;
			char date[64];
			char ps[201];
			while (SQLFetch(henv) == SQL_SUCCESS)
			{
				SQLGetData(henv, 1, SQL_C_ULONG, &rec_id, 0, NULL);
				SQLGetData(henv, 2, SQL_C_ULONG, &id, 0, NULL);
				SQLGetData(henv, 3, SQL_C_CHAR, date, 64, NULL);
				SQLGetData(henv, 4, SQL_C_CHAR, ps, 201, NULL);
				cout << rec_id << " " << id << " " << date << " " << ps << endl;
			}
			//show_error(SQL_HANDLE_STMT, henv);
			//break;
		}
	}
	else
	{
		char name[64];
		char address[64];
		int id;
		while (SQLFetch(henv) == SQL_SUCCESS)
		{
			SQLGetData(henv, 1, SQL_C_ULONG, &id, 0, NULL);
			SQLGetData(henv, 2, SQL_C_CHAR, name, 64, NULL);
			SQLGetData(henv, 3, SQL_C_CHAR, address, 64, NULL);
			cout << id << " " << name << " " << address << endl;
		}
	}

	if (bufsize != 0)
	{
		printf("Connected successfully.\n");
		SQLDisconnect(hconn);
	}
	else
	{
		rc = SQLGetDiagRec(SQL_HANDLE_DBC, hconn, 1, sqlstate, &nativeerror, message, 256, &textlen);

		printf("SQLDriverConnect failed.\n");
		if (rc != SQL_ERROR)
			printf("%s=%s\n", (CHAR *)sqlstate, (CHAR *)message);
	}

	SQLFreeHandle(SQL_HANDLE_DBC, hconn);
	SQLFreeHandle(SQL_HANDLE_ENV, henv);
}
