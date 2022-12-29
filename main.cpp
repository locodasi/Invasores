#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <list>

#define DERECHA 77
#define IZQUIERDA 75

using namespace std;

void xy(int x, int y)
{
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD corde;
    corde.X=x;
    corde.Y=y;
    SetConsoleCursorPosition(h,corde);
}
class Bala
{
    int x,y;
public:
    Bala(int _x, int _y)
    {
        x=_x;
        y=_y;
    }
    void mover2()
    {
        xy(x,y);
        cout<<" ";
        if(y<29)
        {
            y++;
        }
        xy(x,y);
        cout<<"*";
    }
    bool fuera2()
    {
        if(y==29)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void mover()
    {
        xy(x,y);
        cout<<" ";
        if(y>4)
        {
            y--;
        }
        xy(x,y);
        cout<<"*";
    }
    bool fuera()
    {
        if(y==4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void eliminar()
    {
        xy(x,y);
        cout<<" ";
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    ~Bala()
    {
    }
};
class Nave
{
protected:
    int x,y;
    int dano;
public:
    Nave()
    {
    }
    virtual void pintar()
    {
    }
    virtual void mover(char tecla)
    {

    }
    void borrar()
    {
        xy(x,y-1);
        cout<<" ";
        xy(x-1,y);
        cout<<"   ";
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getDano()
    {
        return dano;
    }
    ~Nave()
    {
    }

};
class Nave_equilibrada:public Nave
{
public:
    Nave_equilibrada()
    {
        x=45;
        y=29;
        dano=10;
    }
    void pintar()
    {
        xy(x,y-1);
        printf("%c",219);
        xy(x-1,y);
        printf("%c%c%c",223,223,223);
    }
    void mover(char tecla)
    {
        borrar();
        if(tecla==DERECHA && x<87)
        {
            x+=2;
        }
        else if(tecla==IZQUIERDA && x>5)
        {
            x-=2;
        }
        else if(tecla==DERECHA && x<88)
        {
            x++;
        }
        else if(tecla==IZQUIERDA && x>4)
        {
            x--;
        }
        xy(x,y);
        pintar();
    }
    ~Nave_equilibrada()
    {
    }
};
class Nave_fuerte:public Nave
{
public:
    Nave_fuerte()
    {
        x=45;
        y=29;
        dano=20;
    }
    void pintar()
    {
        xy(x,y-1);
        printf("%c",127);
        xy(x-1,y);
        printf("%c%c%c",17,223,16);
    }
    void mover(char tecla)
    {
        borrar();
        if(tecla==DERECHA && x<88)
        {
            x++;
        }
        if(tecla==IZQUIERDA && x>4)
        {
            x--;
        }
        xy(x,y);
        pintar();

    }
    ~Nave_fuerte()
    {
    }
};
class Nave_rapida:public Nave
{
public:
    Nave_rapida()
    {
        x=45;
        y=29;
        dano=5;
    }
    void pintar()
    {
        xy(x,y-1);
        printf("%c",94);
        xy(x-1,y);
        printf("%c%c%c",60,254,62);
    }
    void mover(char tecla)
    {
        borrar();
        if(tecla==DERECHA && x<86)
        {
            x+=3;
        }
        if(tecla==IZQUIERDA && x>6)
        {
            x-=3;
        }
        else if(tecla==IZQUIERDA && x>4)
        {
            x--;
        }
        else if(tecla==DERECHA && x<7)
        {
            x++;
        }
        xy(x,y);
        pintar();

    }
    ~Nave_rapida()
    {
    }
};
class Enemigo
{
protected:
    int x,y;
    int vida;
    int valor;
public:
    Enemigo()
    {

    }
    virtual bool golpe(int d,int &puntaje,int &puntaje_obj)
    {
        vida-=d;
        if(vida<=0)
        {
            borrar();
            puntaje+=valor;
            puntaje_obj++;
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual void mover()
    {

    }
    virtual void pintar()
    {

    }
    virtual void  borrar()
    {

    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    virtual bool choque(int _x,int _y)
    {

    }
    ~Enemigo()
    {
    }

};
class Ovni:public Enemigo
{
public:
    Ovni(int _x,int _y)
    {
        x=_x;
        y=_y;
        vida=5;
        valor=1;
    }

    void mover()
    {

        borrar();
        x-=2;
        if(x<5)
        {
            x=87;
            y=10+rand()%(25-10+1);
        }
        pintar();
    }
    void pintar()
    {
        xy(x-1,y);
        printf("_%c_",219);
    }
    void  borrar()
    {
        xy(x-1,y);
        cout<<"    ";
    }
    bool choque(int _x, int _y)
    {
        if(y==_y && (x==_x || x-1==_x || x+1==_x))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Ovni()
    {

    }
};
class Ovni_fuerte:public Enemigo
{
public:
    Ovni_fuerte(int _x,int _y)
    {
        x=_x;
        y=_y;
        vida=20;
        valor=3;
    }
    void mover()
    {

        borrar();
        x--;
        if(x<4)
        {
            x=87;
            y=10+rand()%(25-10+1);
        }
        pintar();
    }
    void pintar()
    {
        xy(x-1,y);
        printf("%c%c%c",220,220,220);
        xy(x,y+1);
        printf("%c",190);
    }
    void  borrar()
    {
        xy(x-1,y);
        cout<<"    ";
        xy(x,y+1);
        printf(" ");
    }
    bool choque(int _x, int _y)
    {
        if(y==_y && (x-1==_x || x+1==_x || x==_x))
        {
            return true;
        }
        else if(x==_x && y+1==_y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Ovni_fuerte()
    {

    }
};
class Ovni_escudo:public Enemigo
{
public:
    Ovni_escudo(int _x,int _y)
    {
        x=_x;
        y=_y;
        vida=100;
        valor=10;
    }
    void pintar()
    {
        xy(x-2,y);
        printf("%c%c%c%c%c",174,220,220,220,175);
    }
    void  borrar()
    {
        xy(x-2,y);
        cout<<"     ";
    }
    bool choque(int _x, int _y)
    {
        if(y==_y && (x-1==_x || x+1==_x || x==_x || x-2==_x || x+2==_x))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Ovni_escudo()
    {

    }
};
class Ovni_nodriza:public Enemigo
{
protected:
    int ciclo=0;
    bool jefe_camino=false;
    list<Bala*> onbalas;
        list<Bala*>::iterator onibalas;
public:
    Ovni_nodriza(int _x, int _y)
    {
        x=_x;
        y=_y;
        vida=500;
    }
    void pintar()
    {
        xy(x-2,y-1);
        printf(" %c%c%c",40,1,41);
        xy(x-2,y);
        printf("%c%c%c%c%c",219,219,219,219,219);
        xy(x-2,y+1);
        printf("%c%c%c%c%c",190,31,190,31,190);
    }
    void  borrar()
    {
        xy(x-3,y-1);
        cout<<"       ";
        xy(x-3,y);
        cout<<"       ";
        xy(x-3,y+1);
        cout<<"       ";
    }
    bool choque(int _x, int _y)
    {
        if(y==_y && (x-1==_x || x+1==_x || x==_x || x-2==_x || x+2==_x))
        {
            return true;
        }
        else if (y+1==_y && (x-1==_x || x+1==_x || x==_x || x-2==_x || x+2==_x))
        {
            return true;
        }
        else if (y-1==_y && (x-1==_x || x+1==_x || x==_x))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void mover()
    {
        if(jefe_camino)
        {
            borrar();
            x++;
            if(x>85)
            {
                jefe_camino=false;
            }
            pintar();
        }
        else
        {
            borrar();
            x--;
            if(x<7)
            {
                jefe_camino=true;
            }
            pintar();
        }

    }
    bool golpe(int d)
    {
        vida-=d;
        if(vida<=0)
        {
            morir();
            return true;
        }
        else
        {
            return false;
        }
    }
    void morir()
    {
        borrar();
        if(x>45)
        {
            for(; x>45; x--)
            {
                borrar();
                pintar();
                Sleep(100);
            }
        }
        else if(x<45)
        {
            for(; x<45; x++)
            {
                borrar();
                pintar();
                Sleep(100);
            }
        }
        Sleep(100);
        for(int i=0; i<10; i++)
        {
            borrar();
            y++;
            pintar();
            Sleep(50);
        }
        borrar();
        xy(x,y);
        cout<<"*";
        Sleep(200);
        xy(x-1,y);
        cout<<"***";
        xy(x,y+1);
        cout<<"*";
        xy(x,y-1);
        cout<<"*";
        Sleep(200);
        xy(x-2,y);
        cout<<"*****";
        xy(x-1,y+1);
        cout<<"***";
        xy(x-1,y-1);
        cout<<"***";
        xy(x,y+2);
        cout<<"*";
        xy(x,y-2);
        cout<<"*";
        Sleep(200);
        xy(x-3,y);
        cout<<"*******";
        xy(x-2,y+1);
        cout<<"*****";
        xy(x-2,y-1);
        cout<<"*****";
        xy(x-1,y+2);
        cout<<"***";
        xy(x-1,y-2);
        cout<<"***";
        xy(x,y+3);
        cout<<"*";
        xy(x,y-3);
        cout<<"*";
        Sleep(300);
    }
    void disparo(Nave &n, int &duracion)
    {
        if(ciclo==12)
                {
                    ciclo=0;
                 onbalas.push_back(new Bala(x,y+2));
                }
                else
                {
                    ciclo++;
                }


                for(onibalas=onbalas.begin(); onibalas!=onbalas.end(); onibalas++)
                {
                    (*onibalas)->mover2();
                    if((*onibalas)->getX()==n.getX() && (*onibalas)->getY()==n.getY()-1)
                    {
                        duracion=0;
                    }
                    else if((*onibalas)->getX()==n.getX()-1 && (*onibalas)->getY()==n.getY())
                    {
                       duracion=0;
                    }
                    else if((*onibalas)->getX()==n.getX()+1 && (*onibalas)->getY()==n.getY())
                    {
                       duracion=0;
                    }
                    if((*onibalas)->fuera2())
                    {
                        (*onibalas)->eliminar();
                        delete(*onibalas);
                        onibalas=onbalas.erase(onibalas);
                    }
                }
    }

};

class Objetos
{
protected:
    int x,y;
public:

    virtual void pintar()
    {
    }
    virtual void efecto(int &e)
    {
    }
    bool tocar(int _x,int _y, int &e)
    {
        if(y==_y && (x==_x || x==_x-1 || x==_x+1))
        {
            efecto(e);
            return true;
        }
        return false;
    }
    ~Objetos()
    {
    }
};
class Super_bala:public Objetos
{
public:
    void pintar()
    {
        x=4+rand()%(89-4+1);
        y=29;
        xy(x,y-1);
        cout<<"*";
        xy(x,y);
        cout<<"*";
    }
    void efecto(int &tiempo_sb)
    {
        xy(x,y-1);
        cout<<" ";
        tiempo_sb=10;
    }
    ~Super_bala()
    {
    }

};
class Tiempo:public Objetos
{
public:
    void pintar()
    {
        x=4+rand()%(89-4+1);
        y=29;
        xy(x,y);
        cout<<"+";
    }
    void efecto(int &duracion)
    {
        duracion+=10;
    }
    ~Tiempo()
    {
    }

};
class Punto:public Objetos
{
public:
    void pintar()
    {
        x=4+rand()%(89-4+1);
        y=29;
        xy(x,y);
        cout<<"©";
    }
    void efecto(int &puntaje)
    {
        puntaje+=10;
    }
    ~Punto()
    {
    }
};


class Invasores
{
    int op;
    bool game_over;
    int tiempo;
int puntaje;
int duracion;
bool jefe_derrotado;

        list<Super_bala>sb;
        list<Super_bala>::iterator isb;
        list<Tiempo>t;
        list<Tiempo>::iterator it;
        list<Punto>p;
        list<Punto>::iterator ip;

        list<Ovni*>ovni;
        list<Ovni*>::iterator iovni;
        list<Ovni_fuerte*>ovni_fuerte;
        list<Ovni_fuerte*>::iterator iovni_fuerte;
        list<Ovni_escudo*>ovni_escudo;
        list<Ovni_escudo*>::iterator iovni_escudo;
        list<Bala*> balas;
        list<Bala*>::iterator ibalas;
        int tiempo_sb;
        int ultima_aparicion;
        int puntaje_obj;


public:
    Invasores()
    {
        game_over=false;
        jefe_derrotado=false;
        duracion=60;
        puntaje=0;
        tiempo_sb=0;
        tiempo=time(NULL);
        ultima_aparicion=0;
        puntaje_obj=0;
    }
    void ocultar_cursor()
    {
        HANDLE h;
        h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO consol;
        consol.dwSize=1;
        consol.bVisible=0;
        SetConsoleCursorInfo(h,&consol);
    }
    void mover_enemigo(Ovni_nodriza &on)
    {
        for(iovni=ovni.begin(); iovni!=ovni.end(); iovni++)
                {
                    (*iovni)->mover();
                }
                for(iovni_fuerte=ovni_fuerte.begin(); iovni_fuerte!=ovni_fuerte.end(); iovni_fuerte++)
                {
                    (*iovni_fuerte)->mover();
                }
                for(iovni_escudo=ovni_escudo.begin(); iovni_escudo!=ovni_escudo.end(); iovni_escudo++)
                {
                    (*iovni_escudo)->pintar();
                }
                on.mover();
    }
    void impacto_enemigo(Ovni_nodriza &on, Nave &n)
    {
        for(iovni=ovni.begin(); iovni!=ovni.end(); iovni++)
                {
                    for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
                    {
                        if((*iovni)->choque((*ibalas)->getX(),(*ibalas)->getY()))
                        {
                            (*ibalas)->eliminar();
                            delete(*ibalas);
                            ibalas=balas.erase(ibalas);

                            if((*iovni)->golpe(n.getDano(),puntaje,puntaje_obj))
                            {
                                ovni.push_back(new Ovni(80+rand()%(87-80+1),10+rand()%(25-10+1)));
                                delete(*iovni);
                                iovni=ovni.erase(iovni);
                            }

                        }
                    }
                }
                for(iovni_fuerte=ovni_fuerte.begin(); iovni_fuerte!=ovni_fuerte.end(); iovni_fuerte++)
                {
                    for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
                    {
                        if((*iovni_fuerte)->choque((*ibalas)->getX(),(*ibalas)->getY()))
                        {
                            (*ibalas)->eliminar();
                            delete(*ibalas);
                            ibalas=balas.erase(ibalas);

                            if((*iovni_fuerte)->golpe(n.getDano(),puntaje,puntaje_obj))
                            {
                                ovni_fuerte.push_back(new Ovni_fuerte(80+rand()%(87-80+1),10+rand()%(25-10+1)));
                                delete(*iovni_fuerte);
                                iovni_fuerte=ovni_fuerte.erase(iovni_fuerte);
                            }

                        }
                    }
                }

                for(iovni_escudo=ovni_escudo.begin(); iovni_escudo!=ovni_escudo.end(); iovni_escudo++)
                {
                    for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
                    {
                        if((*iovni_escudo)->choque((*ibalas)->getX(),(*ibalas)->getY()))
                        {
                            (*ibalas)->eliminar();
                            delete(*ibalas);
                            ibalas=balas.erase(ibalas);

                            if((*iovni_escudo)->golpe(n.getDano(),puntaje,puntaje_obj))
                            {
                                ovni_escudo.push_back(new Ovni_escudo(6,8));
                                delete(*iovni_escudo);
                                iovni_escudo=ovni_escudo.erase(iovni_escudo);
                                ovni_escudo.pop_back();

                            }

                        }
                    }
                }

                for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
                {
                    if(on.choque((*ibalas)->getX(),(*ibalas)->getY()))
                    {
                        (*ibalas)->eliminar();
                        delete(*ibalas);
                        ibalas=balas.erase(ibalas);

                        if(on.golpe(n.getDano()))
                        {
                            jefe_derrotado=true;
                        }

                    }
                }
    }
    void meter_enemigos()
    {
        for(int i=0; i<5; i++)
        {
            ovni.push_back(new Ovni(80+rand()%(87-80+1),10+rand()%(25-10+1)));
        }
        for(int i=0; i<4; i++)
        {
            ovni_fuerte.push_back(new Ovni_fuerte(80+rand()%(87-80+1),10+rand()%(25-10+1)));
        }
        for(int i=0,j=6; i<8; i++,j+=11)
        {
            ovni_escudo.push_back(new Ovni_escudo(j,8));
        }
    }
    void disparar(char tecla, Nave &n)
    {
        if(tiempo_sb>0 && tecla==32 && balas.size()<=15)
                    {
                        balas.push_back(new Bala(n.getX(),n.getY()-2));
                        if(n.getX()<=87)
                        {
                            balas.push_back(new Bala(n.getX()+2,n.getY()-2));
                        }
                        if(n.getX()>=5)
                        {
                            balas.push_back(new Bala(n.getX()-2,n.getY()-2));
                        }

                    }
                    else if(tecla==32 && balas.size()<=5)
                    {
                        balas.push_back(new Bala(n.getX(),n.getY()-2));
                    }
    }
    aparecer_objetos(int &puntaje_obj, int &ultima_aparicion)
    {
        int ale;
        if(puntaje_obj==15 || ultima_aparicion==10)
                {
                    if(ultima_aparicion==10)
                    {
                        ultima_aparicion=0;
                    }
                    if(puntaje_obj==15)
                    {
                        puntaje_obj=0;
                    }
                    ale=rand()%10;
                    if(ale==0 || ale==1)
                    {
                        Super_bala s;
                        aparecer(s);
                        sb.push_back(s);
                    }
                    else if(ale>=2 && ale<=4)
                    {
                        Tiempo ti;
                        aparecer(ti);
                        t.push_back(ti);
                    }
                    else
                    {
                        Punto pu;
                        aparecer(pu);
                        p.push_back(pu);
                    }
                }

    }
    tocar_objetos(Nave &n)
    {
        for(isb=sb.begin(); isb!=sb.end(); isb++)
                {
                    if(isb->tocar(n.getX(),n.getY(),tiempo_sb))
                    {
                        sb.erase(isb);
                        isb=sb.begin();
                    }

                }
                for(it=t.begin(); it!=t.end(); it++)
                {
                    if(it->tocar(n.getX(),n.getY(),duracion))
                    {
                        t.erase(it);
                        it=t.begin();
                    }

                }
                for(ip=p.begin(); ip!=p.end(); ip++)
                {
                    if(ip->tocar(n.getX(),n.getY(),puntaje))
                    {
                        p.erase(ip);
                        ip=p.begin();
                    }
                }
    }

    void escenario()
    {
        int i;
        for(i=2; i<=90; i++)
        {
            xy(i,3);
            printf("%c",205);
        }
        for(i=2; i<=90; i++)
        {
            xy(i,30);
            printf("%c",205);
        }
        for(i=3; i<=30; i++)
        {
            xy(2,i);
            printf("%c",186);
        }
        for(i=3; i<=30; i++)
        {
            xy(90,i);
            printf("%c",186);
        }
        xy(2,3);
        printf("%c",201);
        xy(2,30);
        printf("%c",200);
        xy(90,3);
        printf("%c",187);
        xy(90,30);
        printf("%c",188);
    }
    void introduccion()
    {
        xy(40,1);
        cout<<"Invasores";
        xy(3,4);
        cout<<"Bienvenido capi, los aliens nos han invadido y destruido casi todas nuestras fuerzas.";
        xy(3,5);
        cout<<"Eres la ultima ofensiva de la humanidad.";
        xy(3,6);
        cout<<"Debes ya sea, destruir su nave nodriza, o debilitar lo mas posible su ejercito para";
        xy(3,7);
        cout<<"que la resistencia humana tenga una oportunidad.";
        xy(3,8);
        cout<<"Para eso podras elegir entre 3 naves con diferentes caracteristicas para tu lucha.";
        xy(3,10);
        printf(" %c",127);
        xy(3,11);
        printf("%c%c%c La Enterprise, una nave de gran potencia, pero muy lenta.",17,223,16);
        xy(3,13);
        printf(" %c",219);
        xy(3,14);
        printf("%c%c%c El volador espacial 2000, el perfecto equilibrio de fuerza y velocidad.",223,223,223);
        xy(3,16);
        printf(" %c",94);
        xy(3,17);
        printf("%c%c%c El Halcon milenario, una nave con gran velocidad, pero poca potencia de fuego.",60,254,62);
        xy(3,19);
        cout<<"Sin importar la nave que elijas, recuerda que puedes moverte de izquierda a derecha con";
        xy(3,20);
        cout<<"las flechas y disparar con la barra espaciadora.";
        xy(3,22);
        cout<<"Entonces capi, elija su nave: ";
        cin>>op;
        while(op<1 || op>3)
        {
            xy(3,22);
            cout<<"Perdon capi, no existe esa nave, elija de nuevo: ";
            cin>>op;
            xy(3,22);
            cout<<"                                                       ";
            xy(3,22);
        }
        system("CLS");
        escenario();
        if(op==1)
        {
            Nave_fuerte n;
            n.pintar();
            juego(n);
            epilogo();
        }
        else if(op==2)
        {
            Nave_equilibrada n;
            n.pintar();
            juego(n);
            epilogo();
        }
        else
        {
            Nave_rapida n;
            n.pintar();
            juego(n);
            epilogo();
        }

    }
    void juego(Nave &n)
    {
        meter_enemigos();
        Ovni_nodriza on(45,5);

        xy(4,2);
        cout<<"Puntaje:"<<puntaje;
        xy(45,2);
        cout<<duracion;
        getch();
        while(!game_over)
        {

            xy(4,2);
            cout<<"Puntaje:"<<puntaje;
            xy(45,2);
            if(tiempo!=time(NULL))
            {
                tiempo=time(NULL);
                duracion--;
                ultima_aparicion++;
                tiempo_sb--;
                cout<<duracion;
            }
            if(duracion<100)
            {
                xy(47,2);
                cout<<" ";
            }
            if(duracion<10)
            {
                xy(46,2);
                cout<<" ";
            }
            if(duracion>0 && !jefe_derrotado)
            {


                if(kbhit())
                {
                    char tecla=getch();
                    disparar(tecla,n);
                    n.mover(tecla);
                }
                mover_bala();
                mover_enemigo(on);
                impacto_enemigo(on,n);


                on.disparo(n,duracion);
                aparecer_objetos(puntaje_obj,ultima_aparicion);
                tocar_objetos(n);


               /*
               por si descubro como hacer que el impacto de balas no cause error, esto va en on.disparo(n)
                for(onibalas=onbalas.begin(); onibalas!=onbalas.end(); onibalas++)
                {
                    for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
                    {
                      if((*ibalas)->getX()==(*onibalas)->getX() && (*ibalas)->getY()== (*onibalas)->getY())
                      {

                      }
                    }
                }*/



                Sleep(30);
            }
            else
            {
                game_over=true;
            }
        }

    }
    void epilogo()
    {
        system("CLS");
        escenario();
        if(puntaje<150 && !jefe_derrotado)
        {
            xy(40,1);
            cout<<"Invasores";
            xy(3,4);
            cout<<"Lo lamento capi, a pesar de tus esfuerzos, apenas has mermado las fuerzas enemigas.";
            xy(3,5);
            cout<<"Los aliens nos han destruido y apenas les hemos golpeado.";
            xy(3,6);
            cout<<"Dudo que la resistencia pueda con ellos, pero al menos peleamos todo lo que";
            xy(3,7);
            printf("pudimos, %cverdad?",168);
            xy(37,14);
            cout<<"¡¡¡Felicidades!!!";
            xy(35,15);
            cout<<"Conseguiste "<<puntaje<<" Puntos"<<endl<<endl<<endl ;
            Sleep(20000);
            getch();
        }
        else if(puntaje<300 && !jefe_derrotado)
        {
            xy(40,1);
            cout<<"Invasores";
            xy(3,4);
            cout<<"Bien hecho capi, lograste destruir varias de sus naves, talvez no sea suficiente, pero";
            xy(3,5);
            cout<<"al menos has logrado darle una oportunidad a la humanidad.";
            xy(3,6);
            cout<<"Nos espera una dura batalla, pero mientras haya esperanza, lucharemos.";
            xy(3,7);
            cout<<"Al fin y al cabo, asi somos los humanos.";
            xy(40,12);
            cout<<"¡¡¡Felicidades!!!";
            xy(40,13);
            cout<<"Conseguiste "<<puntaje<<" Puntos"<<endl<<endl<<endl ;
            Sleep(20000);
            getch();
        }
        else if(puntaje>300 && !jefe_derrotado)
        {
            xy(40,1);
            cout<<"Invasores";
            xy(3,4);
            cout<<"Impresionante, has destruido completamente sus naves, esto debio ser un duro golpe para";
            xy(3,5);
            cout<<"ellos.";
            xy(3,6);
            cout<<"No te preocupes por no haber podido destruir su nave nodriza, a fin de cuentas lograste";
            xy(3,7);
            cout<<"lastimarlos bastante.";
            xy(3,8);
            printf("La resistencia esta emocionada, ven esta victoria como una se%cal.",164);
            xy(3,9);
            printf("Una se%cal de que no todo esta perdido, de que aun podemos pelear.",164);
            xy(3,10);
            cout<<"Esto es gracias a ti capi, muchas gracias.";
            xy(40,14);
            cout<<"¡¡¡Felicidades!!!";
            xy(40,15);
            cout<<"Conseguiste "<<puntaje<<" Puntos"<<endl<<endl<<endl ;
            Sleep(20000);
            getch();
        }
        else
        {
            xy(40,1);
            cout<<"Invasores";
            xy(3,4);
            cout<<"Lo lograste... JAJAJAJAJA. ¡¡¡¡Lo lograste!!!";
            xy(3,5);
            cout<<"No puedo creerlo capi, no puedo creerlo, destruiste su nave nodriza.";
            xy(3,6);
            cout<<"Los aliens dejaron de atacar, se estan retirando, ¡Ganamos!, ¡¡verdaderamente ganamos!!";
            xy(3,7);
            cout<<"La gente sale a la calle para celebrar esta victoria, es un nuevo dia para la humanidad";
            xy(3,8);
            cout<<"Muchas gracias, capi, gracias por salvarnos a todos, hoy fuiste el heroe";
            xy(40,12);
            cout<<"¡¡¡Felicidades!!!";
            xy(40,13);
            cout<<"Conseguiste "<<puntaje<<" Puntos"<<endl<<endl<<endl ;
            Sleep(20000);
            getch();
            creditos();
        }
        system("cls");
    }
    void creditos_nave(Nave &n)
    {
        n.pintar();
        do
        {
            if(kbhit())
            {
                char tecla=getch();

                if(tecla==32)
                {
                    balas.push_back(new Bala(n.getX(),n.getY()-2));
                }
                else
                {
                    n.mover(tecla);
                }

            }
            mover_bala();
            Sleep(30);
        }
        while(tiempo+10!=time(NULL));
        n.borrar();
        getch();
    }
    void creditos()
    {
        tiempo=time(NULL);
        list<Bala*> balas;
        list<Bala*>::iterator ibalas;
        system("cls");
        escenario();
        xy(40,9);
        cout<<"Muchas gracias por jugar";
        xy(37,10);
        cout<<"Creado por Lucas Da Silva Fradkin";
        Nave_fuerte n1;
        creditos_nave(n1);
        tiempo=time(NULL);
        system("cls");
        escenario();
        xy(7,9);
        cout<<"Juego creado para final de la UCES";
        xy(21,10);
        cout<<"Materia: Programacion II";
        Nave_equilibrada n2;
        creditos_nave(n2);
        tiempo=time(NULL);
        system("cls");
        escenario();
        xy(66,9);
        cout<<"Programado en c++";
        Nave_rapida n3;
        creditos_nave(n3);
        system("cls");
        escenario();
        xy(40,9);
        cout<<"!!Gracias¡¡";
        Sleep(5000);
        getch();
        system("cls");
    }

    void mover_bala()
    {
        for(ibalas=balas.begin(); ibalas!=balas.end(); ibalas++)
        {
            (*ibalas)->mover();
            if((*ibalas)->fuera())
            {
                (*ibalas)->eliminar();
                delete(*ibalas);
                ibalas=balas.erase(ibalas);
            }
        }
    }
    void aparecer(Objetos &i)
    {
        i.pintar();
    }
    ~Invasores()
    {

    }
};
int main()
{
    Invasores in;
    in.ocultar_cursor();
    in.escenario();
    in.introduccion();
    return 0;
}
