#include <iostream>
#include <cstdlib>    // rand, srand
#include <cstdio>     // printf
#include <cstring>    // strcpy
#include <ctime>      // time

// CERT警告1: グローバル変数の使用（DCL00-C）
int alert_count = 0;

// CERT警告2: マジックナンバー（MSC04-C）
#define TEMP_THRESHOLD 30
#define NUM_READINGS 5
#define BUFFER_SIZE 16

// センサ値を疑似的に「取得」する関数
int read_temperature_sensor() {
    // CERT警告3: randの使用（MSC50-CPP）
    return 20 + rand() % 21; // 20～40の疑似乱数値
}

// 警告メッセージをバッファにコピーする
// CERT警告4: strcpyの使用（STR07-C）
void set_alert_message(char* buf, const char* msg) {
    strcpy(buf, msg);
}

int main() {
    // CERT警告5: printfの使用（FIO38-C）
    printf("=== 温度センサ監視プログラム ===\n");

    // 現在時刻で乱数初期化（再現性なし）
    srand(static_cast<unsigned int>(time(nullptr)));

    char alert_msg[BUFFER_SIZE];

    for (int i = 0; i < NUM_READINGS; ++i) {
        int temp = read_temperature_sensor();
        std::cout << "センサ値[" << i << "]: " << temp << "℃" << std::endl;

        if (temp > TEMP_THRESHOLD) {
            set_alert_message(alert_msg, "警告: 温度異常!");
            alert_count++;
            std::cout << alert_msg << std::endl;
        }
    }

    std::cout << "アラート発生回数: " << alert_count << std::endl;
    return 0;
}