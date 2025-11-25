#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	int idKasir, siftKasir, pilihan;
	int nomorHidangan, jumlahHidangan, totalHarga;
	int kembalian, uangDibayar;
	int tambahMenu;
	char lanjutProgram;
	string namaPembeli;
	bool inputValid = false;
	
	// daftar nama kasir yang ada
	string namaKasir [5] = {"Minji", "Haerin", "Hanni", "Danielle", "Hyein"};
	
    // array daftar hidangan
	string hidangan [100] = {
			"Nasi Goreng Spesial",
			"Mie Goreng Spesial",
			"Ayam Geprek",
			"Pecel Lele",
			"Nasi Uduk" 
		};
		
	// array daftar harga hidangan
	int harga [100] = {15000, 15000, 20000, 18000, 12000};
	int jumlahMenu = 5;
	
	// input ID Kasir dari user dengan batas 3 kali kesempatan
	int kesempatan = 0;
	do {
		cout << "ID Kasir		: ";
		cin >> idKasir;
		kesempatan++;
		
		// ID kasir harus antara 1 sampai 5
		if (idKasir >= 1 && idKasir <= 5) {
			inputValid = true;
		} else {
			if (kesempatan < 3) {
				cout << "ID Kasir tidak ditemukan. \nKesempatan tersisa: " << 3 - kesempatan << "\n\n";
			} else {
				// program keluar jika salah 3 kali
				cout << "ID Kasir tidak ditemukan. \nKesempatan habis.\n";
				return 0; 
			}
		}
	} while (!inputValid && kesempatan < 3);
	inputValid = false;
	
	// input Shift Kasir dari user
	do {
		cout << "Shift Kasir (1/2/3)	: ";
		cin >> siftKasir;
		
		// shift kasir harus 1, 2, atau 3
		if (siftKasir >= 1 && siftKasir <= 3) {
			inputValid = true;
		} else {
			cout << "Shift Kasir tidak valid.\n";
		}
	} while (!inputValid);
	inputValid = false;
	
	// menampilkan pesan jika ID valid
	cout << "Halo, " << namaKasir[idKasir - 1] 
		 << " Kamu Bekerja Pada Shift ke-" << siftKasir << " Hari ini. Semangat!\n" << endl;

	// program utama yang berjalan berulang 
	// selama user memilih untuk melanjutkan program.
	do {
		cout << setfill ('=') << setw (65) << " " << endl;
		cout << "Kasir LEZATOS\n";
		cout << setfill ('=') << setw (65) << " " << endl;
		
		// menampilkan pilihan menu
		cout << "1. Daftar menu\n";
		cout << "2. Pembelian menu\n";
		cout << "3. Tambah Data menu\n";
		cout << "4. Keluar\n";
		
		// input pilihan dari user 
		do {
			cout << "\nPILIHAN	: ";
			cin >> pilihan;
			
			// pilihan harus antara 1 sampai 4
			if (pilihan >= 1 && pilihan <= 4) {
				inputValid = true;
			} else {
				cout << "Nomor Pilihan Anda Tidak Valid\n";
			}
		} while (!inputValid);
		inputValid = false; 
		
		// jika pilihan 1, menampilkan daftar menu hidangan
		if (pilihan == 1) {
			
			cout << "\nDAFTAR HIDANGAN\n";
			cout << setfill ('-') << setw (65) << " " << endl;
			
			cout << setfill (' ')
				 << left
				 << setw (4) << "No" 
				 << left
				 << "| Hidangan" << setw (24) 
				 << right
				 << "| Harga" << setw (12) << endl;
			cout << setfill ('-') << setw (65) << " " << endl;
			
			for (int i = 0; i < jumlahMenu; i++) {
				cout << setfill (' ')
					 << left 
					 << setw (4) << (i + 1)
					 << "| " << setw (25) << hidangan[i]
					 << left
					 << "| " << setw (12) << harga[i]
					 << endl;
				 }
			cout << setfill ('-') << setw (65) << " " << endl;
			
		// jika pilihan 2, user menginput pembelian	
		} else if (pilihan == 2) {
			cout << "\nINPUT PEMBELIAN\n";
			cout << setfill ('-') << setw (65) << " " << endl;
			
			cin.ignore();
			
			// input nama pembeli
			cout << "Masukkan Nama Pembeli	 		: ";
			getline(cin, namaPembeli);
			
			// input nomor hidangan yang akan dibeli
			do {
				cout << "Masukkan Nomor Hidangan			: ";
				cin >> nomorHidangan;
				
				// nomor hidangan harus valid
				if (nomorHidangan >= 1 && nomorHidangan <= jumlahMenu) {
					inputValid = true;
				} else {
					cout << "Nomor Hidangan Tidak Valid\n";
				}
			} while (!inputValid);
			inputValid = false;
			
			// input jumlah hidangan yang dibeli
			do {
				cout << "Masukkan Jumlah				: ";
				cin >> jumlahHidangan;
				
				// jumlah hidangan harus > 0
				if (jumlahHidangan > 0) {
					inputValid = true;
				} else {
					cout << "Jumlah hidangan tidak boleh kurang atau sama dengan 0.\n";
				}
			} while (!inputValid);
			inputValid = false;
			cout << endl;
			
			// menghitung total harga pembelian
			totalHarga = harga[nomorHidangan - 1] * jumlahHidangan;
					
			// menampilkan data pembelian	
			cout << "\nDATA PEMBELIAN\n";
			cout << setfill ('-') << setw (65) << " " << endl;
			cout << "Nama Pembeli			        : " << namaPembeli << endl;
			cout << "Nama Hidangan		   	        : " << hidangan[nomorHidangan - 1] << endl;
			cout << "Harga Hidangan			        : " << harga[nomorHidangan - 1] << endl;
			cout << "Jumlah Pembelian  		        : " << jumlahHidangan << endl;
			cout << "Total Harga			        : " << totalHarga << endl;
			
			// input jumlah uang yang dibayar oleh pembeli
			do {
				cout << "\nINPUT PEMBAYARAN\n";
				cout << setfill ('-') << setw (65) << " " << endl;
				cout << "Masukkan Jumlah Uang Yang Dibayar	: ";
				cin >> uangDibayar;
				
				// uang dibayar harus >= total harga
				if (uangDibayar >= totalHarga) {
					inputValid = true;
				} else {
					cout << "Uang yang dibayar tidak cukup.\n";
				}
			} while (!inputValid);
			inputValid = false;
			
			// menghitung kembalian yang harus diberikan
			kembalian = uangDibayar - totalHarga;
			cout << "Kembali					: " << kembalian;
			cout << endl;
			
		// jika pilihan 3, user menambah menu baru	
		} else if (pilihan == 3) {
			cout << "\nTAMBAH DATA MENU\n";
			cout << setfill ('-') << setw (65) << " " << endl;
			
			// input jumlah menu yang ingin ditambahkan
			do {
				cout << "Ingin tambah berapa menu? 	: ";
				cin >> tambahMenu;
				
				// jumlah tambah menu harus > 0 dan tidak melebihi kapasitas array
				if (tambahMenu > 0 && jumlahMenu + tambahMenu <= 100) {
					inputValid = true;
				} else if (tambahMenu <= 0) {
					cout << "Jumlah menu tidak boleh kurang atau sama dengan 0.\n";
				} else {
					cout << "Tidak cukup ruang untuk menambah " << tambahMenu << " menu.\n";
				}
			} while (!inputValid);
			inputValid = false;
			
			// menambahkan menu baru sesuai jumlah yang diminta
			for (int i = 0; i < tambahMenu; i++) {
				cout << "\nData Hidangan ke-" << jumlahMenu + 1 << endl;
				cout << setfill ('=') << setw (65) << " " << endl;
				cout << "Masukkan Nama Hidangan		: ";
				getline(cin, hidangan[jumlahMenu]);

				// input harga hidangan
				do {
					cout << "Masukkan Harga Hidangan		: ";
					cin >> harga[jumlahMenu];
					
					// harga hidangan harus > 0
					if (harga[jumlahMenu] > 0) {
						inputValid = true;
					} else {
						cout << "Harga hidangan tidak boleh kurang atau sama dengan 0.\n";
					}
				} while (!inputValid);
				inputValid = false;
				cin.ignore();
					
				jumlahMenu++;
				cout << setfill ('=') << setw (65) << " " << endl;
					
				cout << "Hidangan Berhasil Ditambahkan\n";
			}
			
		// jika pilihan 4, program berakhir
		} else if (pilihan == 4) {
			cout << "Terima Kasih Telah Menggunakan Program Ini\n";
			return 0;
		}
		
		// menanyakan apakah user ingin melanjutkan program?
		do {
			cout << "\nApakah anda ingin melanjutkan program? (y/n): ";
			cin >> lanjutProgram;
			
			// hanya dapat memilih y/n
			if (lanjutProgram == 'y' || lanjutProgram == 'Y' || lanjutProgram == 'n' || lanjutProgram == 'N') {
				inputValid = true;
			} else {
				cout << "Anda hanya dapat memilih 'y' untuk ya dan 'n' untuk tidak.\n";
			}
		} while (!inputValid);
		inputValid = false;
		cout << endl;
		
	} while (lanjutProgram == 'y' || lanjutProgram == 'Y');
	
	return 0;
}
