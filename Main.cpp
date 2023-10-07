#include <windows.h>
#include <string>
#include <string.h>
#include <winuser.h>
#include "resource.h"
#include <ctime>
#include <time.h>
#include <fstream>
#include <CommDlg.h>
#include <mmsystem.h>
#include <stdio.h>
#include <ctype.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

int identificador = 0;

#pragma region StructCon
struct Contacto
{
	Contacto *ant;
	char nombre[70] = "";
	bool genero;
	char direccion[50] = "";
	char email[50] = "";
	char telefono[10] = "";
	char categoria[20] = "";
	char foto[MAX_PATH] = "";
	char musica[MAX_PATH] = "";
	Contacto *sig;
};

Contacto *inicio;
Contacto *aux;
Contacto *ultimo;
#pragma endregion

#pragma region StructEve
struct Evento
{
	Evento *ant;
	char nombre[70] = "";
	char fecha[20] = "";
	string dia;
	string mes;
	string anio;
	char hora[15] = "";
	char lugar[30] = "";
	char contacto[70] = "";
	char alarma[30] = "";
	char pathalarma[MAX_PATH] = "";
	char descripcion[100] = "";
	bool yafue;
	Evento *sig;
};

Evento *ultimo2;
Evento *inicio2;
Evento *aux2;
Evento *aux3;
Evento *aux4;
Evento *auxcal;
#pragma endregion

#pragma region "HWND"
HINSTANCE WanderLey;
//Ventana Inicio
HWND hInicio;
HWND hBtnContactos;
HWND hBtnEventos;

//Ventana Contactos
HWND hListaContactos;
HWND hBtnAgregarCon;
HWND hBtnModificarCon;
HWND hBtnEliminarCon;

//Ventana Eventos
HWND hListaEventos;
HWND hBtnAgregarEve;
HWND hBtnModificarEve;
HWND hBtnEliminarEve;

//VerContactos
HWND hNombreVerC;
HWND hGeneroVerC;
HWND hCategoriaVerC;
HWND hDireccionVerC;
HWND hEmailVerC;
HWND hTelefonoVerC;
HWND hMusicaVerC;
HWND hFotoVerC;
HWND hPictureVerC;

//VerEventos
HWND hNombreVerE;
HWND hFechaVerE;
HWND hHoraVerE;
HWND hLugarVerE;
HWND hAlarmaVerE;
HWND hContactoVerE;
HWND hDescripcionVerE;

//Ventana AgregarCon
HWND hEditNombreCon;
HWND hEditDireccion;
HWND hEditEmail;
HWND hEditTelefono;
HWND hEditFicheroFoto;
HWND hEditFicheroMusica;
HWND hRadMasculino;
HWND hRadFemenino;
HWND hComboCategoria;
HWND hBtnFoto;
HWND hBtnMusica;
HWND hBtnPlay;
HWND hBtnPause;
HWND hBtnStop;
HWND hPictureControl;
HWND hListaContactos2;
HWND hGenero;

//Ventana AgregarEve
HWND hEditNombreEve;
HWND hPickFecha;
HWND hPickHora;
HWND hEditLugar;
HWND hComboAlarma;
HWND hListaContactos3;
HWND hEditDescripcion;
HWND hEditMusicaEve;
HWND hBtnVerMusica;
HWND hBtnPlayEve;
HWND hBtnPauseEve;
HWND hBtnStopEve;
HWND hEditNombreContacto;

//Ventana ModificarCon
HWND hEditNombreConM;
HWND hRadMasculinoM;
HWND hRadFemeninoM;
HWND hEditDireccionM;
HWND hEditEmailM;
HWND hEditTelefonoM;
HWND hEditCategoriaM;
HWND hComboCategoriaM;
HWND hBtnFotoM;
HWND hBtnMusicaM;
HWND hBtnPlayM;
HWND hBtnPauseM;
HWND hBtnStopM;
HWND hEditFicheroFotoM;
HWND hEditFicheroMusicaM;
HWND hPictureControlM;

//Ventana ModificarEve
HWND hEditNombreEveM;
HWND hPickFechaM;
HWND hPickHoraM;
HWND hEditLugarM;
HWND hComboAlarmaM;
HWND hListaContactos3M;
HWND hEditDescripcionM;
HWND hBtnVerMusicaM;
HWND hBtnPlayEveM;
HWND hBtnPauseEveM;
HWND hBtnStopEveM;
HWND hEditMusicaEveM;
HWND hEditNombreContactoM;
HWND hEditFechaM;
HWND hEditHoraM;
HWND hEditAlarmaActual;
HWND hEditContactoActual;

//Ventana EliminarCon
HWND hEditNombreConE;
HWND hRadMasculinoE;
HWND hRadFemeninoE;
HWND hEditDireccionE;
HWND hEditEmailE;
HWND hEditTelefonoE;
HWND hEditCategoriaE;
HWND hEditFotoE;
HWND hEditMusicaE;
HWND PicureControlE;
HWND hBtnPlayE;
HWND hBtnPauseE;
HWND hBtnStopE;
HWND hBtnRegresar;
HWND hBtnEliminar;

//Ventana EliminarEve
HWND hStNombre;
HWND hStFecha;
HWND hStHora;
HWND hStLugar;
HWND hStAlarma;
HWND hStContacto;
HWND hEditDescripcionE;
HWND hBtnRegresarEveE;
HWND hBtnEliminarEveE;

//Menu1
HWND hArchivoSalir1;
HWND hContactosLista1;
HWND hContactosNuevo1;
HWND hEventosLista1;
HWND hEventosNuevo1;
HWND hCalendarioSemanal1;
HWND hCalendarioMensual1;

//Menu2
HWND hArchivoGuardar2;
HWND hArchivoCerrar2;
HWND hArchivoSalir2;
HWND hContactosLista2;
HWND hContactosNuevo2;
HWND hEventosLista2;
HWND hEventosNuevo2;
HWND hCalendarioSemanal2;
HWND hCalendarioMensual2;

//Menu3
HWND hArchivoCerrar3;
HWND hArchivoSalir3;
HWND hContactosLista3;
HWND hContactosNuevo3;
HWND hEventosLista3;
HWND hEventosNuevo3;
HWND hCalendarioSemanal3;
HWND hCalendarioMensual3;

//Ventana Alarma
HWND hStEvento;
HWND hStFechaA;
HWND hStHoraA;
HWND hStLugarA;
HWND hStContactoA;
HWND hEditDescripcionA;
HWND hBtnAceptar;

//Ventana CalendarioMensual
HWND hBtnSalir;
HWND hBtnBuscar;
HWND hSelectMes;
HWND hSelectAnio;
HWND hSt1, hDia1;
HWND hSt2, hDia2;
HWND hSt3, hDia3;
HWND hSt4, hDia4;
HWND hSt5, hDia5;
HWND hSt6, hDia6;
HWND hSt7, hDia7;
HWND hSt8, hDia8;
HWND hSt9, hDia9;
HWND hSt10, hDia10;
HWND hSt11, hDia11;
HWND hSt12, hDia12;
HWND hSt13, hDia13;
HWND hSt14, hDia14;
HWND hSt15, hDia15;
HWND hSt16, hDia16;
HWND hSt17, hDia17;
HWND hSt18, hDia18;
HWND hSt19, hDia19;
HWND hSt20, hDia20;
HWND hSt21, hDia21;
HWND hSt22, hDia22;
HWND hSt23, hDia23;
HWND hSt24, hDia24;
HWND hSt25, hDia25;
HWND hSt26, hDia26;
HWND hSt27, hDia27;
HWND hSt28, hDia28;
HWND hSt29, hDia29;
HWND hSt30, hDia30;
HWND hSt31, hDia31;
HWND hSt32, hDia32;
HWND hSt33, hDia33;
HWND hSt34, hDia34;
HWND hSt35, hDia35;
HWND hSt36, hDia36;
HWND hSt37, hDia37;
HWND hSt38, hDia38;
HWND hSt39, hDia39;
HWND hSt40, hDia40;
HWND hSt41, hDia41;
HWND hSt42, hDia42;
#pragma endregion

#pragma region "CALLBACK's"
//CALLBACK
BOOL CALLBACK EditDlgProc(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcContactos(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcEventos(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcAgregarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcAgregarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcModificarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcModificarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcEliminarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcEliminarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcVerCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcVerEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcAlarma(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ProcCalendario(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam);
#pragma endregion

#pragma region Funciones
//FUNCIONES
void AgregarFoto(HWND Dialog, HWND Objeto);
void AgregarMusica(HWND Dialog, HWND Objeto);
void Guardar_archivoContactos();
void Guardar_archivoEventos();
void Leer_archivoContactos();
void Leer_archivoEventos();
void Alarma(HWND window);
void calendario(int mes, int anio, HWND window);
int CalcularDiasMes(int anio, int mes);
bool Bisiesto(int anio);
int zeller(int anio, int mes);
#pragma endregion

char Carpeta[MAX_PATH];
char ContactosFile[MAX_PATH] = "con_data.bin";
char EventosFile[MAX_PATH] = "eve_data.bin";
char Save[MAX_PATH];

#define ID_SSECONDS 100
UINT TimmerID1 = 0;

#pragma region WinMain
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, PSTR cmdLine, int nCmdShow)
{
	hInicio = CreateDialog(
		hInst, // Application instance.
		MAKEINTRESOURCE(IDD_INICIO), // Dialog resource ID.
		0, // Parent window--null for no parent.
		EditDlgProc);

	ShowWindow(hInicio, nCmdShow);

	GetCurrentDirectory(MAX_PATH, Carpeta);
	Leer_archivoContactos();
	Leer_archivoEventos();

	MSG mensaje;
	ZeroMemory(&mensaje, sizeof(MSG));
	while (GetMessage(&mensaje, 0, 0, 0))
	{
		// Is the message a dialog message? If so the function
		// IsDialogMessage will return true and then dispatch
		// the message to the dialog window procedure.
		// Otherwise, we process as the message as normal.
		if (hInicio == 0 || !IsDialogMessage(hInicio, &mensaje))
		{
			TranslateMessage(&mensaje);
			DispatchMessage(&mensaje);
		}
	}

	return (int)mensaje.wParam;
}
#pragma endregion


#pragma region Inicio
//****VENTANAS****
//Ventana Inicio
BOOL CALLBACK EditDlgProc(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hBtnContactos = GetDlgItem(ghReproducer, BtnContactos);
		hBtnEventos = GetDlgItem(ghReproducer, BtnEventos);

		hArchivoSalir1 = GetDlgItem(ghReproducer, ArchivoSalir1);
		hContactosLista1 = GetDlgItem(ghReproducer, ContactosLista1);
		hContactosNuevo1 = GetDlgItem(ghReproducer, ContactosNuevo1);
		hEventosLista1 = GetDlgItem(ghReproducer, EventosLista1);
		hEventosNuevo1 = GetDlgItem(ghReproducer, EventosNuevo1);
		hCalendarioSemanal1 = GetDlgItem(ghReproducer, CalendarioSemanal1);
		hCalendarioMensual1 = GetDlgItem(ghReproducer, CalendarioMensual1);
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		DestroyWindow(ghReproducer);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}


	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoSalir1:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			DestroyWindow(ghReproducer);
			return true;
		}

		case ContactosLista1:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ContactosNuevo1:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosLista1:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case EventosNuevo1:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioSemanal1:
		{
			return true;
		}

		case CalendarioMensual1:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		//Objetos
		case BtnContactos:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case BtnEventos:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

			return true;
		}

	case WM_DESTROY:
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		PostQuitMessage(0);
		return true;
	}
	return false;
}
#pragma endregion


