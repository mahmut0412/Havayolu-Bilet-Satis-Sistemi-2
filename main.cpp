#include <iostream>
#include<string.h>
using namespace std;
struct ucus
{
    int ucus_no;
    char kalkis_yeri[20];
    char varis_yeri[20];
    char zaman[5];
    int koltuk_kapasitesi;
    int bos_koltuk_sayisi;
    float baslangic_fiyati;
    ucus* Sonraki;
};

struct bilet
{
    char TC[11];
    int ucus_no;
    float bilet_fiyati;
    bilet* Sonraki;
};

ucus* ucuslar[9000];
int toplam_ucuslar = 0;
bilet* head_bilet = nullptr;
ucus* ucus_ky[9000];
int toplam_ucus_ky = 0;



void Bir_ucusun_kalkis_zamaninin_guncellenmesi();
ucus* get_ucus(int ucus_numarasi);
void Bir_ucusa_iliskin_bilet_satilmasi();
int bilet_sayisi(int ucus_numarasi);
void insertAtend_bilet(int ucus_numarasi, float baslangic_fiyati);
void ucak_bileti_iptali(int ucus_numarasi);
float fiyatBelirleme(float bko, float bbf);
void ucak_bileti_iptali_TC();
void Yeni_bir_ucusun_eklenmesi();
void insert_ucus(int ucus_numarasi);
void insert_node_ucus_circular(ucus* new_node);
ucus* insertToEmptylist_ucus_circular(ucus* head_ucus, ucus* help);
ucus* insertAtend_ucus_circular(ucus* head_ucus, ucus* help);
bool check(ucus* head_ucus, int ucus_numarasi);
bool check_by_numarasi(int ucus_numarasi);
void bir_ucusun_iptal_edilmesi();
void delete_ucus(int ucus_numarasi);
void Bir_yerden_kalkan_ucuslarin_bilgilerinin_listenmesi();
void Bir_yerden_yere_olan_ucuslarin_bilgilerini_listelenmesi();
void Bir_ucusun_bilgilerinin_ve_o_ucusa_iliskin_satilan_biletlerin_listelenmesi();
void bilet_gostermek_ucus_numarasi(int ucus_numarasi);
void Koltuk_doluluk_orani_50();
void Bir_yolcunun_biletlerinin_listelenmesi();
void sort_ucuslar();
/**/

int main() {

    string secmek;
    printf("\t\t\t<><><><><><><><><><><><><><><><><><><><><><><>--------------||\n");

    printf("\t\t\t||    MA Havayolu Bilet Satis Sistemine hosgeldiniz\t    ||\n");

    printf("\t\t\t||--------------<><><><><><><><><><><><><><><><><><><><><><><>\n");

    printf("\n\n\n\n");
    do {
        cout << endl << "\t\t\tLutfen yapmak istediginiz islem numarasini giriniz:" << endl;
        cout << "\t\t\t1-Yeni bir ucusun eklenmesi" << endl;
        cout << "\t\t\t2-Bir ucusun kalkis zamaninin guncellemesi" << endl;
        cout << "\t\t\t3-Bir ucusa iliskin bilet satilmasi" << endl;
        cout << "\t\t\t4-Bir ucusun iptal edilmesi" << endl;
        cout << "\t\t\t5-Bir ucus icin satilan bir biletin iptal edilmesi" << endl;
        cout << "\t\t\t6-Bir yerden kalkan ucuslarin bilgilerinin listenmesi" << endl;
        cout << "\t\t\t7-Bir yerden yere olan ucuslarin bilgilerini listelenmesi" << endl;
        cout << "\t\t\t8-Bir ucusun bilgilerinin ve o ucusa iliskin satilan biletlerin listelenmesi" << endl;
        cout << "\t\t\t9-Koltuk doluluk orani %50'nin altinda olan ucuslarin listelenmesi" << endl;
        cout << "\t\t\t10-Bir yolcunun biletlerinin listelenmesi" << endl;
        cout << "\t\t\tbitirmek icin (bitir) giriniz." << endl;
        cin >> secmek;
        if (secmek == "1") {
            Yeni_bir_ucusun_eklenmesi();
        }
        else if (secmek == "2") {
            Bir_ucusun_kalkis_zamaninin_guncellenmesi();
        }
        else if (secmek == "3") {
            Bir_ucusa_iliskin_bilet_satilmasi();
        }
        else if (secmek == "4") {
            bir_ucusun_iptal_edilmesi();

        }
        else if (secmek == "5") {
            ucak_bileti_iptali_TC();

        }
        else if (secmek == "6") {
            Bir_yerden_kalkan_ucuslarin_bilgilerinin_listenmesi();
        }
        else if (secmek == "7") {
            Bir_yerden_yere_olan_ucuslarin_bilgilerini_listelenmesi();
        }
        else if (secmek == "8") {
            Bir_ucusun_bilgilerinin_ve_o_ucusa_iliskin_satilan_biletlerin_listelenmesi();
        }
        else if (secmek == "9") {
            Koltuk_doluluk_orani_50();
        }
        else if (secmek == "10") {
            Bir_yolcunun_biletlerinin_listelenmesi();
        }
    } while (secmek != "bitir");
    return 0;
}

