#pragma once 
using namespace std;
template <typename T>
class List
{
public:
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
    List()
        :begin(new Node)
        , end(begin)
        , size(0) {}

    //����������� � ����������� 
    explicit List(const T& data)
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
    List(const List& obj)
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
    List(List&& obj)
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
    List& operator =(const List& obj)
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
    List& operator =(List& obj)
    {
        if (obj.begin() == this->begin())
        {
            cout << "Cannot move there";
            abort();
        }
        //������ ����� ������ 
        //��������� ������ � ����� ������ obj � ������� ��� 
        //������ ����� head ��� obj 
        if (obj.begin = this->begin)
        {
            cout << "Error";
            return this;
        }

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

    if (ind < 0 || size < ind)
    {
        cout << "�������� ������" << endl;
        abort();
    }
    int kol = 0;
    Node* temporary = nullptr;
    if (ind < size / 2)
    {
        temporary = begin->right;
        while (ind != kol)
        {
            ++kol;
            temporary = temporary->right;
        }
    }
    else
    {
        temporary = end;
        while (ind != size-kol)
        {
            kol++;
            temporary = temporary->left;
        }
        temporary = temporary->right;
    }
    return temporary->data;
}

    //�������� ���� ��������� ������ 
    void clear()
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

    //����� �� �����
    Node* find(T key)
    {
        Node* temporary = begin->right;
        while (temporary != nullptr && key != temporary->data)
        {
            temporary = temporary->right;
        }

        if (temporary == nullptr)
        {
            cout << "������ �������� ����" << endl;
            return ;
            //abort();
        }
        else
        {
            return temporary;
        }
    }

    //�������� �� ����� ��������  
    void pop_k(T key)
    {
        if (size == 0)
        {
            cout << "������ ������ �������" <<endl;
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