#pragma region Contactos
//Ventana Contactos
BOOL CALLBACK ProcContactos(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char buffer[256];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hListaContactos = GetDlgItem(ghReproducer, ListaContactos);
		hBtnAgregarCon = GetDlgItem(ghReproducer, BtnAgregarCon);
		hBtnModificarCon = GetDlgItem(ghReproducer, BtnModificarCon);
		hBtnEliminarCon = GetDlgItem(ghReproducer, BtnEliminarCon);

		hArchivoCerrar3 = GetDlgItem(ghReproducer, ArchivoCerrar3);
		hArchivoSalir3 = GetDlgItem(ghReproducer, ArchivoSalir3);
		hContactosLista3 = GetDlgItem(ghReproducer, ContactosLista3);
		hContactosNuevo3 = GetDlgItem(ghReproducer, ContactosNuevo3);
		hEventosLista3 = GetDlgItem(ghReproducer, EventosLista3);
		hEventosNuevo3 = GetDlgItem(ghReproducer, EventosNuevo3);
		hCalendarioSemanal3 = GetDlgItem(ghReproducer, CalendarioSemanal3);
		hCalendarioMensual3 = GetDlgItem(ghReproducer, CalendarioMensual3);

		if (inicio == NULL)
			break;
		else
		{
			aux = inicio;
			while (aux != NULL)
			{
				SendMessage(hListaContactos, LB_ADDSTRING, 0, (LPARAM)aux->nombre);
				aux = aux->sig;
			}
			aux = NULL;
		}
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_COMMAND:
	{
		switch (HIWORD(wParam))
		{
		case LBN_DBLCLK:
		{
			int i = 0;
			i = SendMessage(hListaContactos, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					DialogBox(WanderLey, MAKEINTRESOURCE(IDD_VERCONTACTO), hInicio, ProcVerCon);
					break;
				}
				aux = aux->sig;
			}
			aux = NULL;
			return true;
		}
			return true;
		}
		switch (LOWORD(wParam))
		{
			//Menu
		case ArchivoCerrar3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			PostQuitMessage(0);
			return true;
		}

		case ContactosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosLista3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case EventosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioMensual3:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		//Objetos
		case BtnAgregarCon:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case BtnModificarCon:
		{
			int i = 0;
			i = SendMessage(hListaContactos, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					EndDialog(ghReproducer, 0);
					DialogBox(WanderLey, MAKEINTRESOURCE(IDD_MODIFICARCON), hInicio, ProcModificarCon);
					break;
				}
				aux = aux->sig;
			}
			aux = NULL;
			return true;
		}

		case BtnEliminarCon:
		{
		int i = 0;
		i = SendMessage(hListaContactos, LB_GETCURSEL, 0, 0);
		SendMessage(hListaContactos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
		aux = inicio;
		while (aux != NULL)
		{
			if (strcmp(buffer, aux->nombre) == 0)
			{
				EndDialog(ghReproducer, 0);
				DialogBox(WanderLey, MAKEINTRESOURCE(IDD_ELIMINARCON), hInicio, ProcEliminarCon);
				break;
			}
			aux = aux->sig;
		}
		aux = NULL;
			return true;
		}

		case ListaContactos:
		{

		}
		return true;
		}
		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region Eventos
