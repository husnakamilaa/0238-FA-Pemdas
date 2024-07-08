#include <iostream>
using namespace std;

class MasukUniversitas {
private : // isi access modifier disini
    int uangPendaftaran;
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;
    // isi daftar variable yang dibutuhkan di bawah ini
public:
    MasukUniversitas() {
        uangPendaftaran = 0;
        uangSemesterPertama = 0;
        uangBangunan = 0;
        totalBiaya = 0;
    // isi nilai default variable yang dibutuhkan di bawah ini
    }

    virtual void namaJalurMasuk() { return; }
    virtual void input() { return; }
    virtual int hitungTotalBiaya() = 0;
    virtual void tampilkanTotalBiaya() { return; }

 // isi disini dengan fungsi virtual yang dibutuhkan

    void setUangPendaftaran(int nilai) {
        this->uangPendaftaran = nilai;
    }
    float getUangPendaftaran() {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(int value) {
        this->uangSemesterPertama = value;
    }
    float getUangSemesterPertama() {
        return uangSemesterPertama;
    }

    void setUangBangunan(int isi) {
        this->uangBangunan = isi;
    }
    float getUangBangunan() {
        return uangBangunan;
    }

    void setTotalBiaya(int nilai) {
        this->totalBiaya = nilai;
    }
    float getTotalBiaya() {
        return totalBiaya;
    }
 // isi setter dan getter variable yang dibutuhkan di bawah ini
};

class SNBT : public MasukUniversitas {
public :
    void namaJalurMasuk()
    {
        cout << "Jalur SNBT" << endl;

    }

    void input()
    {
        int uangPendaftaran;
        int uangSemesterPertama;
        int uangBangunan;
        int totalBiaya;
        int nilai;
        int value;
        int isi;
        cout << "Masukkan uang pendaftaran: " << endl;
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: " << endl;
        cin >> uangSemesterPertama;
        cout << "Masukkan uang bangunan: " << endl;
        cin >> uangBangunan;
        cout << "Total Biaya: ";
        cin >> totalBiaya;
    }

    int hitungTotalBiaya()
    {
        return getUangPendaftaran() + getUangSemesterPertama() + getUangBangunan();
    }

    void tampilkanTotalBiaya()
    {
        string status;
        string rekomendasi;
        cout << "Total Biaya: " << hitungTotalBiaya() << endl;
        if (hitungTotalBiaya() == 50)
        {
            status = "Sedang";
        }
        else if (hitungTotalBiaya() > 100)
        {
            status = "Mahal";
        }
        else
        {
            status = "Murah";
        }
        
        if (status == "Sedang")
        {
            rekomendasi = "Dipertimbangkan";
        }
        else if (status == "Mahal")
        {
            rekomendasi = "Tidak direkomendasikan";
        }
        else 
        {
            rekomendasi = "Direkomendasikan";
        }
        cout << "Kategori: " << status << endl;
        cout << "Rekomendasi: " << rekomendasi << endl;
    }
 // isi disini untuk melengkapi class SNBT
};
class SNBP : public MasukUniversitas {
public :
    void namaJalurMasuk()
    {
        cout << "Jalur SNBP" << endl;

    }

    void input()
    {
        int uangPendaftaran;
        int uangSemesterPertama;
        int nilai;
        int value;
        cout << "Masukkan uang pendaftaran: " << endl;
        cin >> uangPendaftaran;
        setUangPendaftaran(uangPendaftaran);
        cout << "Masukkan uang semester pertama: " << endl;
        cin >> uangSemesterPertama;
        setUangSemesterPertama(value);
    }

    int hitungTotalBiaya()
    {
        return getUangPendaftaran() + getUangSemesterPertama();
    }

    void tampilkanTotalBiaya()
    {
        string status;
        string rekomendasi;
        cout << "Total Biaya: " << hitungTotalBiaya() << endl;
        if (hitungTotalBiaya() == 50)
        {
            status = "Sedang";
            rekomendasi = "Dipertimbangkan";
        }
        else if (hitungTotalBiaya() > 100)
        {
            status = "Mahal";
            rekomendasi = "Tidak Direkomendasikan";
        }
        else
        {
            status = "Murah";
            rekomendasi = "Direkomendasikan";
        }
        
        cout << "Kategori: " << status << endl;
        cout << "Rekomendasi: " << rekomendasi << endl;
    }
 // isi disini untuk melengkapi class SNBP
};
int main() {
 // isi disini untuk fungsi main
    char pilihan;
    
    MasukUniversitas* jalur;
    SNBT t;
    SNBP p;

    do
    {
        cout << "Pilih Jalur Masuk:" << endl;
        cout << "1. SNBT" << endl;
        cout << "2. SNBP" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: " << endl;
        cin >> pilihan;

        switch(pilihan)
        {
            case '1':
            {
                jalur = &t;
                jalur->namaJalurMasuk();
                jalur->input();
                jalur->hitungTotalBiaya();
                jalur->tampilkanTotalBiaya();
                break;
            }
            case '2':
            {
                jalur = &p;
                jalur->namaJalurMasuk();
                jalur->input();
                jalur->hitungTotalBiaya();
                jalur->tampilkanTotalBiaya();
                break;
            }
            case '3':
            {
                cout << "Keluar...." << endl;
                break;
            }
            default :
                cout << "Invalid Option" << endl;
                break;
        }
    } while (pilihan != '3');
    
    return 0;
}