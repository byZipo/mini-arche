// Test1.cpp : définit le point d'entrée pour l'application.
//

#include "stdafx.h"
#include "Test1.h"
#include <iostream>
#include <commdlg.h>
#include "Modele.h"
#include <atlstr.h>


#define MAX_LOADSTRING 100
int  I = 0;
// Variables globales :
HINSTANCE hInst;
OPENFILENAME ofn;
std::wstring CoursEnCours;
LPWSTR pathFile;
int cmpt = 0;
std::string nomUser = "";
Modele *m;// instance actuelle
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
	m = new Modele();
	Cours *c1 = new Cours("Logique", 15);
	Cours *c2 = new Cours("WEB 2", 20);
	Cours *c3 = new Cours("Systeme", 11);
	Etudiant *e1 = new Etudiant();
	Etudiant *e2 = new Etudiant();
	Etudiant *e3 = new Etudiant();
	Etudiant *e4 = new Etudiant();
	Professeur *p1 = new Professeur();
	p1->setNom("Sokolov");
	p1->setPrenom("toto");
	m->ajouterProf(*p1);
	
	
	e1->setNom("Delavelle");
	e2->setNom("Jeannerot");
	e3->setNom("André");
	e1->setPrenom("111");
	e2->setPrenom("111");
	e3->setPrenom("111");

	e4->setNom("user");
	e4->setPrenom("user");
	
	
	m->ajouterEtudiant(*e1);
	m->ajouterEtudiant(*e2);
	m->ajouterEtudiant(*e3);

	
	m->ajouterCours(*c1);
	m->ajouterCours(*c2);
	m->ajouterCours(*c3);
	c1->addEtudiantListePrincipale(*e1);
	c3->addEtudiantListePrincipale(*e1);

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
	TCHAR Enseignant[12];
	int nbEleves;
	int placesRestantes;
} Cour;

typedef struct
{
	TCHAR achName[MAX_PATH];
	
} Ress;

Cour Roster[1000];
Cour ListeCoursEtuNonInscrit[1000];
Cour ListeCoursEtu[1000];
Cour ListeCoursProf[1000];
Ress ListeRessources[1000];
/*
Cour Roster[] =
{
	
	
	{ TEXT("WEB 2"), TEXT("Brigitte"), 18, 10 },
	{ TEXT("WEB 2"), TEXT("Urso"), 36, 0 },
	{ TEXT("RIEN"), TEXT("Tong"), 26, 5 },
	{ TEXT("Logique"), TEXT("Loufti"), 24, 0 },
	{ TEXT("Maths"), TEXT("Chichon"), 26, 3 },
	{ TEXT("Système"), TEXT("Colotte"), 24, 3 },
};
*/
void remplirListeRessources(){
	string n(CoursEnCours.begin(), CoursEnCours.end());
	for (unsigned int i = 0; i < m->getCours(n).getAllRessource().size(); i++){
		std::string t = m->getCours(n).getRessource(i)->getNom();

		//const TCHAR* data = (TCHAR*)t.c_str();

		TCHAR *param = new TCHAR[t.size() + 1];
		//*param = ;
		TCHAR szProxyAddr[260];

		_tcscpy_s(szProxyAddr, CA2T(t.c_str()));
		//As much as we'd love to, we can't use memcpy() because
		//sizeof(TCHAR)==sizeof(char) may not be true:
		for (unsigned int j = 0; j < 260; j++){
			ListeRessources[i].achName[j] = szProxyAddr[j];
			//Roster[i] = { { (szProxyAddr[1])} };
		}
	}
}
void remplirRoster(){
	for (unsigned int i = 0; i < m->getListeCours().size(); i++){
		std::string t = m->getCoursAt(i).getNomCours();

		//const TCHAR* data = (TCHAR*)t.c_str();

		TCHAR *param = new TCHAR[t.size() + 1];
		//*param = ;
		TCHAR szProxyAddr[260];

		_tcscpy_s(szProxyAddr, CA2T(t.c_str()));
		//As much as we'd love to, we can't use memcpy() because
		//sizeof(TCHAR)==sizeof(char) may not be true:
		for (unsigned int j = 0; j < 260; j++){
		Roster[i].achName[j] = szProxyAddr[j];
		//Roster[i] = { { (szProxyAddr[1])} };
		}
	}
}




