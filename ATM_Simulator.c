#include <stdio.h>

int main() {
    int balance = 1000; // Initial balance
    int pin = 1234; // Initial PIN
    int option, amount, newPin, confirmPin;

    printf("Welcome to the ATM!\n");

    // PIN verification loop
    while (1) {
        printf("Enter your PIN: ");
        scanf("%d", &pin);

        if (pin == -1) {
            printf("PIN verification failed. Exiting...\n");
            return 0;
        }

        if (pin == 1234) {
            printf("PIN verification successful.\n");
            break;
        } else {
            printf("Invalid PIN. Please try again or enter -1 to exit.\n");
        }
    }

    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Withdraw Money\n");
        printf("2. Deposit Money\n");
        printf("3. Check Balance\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Withdraw Money
                printf("Enter the amount to withdraw: ");
                scanf("%d", &amount);

                if (amount <= balance) {
                    balance -= amount;
                    printf("Withdrawal successful. Current balance: %d\n", balance);
                } else {
                    printf("Insufficient funds. Current balance: %d\n", balance);
                }
                break;

            case 2: // Deposit Money
                printf("Enter the amount to deposit: ");
                scanf("%d", &amount);

                balance += amount;
                printf("Deposit successful. Current balance: %d\n", balance);
                break;

            case 3: // Check Balance
                printf("Current balance: %d\n", balance);
                break;

            case 4: // Change PIN
                printf("Enter your new PIN: ");
                scanf("%d", &newPin);

                printf("Confirm your new PIN: ");
                scanf("%d", &confirmPin);

                if (newPin == confirmPin) {
                    pin = newPin;
                    printf("PIN change successful.\n");
                } else {
                    printf("PINs do not match. PIN change failed.\n");
                }
                break;

            case 5: // Exit
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}
