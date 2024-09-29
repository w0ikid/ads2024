#include <stdio.h>
#include <windows.h>

HANDLE hSerial;
DCB dcbSerialParams = {0};
COMMTIMEOUTS timeouts = {0};

// Функция для инициализации COM порта
int initSerialPort() {
    hSerial = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    
    if (hSerial == INVALID_HANDLE_VALUE) {
        printf("Error opening port!\n");
        return -1;
    }

    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        printf("Error getting port state!\n");
        return -1;
    }

    dcbSerialParams.BaudRate = CBR_9600;  // Установим скорость 9600
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        printf("Error setting port parameters!\n");
        return -1;
    }

    // Установим таймауты для чтения и записи
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        printf("Error setting timeouts!\n");
        return -1;
    }

    return 0;
}

// Функция для отправки команды
void sendCommand(BYTE *command, DWORD size) {
    DWORD bytesWritten;
    WriteFile(hSerial, command, size, &bytesWritten, NULL);
}

// Функция для старта теста
void startTest() {
    BYTE command[6] = {0x0C, 0x0A, 0x06, 0x02, 0xCC, 0xCC};
    sendCommand(command, sizeof(command));
    printf("Test started.\n");
}

// Функция для обнаружения выдоха
void detectBlow() {
    BYTE command[6] = {0x0C, 0x0D, 0x06, 0x03, 0xCC, 0xCC};
    sendCommand(command, sizeof(command));
    printf("Blow detection mode activated.\n");
}

// Функция для тестирования выдоха
void blowTest() {
    BYTE command[6] = {0x0C, 0x0D, 0x06, 0x04, 0xCC, 0xCC};
    sendCommand(command, sizeof(command));
    printf("Blow test started.\n");
}

// Функция для анализа данных
void dataAnalysis() {
    BYTE command[6] = {0x0C, 0x0D, 0x06, 0x06, 0xCC, 0xCC};
    sendCommand(command, sizeof(command));
    printf("Data analysis mode activated.\n");
}

// Функция для получения результата теста
void getTestResult() {
    BYTE command[8] = {0x0C, 0x0D, 0x08, 0x07, 0x00, 0x00, 0xCC, 0xCC};  // пример команды с результатом
    sendCommand(command, sizeof(command));
    printf("Test result requested.\n");
}

// Чтение данных с порта
void readSerialPort() {
    DWORD bytesRead;
    char buffer[256];  // Buffer for reading data
    BOOL keepReading = TRUE;

    while (keepReading) {
        if (ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL)) {
            if (bytesRead > 0) {
                printf("RECEIVED: %.*s\n", bytesRead, buffer);
            } else {
                keepReading = FALSE;
            }
        } else {
            printf("Error reading from port!\n");
            keepReading = FALSE;
        }
    }
}

// Основная программа
int main() {
    if (initSerialPort() != 0) {
        return -1;
    }

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Start test\n");
        printf("2. Detect blow\n");
        printf("3. Start blow test\n");
        printf("4. Data analysis\n");
        printf("5. Get test result\n");
        printf("6. Read data from serial port\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startTest();
                break;
            case 2:
                detectBlow();
                break;
            case 3:
                blowTest();
                break;
            case 4:
                dataAnalysis();
                break;
            case 5:
                getTestResult();
                break;
            case 6:
                readSerialPort();
                break;
            case 7:
                CloseHandle(hSerial);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