//Ventana Eventos
BOOL CALLBACK ProcEventos(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char buffer[70];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hListaEventos = GetDlgItem(ghReproducer, ListaEventos);
		hBtnAgregarEve = GetDlgItem(ghReproducer, BtnAgregarEve);
		hBtnModificarEve = GetDlgItem(ghReproducer, BtnModificarEve);
		hBtnEliminarEve = GetDlgItem(ghReproducer, BtnEliminarEve);

		hArchivoCerrar3 = GetDlgItem(ghReproducer, ArchivoCerrar3);
		hArchivoSalir3 = GetDlgItem(ghReproducer, ArchivoSalir3);
		hContactosLista3 = GetDlgItem(ghReproducer, ContactosLista3);
		hContactosNuevo3 = GetDlgItem(ghReproducer, ContactosNuevo3);
		hEventosLista3 = GetDlgItem(ghReproducer, EventosLista3);
		hEventosNuevo3 = GetDlgItem(ghReproducer, EventosNuevo3);
		hCalendarioSemanal3 = GetDlgItem(ghReproducer, CalendarioSemanal3);
		hCalendarioMensual3 = GetDlgItem(ghReproducer, CalendarioMensual3);

		if (inicio2 == NULL)
			break;
		else
		{
			aux2 = inicio2;
			while (aux2 != NULL)
			{
				SendMessage(hListaEventos, LB_ADDSTRING, 0, (LPARAM)aux2->nombre);
				aux2 = aux2->sig;
			}
			aux2 = NULL;
		}
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}


	case WM_COMMAND:
	{
		switch (HIWORD(wParam))
		{
		case LBN_DBLCLK:
		{
			int i = 0;
			i = SendMessage(hListaEventos, LB_GETCURSEL, 0, 0);
			SendMessage(hListaEventos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux2 = inicio2;
			while (aux2 != NULL)
			{
				if (strcmp(buffer, aux2->nombre) == 0)
				{
					DialogBox(WanderLey, MAKEINTRESOURCE(IDD_VEREVENTO), hInicio, ProcVerEve);
					break;
				}
				aux2 = aux2->sig;
			}
			aux2 = NULL;
			return true;
		}
		}

		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoCerrar3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ContactosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioMensual3:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		//Objetos
		case BtnAgregarEve:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case BtnModificarEve:
		{
			int i = 0;
			i = SendMessage(hListaEventos, LB_GETCURSEL, 0, 0);
			SendMessage(hListaEventos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux2 = inicio2;
			while (aux2 != NULL)
			{
				if (strcmp(buffer, aux2->nombre) == 0)
				{
					EndDialog(ghReproducer, 0);
					DialogBox(WanderLey, MAKEINTRESOURCE(IDD_MODIFICAREVE), hInicio, ProcModificarEve);
					break;
				}
				aux2 = aux2->sig;
			}
			return true;
		}

		case BtnEliminarEve:
		{
			int i = 0;
			i = SendMessage(hListaEventos, LB_GETCURSEL, 0, 0);
			SendMessage(hListaEventos, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux2 = inicio2;
			while (aux2 != NULL)
			{
				if (strcmp(buffer, aux2->nombre) == 0)
				{
					EndDialog(ghReproducer, 0);
					DialogBox(WanderLey, MAKEINTRESOURCE(IDD_ELIMINAREVE), hInicio, ProcEliminarEve);
					break;
				}
				aux2 = aux2->sig;
			}
			return true;
		}

			return true;
		}
		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region AgregarCon
//Ventana AgregarCon
BOOL CALLBACK ProcAgregarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char pathbmp[MAX_PATH], pathmp3[MAX_PATH], comando[MAX_PATH];
	int index;
	static HBITMAP bmp;
	char buffer[256];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hEditNombreCon = GetDlgItem(ghReproducer, EditNombreCon);
		hEditDireccion = GetDlgItem(ghReproducer, EditDireccion);
		hEditEmail = GetDlgItem(ghReproducer, EditEmail);
		hEditTelefono = GetDlgItem(ghReproducer, EditTelefono);
		hEditFicheroFoto = GetDlgItem(ghReproducer, EditFicheroFoto);
		hEditFicheroMusica = GetDlgItem(ghReproducer, EditFicheroMusica);
		hRadMasculino = GetDlgItem(ghReproducer, RadMasculino);
		hRadFemenino = GetDlgItem(ghReproducer, RadFemenino);
		hComboCategoria = GetDlgItem(ghReproducer, ComboCategoria);
		hBtnFoto = GetDlgItem(ghReproducer, BtnFoto);
		hBtnMusica = GetDlgItem(ghReproducer, BtnMusica);
		hBtnPlay = GetDlgItem(ghReproducer, BtnPlay);
		hBtnPause = GetDlgItem(ghReproducer, BtnPause);
		hBtnStop = GetDlgItem(ghReproducer, BtnStop);
		hPictureControl = GetDlgItem(ghReproducer, PictureControl);
		hListaContactos2 = GetDlgItem(ghReproducer, ListaContactos2);
		hGenero = GetDlgItem(ghReproducer, CheckGenero);

		CheckRadioButton(ghReproducer, RadMasculino, RadFemenino, RadMasculino);
		CheckDlgButton(ghReproducer, CheckGenero, BST_CHECKED);

		SendMessage(hComboCategoria, CB_ADDSTRING, 0, (LPARAM)"Amigos");
		SendMessage(hComboCategoria, CB_ADDSTRING, 1, (LPARAM)"Familiares");
		SendMessage(hComboCategoria, CB_ADDSTRING, 2, (LPARAM)"Vecinos");
		SendMessage(hComboCategoria, CB_ADDSTRING, 3, (LPARAM)"Escuela");
		SendMessage(hComboCategoria, CB_ADDSTRING, 4, (LPARAM)"Trabajo");
		SendMessage(hComboCategoria, CB_ADDSTRING, 5, (LPARAM)"Novia");
		SendMessage(hComboCategoria, CB_ADDSTRING, 6, (LPARAM)"Novio");

		//Menu
		hArchivoGuardar2 = GetDlgItem(ghReproducer, ArchivoGuardar2);
		hArchivoCerrar2 = GetDlgItem(ghReproducer, ArchivoCerrar2);
		hArchivoSalir2 = GetDlgItem(ghReproducer, ArchivoSalir2);
		hContactosLista2 = GetDlgItem(ghReproducer, ContactosLista2);
		hContactosNuevo2 = GetDlgItem(ghReproducer, ContactosNuevo2);
		hEventosLista2 = GetDlgItem(ghReproducer, EventosLista2);
		hEventosNuevo2 = GetDlgItem(ghReproducer, EventosNuevo2);
		hCalendarioSemanal2 = GetDlgItem(ghReproducer, CalendarioSemanal2);
		hCalendarioMensual2 = GetDlgItem(ghReproducer, CalendarioMensual2);

		//Llenar listbox
		if (inicio == NULL)
			break;
		else
		{
			aux = inicio;
			while (aux != NULL)
			{
				SendMessage(hListaContactos2, LB_ADDSTRING, 0, (LPARAM)aux->nombre);
				aux = aux->sig;
			}
			aux = NULL;
		}
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		mciSendString("stop MP3", NULL, 0, 0);
		mciSendString("close MP3", NULL, 0, 0);
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}


	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoGuardar2:
		{
			Contacto Datos;

			GetWindowText(hEditNombreCon, Datos.nombre, sizeof(Datos.nombre));
			GetWindowText(hEditDireccion, Datos.direccion, sizeof(Datos.direccion));
			GetWindowText(hEditEmail, Datos.email, sizeof(Datos.email));
			GetWindowText(hEditTelefono, Datos.telefono, sizeof(Datos.telefono));
			GetWindowText(hEditFicheroFoto, Datos.foto, sizeof(Datos.foto));
			GetWindowText(hEditFicheroMusica, Datos.musica, sizeof(Datos.musica));

			index = SendMessage(hComboCategoria, CB_GETCURSEL, 0, 0);

			SendMessage(hComboCategoria, CB_GETLBTEXT, (WPARAM)index, (LPARAM)Datos.categoria);

			Contacto *nuevo = new Contacto;

			Datos.genero = true;
			nuevo->genero = true;

			if (IsDlgButtonChecked(ghReproducer, RadMasculino) == BST_CHECKED)
			{
				Datos.genero = false;
				nuevo->genero = false;
			}

			strcpy(nuevo->nombre, Datos.nombre);
			strcpy(nuevo->direccion, Datos.direccion);
			strcpy(nuevo->email, Datos.email);
			strcpy(nuevo->telefono, Datos.telefono);
			strcpy(nuevo->categoria, Datos.categoria);
			strcpy(nuevo->foto, Datos.foto);
			strcpy(nuevo->musica, Datos.musica);
			nuevo->ant = 0;
			nuevo->sig = 0;

			if (strcmp(Datos.nombre, "") == 0 || strcmp(Datos.direccion, "") == 0 || strcmp(Datos.email, "") == 0 || strcmp(Datos.telefono, "") == 0 || strcmp(Datos.categoria, "") == 0 || strcmp(Datos.foto, "") == 0 || strcmp(Datos.musica, "") == 0)
			{
				MessageBox(ghReproducer, "ASEGURATE DE INGRESAR TODOS LOS DATOS", "IMPORTANTE", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				//Lista Ligada
				if (inicio == NULL)
				{
					ultimo = nuevo;
					inicio = nuevo;
					aux = nuevo;
				}
				else
				{
					ultimo->sig = nuevo;
					nuevo->ant = ultimo;
					ultimo = nuevo;
				}
				aux = NULL;
				MessageBox(ghReproducer, "Contacto guardado", "Contactos", MB_OK | MB_ICONINFORMATION);

				GetWindowText(hEditNombreCon, buffer, sizeof(buffer));
				SendMessage(hListaContactos2, LB_ADDSTRING, 0, (LPARAM)buffer);
				mciSendString("stop MP3", NULL, 0, 0);
				mciSendString("close MP3", NULL, 0, 0);
				EndDialog(ghReproducer, 0);
				DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			}
			return true;
		}

		case ArchivoCerrar2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case EventosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case EventosNuevo2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioMensual2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		//Objetos
		case BtnFoto:
		{
			AgregarFoto(ghReproducer, hEditFicheroFoto);
			GetWindowText(hEditFicheroFoto, pathbmp, MAX_PATH);
			if (strcmp(pathbmp, "") != 0)
			{
				bmp = (HBITMAP)LoadImage(NULL, pathbmp, IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
				SendDlgItemMessage(ghReproducer, PictureControl, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);

			}
			return true;
		}

		case BtnMusica:
		{
			AgregarMusica(ghReproducer, hEditFicheroMusica);
			return true;
		}

		case BtnPlay:
		{
			GetWindowText(hEditFicheroMusica, pathmp3, MAX_PATH);
			if (strcmp(pathmp3, "") != 0)
			{
				sprintf(comando, "open \"%s\" alias MP3", pathmp3);
				mciSendString(comando, NULL, 0, 0);
				mciSendString("play MP3", NULL, 0, 0);
			}
			return true;
		}

		case BtnPause:
		{
			mciSendString("pause MP3", NULL, 0, 0);
			return true;
		}

		case BtnStop:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			return true;
		}

			return true;
		}

		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region AgregarEve
//Ventana AgregarEve
BOOL CALLBACK ProcAgregarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char pathmp3[MAX_PATH], comando[MAX_PATH];
	char buffer[256];
	int index = 0;
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hEditNombreEve = GetDlgItem(ghReproducer, EditNombreEve);
		hPickFecha = GetDlgItem(ghReproducer, PickFecha);
		hPickHora = GetDlgItem(ghReproducer, PickHora);
		hEditLugar = GetDlgItem(ghReproducer, EditLugar);
		hComboAlarma = GetDlgItem(ghReproducer, ComboAlarma);
		hListaContactos3 = GetDlgItem(ghReproducer, ListaContactos3);
		hEditDescripcion = GetDlgItem(ghReproducer, EditDescripcion);
		hEditMusicaEve = GetDlgItem(ghReproducer, EditMusicaEve);
		hBtnVerMusica = GetDlgItem(ghReproducer, BtnVerMusica);
		hBtnPlayEve = GetDlgItem(ghReproducer, BtnPlayEve);
		hBtnPauseEve = GetDlgItem(ghReproducer, BtnPauseEve);
		hBtnStopEve = GetDlgItem(ghReproducer, BtnStopEve);
		hEditNombreContacto = GetDlgItem(ghReproducer, EditNombreContacto);

		SendMessage(hComboAlarma, CB_ADDSTRING, 0, (LPARAM)"Alarma 1");
		SendMessage(hComboAlarma, CB_ADDSTRING, 1, (LPARAM)"Alarma 2");
		SendMessage(hComboAlarma, CB_ADDSTRING, 2, (LPARAM)"Alarma 3");
		SendMessage(hComboAlarma, CB_ADDSTRING, 3, (LPARAM)"Alarma 4");
		SendMessage(hComboAlarma, CB_ADDSTRING, 4, (LPARAM)"Alarma 5");
		SendMessage(hComboAlarma, CB_ADDSTRING, 5, (LPARAM)"Musica de Contacto");

		//Menu
		hArchivoGuardar2 = GetDlgItem(ghReproducer, ArchivoGuardar2);
		hArchivoCerrar2 = GetDlgItem(ghReproducer, ArchivoCerrar2);
		hArchivoSalir2 = GetDlgItem(ghReproducer, ArchivoSalir2);
		hContactosLista2 = GetDlgItem(ghReproducer, ContactosLista2);
		hContactosNuevo2 = GetDlgItem(ghReproducer, ContactosNuevo2);
		hEventosLista2 = GetDlgItem(ghReproducer, EventosLista2);
		hEventosNuevo2 = GetDlgItem(ghReproducer, EventosNuevo2);
		hCalendarioSemanal2 = GetDlgItem(ghReproducer, CalendarioSemanal2);
		hCalendarioMensual2 = GetDlgItem(ghReproducer, CalendarioMensual2);

		//Llenar listbox contactos
		if (inicio == NULL)
			break;
		else
		{
			aux = inicio;
			while (aux != NULL)
			{
				SendMessage(hListaContactos3, LB_ADDSTRING, 0, (LPARAM)aux->nombre);
				aux = aux->sig;
			}
			aux = NULL;
		}
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoGuardar2:
		{
			KillTimer(ghReproducer, TimmerID1);

			Evento Datos;

			GetWindowText(hEditNombreEve, Datos.nombre, sizeof(Datos.nombre));
			GetWindowText(hPickFecha, Datos.fecha, sizeof(Datos.fecha));
			GetWindowText(hPickHora, Datos.hora, sizeof(Datos.hora));
			GetWindowText(hEditLugar, Datos.lugar, sizeof(Datos.lugar));
			GetWindowText(hEditDescripcion, Datos.descripcion, sizeof(Datos.descripcion));

			GetWindowText(hPickFecha, buffer, sizeof(buffer));
			string Fecha(buffer);
			string Dia = Fecha.substr(0, 2);
			string Mes = Fecha.substr(3, 2);
			string Anio = Fecha.substr(6, 4);

			int i = 0;
			i = SendMessage(hListaContactos3, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos3, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					SendMessage(hEditNombreContacto, WM_SETTEXT, 0, (LPARAM)aux->nombre);
					GetWindowText(hEditNombreContacto, Datos.contacto, sizeof(Datos.contacto));
					break;
				}
				aux = aux->sig;
			}

			//GuardarAlarma
			index = SendMessage(hComboAlarma, CB_GETCURSEL, 0, 0);

			if (index == 0)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 1");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma1.mp3");
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}
			else if (index == 1)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 2");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma2.mp3");
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}
			else if (index == 2)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 3");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma3.mp3");
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}
			else if (index == 3)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 4");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma4.mp3");
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}
			else if (index == 4)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 5");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma5.mp3");
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}
			else if (index == 5)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma Contacto");
				GetWindowText(hEditMusicaEve, Datos.alarma, sizeof(Datos.alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)aux->musica);
				GetWindowText(hEditMusicaEve, Datos.pathalarma, sizeof(Datos.pathalarma));
			}

			if (strcmp(Datos.nombre, "") == 0 || strcmp(Datos.lugar, "") == 0 || strcmp(Datos.alarma, "") == 0 || strcmp(Datos.pathalarma, "") == 0 || strcmp(Datos.descripcion, "") == 0)
			{
				MessageBox(ghReproducer, "ASEGURATE DE INGRESAR TODOS LOS DATOS", "IMPORTANTE", MB_OK | MB_ICONINFORMATION);
			}
			else
			{
				Evento *nuevo = new Evento;

				strcpy(nuevo->nombre, Datos.nombre);
				strcpy(nuevo->fecha, Datos.fecha);
				strcpy(nuevo->hora, Datos.hora);
				strcpy(nuevo->lugar, Datos.lugar);
				strcpy(nuevo->alarma, Datos.alarma);
				strcpy(nuevo->pathalarma, Datos.pathalarma);
				strcpy(nuevo->contacto, Datos.contacto);
				strcpy(nuevo->descripcion, Datos.descripcion);
				nuevo->dia = Dia;
				nuevo->mes = Mes;
				nuevo->anio = Anio;
				nuevo->yafue = false;
				nuevo->ant = 0;
				nuevo->sig = 0;

				if (inicio2 == NULL)
				{
					ultimo2 = nuevo;
					inicio2 = nuevo;
					aux2 = nuevo;
				}
				else
				{
					ultimo2->sig = nuevo;
					nuevo->ant = ultimo2;
					ultimo2 = nuevo;
				}
				aux = NULL;
				aux2 = NULL;
				
				MessageBox(ghReproducer, "Evento guardado", "Evento", MB_OK | MB_ICONINFORMATION);
				mciSendString("stop MP3", NULL, 0, 0);
				mciSendString("close MP3", NULL, 0, 0);
				EndDialog(ghReproducer, 0);
				DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			}
			return true;
		}

		case ArchivoCerrar2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ContactosNuevo2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case CalendarioMensual2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		case BtnVerMusica:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			int i = 0;
			i = SendMessage(hListaContactos3, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos3, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)aux->musica);
					break;
				}
				aux = aux->sig;
			}
			aux = NULL;
			return true;
		}

		case BtnPlayEve:
		{
			GetWindowText(hEditMusicaEve, pathmp3, MAX_PATH);
			if (strcmp(pathmp3, "") != 0)
			{
				sprintf(comando, "open \"%s\" alias MP3", pathmp3);
				mciSendString(comando, NULL, 0, 0);
				mciSendString("play MP3", NULL, 0, 0);
			}
			return true;
		}

		case BtnPauseEve:
		{
			mciSendString("pause MP3", NULL, 0, 0);
			return true;
		}

		case BtnStopEve:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			return true;
		}

			return true;
		}
		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region ModificarCon
