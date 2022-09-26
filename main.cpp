#include <iostream>

using namespace std;

class PuntoXY {
private:
    double x, y;

public:
    PuntoXY(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() { return x; }

    double getY() { return y; }

    void setX(double x) { this->x = x; }

    void setY(double y) { this->y = y; }

    friend ostream& operator<<(ostream& os, PuntoXY& obj);

    friend bool operator<(PuntoXY& obj1, PuntoXY& obj2);

    friend bool operator==(PuntoXY& obj1, PuntoXY& obj2);

};

ostream& operator<<(ostream& os, PuntoXY& obj) {
    return os << "(" << obj.x  << ", " << obj.y << ")";
}

bool operator<(PuntoXY& obj1, PuntoXY& obj2) {
    return (obj1.x < obj2.x || obj1.y < obj2.y);
}

bool operator==(PuntoXY& obj1, PuntoXY& obj2) {
    return (obj1.x == obj2.x && obj1.y == obj2.y);
}

/**
 *
 * @tparam T
 */

class Veicolo {
public:
    string marca;
    int cavalli;

    int getHorsePower() { return cavalli; }

    virtual ostream& put(ostream& os) {
        os << "Marca veicolo: " << marca << " | Cavalli: " << cavalli << " |";
        return os;
    }
};

class Auto : public Veicolo {
public:
    Auto(string marca, int cavalli) : Veicolo() {
        this->marca = marca;
        this->cavalli = cavalli;
    }


    ostream& put(ostream& os) {
        Veicolo::put(os);
        os << " Tipo veicolo: Auto" << endl;
        return os;
    }

};

class Moto : public Veicolo {
public:
    Moto(string marca, int cavalli) : Veicolo() {
        this->marca = marca;
        this->cavalli = cavalli;
    }
    ostream& put(ostream& os) {
        Veicolo::put(os);
        os << " Tipo veicolo: Moto" << endl;
        return os;
    }
};

class Barca : public Veicolo {
public:
    Barca(string marca, int cavalli) : Veicolo() {
        this->marca = marca;
        this->cavalli = cavalli;
    }
    ostream& put(ostream& os) {
        Veicolo::put(os);
        os << " Tipo veicolo: Barca" << endl;
        return os;
    }
};

ostream& operator<<(ostream& os, Veicolo& obj) {
    return obj.put(os);
}



bool operator==(Veicolo& obj1, Veicolo& obj2) {
    return (obj1.cavalli == obj2.cavalli && obj2.marca == obj1.marca && typeid(obj1) == typeid(obj2));
}

/**
 *
 * @tparam T
 */

template<typename T>
class NodeT {

public:
    NodeT<T>* next;
    NodeT<T>* prev;
    T val;

};

template<typename T>
class DoubleLinkListT {

private:
    NodeT<T>* head;
    NodeT<T>* tail;
    NodeT<T>* current;
    int size;

    /**
     * @brief Support function for search
     * @param x
     * @return NodeT<T>
     */
    NodeT<T>* _search(T x);

public:

    /**
     * @brief Construct a new DoubleLinkListT object
     */
    DoubleLinkListT();

    /**
     * @brief Head Inserting of an element inside the DoubleLinkListT
     * @param x
     * @return DoubleLinkListT<T>
     */
    DoubleLinkListT<T>* headInsert(T x);

    /**
     * @brief Tail Inserting of an element inside the DoubleLinkListT
     * @param x
     * @return DoubleLinkListT<T>
     */
    DoubleLinkListT<T>* tailInsert(T x);

    /**
     * @brief Search an item inside the object
     * @param x
     * @return T&
     */
    T& search(T x);

    /**
     * @brief Delete an item inside the DoubleLinkListT
     * @param val
     * @return
     */
    DoubleLinkListT<T>* deleteItem(T val);

    /**
     * @brief Delete all items with the same value inside the DoubleLinkListT
     * @param val
     * @return
     */
    DoubleLinkListT<T>* deleteAllItem(T x);

    /**
     * @brief Inizialiting of Iterator
     */
    void initIterator() { current = head; }

    /**
     * @brief Iterator
     * @return
     */
    T* iterator();

    /**
     * @brief Sort the DoubleLinkListT
     */
    void sort();

    /**
     * Return Size of DoubleLinkListT
     * @return int
     */
    int getSize();

    /**
     * Printing of DoubleLinkListT
     * @param os
     * @param obj
     * @return std::ostream
     */
    std::ostream& put(std::ostream& os);
    //Stampa con la friend
    //template<typename U//
    //std::ostream& operator<<(ostream& os, const DoubleLinkList<U>& obj)

