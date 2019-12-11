#ifndef TAB2D_H

#define TAB2D_H

class Tab2D

{

public:
    Tab2D();

    virtual ~Tab2D();

    void add();

    double get(int i, int j) { return tab[i][j]; }

    void set(int i, int j, double var) { tab[i][j] = var; }

    void set_mirror(int i, int j, double var)
    {
        tab[i][j] = var;

        tab[j][i] = var;
    }

    void set_all(double var);

    void add_mirror(int i, int j, double var)
    {
        tab[i][j] += var;

        tab[j][i] += var;
    }

    void add_all(double var);

    void add_all(Tab2D &target);

    void copy_mirror(Tab2D &target);

    void all_multiply_by(double var);

protected:
private:
    int tab_size = 0;

    int tab_size_limit = 4;

    double **tab;
};

#endif // TAB2D_H