void Yeni_bir_ucusun_eklenmesi() {
    bool Mevcut_yolculuk = false;
    int ucus_numarasi;
    do {
        cout << endl << "Ucus numarasini girinz:(1000 ile 9999 arasinda)" << endl;
        cin >> ucus_numarasi;
    } while (ucus_numarasi < 1000 || ucus_numarasi>9999);

    for (int i = 0; i < toplam_ucus_ky; i++)
    {
        if (check_by_numarasi(ucus_numarasi) == true) {
            Mevcut_yolculuk = true;
            break;
        }
    }
    if (Mevcut_yolculuk == false) {
        insert_ucus(ucus_numarasi);
    }
    else {
        cout << endl << "Numara daha once kayitliydi" <<endl<<endl;
    }


}


void insert_ucus(int ucus_numarasi) {


    ucus* help = new ucus;
    ucuslar[toplam_ucuslar] = help;
    toplam_ucuslar++;
    help->ucus_no = ucus_numarasi;
    cout << endl << "kalkis yeri giriniz:" << endl;
    cin >> help->kalkis_yeri;
    cout << endl << "varis yeri giriniz:" << endl;
    cin >> help->varis_yeri;
    cout << endl << "kalkis saati giriniz:" << endl;
    cin >> help->zaman;
    cout << endl << "koltuk kapasitesi giriniz:" << endl;
    cin >> help->koltuk_kapasitesi;
    cout << endl << "baslangic fiyati giriniz:" << endl;
    cin >> help->baslangic_fiyati;
    help->bos_koltuk_sayisi = 0;
    insert_node_ucus_circular(help);
    cout<<endl<<"Ucus basariyla eklendi."<<endl<<endl;

}
void insert_node_ucus_circular(ucus* new_node) {
    if (toplam_ucus_ky == 0) {
        ucus_ky[toplam_ucus_ky] = new_node;
        ucus_ky[toplam_ucus_ky]->Sonraki = ucus_ky[toplam_ucus_ky];
        toplam_ucus_ky++;
    }
    else {
        for (int i = 0; i < toplam_ucus_ky; i++)
        {
            if (ucus_ky[i]->kalkis_yeri[0] == new_node->kalkis_yeri[0]) {
                ucus_ky[i] = insertAtend_ucus_circular(ucus_ky[i], new_node);
                return;
            }
        }
        ucus_ky[toplam_ucus_ky] = new_node;
        toplam_ucus_ky++;
    }
    ucus* temp;
    for (int i = 0; i < toplam_ucus_ky - 1; i++)
    {
        for (int j = i + 1; j < toplam_ucus_ky; j++)
        {
            if (ucus_ky[i]->kalkis_yeri[0] > ucus_ky[j]->kalkis_yeri[0]) {
                temp = ucus_ky[i];
                ucus_ky[i] = ucus_ky[j];
                ucus_ky[j] = temp;
            }
        }
    }

}

ucus* insertToEmptylist_ucus_circular(ucus* head_ucus, ucus* help) {

    if (head_ucus != nullptr)

        return head_ucus;


    head_ucus = help;

    head_ucus->Sonraki = head_ucus;

    return head_ucus;

}

