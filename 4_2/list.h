#include <iostream>
#include <set>
using namespace std;

template<typename T>
class list
{
private:
    struct Node
    {
        T data = 0;
        Node* next = nullptr;
        Node()
            : data(0)
            , next(nullptr) {};
    };
    Node* begin;
    Node* end;

public:

    //Кострукторы 
    //конструктор без параметров 
    list()
        :begin(new Node)
        , end(begin)
    {
        cout << "конструктор без параметров" << endl;
    }

    //конструктор с параметрами 
    list(T data)
        :begin(new Node)
        , end(begin)
    {
        cout << "конструктор с параметрами" << endl;
        Node* temporary_list = new Node;
        end = temporary_list;
        begin->next = end;
        end->data = data;
    }

    //деструктор 
    ~list()
    {
        cout << "деструктор" << endl;
        Node* temporary_list = begin;
        Node* aback = nullptr;

        while (temporary_list != nullptr)
        {
            aback = temporary_list;
            temporary_list = temporary_list->next;
            delete aback;
        }
    }

    //конструктор копирования 
    list(const list& obj)
    {
        cout << "конструктор копирования" << endl;

        Node* temporary_list = new Node;
        Node* copy = (obj.begin)->next;
        begin = end = temporary_list;

        while (copy != nullptr)
        {
            Node* temporary_list = new Node;
            temporary_list->data = copy->data;
            end->next = temporary_list;
            end = temporary_list;
            copy = copy->next;
        }
    }

    //конструктор перемещения 
    list(list&& obj)
    {
        cout << "конструктор перемещения" << endl;

        begin = obj->begin;
        end = obj->end;

        obj->begin = obj->end = new Node;
    }

    //Операторы 
    //оператор перемещения 
    list& operator =(list&& obj)
    {
        if (obj == this) return *this;
        cout << "оператор перемещения" << endl;
        begin = obj->begin;
        end = obj->end;
        obj->begin = obj->end = new Node;
        return *this;
    }

    //оператор копирования 
    list& operator =(const list& obj)
    {
        if (obj == this) return *this;
        cout << "оператор копирования" << endl;
        Node* temporary_list = new Node;
        Node* t_list = obj.begin->next;

        //очищаем левый список 
        Node* aback = begin, * t = nullptr;
        while (aback != nullptr)
        {
            t = aback;
            aback = aback->next;
            delete t;
        }

        begin = end = temporary_list;

        while (t_list != nullptr)
        {
            Node* temporary_list = new Node;
            temporary_list->data = t_list->data;
            end->next = temporary_list;
            end = temporary_list;
            t_list = t_list->next;
        }

        return *this;
    }
    //Методы 
    //добавление 
    void push(const T data)
    {
        Node* temporary_list = new Node;
        temporary_list->data = data;
        end->next = temporary_list;
        end = temporary_list;
    }

    //удаление элемента по ключу 
    void erase_k(const T data)
    {
        Node* temporary_list = begin->next;
        Node* aback = begin;

        while (temporary_list != nullptr && temporary_list->data != data)
        {
            aback = temporary_list;
            temporary_list = temporary_list->next;
        }

        if (temporary_list != nullptr && temporary_list->data == data)
        {
            if (temporary_list->next == nullptr)
            {
                end = aback;
            }

            aback->next = temporary_list->next;
            delete temporary_list;
        }
        else
        {
            cout << "Такого символа для удаление нету" << endl;
        }
    }

    //очистка списка 
    void erase()
    {
        Node* temporary_list = begin->next;
        Node* aback = begin;

        while (temporary_list != nullptr)
        {
            aback = temporary_list;
            temporary_list = temporary_list->next;
            delete aback;
        }
        end = begin;
        begin->next = nullptr;
    }

    //Вывод  
    void output()
    {
        Node* temporary_list = begin->next;
        while (temporary_list != nullptr)
        {
            cout << temporary_list->data << " ";
            temporary_list = temporary_list->next;
        }
        cout << endl;
    }

    //поиск 
    bool search(const T data)
    {
        Node* temporary_list = begin->next;
        Node* aback = begin;

        while (temporary_list != nullptr && temporary_list->data != data)
        {
            aback = temporary_list;
            temporary_list = temporary_list->next;
        }

        if (temporary_list != nullptr && temporary_list->data == data)
        {
            return 1;
        }
        return 0;
    }

    //ссылочные параметры чтобы конструктор и деструктор лишний раз не вызывался 
    template<class T>
    void TASK(list<T>& l1, list<T>& l2)
    {
        Node* inser = (l2.begin)->next, * entry = (l1.begin)->next, * l = begin->next, * pr = begin;
        set<T> number;
        while (entry)
        {
            number.insert(entry->data);
            entry = entry->next;
        }

        while (inser)
        {
            number.insert(inser->data);
            inser = inser->next;
        }
        for (auto q : number)
        {
            this->push(q);
        }
    }
};