//Ventana ModificarCon
BOOL CALLBACK ProcModificarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP bmp;
	char pathbmp[MAX_PATH], pathmp3[MAX_PATH], comando[MAX_PATH];
	int index;
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hEditNombreConM = GetDlgItem(ghReproducer, EditNombreConM);
		hRadMasculinoM= GetDlgItem(ghReproducer, RadMasculinoM);
		hRadFemeninoM = GetDlgItem(ghReproducer, RadFemeninoM);
		hEditDireccionM = GetDlgItem(ghReproducer, EditDireccionM);
		hEditEmailM = GetDlgItem(ghReproducer, EditEmailM);
		hEditTelefonoM= GetDlgItem(ghReproducer, EditTelefonoM);
		hComboCategoriaM = GetDlgItem(ghReproducer, ComboCategoriaM);
		hBtnFotoM = GetDlgItem(ghReproducer, BtnFotoM);
		hBtnMusicaM = GetDlgItem(ghReproducer, BtnMusicaM);
		hBtnPlayM = GetDlgItem(ghReproducer, BtnPlayM);
		hBtnPauseM = GetDlgItem(ghReproducer, BtnPauseM);
		hBtnStopM= GetDlgItem(ghReproducer, BtnStopM);
		hEditFicheroFotoM = GetDlgItem(ghReproducer, EditFicheroFotoM);
		hEditFicheroMusicaM = GetDlgItem(ghReproducer, EditFicheroMusicaM);
		hPictureControlM = GetDlgItem(ghReproducer, PictureControlM);
		hEditCategoriaM = GetDlgItem(ghReproducer, EditCategoriaM);
		hArchivoGuardar2 = GetDlgItem(ghReproducer, ArchivoGuardar2);
		hArchivoCerrar2 = GetDlgItem(ghReproducer, ArchivoCerrar2);
		hArchivoSalir2 = GetDlgItem(ghReproducer, ArchivoSalir2);
		hContactosLista2 = GetDlgItem(ghReproducer, ContactosLista2);
		hContactosNuevo2 = GetDlgItem(ghReproducer, ContactosNuevo2);
		hEventosLista2 = GetDlgItem(ghReproducer, EventosLista2);
		hEventosNuevo2 = GetDlgItem(ghReproducer, EventosNuevo2);
		hCalendarioSemanal2 = GetDlgItem(ghReproducer, CalendarioSemanal2);
		hCalendarioMensual2 = GetDlgItem(ghReproducer, CalendarioMensual2);

		SendMessage(hEditNombreConM, WM_SETTEXT, 0, (LPARAM)aux->nombre);
		SendMessage(hEditDireccionM, WM_SETTEXT, 0, (LPARAM)aux->direccion);
		SendMessage(hEditEmailM, WM_SETTEXT, 0, (LPARAM)aux->email);
		SendMessage(hEditTelefonoM, WM_SETTEXT, 0, (LPARAM)aux->telefono);
		SendMessage(hEditFicheroFotoM, WM_SETTEXT, 0, (LPARAM)aux->foto);
		SendMessage(hEditFicheroMusicaM, WM_SETTEXT, 0, (LPARAM)aux->musica);

		if (aux->genero == TRUE)
		{
			CheckRadioButton(ghReproducer, RadMasculinoM, RadFemeninoM, RadFemeninoM);
		}
		else
		{
			CheckRadioButton(ghReproducer, RadMasculinoM, RadFemeninoM, RadMasculinoM);
		}

		SendMessage(hEditCategoriaM, WM_SETTEXT, 0, (LPARAM)aux->categoria);

		SendMessage(hComboCategoriaM, CB_ADDSTRING, 0, (LPARAM)"Amigos");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 1, (LPARAM)"Familiares");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 2, (LPARAM)"Vecinos");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 3, (LPARAM)"Escuela");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 4, (LPARAM)"Trabajo");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 5, (LPARAM)"Novia");
		SendMessage(hComboCategoriaM, CB_ADDSTRING, 6, (LPARAM)"Novio");

		bmp = (HBITMAP)LoadImage(NULL, aux->foto, IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
		SendDlgItemMessage(ghReproducer, PictureControlM, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		mciSendString("stop MP3", NULL, 0, 0);
		mciSendString("close MP3", NULL, 0, 0);
		EndDialog(ghReproducer, 0);
		aux = NULL;
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoGuardar2:
		{
			GetWindowText(hEditNombreConM, aux->nombre, sizeof(aux->nombre));
			GetWindowText(hEditDireccionM, aux->direccion, sizeof(aux->direccion));
			GetWindowText(hEditEmailM, aux->email, sizeof(aux->email));
			GetWindowText(hEditTelefonoM, aux->telefono, sizeof(aux->telefono));
			GetWindowText(hEditFicheroFotoM, aux->foto, sizeof(aux->foto));
			GetWindowText(hEditFicheroMusicaM, aux->musica, sizeof(aux->musica));

			index = SendMessage(hComboCategoriaM, CB_GETCURSEL, 0, 0);

			SendMessage(hComboCategoriaM, CB_GETLBTEXT, (WPARAM)index, (LPARAM)aux->categoria);

			aux->genero = true;

			if (IsDlgButtonChecked(ghReproducer, RadMasculinoM) == BST_CHECKED)
				aux->genero = false;

			SendMessage(hEditCategoriaM, WM_SETTEXT, 0, (LPARAM)aux->categoria);

			SendMessage(hEditFicheroFotoM, WM_SETTEXT, 0, (LPARAM)aux->foto);
			SendMessage(hEditFicheroMusicaM, WM_SETTEXT, 0, (LPARAM)aux->musica);

			bmp = (HBITMAP)LoadImage(NULL, aux->foto, IMAGE_BITMAP, 210, 210, LR_LOADFROMFILE);
			SendDlgItemMessage(ghReproducer, PictureControlM, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);

			MessageBox(ghReproducer, "Contacto modificado", "Contactos", MB_OK | MB_ICONINFORMATION);

			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ArchivoCerrar2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			aux = NULL;
			return true;
		}

		case ArchivoSalir2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			aux = NULL;
			return true;
		}

		case ContactosNuevo2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			aux = NULL;
			return true;
		}

		case EventosLista2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			aux = NULL;
			return true;
		}

		case EventosNuevo2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			aux = NULL;
			return true;
		}

		case CalendarioMensual2:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			aux = NULL;
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		case BtnFotoM:
		{
			AgregarFoto(ghReproducer, hEditFicheroFotoM);
			GetWindowText(hEditFicheroFotoM, pathbmp, MAX_PATH);
			if (strcmp(pathbmp, "") != 0)
			{
				//Al objeto bmp2, se le asigna una imagen local:
				bmp = (HBITMAP)LoadImage(NULL, pathbmp, IMAGE_BITMAP, 180, 180, LR_LOADFROMFILE);
				SendDlgItemMessage(ghReproducer, PictureControlM, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);

			}
			return true;
		}

		case BtnMusicaM:
		{
			AgregarMusica(ghReproducer, hEditFicheroMusicaM);
			return true;
		}

		case BtnPlayM:
		{
			GetWindowText(hEditFicheroMusicaM, pathmp3, MAX_PATH);
			if (strcmp(pathmp3, "") != 0)
			{
				sprintf(comando, "open \"%s\" alias MP3", pathmp3);
				mciSendString(comando, NULL, 0, 0);
				mciSendString("play MP3", NULL, 0, 0);
			}
			return true;
		}

		case BtnPauseM:
		{
			mciSendString("pause MP3", NULL, 0, 0);
			return true;
		}

		case BtnStopM:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			return true;
		}

			return true;
		}
		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region ModificarEve