ucus* insertAtend_ucus_circular(ucus* head_ucus, ucus* help) {

    if (head_ucus == nullptr)

        return insertToEmptylist_ucus_circular(head_ucus, help);



    help->Sonraki = head_ucus->Sonraki;

    head_ucus->Sonraki = help;

    head_ucus = help;

    return head_ucus;

}
bool check_by_numarasi(int ucus_numarasi) {

    for (int i = 0; i < toplam_ucus_ky; i++)
    {
        if (ucuslar[i]->ucus_no == ucus_numarasi) {
            return true;
        }
    }
    return false;
}
bool check(ucus* head_ucus, int ucus_numarasi) {

    ucus* ptr;

    if (head_ucus == nullptr) {
        return false;
    }

    ptr = head_ucus->Sonraki;

    do {
        if (ptr->ucus_no == ucus_numarasi) {
            return true;
        }
        ptr = ptr->Sonraki;
    } while (ptr != head_ucus->Sonraki);
    return false;
}

ucus* get_ucus(int ucus_numarasi) {


    if (toplam_ucuslar == 0) {
        return nullptr;
    }

    int i = 0;
    do {
        if (ucuslar[i]->ucus_no == ucus_numarasi) {
            return ucuslar[i];
        }
        i++;
    } while (i < toplam_ucuslar);
    return nullptr;
}
void Bir_ucusun_kalkis_zamaninin_guncellenmesi() {
    ucus* ptr;
    int ucus_numarasi;
    do {
        cout << endl << "Ucus numarasini girinz:" << endl;
        cin >> ucus_numarasi;
    } while (ucus_numarasi < 1000 || ucus_numarasi>9999);

    if (toplam_ucuslar == 0) {
        return;
    }
    int i = 0;
    while (i < toplam_ucuslar) {
        if (ucuslar[i]->ucus_no == ucus_numarasi) {
            cout << endl << "Ucusun yeni kalkis saati giriniz:" << endl;
            cin >> ucuslar[i]->zaman;
            return;
        }
        i++;
    }

}
void Bir_ucusa_iliskin_bilet_satilmasi() {
    int ucus_numarasi, Alinacak_bilet_sayisi;

    cout << endl << "Ucus numarasini girinz:" << endl;
    cin >> ucus_numarasi;
    do {
        cout << endl << "Satin alinacak bilet sayisini giriniz:" << endl;
        cin >> Alinacak_bilet_sayisi;
    } while (Alinacak_bilet_sayisi > 10);
    ucus* ucus_bilgisi = get_ucus(ucus_numarasi);

    if (ucus_bilgisi != nullptr) {

            if ((bilet_sayisi(ucus_numarasi) + Alinacak_bilet_sayisi) <= ucus_bilgisi->koltuk_kapasitesi) {
                float top_fiyat = 0, bos_koltuk_orani;
                int Bos_koltuk_sayisi, sayac1 = bilet_sayisi(ucus_numarasi);

                for (int k = 0; k < Alinacak_bilet_sayisi; k++)
                {
                    Bos_koltuk_sayisi = ucus_bilgisi->koltuk_kapasitesi - sayac1;
                    bos_koltuk_orani = ((float)Bos_koltuk_sayisi / (float)ucus_bilgisi->koltuk_kapasitesi) * 100;
                    top_fiyat += fiyatBelirleme(bos_koltuk_orani, ucus_bilgisi->baslangic_fiyati);
                    sayac1++;
                }
                cout << endl << "toplam fiyat: " << top_fiyat << endl;
                string onaylama;
                cout << endl << "Satin almak istiyor musunuz? (evet/hayir): " << endl;
                cin >> onaylama;

                if (onaylama == "evet") {
                    int i = 1, bks, sayac2 = bilet_sayisi(ucus_numarasi);
                    float fiyat, bko;
                    while (i <= Alinacak_bilet_sayisi) {
                        bks = ucus_bilgisi->koltuk_kapasitesi - sayac2;
                        bko = ((float)bks / (float)ucus_bilgisi->koltuk_kapasitesi) * 100;
                        fiyat = fiyatBelirleme(bko, ucus_bilgisi->baslangic_fiyati);
                        insertAtend_bilet(ucus_numarasi, fiyat);
                        i++;
                        sayac2++;
                    }
                    cout<<endl<<endl<<"bilet basariyla alindi."<<endl<<endl;
                }

            }
            else {
                cout << endl<<endl << "Ucus koltuklarinin sayisi yeterli degil!" << endl;
            }
        }
        else {
             cout << endl<<endl << "Bu numara ile ucus bulunmadi! " << endl;
            }

}
int bilet_sayisi(int ucus_numarasi) {
    int sayisi = 0;
    bilet* ptr;
    if (head_bilet == nullptr) {
        return 0;
    }

    ptr = head_bilet;

    do {
        if (ptr->ucus_no == ucus_numarasi) {
            sayisi++;
        }
        ptr = ptr->Sonraki;
    } while (ptr != nullptr);
    return sayisi;
}
void insertAtend_bilet(int ucus_numarasi, float baslangic_fiyati)
{
    bilet* temp, * trav;
    temp = new bilet;
    temp->Sonraki = nullptr;

    cout << endl << "TC giriniz:" << endl;
    cin >> temp->TC;
    temp->ucus_no = ucus_numarasi;
    temp->bilet_fiyati = baslangic_fiyati;
    trav = head_bilet;

    if (head_bilet == nullptr) {

        head_bilet = temp;
    }

    else {
        while (trav->Sonraki != NULL)
            trav = trav->Sonraki;
        trav->Sonraki = temp;
    }
}
void ucak_bileti_iptali(int ucus_numarasi)
{
    int i = 0, sayisi = bilet_sayisi(ucus_numarasi);
    bilet* temp = head_bilet;
    while (i < sayisi) {
        if (head_bilet->ucus_no == ucus_numarasi)
        {
            temp = head_bilet;
            head_bilet = head_bilet->Sonraki;
            free(temp);
        }
        else
        {
            bilet* current = head_bilet;
            while (current->Sonraki != NULL)
            {
                if (current->Sonraki->ucus_no == ucus_numarasi)
                {
                    temp = current->Sonraki;
                    current->Sonraki = current->Sonraki->Sonraki;
                    free(temp);
                    break;
                }
                else
                    current = current->Sonraki;
            }
        }
        i++;
    }

}
void ucak_bileti_iptali_TC()
{
    int i = 0;
    bilet* temp = head_bilet;
    char TC[11];
    cout << endl << "TC giriniz:" << endl;
    cin >> TC;

    if (strcmp(head_bilet->TC, TC) == 0)
    {
        temp = head_bilet;
        head_bilet = head_bilet->Sonraki;
        free(temp);
    }
    else
    {
        bilet* current = head_bilet;
        while (current->Sonraki != NULL)
        {
            if (strcmp(current->Sonraki->TC, TC) == 0)
            {
                temp = current->Sonraki;
                current->Sonraki = current->Sonraki->Sonraki;
                free(temp);
                break;
            }
            else
                current = current->Sonraki;
        }
    }
    cout<<endl<<"Islem basariyla gerceklesti."<<endl<<endl;
}

