// @File	BPMN-ProcessValidation.cpp
// @Author	YUSUF GÖÇ(yusufsalih987@gmail.com), KOKSAL GOK(koksal_gok@msn.com)
// @Date	2025-04-28
// BPMN proje süreç doğrulama programı.
#include <iostream>
#include <string>
using namespace std;

class GameDevelopmentProcess {
public:
	int state = 1;
	char str2test[100]	;
	int pos = 0;

	void start() {
		state = 1;
		cout << "Test edilecek cumleyi giriniz. " << endl;
		cin >> str2test;
		while (str2test[pos] || state == 9) {
			dojob();
			if (state >= 10) break;
		} 
		cout << endl << endl << "Son state:" << state << endl;
		cout << "Test sonucu:" << endl << "string " << str2test ;
		if (state >= 10) {
			cout << " is in the language" << endl;
		}
		else cout << " is not in the language" << endl;
	}

private:
	void dojob() {
		//durum yönetimi
	//0*10*10*11*0 1110
		switch (state) {
		case 1:
			std::cout << "1. Yeni oyun fikri ortaya atildi.\n";
			state = 2;
			break;
		case 2: defineConcept(); break;//Konsept belirleme
		case 3: developPrototype(); break;//Prototip geliştirme
		case 4: testPrototype(); break;//Prototip testi
		case 5: createCharacters(); break;//Karakter ve ortam tasarımı
		case 6: createArtAssets(); break;//Animasyon ve efektler
		case 7: detectBugs(); break;//Hata tespiti
		case 8: fixBugs(); break;//Hata ayıklama
		case 9: promoteGame(); //Oyun tanıtımı
		case 10: marketing(); break;//Pazarlama
		}
	}
	void defineConcept() {
		std::cout << "2. Oyun konsepti belirleniyor...\n";
		if (!getUserApproval("Konsept onaylandi mi? (1=Evet, 0=Hayir): ")) {
			std::cout << "Konsept reddedildi. Tekrar konsept gelistiriliyor...\n";
		}
		else state = 3;
	}
	void developPrototype() {
		std::cout << "3. Prototip gelistiriliyor...\n";
		state = 4;
	}
	void testPrototype() {
		std::cout << "4. Prototip test ediliyor...\n";
		if (!getUserApproval("Prototip testinden gecti mi? (1=Evet, 0=Hayir): ")) {
			std::cout << "Test basarisiz. Prototip tekrar gelistirilecek...\n";
			state = 3;
		}
		else state = 5;
	}
	void createCharacters() {
		std::cout << "5. Karakter ve ortam tasarimi yapiliyor...\n"; state = 6;
	}
	void createArtAssets() {
		std::cout << "6. Animasyon ve efektler ekleniyor...\n";
		if (!getUserApproval("Sanatsal icerik testi basarili mi? (1=Evet, 0=Hayir): ")) state = 5;
		else state = 7;
	}
	void detectBugs() {
		std::cout << "7. Hatalar tespit ediliyor...\n";
		if (getUserApproval("Hata bulundu mu? (1=Evet, 0=Hayir): ")) state = 8;
		else state = 9;
	}
	void fixBugs() {
		std::cout << "8. Hatalar ayiklaniyor...\n"; state = 7;
	}
	void promoteGame() {
		std::cout << "9. Oyun tanitimi yapiliyor...\n"; state = 10;
	}
	void marketing() {
		std::cout << "10. Pazarlama kampanyasi baslatiliyor...\n";
		std::cout << "🎉 Oyun basariyla piyasaya suruldu!\n";
		state = 100;
	}

	bool getUserApproval(const std::string& question) {
		cout << question << endl;
		char input;
		input = str2test[pos++];
		if (input == '1') cout << "Evet";
		else cout << "Hayir";
		cout << endl;
		//int input;
		//std::cin >> input;
		return input == '1';
	}
};

int main() {
	GameDevelopmentProcess process;
	process.start();
	return 0;
}