//Ventana ModificarEve
BOOL CALLBACK ProcModificarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char pathmp3[MAX_PATH], comando[MAX_PATH];
	char buffer[256];
	int index = 0;
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hEditNombreEveM = GetDlgItem(ghReproducer, EditNombreEveM);
		hPickFechaM = GetDlgItem(ghReproducer, PickFechaM);
		hPickHoraM = GetDlgItem(ghReproducer, PickHoraM);
		hEditLugarM = GetDlgItem(ghReproducer, EditLugarM);
		hComboAlarmaM = GetDlgItem(ghReproducer, ComboAlarmaM);
		hListaContactos3M= GetDlgItem(ghReproducer, ListaContactos3M);
		hEditDescripcionM = GetDlgItem(ghReproducer, EditDescripcionM);
		hEditMusicaEveM = GetDlgItem(ghReproducer, EditMusicaEveM);
		hBtnVerMusicaM = GetDlgItem(ghReproducer, BtnVerMusicaM);
		hBtnPlayEveM = GetDlgItem(ghReproducer, BtnPlayEveM);
		hBtnPauseEveM = GetDlgItem(ghReproducer, BtnPauseEveM);
		hBtnStopEveM = GetDlgItem(ghReproducer, BtnStopEveM);
		hEditNombreContactoM = GetDlgItem(ghReproducer, EditNombreContactoM);
		hEditFechaM = GetDlgItem(ghReproducer, EditFechaM);
		hEditHoraM = GetDlgItem(ghReproducer, EditHoraM);
		hEditAlarmaActual = GetDlgItem(ghReproducer, EditAlarmaActual);
		hEditContactoActual = GetDlgItem(ghReproducer, EditContactoActual);

		hArchivoGuardar2 = GetDlgItem(ghReproducer, ArchivoGuardar2);
		hArchivoCerrar2 = GetDlgItem(ghReproducer, ArchivoCerrar2);
		hArchivoSalir2 = GetDlgItem(ghReproducer, ArchivoSalir2);
		hContactosLista2 = GetDlgItem(ghReproducer, ContactosLista2);
		hContactosNuevo2 = GetDlgItem(ghReproducer, ContactosNuevo2);
		hEventosLista2 = GetDlgItem(ghReproducer, EventosLista2);
		hEventosNuevo2 = GetDlgItem(ghReproducer, EventosNuevo2);
		hCalendarioSemanal2 = GetDlgItem(ghReproducer, CalendarioSemanal2);
		hCalendarioMensual2 = GetDlgItem(ghReproducer, CalendarioMensual2);

		SendMessage(hComboAlarmaM, CB_ADDSTRING, 0, (LPARAM)"Alarma 1");
		SendMessage(hComboAlarmaM, CB_ADDSTRING, 1, (LPARAM)"Alarma 2");
		SendMessage(hComboAlarmaM, CB_ADDSTRING, 2, (LPARAM)"Alarma 3");
		SendMessage(hComboAlarmaM, CB_ADDSTRING, 3, (LPARAM)"Alarma 4");
		SendMessage(hComboAlarmaM, CB_ADDSTRING, 4, (LPARAM)"Alarma 5");
		SendMessage(hComboAlarmaM, CB_ADDSTRING, 5, (LPARAM)"Musica de Contacto");

		SendMessage(hEditNombreEveM, WM_SETTEXT, 0, (LPARAM)aux2->nombre);
		SendMessage(hEditLugarM, WM_SETTEXT, 0, (LPARAM)aux2->lugar);
		SendMessage(hEditDescripcionM, WM_SETTEXT, 0, (LPARAM)aux2->descripcion);
		SendMessage(hEditFechaM, WM_SETTEXT, 0, (LPARAM)aux2->fecha);
		SendMessage(hEditHoraM, WM_SETTEXT, 0, (LPARAM)aux2->hora);
		SendMessage(hEditAlarmaActual, WM_SETTEXT, 0, (LPARAM)aux2->alarma);
		SendMessage(hEditContactoActual, WM_SETTEXT, 0, (LPARAM)aux2->contacto);

		if (inicio == NULL)
			break;
		else
		{
			aux = inicio;
			while (aux != NULL)
			{
				SendMessage(hListaContactos3M, LB_ADDSTRING, 0, (LPARAM)aux->nombre);
				aux = aux->sig;
			}
			aux = NULL;
		}
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		//Menu
		case ArchivoGuardar2:
		{
			Evento Datos;

			GetWindowText(hEditNombreEveM, aux2->nombre, sizeof(aux2->nombre));
			GetWindowText(hPickFechaM, aux2->fecha, sizeof(aux2->fecha));
			GetWindowText(hPickHoraM, aux2->hora, sizeof(aux2->hora));
			GetWindowText(hEditLugarM, aux2->lugar, sizeof(aux2->lugar));
			GetWindowText(hEditDescripcionM, aux2->descripcion, sizeof(aux2->descripcion));
			
			GetWindowText(hPickFechaM, buffer, sizeof(buffer));
			string Fecha(buffer);
			string Dia = Fecha.substr(0, 2);
			string Mes = Fecha.substr(3, 2);
			string Anio = Fecha.substr(6, 4);

			aux2->dia = Dia;
			aux2->mes = Mes;
			aux2->anio = Anio;

			int i = 0;
			i = SendMessage(hListaContactos3M, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos3M, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					SendMessage(hEditNombreContactoM, WM_SETTEXT, 0, (LPARAM)aux->nombre);
					GetWindowText(hEditNombreContactoM, aux2->contacto, sizeof(aux2->contacto));
					break;
				}
				aux = aux->sig;
			}

			//GuardarAlarma
			index = SendMessage(hComboAlarmaM, CB_GETCURSEL, 0, 0);

			if (index == 0)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 1");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma1");
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}
			else if (index == 1)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 2");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma2");
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}
			else if (index == 2)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 3");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma3");
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}
			else if (index == 3)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 4");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma4.mp3");
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}
			else if (index == 4)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma 5");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"media\\Alarma5.mp3");
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}
			else if (index == 5)
			{
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)"Alarma Contacto");
				GetWindowText(hEditMusicaEve, aux2->alarma, sizeof(aux2->alarma));
				SendMessage(hEditMusicaEve, WM_SETTEXT, 0, (LPARAM)aux->musica);
				GetWindowText(hEditMusicaEve, aux2->pathalarma, sizeof(aux2->pathalarma));
			}

			aux2->yafue = false;

			aux = NULL;
			aux2 = NULL;

			MessageBox(ghReproducer, "Evento modificado", "Evento", MB_OK | MB_ICONINFORMATION);
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case ArchivoCerrar2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir2:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista2:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ContactosNuevo2:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosLista2:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case EventosNuevo2:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioMensual2:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		case BtnVerMusicaM:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			int i = 0;
			i = SendMessage(hListaContactos3M, LB_GETCURSEL, 0, 0);
			SendMessage(hListaContactos3M, LB_GETTEXT, (WPARAM)i, (LPARAM)buffer);
			aux = inicio;
			while (aux != NULL)
			{
				if (strcmp(buffer, aux->nombre) == 0)
				{
					SendMessage(hEditMusicaEveM, WM_SETTEXT, 0, (LPARAM)aux->musica);
					break;
				}
				aux = aux->sig;
			}
			aux = NULL;
			return true;
		}

		case BtnPlayEveM:
		{
			GetWindowText(hEditMusicaEve, pathmp3, MAX_PATH);
			if (strcmp(pathmp3, "") != 0)
			{
				sprintf(comando, "open \"%s\" alias MP3", pathmp3);
				mciSendString(comando, NULL, 0, 0);
				mciSendString("play MP3", NULL, 0, 0);
			}
			return true;
		}

		case BtnPauseEveM:
		{
			mciSendString("pause MP3", NULL, 0, 0);
			return true;
		}

		case BtnStopEveM:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			return true;
		}

			return true;
		}
		return true;
	}

	}
	return false;
}
#pragma endregion