float fiyatBelirleme(float bko, float bbf)  //bbf (Baslangic bilet fiyati) bko (bos koltuk orani)
{
    if (bko > 90 && bko <= 100)
        return bbf;
    else if (bko > 80 && bko <= 90)
        return bbf * 1.1;
    else if (bko > 70 && bko <= 80)
        return bbf * 1.2;
    else if (bko > 60 && bko <= 70)
        return bbf * 1.3;
    else if (bko > 50 && bko <= 60)
        return bbf * 1.4;
    else if (bko > 40 && bko <= 50)
        return bbf * 1.5;
    else if (bko > 30 && bko <= 40)
        return bbf * 1.6;
    else if (bko > 20 && bko <= 30)
        return bbf * 1.7;
    else if (bko > 10 && bko <= 20)
        return bbf * 1.8;
    else if (bko > 0 && bko <= 10)
        return bbf * 1.9;
}


void bir_ucusun_iptal_edilmesi() {
    int ucus_numarasi;
    cout << endl << "Ucus numarasini giriniz:" << endl;
    cin >> ucus_numarasi;
    if (check_by_numarasi(ucus_numarasi)) {
        ucak_bileti_iptali(ucus_numarasi);
        cout << endl<<"Islem basariyla gerceklestirildi."<<endl<<endl;
        delete_ucus(ucus_numarasi);
    }
}
void delete_ucus(int ucus_numarasi)
{
    int i;
    for (i = 0; i < toplam_ucuslar; i++)
        if (ucuslar[i]->ucus_no == ucus_numarasi) {
            free(ucuslar[i]);
            break;
        }

    if (i < toplam_ucuslar)
    {
        toplam_ucuslar = toplam_ucuslar - 1;
        for (int j = i; j < toplam_ucuslar; j++)
            ucuslar[j] = ucuslar[j + 1];
    }

}
void Bir_yerden_kalkan_ucuslarin_bilgilerinin_listenmesi() {
    char kalkis_yeri[20];
    cout << endl << "Kalkis yerini giriniz:" << endl;
    cin >> kalkis_yeri;
    if (toplam_ucuslar == 0) {
        cout << "listelenecek oge bulunmadi!" << endl;
        return;
    }
    ucus* ucus_temp[9000];
    int toplam = 0;
    for (int i = 0; i < toplam_ucuslar; i++)
    {
        if (strcmp(ucuslar[i]->kalkis_yeri, kalkis_yeri) == 0) {
            ucus_temp[toplam] = ucuslar[i];
            toplam++;
        }

    }
    ucus* temp;
    for (int i = 0; i < toplam - 1; i++)
    {
        for (int j = i + 1; j < toplam; j++)
        {
            if (strcmp(ucus_temp[i]->zaman, ucus_temp[j]->zaman) > 0) {
                temp = ucus_temp[i];
                ucus_temp[i] = ucus_temp[j];
                ucus_temp[j] = temp;
            }
        }
    }

    for (int i = 0; i < toplam; i++)
    {
        cout << "ucus numarasi: " << ucus_temp[i]->ucus_no << endl;
        cout << "kalkis yeri: " << ucus_temp[i]->kalkis_yeri << endl;
        cout << "varis yeri: " << ucus_temp[i]->varis_yeri << endl;
        cout << "kalkis saati: " << ucus_temp[i]->zaman << endl;
        cout << "koltuk kapasitesi: " << ucus_temp[i]->koltuk_kapasitesi << endl;
        cout << "baslangic fiyati: " << ucus_temp[i]->baslangic_fiyati << endl;
    }
}
void Bir_yerden_yere_olan_ucuslarin_bilgilerini_listelenmesi() {
    char kalkis_yeri[20], varis_yeri[20];
    cout << endl << "Kalkis yerini giriniz:" << endl;
    cin >> kalkis_yeri;
    cout << endl << "varis yerini giriniz:" << endl;
    cin >> varis_yeri;
    if (toplam_ucuslar == 0) {
        cout << "listelenecek oge bulunmadi!" << endl;
        return;
    }
    ucus* ucus_temp[9000];
    int toplam = 0;
    for (int i = 0; i < toplam_ucuslar; i++)
    {
        if (strcmp(ucuslar[i]->kalkis_yeri, kalkis_yeri) == 0 && strcmp(ucuslar[i]->varis_yeri, varis_yeri) == 0) {
            ucus_temp[toplam] = ucuslar[i];
            toplam++;
        }

    }
    ucus* temp;
    for (int i = 0; i < toplam - 1; i++)
    {
        for (int j = i + 1; j < toplam; j++)
        {
            if (strcmp(ucus_temp[i]->zaman, ucus_temp[j]->zaman) > 0) {
                temp = ucus_temp[i];
                ucus_temp[i] = ucus_temp[j];
                ucus_temp[j] = temp;
            }
        }
    }

    for (int i = 0; i < toplam; i++)
    {
        cout << "ucus numarasi: " << ucus_temp[i]->ucus_no << endl;
        cout << "kalkis yeri: " << ucus_temp[i]->kalkis_yeri << endl;
        cout << "varis yeri: " << ucus_temp[i]->varis_yeri << endl;
        cout << "kalkis saati: " << ucus_temp[i]->zaman << endl;
        cout << "koltuk kapasitesi: " << ucus_temp[i]->koltuk_kapasitesi << endl;
        cout << "baslangic fiyati: " << ucus_temp[i]->baslangic_fiyati << endl<<endl;
    }
}
void Bir_ucusun_bilgilerinin_ve_o_ucusa_iliskin_satilan_biletlerin_listelenmesi() {
    int ucus_numarasi;
    cout << endl << "Ucus numarasini giriniz:" << endl;
    cin >> ucus_numarasi;
    ucus* temp = get_ucus(ucus_numarasi);
    cout << "ucus numarasi: " << temp->ucus_no << endl;
    cout << "kalkis yeri: " << temp->kalkis_yeri << endl;
    cout << "varis yeri: " << temp->varis_yeri << endl;
    cout << "kalkis saati: " << temp->zaman << endl;
    cout << "koltuk kapasitesi: " << temp->koltuk_kapasitesi << endl;
    cout << "baslangic fiyati: " << temp->baslangic_fiyati << endl<<endl;
    bilet* ptr;
    ptr = head_bilet;
    int Toplam_bilet_sayisi = 0;
    float toplam_kar = 0;

    if (head_bilet == nullptr) {
        cout <<endl<<endl<< "Toplam bilet sayisi: " << 0 << endl;
        cout << "toplam kar: " << 0 << endl;
        cout << "Ortalama fiyat: " << 0 << endl<<endl;
        return;
    }


    do {
        if (ptr->ucus_no == ucus_numarasi) {
            cout << "TC: " << ptr->TC << endl;
            cout << "ucus no: " << ptr->ucus_no << endl;
            cout << "bilet fiyati: " << ptr->bilet_fiyati << endl;
            Toplam_bilet_sayisi += 1;
            toplam_kar += ptr->bilet_fiyati;
        }
        ptr = ptr->Sonraki;
    } while (ptr != nullptr);
    cout << "Toplam bilet sayisi: " << Toplam_bilet_sayisi << endl;
    cout << "toplam kar: " << toplam_kar << endl;
    cout << "Ortalama fiyat: " << (float)toplam_kar / Toplam_bilet_sayisi << endl;

}
void bilet_gostermek_ucus_numarasi(int ucus_numarasi) {
    bilet* ptr;
    if (head_bilet == nullptr) {
        return;
    }

    ptr = head_bilet;

    do {
        if (ptr->ucus_no == ucus_numarasi) {
            cout << "TC: " << ptr->TC << endl;
            cout << "ucus no: " << ptr->ucus_no << endl;
            cout << "bilet fiyati: " << ptr->bilet_fiyati << endl;
        }
        ptr = ptr->Sonraki;
    } while (ptr != nullptr);
}

