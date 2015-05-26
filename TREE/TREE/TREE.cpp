/** @file TREE.cpp */

#include <iostream>
using namespace std;

//! Funkciya provodit obhod dereva v pryamom poryadke.
/**
@param uzel - uzel
@param n - kolichestvo uzlov
@param *pTr_1 - ukazatel' na nachalo massiva uzlov
**/
void Direct_order(int uzel, int n, int *pTr_1)
{
	cout << uzel + 1 << " ";

	int *Tr_2 = new int[n];
	for (int i = 0; i < n; i++) Tr_2[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr_1[j] == uzel + 1) Tr_2[j] = pTr_1[j];

	for (int k = 0; k < n; k++)
		if (Tr_2[k]) Direct_order(k, n, pTr_1);

	delete[]Tr_2;
}

//! Funkcija provodit obhod dereva v obratnom poryadke.
/**
@param uzel - uzel
@param n - kolichestvo uzlov
@param *pTr_1 - ukazatel' na nachalo massiva uzlov
**/
void inDirect_order(int uzel, int n, int *pTr_1)
{
	int *Tr_3 = new int[n];
	for (int i = 0; i < n; i++) Tr_3[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr_1[j] == uzel + 1) Tr_3[j] = pTr_1[j];

	for (int k = 0; k < n; k++)
		if (Tr_3[k]) inDirect_order(k, n, pTr_1);

	cout << uzel + 1 << " ";

	delete[]Tr_3;
}

//! Funkciya provodit obhod dereva v simmetrichnom poryadke.
/**
@param uzel - uzel
@param n - kolichestvo uzlov
@param *pTr_1 - ukazatel' na nachalo massiva uzlov
**/
void Symmetric_order(int uzel, int n, int *pTr_1)
{
	int *Tr_4 = new int[n];
	for (int i = 0; i < n; i++) Tr_4[i] = 0;

	for (int j = 0; j < n; j++)
		if (pTr_1[j] == uzel + 1) Tr_4[j] = pTr_1[j];

	for (int k = 0; k < n; k++)
		if (Tr_4[k]) Symmetric_order(k, n, pTr_1);

	int w = 0;
	for (int z = 0; z < n; z++)
		if (pTr_1[z] == uzel + 1) w++;

	if (w == 0) cout << uzel + 1 << " ";
	if ((pTr_1[uzel - 1] != pTr_1[uzel]) && (pTr_1[uzel]))
		cout << pTr_1[uzel] << " ";

	delete[]Tr_4;
}

//! Glavnaya funkciya.
int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "Введите кол-во узлов дерева: "; cin >> n; /// Vvod kolichestva uzlov
	int *Tr_1 = new int[n];
	cout << "Введите узлы: "; /// Vvod uzlov
	for (int i = 0; i < n; i++) cin >> Tr_1[i];

	cout << "Прямой обход: "; /// Vyzov funkcij obhoda dereva:
	Direct_order(0, n, Tr_1); /// - Prjamoj obhod
	cout << "\nОбратный обход: ";
	inDirect_order(0, n, Tr_1); /// - Obratnyj obhod
	cout << "\nСимметричный: ";
	Symmetric_order(0, n, Tr_1); /// - Simmetrichnyj obhod
	cout << endl;

	delete[]Tr_1;
	system("pause");
}