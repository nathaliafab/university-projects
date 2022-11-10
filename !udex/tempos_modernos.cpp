// https://iudex.io/problem/6153526597713f0001036ac9/statement

#include <iostream>

using namespace std;

class Item
{
public:
    int X;
    int T;
    Item *next = NULL;

    Item(int X, int T)
    {
        this->X = X;
        this->T = T;
    }
};

class List
{
public:
    Item *head = NULL;
    Item *tail = NULL;
};

void insertAtTail(List *&lista, int X, int T)
{
    Item *novoItem = new Item(X, T);

    if (lista->head == NULL) //será o primeiro item a ser inserido
    {
        lista->head = novoItem;
        lista->tail = novoItem;
        lista->tail->next = lista->head;
        lista->head->next = lista->tail;
    }

    else
    {
        lista->tail->next = novoItem;
        novoItem->next = lista->head;
        lista->tail = novoItem;
    }
}

void insertPrevious(List *&lista, Item *&current, int X, int T)
{
    Item *novoItem = new Item(X, T);

    if (lista->head == NULL || current == NULL) //será o primeiro item a ser inserido
    {
        lista->head = novoItem;
        lista->tail = novoItem;
        lista->tail->next = lista->head;
        lista->head->next = lista->tail;
    }

    else
    {
        Item *atual = lista->head;

        while (atual->next != current)
            atual = atual->next;

        atual->next = novoItem;
        novoItem->next = current;

        if (lista->head == current)
            lista->tail = novoItem;
    }
}

void removeFromHead(List *&lista, bool flag)
{
    if (lista->head == NULL)
        return;

    if (flag == true)
        cout << "UNLD " << lista->head->X << endl;

    if (lista->head == lista->tail) //caso só tenha um item na lista
    {
        delete (lista->head);
        lista->head = NULL;
        return;
    }

    Item *toDelete = lista->head;
    lista->tail->next = lista->head->next;
    lista->head = lista->head->next;

    delete (toDelete);
}

void removeCurrent(List *&lista, Item *&current)
{
    if (current == NULL)
        return;

    if (lista->head == lista->tail) //caso só tenha um item na lista
    {
        delete (lista->head);
        lista->head = NULL;
        return;
    }

    Item *toDelete = current;
    Item *atual = lista->head;

    while (atual->next != current)
        atual = atual->next;

    atual->next = current->next;

    if (lista->tail == current)
        lista->tail = atual;

    if (lista->head == current)
    {
        lista->head = current->next;
        lista->tail->next = lista->head;
    }

    current = current->next;

    delete (toDelete);
}

int main(void)
{
    int K, X, T; //K unidades de tempo, X identificador, T tempo restante de processamento
    List *filaEnt = new List(), *filaSaida = new List(), *filaProc = new List();
    Item *current = NULL;
    string evento;

    cin >> K;

    do
    {
        cin >> evento;

        if (evento == "LOAD")
        {
            cin >> X >> T;
            insertAtTail(filaEnt, X, T);
        }

        else if (evento == "UNLD")
        {
            removeFromHead(filaSaida, true);
        }

        else if (evento == "PROC")
        {
            if (current != NULL && current->T == 0)
            {
                insertAtTail(filaSaida, current->X, current->T);
                removeCurrent(filaProc, current);
            }

            if (filaEnt->head != NULL)
            {
                insertPrevious(filaProc, current, filaEnt->head->X, filaEnt->head->T);
                removeFromHead(filaEnt, false);
            }

            if (filaProc->head != NULL)
            {
                if (current == NULL)
                    current = filaProc->head;

                current->T -= K;

                if (current->T < 0)
                    current->T = 0;

                cout << "PROC " << current->X << " " << current->T << endl;

                if (current->T > 0) //caso não seja, o current será o que tem T = 0, sendo removido no próximo PROC
                    current = current->next;
            }

            else
                cout << "PROC -1 -1" << endl;
        }

    } while (evento != "END");

    return 0;
}
