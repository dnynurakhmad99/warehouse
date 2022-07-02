#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Sakanane
{
	string nama;
	string merk;
	string stok;
	int harga;
};

const int SIZE = 100;
Sakanane gd[SIZE];

int hitung = 0;

void add_produk(); void show_produk(); void sc_produk();
void ed_produk(); void mrh_produk(); void mhl_produk();
char list_harga(); char get_menu();

int main()
{
	while (true)
	{
		char select = get_menu();
		if (select == '1')
			add_produk();
		else if (select == '2')
			show_produk();
		else if (select == '3')
			sc_produk();
		else if (select == '4')
			ed_produk();
		else if (select == '5')
		{
			while (true)
			{
				char select = list_harga();
				if (select == '1')
					mrh_produk();
				else if (select == '2')
					mhl_produk();
				else if (select == '3')
					break;
			}
		}
		else if (select == '6')
			break;
	}
	return 0;
}

void add_produk()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Tambahkan Produk\n\n";
	cout << " Nama Produk : ";
	getline(cin, gd[hitung].nama);
	cout << " Merk Produk : ";
	getline(cin, gd[hitung].merk);
	cout << " Stok Produk : ";
	getline(cin, gd[hitung].stok);
	cout << " Harga Produk (ecer) : ";
	cin >> gd[hitung].harga;

	++hitung;
}

void show_produk()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Tampilkan Produk\n\n";
	cout << " --------------------------------------------------------------\n";
	cout << setw(5) << "No.";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga";
	cout << endl;
	cout << " --------------------------------------------------------------\n";
	for (int x = 0; x < hitung; ++x)
	{
		cout << setw(4) << x + 1;
		cout << setw(15) << gd[x].nama;
		cout << setw(15) << gd[x].merk;
		cout << setw(15) << gd[x].stok;
		cout << setw(7) << "Rp. " << gd[x].harga;
		cout << "\n ==============================================================\n";
	}

	system("pause");
}

void sc_produk()
{
	string y;

	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Mencari Produk\n\n";
	cout << " Nama/merk produk yang dicari : ";
	getline(cin, y);

	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Produk ditemukan :\n\n";
	cout << " --------------------------------------------------------------\n";
	cout << setw(5) << "No.";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga";
	cout << endl;
	cout << " --------------------------------------------------------------\n";

	bool cari{ false };

	for (int z = 0; z < hitung; ++z)
	{
		gd[z].nama;
		gd[z].merk;

		if (y == gd[z].nama)
		{
			cari = true;

			cout << setw(4) << z + 1;
			cout << setw(15) << gd[z].nama;
			cout << setw(15) << gd[z].merk;
			cout << setw(15) << gd[z].stok;
			cout << setw(7) << "Rp. " << gd[z].harga;
			cout << "\n ==============================================================\n";
		}

		else if (y == gd[z].merk)
		{
			cari = true;

			cout << setw(4) << z + 1;
			cout << setw(15) << gd[z].nama;
			cout << setw(15) << gd[z].merk;
			cout << setw(15) << gd[z].stok;
			cout << setw(7) << "Rp. " << gd[z].harga;
			cout << "\n ==============================================================\n";
		}
	}

	if (cari == false)
	{
		system("cls");

		cout << "[==============================================================]\n";
		cout << "|                        Gudang Sakanane                       |\n";
		cout << "[==============================================================]\n\n";
		cout << " " << y << endl << endl;
		cout << " Produk tidak ditemukan\n";
	}

	system("pause");
}

void ed_produk()
{
	system("cls");

	int a, b;

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Ubah Produk\n\n";
	cout << " Urutan produk yang ingin diedit	: ";
	cin >> a;
	cin.ignore(1, '\n');

	b = a - 1;

	if (b < hitung)
	{
		cout << "\n Nama Produk : ";
		getline(cin, gd[b].nama);
		cout << " Merk Produk : ";
		getline(cin, gd[b].merk);
		cout << " Stok Produk : ";
		getline(cin, gd[b].stok);
		cout << " Harga Produk (ecer) : ";
		cin >> gd[b].harga;
	}

	else
	{
		cout << "\n Produk tidak ditemukan" << endl;
		system("pause");
	}
}