void remplirListeCoursEtuNonInscrit(){
	vector<Cours>* listeCoursPasInscrit = m->getCoursEtuPasInscrit(m->getEtudiant(nomUser));
	for (unsigned int i = 0; i < listeCoursPasInscrit->size(); i++){
		std::string t = listeCoursPasInscrit->at(i).getNomCours();

		//const TCHAR* data = (TCHAR*)t.c_str();

		TCHAR *param = new TCHAR[t.size() + 1];
		//*param = ;
		TCHAR szProxyAddr[260];
		
		_tcscpy_s(szProxyAddr, CA2T(t.c_str()));
		//As much as we'd love to, we can't use memcpy() because
		//sizeof(TCHAR)==sizeof(char) may not be true:
		for (unsigned int j = 0; j < 260; j++){
			ListeCoursEtuNonInscrit[i].achName[j] = szProxyAddr[j];
			//Roster[i] = { { (szProxyAddr[1])} };
		}
		
	}
}


void remplirListeCoursEtu(){
	for (unsigned int i = 0; i < m->getListeCoursEtudiant(m->getEtudiant(nomUser)).size(); i++){
		std::string t = m->getListeCoursEtudiant(m->getEtudiant(nomUser)).at(i).getNomCours();
		//std::string t = m->getCoursAt(i).getNomCours();
		//const TCHAR* data = (TCHAR*)t.c_str();

		TCHAR *param = new TCHAR[t.size() + 1];
		//*param = ;
		TCHAR szProxyAddr[260];

		_tcscpy_s(szProxyAddr, CA2T(t.c_str()));
		//As much as we'd love to, we can't use memcpy() because
		//sizeof(TCHAR)==sizeof(char) may not be true:
		for (unsigned int j = 0; j < 260; j++){
			ListeCoursEtu[i].achName[j] = szProxyAddr[j];
			//Roster[i] = { { (szProxyAddr[1])} };
		}
	}
}