#pragma region EliminarCon
//Ventana EliminarCon
BOOL CALLBACK ProcEliminarCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char pathmp3[MAX_PATH], comando[MAX_PATH];
	static HBITMAP bmp;
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hEditNombreConE = GetDlgItem(ghReproducer, EditNombreConE);
		hRadMasculinoE = GetDlgItem(ghReproducer, RadMasculinoE);
		hRadFemeninoE = GetDlgItem(ghReproducer, RadFemeninoE);
		hEditDireccionE = GetDlgItem(ghReproducer, EditDireccionE);
		hEditEmailE = GetDlgItem(ghReproducer, EditEmailE);
		hEditTelefonoE = GetDlgItem(ghReproducer, EditTelefonoE);
		hEditCategoriaE = GetDlgItem(ghReproducer, EditCategoriaE);
		hEditFotoE = GetDlgItem(ghReproducer, EditFotoE);
		hEditMusicaE = GetDlgItem(ghReproducer, EditMusicaE);
		PicureControlE = GetDlgItem(ghReproducer, PictureControlE);
		hBtnPlayE = GetDlgItem(ghReproducer, BtnPlayE);
		hBtnPauseE = GetDlgItem(ghReproducer, BtnPauseE);
		hBtnStopE = GetDlgItem(ghReproducer, BtnStopE);
		hBtnRegresar = GetDlgItem(ghReproducer, BtnRegresar);
		hBtnEliminar = GetDlgItem(ghReproducer, BtnEliminar);

		hArchivoCerrar3 = GetDlgItem(ghReproducer, ArchivoCerrar3);
		hArchivoSalir3 = GetDlgItem(ghReproducer, ArchivoSalir3);
		hContactosLista3 = GetDlgItem(ghReproducer, ContactosLista3);
		hContactosNuevo3 = GetDlgItem(ghReproducer, ContactosNuevo3);
		hEventosLista3 = GetDlgItem(ghReproducer, EventosLista3);
		hEventosNuevo3 = GetDlgItem(ghReproducer, EventosNuevo3);
		hCalendarioSemanal3 = GetDlgItem(ghReproducer, CalendarioSemanal3);
		hCalendarioMensual3 = GetDlgItem(ghReproducer, CalendarioMensual3);

		//Llenar campos
		SendMessage(hEditNombreConE, WM_SETTEXT, 0, (LPARAM)aux->nombre);
		SendMessage(hEditDireccionE, WM_SETTEXT, 0, (LPARAM)aux->direccion);
		SendMessage(hEditEmailE, WM_SETTEXT, 0, (LPARAM)aux->email);
		SendMessage(hEditTelefonoE, WM_SETTEXT, 0, (LPARAM)aux->telefono);
		SendMessage(hEditCategoriaE, WM_SETTEXT, 0, (LPARAM)aux->categoria);
		SendMessage(hEditFotoE, WM_SETTEXT, 0, (LPARAM)aux->foto);
		SendMessage(hEditMusicaE, WM_SETTEXT, 0, (LPARAM)aux->musica);

		if (aux->genero == TRUE)
		{
			CheckRadioButton(ghReproducer, RadMasculinoE, RadFemeninoE, RadFemeninoE);
		}
		else
		{
			CheckRadioButton(ghReproducer, RadMasculinoE, RadFemeninoE, RadMasculinoE);
		}

		bmp = (HBITMAP)LoadImage(NULL, aux->foto, IMAGE_BITMAP, 290, 290, LR_LOADFROMFILE);
		SendDlgItemMessage(ghReproducer, PictureControlE, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		mciSendString("stop MP3", NULL, 0, 0);
		mciSendString("close MP3", NULL, 0, 0);
		EndDialog(ghReproducer, 0);
		aux = NULL;
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			//Menu
		case ArchivoCerrar3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			aux = NULL;
			return true;
		}

		case ArchivoSalir3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			PostQuitMessage(0);
			aux = NULL;
			return true;
		}
		
		case ContactosLista3:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			aux = NULL;
			return true;
		}

		case ContactosNuevo3:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			aux = NULL;
			return true;
		}

		case EventosLista3:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			aux = NULL;
			return true;
		}

		case EventosNuevo3:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			aux = NULL;
			return true;
		}

		case CalendarioMensual3:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			aux = NULL;
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		//Objectos
		
		case BtnMusica:
		{
			AgregarMusica(ghReproducer, hEditFicheroMusica);
			return true;
		}

		case BtnPlayE:
		{
			GetWindowText(hEditMusicaE, pathmp3, MAX_PATH);
			if (strcmp(pathmp3, "") != 0)
			{
				sprintf(comando, "open \"%s\" alias MP3", pathmp3);
				mciSendString(comando, NULL, 0, 0);
				mciSendString("play MP3", NULL, 0, 0);
			}
			return true;
		}

		case BtnPauseE:
		{
			mciSendString("pause MP3", NULL, 0, 0);
			return true;
		}

		case BtnStopE:
		{
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			return true;
		}

		case BtnRegresar:
		{
			aux = NULL;
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			aux = NULL;
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case BtnEliminar:
		{
			if (aux == inicio)
			{
				inicio = inicio->sig;
				aux->ant = NULL;
				aux->sig = NULL;
				delete aux;
			}
			else if (aux->sig != NULL && aux->ant != NULL)
			{
				aux->ant->sig = aux->sig;
				aux->sig->ant = aux->ant;
				aux->ant = NULL;
				aux->sig = NULL;
				delete aux;
			}
			else if (aux == ultimo)
			{
				ultimo = aux->ant;
				aux->ant->sig = NULL;
				aux->ant = NULL;
				delete aux;
			}

			aux = NULL;
			EndDialog(ghReproducer, 0);
			MessageBox(ghReproducer, "Usuario eliminado", "Contactos", MB_OK | MB_ICONINFORMATION);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		return true;
		}
		return true;
	}
	}
	return false;
}
#pragma endregion


#pragma region EliminarEve
//Ventana EliminarEve
BOOL CALLBACK ProcEliminarEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		TimmerID1 = SetTimer(ghReproducer, 100, 1000, NULL);

		//Objetos
		hStNombre = GetDlgItem(ghReproducer, StNombre);
		hStFecha = GetDlgItem(ghReproducer, StFecha);
		hStHora = GetDlgItem(ghReproducer, StHora);
		hStLugar = GetDlgItem(ghReproducer, StLugar);
		hStAlarma = GetDlgItem(ghReproducer, StAlarma);
		hStContacto = GetDlgItem(ghReproducer, StContacto);
		hEditDescripcionE = GetDlgItem(ghReproducer, EditDescripcionE);
		hBtnRegresarEveE = GetDlgItem(ghReproducer, BtnRegresarEveE);
		hBtnEliminarEveE = GetDlgItem(ghReproducer, BtnEliminarEveE);

		SetWindowText(hStNombre, aux2->nombre);
		SetWindowText(hStFecha, aux2->fecha);
		SetWindowText(hStHora, aux2->hora);
		SetWindowText(hStLugar, aux2->lugar);
		SetWindowText(hStAlarma, aux2->alarma);
		SetWindowText(hStContacto, aux2->contacto);
		SendMessage(hEditDescripcionE, WM_SETTEXT, 0, (LPARAM)aux2->descripcion);

		hArchivoCerrar3 = GetDlgItem(ghReproducer, ArchivoCerrar3);
		hArchivoSalir3 = GetDlgItem(ghReproducer, ArchivoSalir3);
		hContactosLista3 = GetDlgItem(ghReproducer, ContactosLista3);
		hContactosNuevo3 = GetDlgItem(ghReproducer, ContactosNuevo3);
		hEventosLista3 = GetDlgItem(ghReproducer, EventosLista3);
		hEventosNuevo3 = GetDlgItem(ghReproducer, EventosNuevo3);
		hCalendarioSemanal3 = GetDlgItem(ghReproducer, CalendarioSemanal3);
		hCalendarioMensual3 = GetDlgItem(ghReproducer, CalendarioMensual3);
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			//Menu
		case ArchivoCerrar3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			EndDialog(ghReproducer, 0);
			return true;
		}

		case ArchivoSalir3:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			PostQuitMessage(0);
			return true;
		}

		case ContactosLista3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CONTACTOS), hInicio, ProcContactos);
			return true;
		}

		case ContactosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGARCON), hInicio, ProcAgregarCon);
			return true;
		}

		case EventosLista3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case EventosNuevo3:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_AGREGAREVE), hInicio, ProcAgregarEve);
			return true;
		}

		case CalendarioMensual3:
		{
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_CALENDARIOMENSUAL), hInicio, ProcCalendario);
			return true;
		}

		case BtnRegresarEveE:
		{
			EndDialog(ghReproducer, 0);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		case BtnEliminarEveE:
		{
			if (aux2 == inicio2)
			{
				inicio2 = inicio2->sig;
				aux2->ant = NULL;
				aux2->sig = NULL;
				delete aux2;
			}
			else if (aux2->sig != NULL && aux2->ant != NULL)
			{
				aux2->ant->sig = aux2->sig;
				aux2->sig->ant = aux2->ant;
				aux2->ant = NULL;
				aux2->sig = NULL;
				delete aux2;
			}
			else if (aux2 == ultimo2)
			{
				ultimo2 = aux2->ant;
				aux2->ant->sig = NULL;
				aux2->ant = NULL;
				delete aux2;
			}

			aux2 = NULL;
			EndDialog(ghReproducer, 0);
			MessageBox(ghReproducer, "Evento eliminado", "Eventos", MB_OK | MB_ICONINFORMATION);
			DialogBox(WanderLey, MAKEINTRESOURCE(IDD_EVENTOS), hInicio, ProcEventos);
			return true;
		}

		return true;
		}
		return true;
	}
	}
	return false;
}
#pragma endregion


#pragma region VerContacto
//Ventana VerContacto
BOOL CALLBACK ProcVerCon(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP bmp;
	char pathbmp[MAX_PATH];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		hNombreVerC = GetDlgItem(ghReproducer, StNombreVerC);
		hGeneroVerC = GetDlgItem(ghReproducer, StGeneroVerC);
		hCategoriaVerC = GetDlgItem(ghReproducer, StCategoriaVerC);
		hDireccionVerC = GetDlgItem(ghReproducer, StDireccionVerC);
		hEmailVerC = GetDlgItem(ghReproducer, StEmailVerC);
		hTelefonoVerC = GetDlgItem(ghReproducer, StTelefonoVerC);
		hMusicaVerC = GetDlgItem(ghReproducer, StMusicaVerC);
		hFotoVerC = GetDlgItem(ghReproducer, StFotoVerC);
		hPictureVerC = GetDlgItem(ghReproducer, PictureControlVerC);

		SetWindowText(hNombreVerC, aux->nombre);
		if (aux->genero == true)
		{
			SetWindowText(hGeneroVerC, "Femenino");
		}
		else
		{
			SetWindowText(hGeneroVerC, "Masculino");
		}
		SetWindowText(hCategoriaVerC, aux->categoria);
		SetWindowText(hDireccionVerC, aux->direccion);
		SetWindowText(hEmailVerC, aux->email);
		SetWindowText(hTelefonoVerC, aux->telefono);
		SetWindowText(hMusicaVerC, aux->musica);
		SetWindowText(hFotoVerC, aux->foto);

		GetWindowText(hFotoVerC, pathbmp, MAX_PATH);

		if (strcmp(pathbmp, "") != 0)
		{
			bmp = (HBITMAP)LoadImage(NULL, pathbmp, IMAGE_BITMAP, 240, 240, LR_LOADFROMFILE);
			SendDlgItemMessage(ghReproducer, PictureControlVerC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmp);
		}
		aux = NULL;
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		mciSendString("stop MP3", NULL, 0, 0);
		mciSendString("close MP3", NULL, 0, 0);
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	return true;
	}

	return false;
}
#pragma endregion