void mrh_produk()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Urutan dari harga termurah\n\n";
	cout << " --------------------------------------------------------------\n";
	cout << setw(5) << "No.";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga";
	cout << endl;
	cout << " --------------------------------------------------------------\n";

	string TEMPnama;
	string TEMPmerk;
	string TEMPstok;
	int TEMPharga;

	for (int c = 0; c < hitung; ++c)
	{
		for (int d = c + 1; d < hitung; ++d)
		{
			if (gd[c].harga > gd[d].harga)
			{
				TEMPnama = gd[c].nama;
				TEMPmerk = gd[c].merk;
				TEMPstok = gd[c].stok;
				TEMPharga = gd[c].harga;

				gd[c].nama = gd[d].nama;
				gd[c].merk = gd[d].merk;
				gd[c].stok = gd[d].stok;
				gd[c].harga = gd[d].harga;

				gd[d].nama = TEMPnama;
				gd[d].merk = TEMPmerk;
				gd[d].stok = TEMPstok;
				gd[d].harga = TEMPharga;
			}
		}
	}

	for (int e = 0; e < hitung; ++e)
	{
		cout << setw(4) << e + 1;
		cout << setw(15) << gd[e].nama;
		cout << setw(15) << gd[e].merk;
		cout << setw(15) << gd[e].stok;
		cout << setw(7) << "Rp. " << gd[e].harga;
		cout << "\n ==============================================================\n";
	}

	system("pause");
}

void mhl_produk()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Urutan dari harga termahal\n\n";
	cout << " --------------------------------------------------------------\n";
	cout << setw(5) << "No.";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga";
	cout << endl;
	cout << " --------------------------------------------------------------\n";

	string TEMPnama;
	string TEMPmerk;
	string TEMPstok;
	int TEMPharga;

	for (int c = 0; c < hitung; ++c)
	{
		for (int d = c + 1; d < hitung; ++d)
		{
			if (gd[c].harga < gd[d].harga)
			{
				TEMPnama = gd[c].nama;
				TEMPmerk = gd[c].merk;
				TEMPstok = gd[c].stok;
				TEMPharga = gd[c].harga;

				gd[c].nama = gd[d].nama;
				gd[c].merk = gd[d].merk;
				gd[c].stok = gd[d].stok;
				gd[c].harga = gd[d].harga;

				gd[d].nama = TEMPnama;
				gd[d].merk = TEMPmerk;
				gd[d].stok = TEMPstok;
				gd[d].harga = TEMPharga;
			}
		}
	}

	for (int e = 0; e < hitung; ++e)
	{
		cout << setw(4) << e + 1;
		cout << setw(15) << gd[e].nama;
		cout << setw(15) << gd[e].merk;
		cout << setw(15) << gd[e].stok;
		cout << setw(7) << "Rp. " << gd[e].harga;
		cout << "\n ==============================================================\n";
	}

	system("pause");
}

char list_harga()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Urutkan Harga Produk\n\n";
	cout << " [1] Dari Termurah\n";
	cout << " [2] Dari Termahal\n";
	cout << " [3] Keluar\n\n";
	cout << " Pilih	: ";
	string sel;
	getline(cin, sel);
	return sel[0];
}

char get_menu()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                        Gudang Sakanane                       |\n";
	cout << "[==============================================================]\n\n";
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Mencari Produk\n";
	cout << " [4] Ubah Produk\n";
	cout << " [5] Urutkan Harga\n";
	cout << " [6] Keluar\n\n";
	cout << " Pilih	: ";
	string sel;
	getline(cin, sel);
	return sel[0];
}