#include <iostream>
#include <string>

class GameDevelopmentProcess {
public:
	int state = 1;
	void start() {
		state = 1;
		while (state > 0 && state <= 10) {
			switch (state) {
			case 1:
				std::cout << "1. Yeni oyun fikri ortaya atildi.\n";
				state = 2;
				break;
			case 2: defineConcept(); break;
			case 3: developPrototype(); break;
			case 4: testPrototype(); break;
			case 5: createCharacters(); break;
			case 6: createArtAssets(); break;
			case 7: detectBugs(); break;
			case 8: fixBugs(); break;
			case 9: promoteGame(); break;
			case 10: marketing(); break;
			default: state = -1;
			}
		}
		
	}

private:
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
	}void createArtAssets() {
		std::cout << "6. Animasyon ve efektler ekleniyor...\n";
		if (!getUserApproval("Sanatsal içerik testi basarili mi? (1=Evet, 0=Hayir): ")) state = 5;
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
		int input;
		std::cout << question;
		std::cin >> input;
		return input == 1;
	}
};

int main() {
	GameDevelopmentProcess process;
	process.start();
	return 0;
}
