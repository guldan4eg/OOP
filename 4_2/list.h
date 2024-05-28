#include <iostream>
using namespace std;

template<typename T>
class List
{

    struct Node
    {
        T data = 0;
        Node* next = nullptr;
    };
    Node* begin;
    Node* end;

public:

    //����������� 
    //����������� ��� ���������� 
    List()
        :begin(new Node)
        , end(begin)
    {
    }

    //����������� � ����������� 
    List(T data)
        :begin(new Node)
        , end(begin)
    {
        Node* temporary_List = new Node;
        end = temporary_List;
        begin->next = end;
        end->data = data;
    }

    //���������� 
    ~List()
    {
        Node* temporary_List = begin;
        Node* aback = nullptr;

        while (temporary_List != nullptr)
        {
            aback = temporary_List;
            temporary_List = temporary_List->next;
            delete aback;
        }
    }

    //����������� ����������� 
    List(const List& obj)
    {
        Node* temporary_List = new Node;
        Node* copy = (obj.begin)->next;
        begin = end = temporary_List;

        while (copy != nullptr)
        {
            Node* temporary_List = new Node;
            temporary_List->data = copy->data;
            end->next = temporary_List;
            end = temporary_List;
            copy = copy->next;
        }
    }

    //����������� ����������� 
    List(List&& obj)
    {
        begin = obj->begin;
        end = obj->end;

        obj->begin = obj->end = new Node;
    }

    //��������� 
    //�������� ����������� 
    List& operator =(List&& obj)
    {
        if (obj == this) return *this;
        begin = obj->begin;
        end = obj->end;
        obj->begin = obj->end = new Node;
        return *this;
    }

    //�������� ����������� 
    List& operator =(const List& obj)
    {
        if (obj == this) return *this;
        Node* temporary_List = new Node;
        Node* t_List = obj.begin->next;

        //������� ����� ������ 
        Node* aback = begin, * t = nullptr;
        while (aback != nullptr)
        {
            t = aback;
            aback = aback->next;
            delete t;
        }

        begin = end = temporary_List;

        while (t_List != nullptr)
        {
            Node* temporary_List = new Node;
            temporary_List->data = t_List->data;
            end->next = temporary_List;
            end = temporary_List;
            t_List = t_List->next;
        }

        return *this;
    }
    T& operator[](const int& ind)
    {
        if (ind < 0)
        {
            cout << "Error ";
            abort();
        }
        int kol = 0;
        Node* temporary = nullptr;
        temporary = begin->next;
        while (ind != kol)
        {
            ++kol;
            temporary = temporary->next;
        }
        return temporary->data;
    }
    //������ 
    //���������� 
    void push(const T data)
    {
        Node* temporary_List = new Node;
        temporary_List->data = data;
        end->next = temporary_List;
        end = temporary_List;
    }
    //�������� �������
    void pop()
    {
        Node* temporary_List = begin->next;
        Node* aback = begin;
        begin = begin->next;
        delete aback;
    }
    //�������� �������� �� ����� 
    void erase_k(const T data)
    {
        Node* temporary_List = begin->next;
        Node* aback = begin;

        while (temporary_List != nullptr && temporary_List->data != data)
        {
            aback = temporary_List;
            temporary_List = temporary_List->next;
        }

        if (temporary_List != nullptr && temporary_List->data == data)
        {
            if (temporary_List->next == nullptr)
            {
                end = aback;
            }

            aback->next = temporary_List->next;
            delete temporary_List;
        }
        else
        {
            cout << "������ ������� ��� �������� ����" << endl;
        }
    }

    //������� ������ 
    void erase()
    {
        Node* temporary_List = begin->next;
        Node* aback = begin;

        while (temporary_List != nullptr)
        {
            aback = temporary_List;
            temporary_List = temporary_List->next;
            delete aback;
        }
        end = begin;
        begin->next = nullptr;
    }

    //�����  
    void output()
    {
        Node* temporary_List = begin->next;
        while (temporary_List != nullptr)
        {
            cout << temporary_List->data << " ";
            temporary_List = temporary_List->next;
        }
        cout << endl;
    }

    //����� 
    bool search(const T data)
    {
        Node* temporary_List = begin->next;
        Node* aback = begin;

        while (temporary_List != nullptr && temporary_List->data != data)
        {
            aback = temporary_List;
            temporary_List = temporary_List->next;
        }

        if (temporary_List != nullptr && temporary_List->data == data)
        {
            return 1;
        }
        return 0;
    }
    //��������� ��������� ����� ����������� � ���������� ������ ��� �� ��������� 

};