#pragma region VerEvento
//Ventana VerEvento
BOOL CALLBACK ProcVerEve(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		hNombreVerE = GetDlgItem(ghReproducer, StNombreVerE);
		hFechaVerE = GetDlgItem(ghReproducer, StFechaVerE);
		hHoraVerE = GetDlgItem(ghReproducer, StHoraVerE);
		hLugarVerE = GetDlgItem(ghReproducer, StLugarVerE);
		hAlarmaVerE = GetDlgItem(ghReproducer, StAlarmaVerE);
		hContactoVerE = GetDlgItem(ghReproducer, StContactoVerE);
		hDescripcionVerE = GetDlgItem(ghReproducer, EditDescripcionVerE);

		SetWindowText(hNombreVerE, aux2->nombre);
		SetWindowText(hFechaVerE, aux2->fecha);
		SetWindowText(hHoraVerE, aux2->hora);
		SetWindowText(hLugarVerE, aux2->lugar);
		SetWindowText(hAlarmaVerE, aux2->alarma);
		SetWindowText(hContactoVerE, aux2->contacto);
		SetWindowText(hDescripcionVerE, aux2->descripcion);
		aux2 = NULL;
		return true;
	}

	case WM_CLOSE:
	{
		Guardar_archivoContactos();
		Guardar_archivoEventos();
		mciSendString("stop MP3", NULL, 0, 0);
		mciSendString("close MP3", NULL, 0, 0);
		EndDialog(ghReproducer, 0);
		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	return true;
	}

	return false;
}
#pragma endregion


#pragma region Alarma
//Ventana Alarma
BOOL CALLBACK ProcAlarma(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char comando[MAX_PATH];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{
		hStEvento = GetDlgItem(ghReproducer, StEvento);
		hStFechaA = GetDlgItem(ghReproducer, StFechaA);
		hStHoraA = GetDlgItem(ghReproducer, StHoraA);
		hStLugarA = GetDlgItem(ghReproducer, StLugarA);
		hStContactoA = GetDlgItem(ghReproducer, StContactoA);
		hEditDescripcionA = GetDlgItem(ghReproducer, EditDescripcionA);
		hBtnAceptar = GetDlgItem(ghReproducer, BtnAceptar);

		KillTimer(ghReproducer, TimmerID1);

		if (strcmp(aux3->pathalarma , "") != 0)
		{
			sprintf(comando, "open \"%s\" alias MP3", aux3->pathalarma);
			mciSendString(comando, NULL, 0, 0);
			mciSendString("play MP3", NULL, 0, 0);
		}

		SetWindowText(hStEvento, aux3->nombre);
		SetWindowText(hStFechaA, aux3->fecha);
		SetWindowText(hStHoraA, aux3->hora);
		SetWindowText(hStLugarA, aux3->lugar);
		SetWindowText(hStContactoA, aux3->contacto);
		SendMessage(hEditDescripcionA, WM_SETTEXT, 0, (LPARAM)aux3->descripcion);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case BtnAceptar:
		{
			Guardar_archivoContactos();
			Guardar_archivoEventos();
			EndDialog(ghReproducer, 0);
			mciSendString("stop MP3", NULL, 0, 0);
			mciSendString("close MP3", NULL, 0, 0);
			aux3 = NULL;
			return true;
		}

		return true;
		}
		return true;
	}
	}
	return false;
}
#pragma endregion


#pragma region Calendario
BOOL CALLBACK ProcCalendario(HWND ghReproducer, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
	char buffer[256];
	switch (mensaje)
	{
	case WM_INITDIALOG:
	{

#pragma region "HWND's"
		hBtnSalir = GetDlgItem(ghReproducer, BtnSalir);
		hBtnBuscar = GetDlgItem(ghReproducer, BtnBuscar);
		hSelectMes = GetDlgItem(ghReproducer, SelectMes);
		hSelectAnio = GetDlgItem(ghReproducer, SelectAnio);
		hSt1 = GetDlgItem(ghReproducer, St1);
		hSt2 = GetDlgItem(ghReproducer, St2);
		hSt3 = GetDlgItem(ghReproducer, St3);
		hSt4 = GetDlgItem(ghReproducer, St4);
		hSt5 = GetDlgItem(ghReproducer, St5);
		hSt6 = GetDlgItem(ghReproducer, St6);
		hSt7 = GetDlgItem(ghReproducer, St7);
		hSt8 = GetDlgItem(ghReproducer, St8);
		hSt9 = GetDlgItem(ghReproducer, St9);
		hSt10 = GetDlgItem(ghReproducer, St10);
		hSt11 = GetDlgItem(ghReproducer, St11);
		hSt12 = GetDlgItem(ghReproducer, St12);
		hSt13 = GetDlgItem(ghReproducer, St13);
		hSt14 = GetDlgItem(ghReproducer, St14);
		hSt15 = GetDlgItem(ghReproducer, St15);
		hSt16 = GetDlgItem(ghReproducer, St16);
		hSt17 = GetDlgItem(ghReproducer, St17);
		hSt18 = GetDlgItem(ghReproducer, St18);
		hSt19 = GetDlgItem(ghReproducer, St19);
		hSt20 = GetDlgItem(ghReproducer, St20);
		hSt21 = GetDlgItem(ghReproducer, St21);
		hSt22 = GetDlgItem(ghReproducer, St22);
		hSt23 = GetDlgItem(ghReproducer, St23);
		hSt24 = GetDlgItem(ghReproducer, St24);
		hSt25 = GetDlgItem(ghReproducer, St25);
		hSt26 = GetDlgItem(ghReproducer, St26);
		hSt27 = GetDlgItem(ghReproducer, St27);
		hSt28 = GetDlgItem(ghReproducer, St28);
		hSt29 = GetDlgItem(ghReproducer, St29);
		hSt30 = GetDlgItem(ghReproducer, St30);
		hSt31 = GetDlgItem(ghReproducer, St31);
		hSt32 = GetDlgItem(ghReproducer, St32);
		hSt33 = GetDlgItem(ghReproducer, St33);
		hSt34 = GetDlgItem(ghReproducer, St34);
		hSt35 = GetDlgItem(ghReproducer, St35);
		hSt36 = GetDlgItem(ghReproducer, St36);
		hSt37 = GetDlgItem(ghReproducer, St37);
		hSt38 = GetDlgItem(ghReproducer, St38);
		hSt39 = GetDlgItem(ghReproducer, St39);
		hSt40 = GetDlgItem(ghReproducer, St40);
		hSt41 = GetDlgItem(ghReproducer, St41);
		hSt42 = GetDlgItem(ghReproducer, St42);
		hDia1 = GetDlgItem(ghReproducer, Dia1);
		hDia2 = GetDlgItem(ghReproducer, Dia2);
		hDia3 = GetDlgItem(ghReproducer, Dia3);
		hDia4 = GetDlgItem(ghReproducer, Dia4);
		hDia5 = GetDlgItem(ghReproducer, Dia5);
		hDia6 = GetDlgItem(ghReproducer, Dia6);
		hDia7 = GetDlgItem(ghReproducer, Dia7);
		hDia8 = GetDlgItem(ghReproducer, Dia8);
		hDia9 = GetDlgItem(ghReproducer, Dia9);
		hDia10 = GetDlgItem(ghReproducer, Dia10);
		hDia11 = GetDlgItem(ghReproducer, Dia11);
		hDia12 = GetDlgItem(ghReproducer, Dia12);
		hDia13 = GetDlgItem(ghReproducer, Dia13);
		hDia14 = GetDlgItem(ghReproducer, Dia14);
		hDia15 = GetDlgItem(ghReproducer, Dia15);
		hDia16 = GetDlgItem(ghReproducer, Dia16);
		hDia17 = GetDlgItem(ghReproducer, Dia17);
		hDia18 = GetDlgItem(ghReproducer, Dia18);
		hDia19 = GetDlgItem(ghReproducer, Dia19);
		hDia20 = GetDlgItem(ghReproducer, Dia20);
		hDia21 = GetDlgItem(ghReproducer, Dia21);
		hDia22 = GetDlgItem(ghReproducer, Dia22);
		hDia23 = GetDlgItem(ghReproducer, Dia23);
		hDia24 = GetDlgItem(ghReproducer, Dia24);
		hDia25 = GetDlgItem(ghReproducer, Dia25);
		hDia26 = GetDlgItem(ghReproducer, Dia26);
		hDia27 = GetDlgItem(ghReproducer, Dia27);
		hDia28 = GetDlgItem(ghReproducer, Dia28);
		hDia29 = GetDlgItem(ghReproducer, Dia29);
		hDia30 = GetDlgItem(ghReproducer, Dia30);
		hDia31 = GetDlgItem(ghReproducer, Dia31);
		hDia32 = GetDlgItem(ghReproducer, Dia32);
		hDia33 = GetDlgItem(ghReproducer, Dia33);
		hDia34 = GetDlgItem(ghReproducer, Dia34);
		hDia35 = GetDlgItem(ghReproducer, Dia35);
		hDia36 = GetDlgItem(ghReproducer, Dia36);
		hDia37 = GetDlgItem(ghReproducer, Dia37);
		hDia38 = GetDlgItem(ghReproducer, Dia38);
		hDia39 = GetDlgItem(ghReproducer, Dia39);
		hDia40 = GetDlgItem(ghReproducer, Dia40);
		hDia41 = GetDlgItem(ghReproducer, Dia41);
		hDia42 = GetDlgItem(ghReproducer, Dia42);
#pragma endregion

		SendMessage(hSelectMes, CB_ADDSTRING, 0, (LPARAM)"Enero");
		SendMessage(hSelectMes, CB_ADDSTRING, 1, (LPARAM)"Febrero");
		SendMessage(hSelectMes, CB_ADDSTRING, 2, (LPARAM)"Marzo");
		SendMessage(hSelectMes, CB_ADDSTRING, 3, (LPARAM)"Abril");
		SendMessage(hSelectMes, CB_ADDSTRING, 4, (LPARAM)"Mayo");
		SendMessage(hSelectMes, CB_ADDSTRING, 5, (LPARAM)"Junio");
		SendMessage(hSelectMes, CB_ADDSTRING, 6, (LPARAM)"Julio");
		SendMessage(hSelectMes, CB_ADDSTRING, 7, (LPARAM)"Agosto");
		SendMessage(hSelectMes, CB_ADDSTRING, 8, (LPARAM)"Septiembre");
		SendMessage(hSelectMes, CB_ADDSTRING, 9, (LPARAM)"Octubre");
		SendMessage(hSelectMes, CB_ADDSTRING, 10, (LPARAM)"Noviembre");
		SendMessage(hSelectMes, CB_ADDSTRING, 11, (LPARAM)"Diciembre");

		return true;
	}

	case WM_TIMER:
	{
		Alarma(ghReproducer);
		return true;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case BtnBuscar:
		{
			int Dia[42] = { St1 ,St2 ,St3 ,St4 ,St5 ,St6 ,St7 ,St8 ,St9 ,St10 ,St11 ,St12 ,St13 ,St14 ,St15 ,St16 ,St17 ,St18 ,St19 ,St20 ,St21 ,St22 ,St23 ,St24 ,St25 ,St26 ,St27 ,St28 ,St29 ,St30 ,St31 ,St32 ,St33 ,St34 ,St35, St36, St37, St38, St39, St40, St41, St42 };
			int Lista[42] = { Dia1 ,Dia2 ,Dia3 ,Dia4 ,Dia5 ,Dia6 ,Dia7 ,Dia8 ,Dia9 ,Dia10 ,Dia11 ,Dia12 ,Dia13 ,Dia14 ,Dia15 ,Dia16 ,Dia17 ,Dia18 ,Dia19 ,Dia20 ,Dia21 ,Dia22 ,Dia23 ,Dia24 ,Dia25 ,Dia26 ,Dia27 ,Dia28 ,Dia29 ,Dia30 ,Dia31 ,Dia32 ,Dia33 ,Dia34 ,Dia35, Dia36, Dia37, Dia38, Dia39, Dia40, Dia41, Dia42 };
			int mes = 0, anio = 0;

			for(int i = 0; i<=42; i++)
			{
				SetWindowText(GetDlgItem(ghReproducer, Dia[i]), "");
			}

			for (int i = 0; i <= 42; i++)
			{
				SendDlgItemMessage(ghReproducer, Lista[i], LB_DELETESTRING, 0, 0);
			}

			mes = SendMessage(hSelectMes, CB_GETCURSEL, 0, 0);
			mes = mes + 1;
			GetWindowText(hSelectAnio, buffer, sizeof(buffer));
			anio = atoi(buffer);

			calendario(mes, anio, ghReproducer);
			return true;
		}
		
		case BtnSalir:
		{
			EndDialog(ghReproducer, 0);
			return true;
		}

		return true;
		}
		return true;
	}
	}

	return false;
}
#pragma endregion