    /**
     * @brief Overloading []
     * @param i
     * @return
     */
    T& operator[](int i);

};

template<typename T>
DoubleLinkListT<T>::DoubleLinkListT() {
    head = new NodeT<T>;
    tail = new NodeT<T>;
    head->next = tail;
    tail->prev = head;
    size = 0;
}

template<typename T>
DoubleLinkListT<T> *DoubleLinkListT<T>::headInsert(T y) {
    NodeT<T>* n = new NodeT<T>();
    n->val = y;
    NodeT<T>* x = head->next;

    head->next = n;
    n->next = x;

    n->prev = head;
    x->prev = n;

    size++;
    return this;
}

template<typename T>
DoubleLinkListT<T> *DoubleLinkListT<T>::tailInsert(T y) {
    NodeT<T>* n = new NodeT<T>();
    n->val = y;

    NodeT<T>* x = tail->prev;

    n->next = tail;
    x->next = n;
    n->prev = x;
    tail->prev = n;

    size++;
    return this;
}

template<typename T>
NodeT<T> *DoubleLinkListT<T>::_search(T x) {
    NodeT<T>* tmp = head;
    while(tmp->next != tail){
        tmp = tmp->next;
        if(*tmp->val == *x){
            return tmp;
        }
    }
    return nullptr;
}

template<typename T>
T& DoubleLinkListT<T>::search(T x) {
    NodeT<T>* tmp = _search(x);

    if(tmp) return *tmp->val;
    T err;
    return err;
}

template<typename T>
DoubleLinkListT<T>* DoubleLinkListT<T>::deleteItem(T val) {
    NodeT<T>* x = _search(val);
    if(!x) return this;

    NodeT<T>* pred = x->prev;
    NodeT<T>* succ = x->next;

    pred->next = succ;
    succ->prev = pred;

    delete x;
    size--;

    return this;
}


template<typename T>
DoubleLinkListT<T>* DoubleLinkListT<T>::deleteAllItem(T x) {
    NodeT<T>* tmp = head;

    while(tmp->next != tail) {
        tmp = tmp->next;
        if(tmp->val == x) {
            NodeT<T>* y = tmp;
            NodeT<T>* pred = y->prev;
            NodeT<T>* succ = y->next;
            pred->next = succ;
            succ->prev = pred;
            delete y;
            tmp = succ->prev;
            size--;
            if(tmp == tail) return this;
        }
    }
    return this;
}


template<typename T>
void DoubleLinkListT<T>::sort() {
    NodeT<T>* tmp = head;
    NodeT<T>* minN = head;
    NodeT<T>* start = head;

    while(tmp->next != tail) {
        tmp = tmp->next;
        T min = tmp->val;
        minN = tmp;
        start = tmp;

        while(start->next != tail) {
            start = start->next;
            if(start->val < min) {
                min = start->val;
                minN = start;
            }
        }

        if(tmp != minN) { //Ottimizzazione per vedere se l'elemento di partenza è uguale al minimo, così non sostituiamo
            minN->val = tmp->val;
            tmp->val = min;
        }
    }
}


template<typename T>
int DoubleLinkListT<T>::getSize() {
    return size;
}

template<typename T>
std::ostream &DoubleLinkListT<T>::put(std::ostream &os) {
    NodeT<T>* tmp = head;
    os << "H -> ";
    while(tmp->next != tail){
        tmp = tmp->next;
        os << *tmp->val << " -> ";
    }
    os << "T";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, DoubleLinkListT<T>& obj) {
    return obj.put(os);
}

//Stampa con friend
//template<typename U>
//std::ostream& operator<<(std::ostream& os, const DoubleLinkList<U>& obj){ stampa dentro il corpo}

template<typename T>
T& DoubleLinkListT<T>::operator[](int i) {
    NodeT<T>* tmp = head;
    int count = 0;

    while(tmp->next != tail) {
        tmp = tmp->next;
        if(count == i) return tmp->val;
        count++;
    }
    T* err = new T();
    return *err;
}

int main() {

    DoubleLinkListT<PuntoXY*>* list = new DoubleLinkListT<PuntoXY*>();
    list->tailInsert(new PuntoXY(1,1))->tailInsert(new PuntoXY(2,2))->tailInsert(new PuntoXY(3,3));

    cout << "Lista di PuntoXY 'list': ";
    cout << *list << endl << endl;

    cout << "Eliminazione PuntoXY(1,1): " << endl;
    list->deleteItem(new PuntoXY(1,1));
    cout << *list << endl;

    cout << "Eliminazione PuntoXY(3,3): " << endl;
    list->deleteItem(new PuntoXY(3,3));
    cout << *list << endl << endl;

    DoubleLinkListT<Veicolo*>* list_veicoli = new DoubleLinkListT<Veicolo*>();
    list_veicoli->tailInsert(new Auto("Ferrari",780))->tailInsert(new Moto("Ducati", 120))->tailInsert(new Barca("Azimut", 5000));

    cout << "Lista di Veicolo 'list_veicolo':";
    cout << *list_veicoli << endl << endl;
    cout << "Eliminazione Auto(Ferrari,780): " << endl;
    list_veicoli->deleteItem(new Auto("Ferrari",780));
    cout << *list_veicoli << endl;
    
    return 0;
}
