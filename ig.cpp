#include<iostream>
using namespace std;

struct term
{
    int min_dec[100], bin[100],no_of_one;
    term *next;
};
term *previous, *imp, *saved, *start;
int func, var, no_of_minterms[100];

void display_list(term*);

int main()
{
    int i,j,k,t,x,l;
    term *temp;
    cout<<"Enter number of functions: ";
    cin>>func;
    cout<<"\nEnter number of variables: ";
    cin>>var;
    for(i=0;i<func;i++)
    {
        cout<<"Enter data for function "<<i+1<<" :\n";
        cout<<"Enter the number of minterms\n";
        cin>>no_of_minterms[i];
        cout<<"Enter the minterms: \n";
        start = temp = new term();
        t = no_of_minterms[i] - 1;
        cin>>temp->min_dec[0];
        temp->no_of_one = 0;
        x = var;
        k = 0;
        l = temp->min_dec[0];
        while(x--)
        {
            if(l % 2 == 1)
            {
                temp->bin[k] = 1;
                temp->no_of_one++;
            }
            else
            {
                temp->bin[k] = 0;
            }
            l/=2;
            k++;
        }
        while(t--)
        {
            temp = temp->next = new term();
            cin>>temp->min_dec[0];
            l = temp->min_dec[0];
            l/=2;
            temp->no_of_one=0;
            x = var;
            k = 0;
            while(x--)
            {
                if(l % 2 ==1)
                {
                    temp->bin[k] = 1;
                    temp->no_of_one++;
                }
                else
                {
                    temp->bin[k] = 0;
                }
                l /= 2;
                k++;
            }
        }
        temp->next = NULL;
        // display_list(start);
        
    }
    return 0;
}

void display_list(term *temp)
{
    while(temp != NULL)
    {
        cout<<temp->min_dec[0]<<endl;
        for(int i=var-1;i>=0;i--)
        {
            cout<<temp->bin[i];
        }
        cout<<endl;
        temp = temp->next;
    }
}