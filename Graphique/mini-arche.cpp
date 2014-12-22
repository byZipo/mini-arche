// Test1.cpp : définit le point d'entrée pour l'application.
//

#include "stdafx.h"
#include "Test1.h"
#include <iostream>

#define MAX_LOADSTRING 100
int  I = 0;
// Variables globales :
HINSTANCE hInst;								// instance actuelle
TCHAR szTitle[MAX_LOADSTRING];					// Le texte de la barre de titre
TCHAR szWindowClass[MAX_LOADSTRING];			// le nom de la classe de fenêtre principale

// Pré-déclarations des fonctions incluses dans ce module de code :
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 	// TODO: placez ici le code.
	MSG msg;
	HACCEL hAccelTable;

	// Initialise les chaînes globales
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_TEST1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Effectue l'initialisation de l'application :
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEST1));

	// Boucle de messages principale :
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FONCTION : MyRegisterClass()
//
//  BUT : inscrit la classe de fenêtre.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEST1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_TEST1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FONCTION : InitInstance(HINSTANCE, int)
//
//   BUT : enregistre le handle de l'instance et crée une fenêtre principale
//
//   COMMENTAIRES :
//
//        Dans cette fonction, nous enregistrons le handle de l'instance dans une variable globale, puis
//        créons et affichons la fenêtre principale du programme.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
  
  
   hInst = hInstance; // Stocke le handle d'instance dans la variable globale

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
  

   if (!hWnd)
   {
      return FALSE;
   }
   

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FONCTION : WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  BUT :  traite les messages pour la fenêtre principale.
//
//  WM_COMMAND	- traite le menu de l'application
//  WM_PAINT	- dessine la fenêtre principale
//  WM_DESTROY	- génère un message d'arrêt et retourne
//
//
typedef struct
{
	TCHAR achName[MAX_PATH];
	TCHAR achPosition[12];
	int nGamesPlayed;
	int nGoalsScored;
} Player;

Player Roster[] =
{
	{ TEXT("Haas, Jonathan"), TEXT("Midfield"), 18, 4 },
	{ TEXT("Pai, Jyothi"), TEXT("Forward"), 36, 12 },
	{ TEXT("Hanif, Kerim"), TEXT("Back"), 26, 0 },
	{ TEXT("Anderberg, Michael"), TEXT("Back"), 24, 2 },
	{ TEXT("Jelitto, Jacek"), TEXT("Midfield"), 26, 3 },
	{ TEXT("Raposo, Rui"), TEXT("Back"), 24, 3 },
	{ TEXT("Joseph, Brad"), TEXT("Forward"), 13, 3 },
	{ TEXT("Bouchard, Thomas"), TEXT("Forward"), 28, 5 },
	{ TEXT("Salmre, Ivo "), TEXT("Midfield"), 27, 7 },
	{ TEXT("Camp, David"), TEXT("Midfield"), 22, 3 },
	{ TEXT("Kohl, Franz"), TEXT("Goalkeeper"), 17, 0 },
};


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	using namespace std;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//LPWSTR ptr;
	//HWND hListBox;
	HMENU hmenu = GetMenu(hWnd);
	
	/*remplacer le test sur I par un test sur la personne (Professeur ou non)*/
	if (I == 1){
		
		EnableMenuItem(hmenu, ID_OPTIONS_AJOUTCOURS, MF_DISABLED | MF_GRAYED);
	}
	else{
		EnableMenuItem(hmenu, ID_OPTIONS_AJOUTCOURS, MF_ENABLED);
	}
	switch (message)
	{

	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		

		// Analyse les sélections de menu :
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			
			
			break;
		case IDM_EXIT:
			
			DialogBox(hInst, MAKEINTRESOURCE(IDD_Quit), hWnd, About);
			break;
		case ID_OPTIONS_AJOUTCOURS:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_AJOUT_COURS), hWnd, About);
			break;
		case ID_CONCULTATION_VOIRSESCOURS:
			
			//return TRUE;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_LIST_COURS), hWnd, About);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
	hdc = BeginPaint(hWnd, &ps);
		// TODO: ajoutez ici le code de dessin...



		/*
		
		char buf[256];
		SYSTEMTIME CurrentTime;
		HFONT hFont;
		hFont = CreateFont(20, 0, 0, 0, 700, FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Comic Sans MS");
		
		hdc = BeginPaint(hWnd, &ps);
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		SelectObject(hdc, hFont);
		GetLocalTime(&CurrentTime);
		sprintf(buf, "%dh%d",CurrentTime.wHour,CurrentTime.wMinute);
		wchar_t wtext[20];
		
		mbstowcs(wtext, buf, strlen(buf) + 1);//Plus null
		ptr = wtext;
		TextOut(hdc, 0, 0, ptr, strlen(buf));
		//EndPaint(hWnd, &ps);
		DeleteObject(hFont);

		*/




		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Gestionnaire de messages pour la boîte de dialogue À propos de.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hwndList = GetDlgItem(hDlg, IDC_LIST3);

	
	//UNREFERENCED_PARAMETER(lParam)
	switch (message)
	{
	case WM_INITDIALOG:
		for (int i = 0; i < ARRAYSIZE(Roster); i++)
		{
			int pos = (int)SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)Roster[i].achName);
			// Set the array index of the player as item data.
			// This enables us to retrieve the item from the array
			// even after the items are sorted by the list box.
			SendMessage(hwndList, LB_SETITEMDATA, pos, (LPARAM)i);
		}
		// Set input focus to the list box.
		SetFocus(hwndList);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{

			wchar_t Login[128];
			wchar_t Pwd[128];
			std::wstring message1 = L"Bienvenue  ";

			GetDlgItemText(hDlg, IDC_EDIT1, Login, 50);
			GetDlgItemText(hDlg, IDC_EDIT2, Pwd, 50);
			if (wcslen(Login) != 0 && wcslen(Pwd) != 0){
				message1 += Login;
				MessageBox(hDlg, message1.c_str(), L"Connexion réussie", NULL);
				
				/*if(!estUnProf())*/
				I++;
				
				
				/**/
				EndDialog(hDlg, LOWORD(wParam));
				
			}
			else{
				MessageBox(hDlg, L"Veuillez renseigner votre Login / Mot de passe", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL || LOWORD(wParam) == IDC_BUTTON1){
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_QUIT_OK){
			EndDialog(hDlg, LOWORD(wParam));
			exit(0);
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDOK_COURS){
			wchar_t Title[128];
			GetDlgItemText(hDlg, IDC_TITRE, Title, 50);
			std::wstring message1 = L"Cours  ";
			/* ajouter fonction de test de l'existance du cours */
			if (wcslen(Title) != 0){
				message1 += Title;
				message1 += L" ajouté !";
				MessageBox(hDlg, message1.c_str(), L"Ajout réussi", NULL);
				EndDialog(hDlg, LOWORD(wParam));
				
			}
			else{
				MessageBox(hDlg, L"Veuillez renseigner un Titre valide", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		
		break;
	}
	return (INT_PTR)FALSE;
}