void Koltuk_doluluk_orani_50() {
    for (int i = 0; i < toplam_ucuslar; i++)
    {
        if (((ucuslar[i]->bos_koltuk_sayisi * 100.0) / ucuslar[i]->koltuk_kapasitesi) < 50) {
            cout << "ucus numarasi: " << ucuslar[i]->ucus_no << endl;
            cout << "kalkis yeri: " << ucuslar[i]->kalkis_yeri << endl;
            cout << "varis yeri: " << ucuslar[i]->varis_yeri << endl;
            cout << "kalkis saati: " << ucuslar[i]->zaman << endl;
            cout << "koltuk kapasitesi: " << ucuslar[i]->koltuk_kapasitesi << endl;
            cout << "baslangic fiyati: " << ucuslar[i]->baslangic_fiyati << endl<<endl<<endl;
        }

    }
}
void Bir_yolcunun_biletlerinin_listelenmesi() {
    char TC[11];
    ucus* temp;
    cout << endl << "TC giriniz:" << endl;
    cin >> TC;
    bilet* ptr;
    if (head_bilet == nullptr) {
        return;
    }
    sort_ucuslar();
    ptr = head_bilet;
    cout << endl << "ucus no:\t" << "kalkis yeri:\t" << "varis yeri:\t" << "kalkis saati:\t" <<"fiyat:";
    cout << endl << "________\t" << "____________\t" << "___________\t" << "_____________\t" <<"______";
    do {
        if (strcmp(ptr->TC, TC) == 0) {
            temp = get_ucus(ptr->ucus_no);
            cout <<endl<< temp->ucus_no <<"             "<< temp->kalkis_yeri <<"            "<< temp->varis_yeri <<"          "<< temp->zaman <<"            "<< ptr->bilet_fiyati<<endl;
        }
        ptr = ptr->Sonraki;
    } while (ptr != nullptr);
}

void sort_ucuslar() {
    ucus* temp;
    for (int i = 0; i < toplam_ucuslar - 1; i++)
    {
        for (int j = i + 1; j < toplam_ucuslar; j++)
        {
            if (ucuslar[i]->ucus_no > ucuslar[j]->ucus_no) {
                temp = ucuslar[i];
                ucuslar[i] = ucuslar[j];
                ucuslar[j] = temp;
            }
        }
    }
}

