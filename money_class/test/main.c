#include "stdio.h"
#include "money.h"

MONEY* MoneyA = NULL;
MONEY_IMPLEMENTS* moneyA = NULL;

MONEY* MoneyB = NULL;
MONEY_IMPLEMENTS* moneyB = NULL;

int main(void)
{
    Money_Attribute attr1 = {
        .amount = 10
    };

    Money_Attribute attr2 = {
        .amount = 5
    };

    MoneyA = MONEY_CTOR();
    MoneyA->init(MoneyA, &attr1);
    moneyA = (MONEY_IMPLEMENTS*)MoneyA;

    MoneyB = MONEY_CTOR();
    MoneyB->init(MoneyB, &attr2);
    moneyB = (MONEY_IMPLEMENTS*)MoneyB;

    CLASS_LOG("MoneyA\n");
    moneyA->get_amount(moneyA);
    moneyA->comparison(moneyA, moneyB);

    CLASS_LOG("MoneyB\n");
    moneyB->get_amount(moneyB);
    moneyA->comparison(moneyB, moneyA);
}