void remplirListeCoursProf(){
	for (unsigned int i = 0; i < m->getListeCoursProf(m->getProfesseur(nomUser)).size(); i++){
		std::string t = m->getListeCoursProf(m->getProfesseur(nomUser)).at(i).getNomCours();
		//std::string t = m->getCoursAt(i).getNomCours();
		//const TCHAR* data = (TCHAR*)t.c_str();

		TCHAR *param = new TCHAR[t.size() + 1];
		//*param = ;
		TCHAR szProxyAddr[260];

		_tcscpy_s(szProxyAddr, CA2T(t.c_str()));
		//As much as we'd love to, we can't use memcpy() because
		//sizeof(TCHAR)==sizeof(char) may not be true:
		for (unsigned int j = 0; j < 260; j++){
			ListeCoursProf[i].achName[j] = szProxyAddr[j];
			//Roster[i] = { { (szProxyAddr[1])} };
		}
	}
}




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
	if (!m->estProfesseur(nomUser)){
		
		EnableMenuItem(hmenu, ID_OPTIONS_AJOUTCOURS, MF_DISABLED | MF_GRAYED);
		EnableMenuItem(hmenu, ID_OPTIONS_SUPPRIMERCOURS, MF_DISABLED | MF_GRAYED);
		EnableMenuItem(hmenu, ID_OPTIONS_INSCRIPTION, MF_ENABLED);
	}
	else{
		EnableMenuItem(hmenu, ID_OPTIONS_AJOUTCOURS, MF_ENABLED);
		EnableMenuItem(hmenu, ID_OPTIONS_SUPPRIMERCOURS, MF_ENABLED);
		EnableMenuItem(hmenu, ID_OPTIONS_INSCRIPTION, MF_DISABLED | MF_GRAYED);
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
		case ID_OPTIONS_SUPPRIMERCOURS:
			cmpt = 0;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DELETE_COURS), hWnd, About);
			break;
		case ID_OPTIONS_INSCRIPTION:
			cmpt = 1;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_INSCRIPTION), hWnd, About);
			break;
		case ID_CONCULTATION_VOIRSESCOURS:
			cmpt = 2;
			//return TRUE;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_LIST_COURS), hWnd, About);
			break;
		case ID_OPTIONS_DESINSCRIPTION:
			cmpt = 3;
			//return TRUE;
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DESINCRIP), hWnd, About);
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
	HWND hwndListCoursNonInscrit = GetDlgItem(hDlg, IDC_LIST4);
	HWND hwndListCoursInscrit = GetDlgItem(hDlg, IDC_LIST5);
	HWND hwndListCoursDesc = GetDlgItem(hDlg, IDC_LIST6);
	HWND hwndListRessources = GetDlgItem(hDlg, IDC_LIST1);
	
	//UNREFERENCED_PARAMETER(lParam)
	switch (message)
	{
	case WM_INITDIALOG:
		
		
		//

		//for (int i = 0; i < ARRAYSIZE(Roster); i++)
		if (cmpt == 0){
			remplirRoster();
			for (unsigned int i = 0; i < m->getListeCours().size(); i++)
			{
				int pos = (int)SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)Roster[i].achName);
			}
		}
		else if (cmpt == 1){
			
			remplirListeCoursEtuNonInscrit();
		//	MessageBox(hDlg, nomUser.c_str(), L"Connexion refusée", NULL);
			//vector<Cours> listeCoursPasInscrit = m->getCoursEtuPasInscrit(m->getEtudiant(nomUser));
			for (unsigned int i = 0; i < m->getCoursEtuPasInscrit(m->getEtudiant(nomUser))->size(); i++){
				int pas = (int)SendMessage(hwndListCoursNonInscrit, LB_ADDSTRING, 0, (LPARAM)ListeCoursEtuNonInscrit[i].achName);
			}
		}
		else if (cmpt == 2 && !m->estProfesseur(nomUser)){
			remplirListeCoursEtu();
			
			for (unsigned int i = 0; i < m->getListeCoursEtudiant(m->getEtudiant(nomUser)).size(); i++){
				
				int pis = (int)SendMessage(hwndListCoursInscrit, LB_ADDSTRING, 0, (LPARAM)ListeCoursEtu[i].achName);
			}
		}
		else if (cmpt == 3 && !m->estProfesseur(nomUser)){
			remplirListeCoursEtu();

			for (unsigned int i = 0; i < m->getListeCoursEtudiant(m->getEtudiant(nomUser)).size(); i++){

				int pis = (int)SendMessage(hwndListCoursDesc, LB_ADDSTRING, 0, (LPARAM)ListeCoursEtu[i].achName);
			}
		}




		else if (cmpt == 2 && m->estProfesseur(nomUser)){
			remplirListeCoursProf();
			for (unsigned int i = 0; i < m->getListeCoursProf(m->getProfesseur(nomUser)).size(); i++){
				int pis = (int)SendMessage(hwndListCoursInscrit, LB_ADDSTRING, 0, (LPARAM)ListeCoursProf[i].achName);
			}
		}
		else if (cmpt == 4){
			remplirListeRessources();
			string n(CoursEnCours.begin(), CoursEnCours.end());
			for (unsigned int i = 0; i < m->getCours(n).getAllRessource().size(); i++){
				int pys = (int)SendMessage(hwndListRessources, LB_ADDSTRING, 0, (LPARAM)ListeRessources[i].achName);
			}
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
			std::wstring toto = Login;
			string ns(toto.begin(), toto.end());
			std::wstring tata = Pwd;
			string nx(tata.begin(), tata.end());
			nomUser = ns;
			if (wcslen(Login) != 0 && wcslen(Pwd) != 0){
				if (m->estProfesseur(ns)){
					if (m->getProfesseur(ns).getPrenom() == nx){
						message1 += Login;
						MessageBox(hDlg, message1.c_str(), L"Connexion réussie", NULL);
						EndDialog(hDlg, LOWORD(wParam));
					}
					else{
						MessageBox(hDlg, L"Password incorrect", L"Connexion refusée", NULL);
					}
					/*if(!estUnProf())*/
					//I++;
				}
				else if (m->estEtudiant(ns)){
					if (m->getEtudiant(ns).getPrenom() == nx){
						message1 += Login;
						MessageBox(hDlg, message1.c_str(), L"Connexion réussie", NULL);
						EndDialog(hDlg, LOWORD(wParam));
					}
					else{
						MessageBox(hDlg, L"Password incorrect", L"Connexion refusée", NULL);
					}
				}
				else{
					MessageBox(hDlg, L"Login incorrect", L"Connexion refusée", NULL);
				}
				
					/**/
					
				
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
			wchar_t Cour[128];
			GetDlgItemText(hDlg, IDC_TITRE, Cour, 50);
			std::wstring message2 = L"Cours  ";
			std::wstring toto = Cour;
			

			string ns(toto.begin(), toto.end());

			//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)


			/* ajouter fonction de test de l'existance du cours */
			if (wcslen(Cour) != 0 &&  m->estDisponible(ns)){
				message2 += Cour;
				message2 += L" ajouté !";
				Cours *o = new Cours(ns, 30);
				m->ajouterCours(*o);
				MessageBox(hDlg, message2.c_str(), L"Ajout réussi", NULL);
				EndDialog(hDlg, LOWORD(wParam));

			}
			else{
				MessageBox(hDlg, L"Veuillez renseigner un Titre valide", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_DELETE_COURS){
			wchar_t Title[128];
			GetDlgItemText(hDlg, IDC_COURS_A_DELETE, Title, 50);
			std::wstring message1 = L"Cours  ";

			std::wstring tata = Title;


			string ns(tata.begin(), tata.end());
			/* ajouter fonction de test de l'existance du cours */
			bool toto = false;
			for (int i = 0; i < ARRAYSIZE(Roster); i++)
			{
				if (_tcscmp(Roster[i].achName, Title) == 0){
					toto = true;
				}
			}
			if (wcslen(Title) != 0 && toto == true){
				
				
				m->supprimerCours(m->getCours(ns));
				message1 += Title;
				message1 += L" supprimé !";
				MessageBox(hDlg, message1.c_str(), L"Suppression effectuée", NULL);
				EndDialog(hDlg, LOWORD(wParam));
				// Ajouter fonction de suppression dans la liste des cours 

			}
			else{
				MessageBox(hDlg, L"Le cours saisi n'existe pas dans la liste", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_OK_INSC){
			wchar_t Title[128];
			GetDlgItemText(hDlg, IDC_COURS_TO_INSC, Title, 50);
			std::wstring message1 = L"Inscription au cours  ";
			
			bool toto = false;
			for (int i = 0; i < ARRAYSIZE(Roster); i++)
			{
				if (_tcscmp(Roster[i].achName, Title) == 0){
					toto = true;
				}
			}
			if (wcslen(Title) != 0 && toto == true && m->coursEstDispoPourEtu(nomUser)){


				std::wstring tata = Title;
				string ns(tata.begin(), tata.end());
				
				if (m->ListePrincipaleDisponible(m->getCours(ns))){
					m->getCours(ns).addEtudiantListePrincipale(m->getEtudiant(nomUser));
				}
				else{
					m->getCours(ns).addEtudiantListeAttente(m->getEtudiant(nomUser));
				}
				message1 += Title;
				message1 += L" réussie !";
				MessageBox(hDlg, message1.c_str(), L"Inscription effectuée", NULL);
				EndDialog(hDlg, LOWORD(wParam));
				// Ajouter fonction de suppression dans la liste des cours 

			}
			else{
				MessageBox(hDlg, L"Le cours saisi n'existe pas dans la liste", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_OK_DESINSC){
			wchar_t Title[128];
			GetDlgItemText(hDlg, IDC_COURS_TO_DESINSC, Title, 50);
			std::wstring message1 = L"Désinscription au cours  ";

			bool toto = false;
			for (int i = 0; i < ARRAYSIZE(Roster); i++)
			{
				if (_tcscmp(Roster[i].achName, Title) == 0){
					toto = true;
				}
			}
			if (wcslen(Title) != 0 && toto == true && m->coursEstDispoPourEtu(nomUser)){


				std::wstring tata = Title;
				string ns(tata.begin(), tata.end());

				m->getCours(ns).supprimerEtudiant(m->getEtudiant(nomUser));
				message1 += Title;
				message1 += L" réussie !";
				MessageBox(hDlg, message1.c_str(), L"Désinscription effectuée", NULL);
				EndDialog(hDlg, LOWORD(wParam));
				// Ajouter fonction de suppression dans la liste des cours 

			}
			else{
				MessageBox(hDlg, L"Le cours saisi n'existe pas dans la liste", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_SHOW_COURS){
			cmpt = 4;
			wchar_t Title[128];
			GetDlgItemText(hDlg, IDC_COURS_TO_SHOW, Title, 50);
			std::wstring message1 = L"Cours  ";
			/* ajouter fonction de test de l'existance du cours */
			bool toto = false;
			for (int i = 0; i < ARRAYSIZE(Roster); i++)
			{
				if (_tcscmp(Roster[i].achName, Title) == 0){
					toto = true;
				}
			}
			if (wcslen(Title) != 0 && toto == true){


				message1 += Title;
				CoursEnCours = Title;
				message1 += L"";
				if (!m->estProfesseur(nomUser)){
					DialogBox(hInst, MAKEINTRESOURCE(IDD_AFF_COURS), hDlg, About);
				}
				else{
					DialogBox(hInst, MAKEINTRESOURCE(IDD_AFF_COURSPOURPROF), hDlg, About);
				}
				//MessageBox(hDlg, message1.c_str(), L"Votre cours", NULL);
				// Ajouter fonction de suppression dans la liste des cours 

			}
			else{
				MessageBox(hDlg, L"Le cours saisi n'existe pas dans la liste", L"Erreur ", NULL);
			}
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_PARCOURIR){
			OPENFILENAME ofn;
			char szFileName[MAX_PATH] = "";
			wchar_t wtext[20];
			mbstowcs(wtext, szFileName, strlen(szFileName) + 1);//Plus null
			LPWSTR ptr = wtext;
			ZeroMemory(&ofn, sizeof(ofn));

			ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
			ofn.hwndOwner = hDlg;
			// Filtres possibles sur le type du fichier
			ofn.lpstrFilter = L"DOC Files (*.doc)\0*.doc\0"  L"DOCX Files (*.docx)\0*.docx\0" L"Text Files (*.txt)\0*.txt\0" L"ODT Files (*.odt)\0*.odt\0"L"PDF Files (*.pdf)\0*.pdf\0All Files (*.*)\0*.*\0";
			ofn.lpstrFile = ptr;
			ofn.nMaxFile = MAX_PATH;
			ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
			ofn.lpstrDefExt = L"txt";

			if (GetOpenFileName(&ofn))
			{
				//nom du fichier
				MessageBox(hDlg, ofn.lpstrFile, L"Nom du fichier ", NULL);
				LPWSTR tmp = ofn.lpstrFile;
				pathFile = tmp;
		
				
				
			}
			//ici réaliser la copie du fichier lu dans un nouveau fichier HANDLE hFile = CreateFile();
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_AJOUTER){
			wchar_t Title[128];
			
			std::wstring s = pathFile;
			string ns(s.begin(), s.end());
			GetDlgItemText(hDlg, IDC_NOMRESSOURCE, Title, 50);
			std::wstring message1 = L"Cours  ";
			if (pathFile == L"null"){
				MessageBox(hDlg, L"Veuillez selectionner un fichier", L"Erreur ", NULL);
			}
			else if (wcslen(Title) == 0){
				MessageBox(hDlg, L"Veuillez rentrer un nom de fichier", L"Erreur ", NULL);
			}
			
			else{
				
				if (m->donneExtension(ns)=="pdf"){
					/*PDF *p = new PDF();
					string n(CoursEnCours.begin(), CoursEnCours.end());
					m->getCours(n).addRessources(p);*/

					MessageBox(hDlg, L"Ressource PDF ajoutée", L"Ajout effectué ", NULL);
					EndDialog(hDlg, LOWORD(wParam));
				}
				else if (m->donneExtension(ns) == "docx" || m->donneExtension(ns) == "doc" || m->donneExtension(ns) == "txt"){
					/*Devoir *d = new Devoir();
					string n(CoursEnCours.begin(), CoursEnCours.end());
					m->getCours(n).addRessources(d);*/
					MessageBox(hDlg, L"Ressource ajoutée", L"Ajout effectué ", NULL);
					EndDialog(hDlg, LOWORD(wParam));
				}
				else{
					std::wstring toto = Title;


					string ns(toto.begin(), toto.end());
					Ressource *r=new Ressource(ns,"pdf");
					string n(CoursEnCours.begin(), CoursEnCours.end());
					
					
					m->getCours(n).addRessources(r);
					MessageBox(hDlg, L"Ressource ajoutée" ,L"Ajout effectué ", NULL);
					EndDialog(hDlg, LOWORD(wParam));
				}
				
			}
			return (INT_PTR)TRUE;
		}

		
		break;
	}
	return (INT_PTR)FALSE;
}
