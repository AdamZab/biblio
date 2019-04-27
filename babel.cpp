#include <iostream>

using namespace std;

int main ()
{
int tab[5];
int tmp, ii,jj;

    for(ii=0; ii<5; ii++){
        cin >> tab[ii];
    }

    for(jj=0; jj<5; jj++){
        for(ii=0; ii<5; ii++){
            if (tab[ii]>tab[ii+1]){
                tmp=tab[ii+1];
                tab[ii+1]=tab[ii];
                tab[ii]=tmp;
            }
        }
    }

    cout << "sorted:" << endl;

    for(ii=0; ii<5; ii++){
        cout << tab[ii] << endl;
    }

    return 0;
}
		
