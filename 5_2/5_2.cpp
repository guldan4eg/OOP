#include <iostream>
#include <vector>

using namespace std;

void Generate_Random(vector<int>& nums, int n);
void Generate_Manual(vector<int>& nums, int n);
void SortObmen(vector<int>& nums, short length);
void Sort(vector<int>& nums, vector<int>& resnums, int n);

int main()
{
    srand(time(NULL));
    vector<int> nums{ 0 }, resnums{0};
    int choice=0, n = 0;
    cout << "Random-1 Manual-2\n";
    cin >> choice;
    cout << "enter size ";
    cin >> n;
    if (choice == 1)
    {
        Generate_Random(nums, n);
    }
    else if(choice == 2)
    {
        Generate_Manual(nums, n);
    }
    else
    {
        cout << "wrong bruh ";
        return 2;
    }

    SortObmen(nums, n);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    Sort(nums, resnums, n);
    SortObmen(resnums, size(resnums));
    for (int i = 1; i < size(resnums); i++)
    {
        cout << resnums[i] << " ";
    }
}

void Generate_Random(vector<int>& nums, int n)
{
    nums[0] = rand() % 10;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(rand()%10);
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i]<<" ";
    }
    cout << endl;
}

void Generate_Manual(vector<int>& nums, int n)
{
    int nument=0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number in massive"<<endl;
        cin >> nument;
        if (i != 0)
        {
            nums.push_back(nument);
        }
        else
        {
            nums[0] = nument;
        }
    }
    cout << endl;
}


void SortObmen(vector<int>& nums, short length)
{
    int min = nums[0];

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = length - 1; j > i; j--)
        {
            if (nums[j - 1] > nums[j])
            {
                min = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = min;
            }
        }
    }
}

void Sort(vector<int>& nums, vector<int>& resnums, int n)
{
    bool k = 0;
    if (nums[0] != nums[1])
    {
        resnums.push_back(nums[0]);
    }
    if (nums[n-1] != nums[n-2])
    {
        resnums.push_back(nums[n-1]);
    }

    for (int i = 1; i < n-1; i++)
    {
        
        if (nums[i] != nums[i-1] && nums[i] != nums[i+1])
        {
            resnums.push_back(nums[i]);
        }
    }
}