//****FUNCIONES****
void AgregarFoto(HWND Dialog, HWND Objeto)
{
	char szFile[MAX_PATH];
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = Dialog;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = "Imagen BITMAP\0*.bmp\0";
	ofn.nFilterIndex = 2;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
		SetWindowText(Objeto, ofn.lpstrFile);
	}
}

void AgregarMusica(HWND Dialog, HWND Objeto)
{
	char szFile[MAX_PATH];
	OPENFILENAME ofn;

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = Dialog;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFilter = "Musica MP3\0*.mp3\0";
	ofn.nFilterIndex = 2;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn) == TRUE)
	{
		SetWindowText(Objeto, ofn.lpstrFile);
	}
}

void Guardar_archivoContactos()
{
	sprintf(Save, "%s\\%s", Carpeta, ContactosFile);

	Contacto *escribir;
	escribir = inicio;

	ofstream descargar;
	descargar.open(Save, ios::out | ios::binary | ios::trunc);
	if (inicio != NULL)
	{
		while (escribir != NULL)
		{
			descargar.write((char*)reinterpret_cast < char* > (escribir), sizeof(Contacto));
			escribir = escribir->sig;
		}

	}
}

void Leer_archivoContactos()
{
	sprintf(Save, "%s\\%s", Carpeta, ContactosFile);
	Contacto *nuevo;
	ifstream cargar;
	cargar.open(Save, ios::in | ios::binary);
	if (cargar.is_open())
	{
		nuevo = new Contacto;
		cargar.read(reinterpret_cast<char*>(nuevo), sizeof(Contacto));
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		while (!cargar.eof())
		{
			if (inicio == NULL)
			{
				inicio = nuevo;
				ultimo = nuevo;
				aux = nuevo;
			}
			else
			{
				nuevo->ant = ultimo;
				ultimo->sig = nuevo;
				ultimo = ultimo->sig;
			}
			nuevo = new Contacto;
			cargar.read(reinterpret_cast<char*>(nuevo), sizeof(Contacto));
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		}
	}
}

void Guardar_archivoEventos()
{
	sprintf(Save, "%s\\%s", Carpeta, EventosFile);

	Evento *escribir;
	escribir = inicio2;

	ofstream descargar;
	descargar.open(Save, ios::out | ios::binary | ios::trunc);
	if (inicio2 != NULL)
	{
		while (escribir != NULL)
		{
			descargar.write((char*)reinterpret_cast < char* > (escribir), sizeof(Evento));
			escribir = escribir->sig;
		}

	}
}

void Leer_archivoEventos()
{
	sprintf(Save, "%s\\%s", Carpeta, EventosFile);
	Evento *nuevo;
	ifstream cargar;
	cargar.open(Save, ios::in | ios::binary);
	if (cargar.is_open())
	{
		nuevo = new Evento;
		cargar.read(reinterpret_cast<char*>(nuevo), sizeof(Evento));
		nuevo->sig = NULL;
		nuevo->ant = NULL;
		while (!cargar.eof())
		{
			if (inicio2 == NULL)
			{
				inicio2 = nuevo;
				ultimo2 = nuevo;
				aux2 = nuevo;
			}
			else
			{
				ultimo2->sig = nuevo;
				nuevo->ant = ultimo2;
				ultimo2 = nuevo;
			}
			nuevo = new Evento;
			cargar.read(reinterpret_cast<char*>(nuevo), sizeof(Evento));
			nuevo->sig = NULL;
			nuevo->ant = NULL;
		}
	}
}

void Alarma(HWND window)
{
	char dia[10];
	char mes[10];
	char anio[10];

	char fecha[15];
	char hora[15];

	//FECHA
	int i = 0;
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(dia, sizeof(dia), "%d", timeinfo);
	strftime(mes, sizeof(mes), "%m", timeinfo);
	strftime(anio, sizeof(anio), "%Y", timeinfo);
	strftime(fecha, sizeof(fecha), "%d/%m/%Y", timeinfo);
	strftime(hora, sizeof(hora), "%T", timeinfo);

	int diaa = atoi(dia);
	int mesa = atoi(mes);
	int anioa = atoi(anio);

	aux3 = inicio2;
	if (inicio2 != NULL)
	{
		while (aux3 != NULL)
		{
			if (strncmp(aux3->fecha, fecha, MAX_PATH) == 0)
			{
				if (strncmp(aux3->hora, hora, MAX_PATH) == 0)
				{
					if (aux3->yafue == false)
					{
						aux3->yafue = true;
						//KillTimer(window, TimmerID1);
						DialogBox(WanderLey, MAKEINTRESOURCE(IDD_ALARMA), hInicio, ProcAlarma);
						break;
					}
				}
			}

			int anio2, mes2, dia2;
			anio2 = stoi(aux3->anio);
			mes2 = stoi(aux3->mes);
			dia2 = stoi(aux3->dia);

			if (anio2 < anioa || anio2 == anioa)
			{
				if (mes2 < mesa || mes2 == mesa)
				{
					if(dia2 < diaa || dia2 == diaa)
					{
						if (strncmp(aux3->hora, hora, MAX_PATH) < 0)
						{
							if (aux3->yafue == false)
							{
								aux3->yafue = true;
								//KillTimer(window, TimmerID1);
								DialogBox(WanderLey, MAKEINTRESOURCE(IDD_ALARMA), hInicio, ProcAlarma);
								break;
							}
						}
					}
				}
			}
			aux3 = aux3->sig;
		}
	}
	aux3 = NULL;
}

void calendario(int mes, int anio, HWND window)
{
	char buffer[256];
	int Dia[42] = { St1 ,St2 ,St3 ,St4 ,St5 ,St6 ,St7 ,St8 ,St9 ,St10 ,St11 ,St12 ,St13 ,St14 ,St15 ,St16 ,St17 ,St18 ,St19 ,St20 ,St21 ,St22 ,St23 ,St24 ,St25 ,St26 ,St27 ,St28 ,St29 ,St30 ,St31 ,St32 ,St33 ,St34 ,St35, St36, St37, St38, St39, St40, St41, St42 };
	int Lista[42] = { Dia1 ,Dia2 ,Dia3 ,Dia4 ,Dia5 ,Dia6 ,Dia7 ,Dia8 ,Dia9 ,Dia10 ,Dia11 ,Dia12 ,Dia13 ,Dia14 ,Dia15 ,Dia16 ,Dia17 ,Dia18 ,Dia19 ,Dia20 ,Dia21 ,Dia22 ,Dia23 ,Dia24 ,Dia25 ,Dia26 ,Dia27 ,Dia28 ,Dia29 ,Dia30 ,Dia31 ,Dia32 ,Dia33 ,Dia34 ,Dia35, Dia36, Dia37, Dia38, Dia39, Dia40, Dia41, Dia42 };
	int dia = 0;

	int z = zeller(anio, mes);

	for(dia; dia<z; dia++)
	{
		SetWindowText(GetDlgItem(window, Dia[dia]), "");
	}

	int diasMes = CalcularDiasMes(anio, mes);

	for (int i = 1; i <= diasMes; i++)
	{
		sprintf(buffer, "%i", i);
		SetWindowText(GetDlgItem(window, Dia[dia]), buffer);

		auxcal = inicio2;
		if(inicio2 != NULL)
		{
			while (auxcal != 0)
			{
				int anio2, mes2, dia2;
				anio2 = stoi(auxcal->anio);
				mes2 = stoi(auxcal->mes);
				dia2 = stoi(auxcal->dia);
				if (anio2 == anio)
				{
					if (mes2 == mes)
					{
						if (dia2 == i)
						{
							SendDlgItemMessage(window, Lista[dia], LB_ADDSTRING, 0, (LPARAM)auxcal->nombre);
						}
					}
				}
				auxcal = auxcal->sig;
			}
		}
		dia++;
	}
	auxcal = NULL;
}

int CalcularDiasMes(int anio, int mes)
{
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
		return 31;

	if (mes == 2)
	{
		if (Bisiesto(anio)) return 29;
		return 28;
	}

	return 30;
}

bool Bisiesto(int anio)
{
	if (anio % 4 != 0)
		return false;
	if (anio % 100 != 0)
		return true;
	if (anio % 400 != 0)
		return false;

	return true;
}

// domingo = 0, lunes = 1, martes = 2, miercoles = 3, jueves = 4, viernes = 5, sabado = 6
int zeller(int anio, int mes)
{
	int a = (14 - mes) / 12;
	int y = anio - a;
	int m = mes + 12 * a - 2;
	int dia = 1, d;
	d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}