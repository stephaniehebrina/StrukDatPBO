// Stephanie Hebrina Mabunbun Simatupang - 5027221069//

#include <iostream>
#include <string>

using namespace std;

const int MAX_DATA = 100;

typedef struct
{
    string nama;
    string nrp;
    int umur;
    bool jenis_kelamin; // 0 = perempuan ; 1 = laki-laki
} mahasiswa;


int main()
{
    mahasiswa mhs[MAX_DATA];
    
    int jumlahData = 0;

    int input_user;

    if (jumlahData < MAX_DATA) {
    mhs[jumlahData].nama = "leo";
    mhs[jumlahData].nrp = "5025";
    mhs[jumlahData].umur = 14;
    mhs[jumlahData].jenis_kelamin = 0;  
    jumlahData++;

    mhs[jumlahData].nama = "pisces";
    mhs[jumlahData].nrp = "5026";
    mhs[jumlahData].umur = 15;
    mhs[jumlahData].jenis_kelamin = 1; 
    jumlahData++;

    mhs[jumlahData].nama = "sagi";
    mhs[jumlahData].nrp = "5027";
    mhs[jumlahData].umur = 16;
    mhs[jumlahData].jenis_kelamin = 0;  
    jumlahData++;

    mhs[jumlahData].nama = "capri";
    mhs[jumlahData].nrp = "5028";
    mhs[jumlahData].umur = 17;
    mhs[jumlahData].jenis_kelamin = 1;  
    jumlahData++;

    mhs[jumlahData].nama = "cancer";
    mhs[jumlahData].nrp = "5029";
    mhs[jumlahData].umur = 18;
    mhs[jumlahData].jenis_kelamin = 1;  
    jumlahData++;
}

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Menampilkan data mahasiswa" << endl;
        cout << "2. Menambahkan data baru" << endl;
        cout << "3. Menghapus mahasiswa" << endl;
        cout << "4. Mengubah data mahasiswa" << endl
            << endl;
        cout << "5. Keluar" << endl;

        cout << "Pilih: " << endl;
        cin >> input_user;

        if (input_user == 1)
        {
            cout << "\nStudents data:" << endl <<endl;
            for (int i = 0; i < jumlahData; i++)
            {
                cout << "===" << endl;
                cout << "Mahasiswa : " << i + 1 << ":" << endl;
                cout << "Nama = " << mhs[i].nama << endl;
                cout << "NRP = " << mhs[i].nrp << endl;
                cout << "Umur = " << mhs[i].umur << endl;
                cout << "Jenis Kelamin = " << (mhs[i].jenis_kelamin == 0 ? "Perempuan" : "Laki-laki");
                cout << "\n====" << endl << endl;
            }
        }
        else if (input_user == 2)
        {
            if (jumlahData < 10)
            {
                cout << "Input data Mahasiswa:" << endl;
                cout << "Nama = ";
                cin >> mhs[jumlahData].nama;
                cout << "NRP =  ";
                cin >> mhs[jumlahData].nrp;
                cout << "Umur = ";
                cin >> mhs[jumlahData].umur;
                cout << "Jenis Kelamin (0 = Perempuan, 1 = Laki-laki) = ";
                cin >> mhs[jumlahData].jenis_kelamin;

                jumlahData++;
                cout << "Data sudah ditambahkan." << endl << endl;
            }
            else
            {
                cout << "Data tidak bisa ditambah karena sudah full" << endl << endl;
            }
        }
        else if (input_user == 3)
        {
            if (jumlahData > 0)
            {
                int del;
                cout << "Masukkan data indeks yang ingin dihapus: (0-" << jumlahData - 1 << "): ";
                cin >> del;

                if (del >= 0 && del < jumlahData)
                {
                    for (int i = del; i < jumlahData - 1; i++)
                    {
                        mhs[i] = mhs[i + 1];
                    }
                    jumlahData--;
                    cout << "Data tersebut sudah dihapus" << endl << endl;
                }
                else
                {
                    cout << "Indeks tidak valid." << endl << endl;
                }
            }
            else
            {
                cout << "Error." << endl << endl;
            }
        }
        else if (input_user == 4)
        {
            if (jumlahData > 0)
            {
                int edit;
                cout << "Masukkan nomor indeks data yang ingin diedit : (0-" << jumlahData - 1 << "): ";
                cin >> edit;

                if (edit >= 0 && edit < jumlahData)
                {
                    cout << "Input data Mahasiswa:" << endl;
                    cout << "Nama =  ";
                    cin >> mhs[edit].nama;
                    cout << "NRP = ";
                    cin >> mhs[edit].nrp;
                    cout << "Umur = ";
                    cin >> mhs[edit].umur;
                    cout << "Jenis Kelamin (0 = Perempuan, 1 = Laku-laki) = ";
                    cin >> mhs[edit].jenis_kelamin;

                    cout << "Data sudah diedit" << endl << endl;
                }
                else
                {
                    cout << "Indeks tidak valid" << endl << endl;
                }
            }
            else
            {
                cout << "Error." << endl << endl;
            }
        }
        else if (input_user == 5)
        {
            cout << "Program selesai." << endl << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl << endl;
        }
    }

    return 0;
}