#include "tab2d.h"


Tab2D::Tab2D()

{

tab = new double*[tab_size_limit];

}


void Tab2D::add()

{

if(tab_size==tab_size_limit)

{

tab_size_limit*=2;

double ** tab_buffer = new double*[tab_size_limit];

for(int i = 0; i<tab_size; i++)

{

tab_buffer[i] = new double[tab_size_limit];

for(int j = 0; j < tab_size; j++)

{

tab_buffer[i][j] = tab[i][j];

}


}

for(int i = 0; i<tab_size_limit/2; i++)

delete [] tab[i];

delete [] tab;


tab = tab_buffer;

}


tab[tab_size] = new double[tab_size_limit];

tab_size++;

}

void Tab2D::copy_mirror(Tab2D &target)

{

for(int i=0; i< tab_size; i++)

{

for(int j=0; i<j;j++)

{

tab[i][j]=tab[j][i]=target.get(i,j);

}

}

}


void Tab2D::set_all(double var)

{

for(int i=0; i< tab_size; i++)

{

for(int j=0; i<j;j++)

{

tab[i][j]=tab[j][i]=var;

}

}



}


void Tab2D::add_all(double var)

{

for(int i=0; i< tab_size; i++)

{

for(int j=0; i<j;j++)

{

tab[i][j]=tab[j][i]+=var;

}

}

}


void Tab2D::add_all(Tab2D &target)

{

for(int i=0; i< tab_size; i++)

{

for(int j=0; i<j;j++)

{

tab[i][j]=tab[j][i]+=target.get(i,j);

}

}

}


void Tab2D::all_multiply_by(double var)

{

for(int i=0; i< tab_size; i++)

{

for(int j=0; i<j;j++)

{

tab[i][j]=tab[j][i]*=var;

}

}

}


Tab2D::~Tab2D()

{

for(int i = 0; i<tab_size; i++)

delete [] tab[i];

delete [] tab;

}

