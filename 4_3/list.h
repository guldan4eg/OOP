#pragma once 
using namespace std;
template <typename T>
class list
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        Node()
            :left(nullptr)
            , right(nullptr)
            , data(0) {};
    };
    Node* begin;
    Node* end;
    int size = 0;
public:

    //���������� ��� ���������� 
    list()
        :begin(new Node)
        , end(begin)
        , size(0) {}

    //����������� � ����������� 
    explicit list(const T& data)
        :begin(new Node)
        , end(begin)
        , size(1)
    {
        Node* temporary = new Node;
        temporary->data = data;
        end = temporary;
        begin->right = end;
        end->left = begin;
    }

    //����������� ����������� 
    list(const list& obj)
    {
        Node* temporary = obj.begin->right;
        Node* copy = new Node;
        begin = end = copy;
        while (temporary != nullptr)
        {
            Node* copy = new Node;
            copy->data = temporary->data;
            end->right = copy;
            copy->left = end;
            end = copy;
            temporary = temporary->right;
        }
        size = obj.size;
    }

    //����������� ����������� 
    list(list&& obj)
    {
        begin = obj.begin;
        end = obj.end;
        size = obj.size;

        Node* a = new Node;
        obj.begin = a;
        obj.end = a;
        obj.size = 0;
    }

    //�������� ��������� � ����������� 
    list& operator =(const list& obj)
    {
        //������ ����� ������ 
        //������ ������ ������� � ����� 

        Node* temporary = begin;
        Node* aback = nullptr;

        while (temporary != nullptr)
        {
            aback = temporary;
            temporary = temporary->right;
            delete[] aback;
        }

        temporary = obj.begin->right;
        Node* copy = new Node;
        begin = end = copy;

        while (temporary != nullptr)
        {
            Node* copy_s = new Node;

            copy_s->data = temporary->data;
            end->right = copy_s;
            copy_s->left = end;
            end = copy_s;
            temporary = temporary->right;
        }
        size = obj.size;
        return *this;
    }

    //�������� ������������ � ������������ 
    list& operator =(list& obj)
    {
        //������ ����� ������ 
        //��������� ������ � ����� ������ obj � ������� ��� 
        //������ ����� head ��� obj 

        Node* temporary = begin;
        Node* aback = nullptr;

        while (temporary != nullptr)
        {
            aback = temporary;
            temporary = temporary->right;
            delete[] aback;
        }

        begin = obj.begin;
        end = obj.end;
        size = obj.size;

        Node* a = new Node;
        obj.begin = a;
        obj.end = a;
        obj.size = 0;
        return *this;
    }

    //������ 
    //���������� 
    void push(const T& data)
    {
        Node* temporary = new Node;
        end->right = temporary;
        temporary->left = end;
        end = temporary;
        temporary->data = data;
        ++size;
    }

    //����� 
    void output()
    {
        Node* temporary = begin->right;
        while (temporary != nullptr)
        {
            cout << temporary->data << " ";
            temporary = temporary->right;
        }
        cout << '\n';
    }

    //���������� [] 
    T& operator[](const int& ind)
    {

        if (ind < 0 && size < ind)
        {
            cout << "�������� ������" << endl;
            abort();
        }
        int kol = 0;
        Node* temporary = begin->right;
        while (ind != kol)
        {
            ++kol;
            temporary = temporary->right;
        }
        return temporary->data;
    }

    //����������� ���������� 
    T operator[](const int& ind) const
    {
        if (0 > ind && size <= ind)
        {
            cout << "�������� ������" << endl;
            abort();
        }
        int kol = 0;
        Node* temporary = begin->right;
        while (ind != kol)
        {
            ++kol;
            temporary = temporary->right;
        }
        return temporary->data;
    }

    //�������� ���� ��������� ������ 
    void erase()
    {
        Node* temporary = begin->right;
        Node* aback = nullptr;

        while (temporary != nullptr)
        {
            aback = temporary;
            temporary = temporary->right;
            delete[] aback;
        }

        end = begin;
        begin->right = nullptr;
        end->left = nullptr;
        size = 0;
    }

    //�������� ���������� �������� 
    void pop()
    {
        if (size == 0)
        {
            cout << "������ ������ �������" << endl;
            return;
        }
        Node* temporary = end;
        end = end->left;
        end->right = nullptr;
        delete[] temporary;
        size--;
    }

    //�������� �� ����� ��������  
    void pop_k(T key)
    {
        if (size == 0)
        {
            cout << "������ ������ �������" <<
                endl;
            return;
        }
        Node* temporary = begin->right;
        while (temporary != nullptr && key != temporary->data)
        {
            temporary = temporary->right;
        }

        if (temporary == nullptr)
        {
            cout << "������ �������� ����" << endl;
            return;
        }
        else
        {
            if (temporary == end)
                end = temporary->left;

            (temporary->left)->right = temporary->right;
            delete[]temporary;
            --size;
        }
    }
};