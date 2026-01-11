#include <stdio.h>
#include <stdlib.h>
#include "bank_interface.h"

typedef struct account {
    unsigned int account;
    int balance;
    struct account *next;
} account_t;

typedef struct ledger {
    account_t *head;
    account_t *tail;
} ledger_t;

int create_account(unsigned int account, void *ledger) {
    // TODO:
    return -1;
}

void list_accounts(void *ledger) {
    ledger_t *ledger_ptr = (ledger_t *)ledger;
    account_t *current = ledger_ptr->head;

    while (current != NULL) {
        printf("Account: %u, Balance: %d\n", current->account, current->balance);
        current = current->next;
    }
}

int modify_balance(unsigned int account, int balance, void *ledger) {
    ledger_t *ledger_ptr = (ledger_t *)ledger;
    account_t *current = ledger_ptr->head;

    while (current != NULL) {
        if (current->account == account) {
            current->balance += balance;
            return current->balance;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    ledger_t ledger;
    ledger.head = NULL;
    ledger.tail = NULL;

    create_account(0, &ledger);
    create_account(1, &ledger);
    create_account(2, &ledger);

    list_accounts(&ledger);
    
    modify_balance(1, 10, &ledger);
    modify_balance(0, -100, &ledger);
    modify_balance(123, -100, &ledger);

    list_accounts(&ledger);

    return 0;
}