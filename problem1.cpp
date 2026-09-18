#include <iostream>

bool isGenap(int num) {
    return (num % 2 == 0);
}

int main() {
    int N, K;
    std::cin >> N >> K;

    if (K < 2) {
        K = 2;
    }

    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int sisaAktif = N;
    int currentIndex = 0;

    while (sisaAktif > 1) {
        int count = 0;

        while (count < K) {
            if (astronot[currentIndex] != 0) {
                count++;
            }
            if (count < K) {
                currentIndex = (currentIndex + 1) % N;
            }
        }

        int tereliminasi = astronot[currentIndex];
        
        // PERBAIKAN: Cetak astronot yang baru saja tereliminasi
        std::cout << tereliminasi << " ";

        astronot[currentIndex] = 0;
        sisaAktif--;

        if (isGenap(tereliminasi)) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        if (K < 2) {
            K = 2;
        }

        if (sisaAktif > 1) {
            do {
                currentIndex = (currentIndex + 1) % N;
            } while (astronot[currentIndex] == 0);
        }
    }

    // Cetak astronot terakhir yang bertahan
    for (int i = 0; i < N; i++) {
        if (astronot[i] != 0) {
            std::cout << astronot[i] << std::endl;
            break;
        }
    }

    return 0;
}
