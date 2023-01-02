#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Node
{public:
    Node(){  }
    Node(int a, int b){ x=a; y=b; }
    Node *next;
    void setX(int a){ x=a; }
    void setY(int a){ y=a; }
    int getX(){ return x; }
    int getY(){ return y; }

private:
    int x, y;
};


class List
{public:
    List(){first=new Node; last=new Node; first=NULL; last=NULL; Size=0; }


    int isEmpty(){ if(first==NULL)return 1; return 0; }


    int getSize(){ return Size; }


    void setFirstX(int a){ firstX=a; }


    void setFirstY(int a){ firstY=a; }


    int getFirstX(){ return firstX; }


    int getFirstY(){ return firstY; }


    void setDirection(string x){ direction=x; }


    string getDirection(){ return direction; }


    int checkForZeroList()
        { int ok=0;
        Node *temp;

        temp=first;
        if(temp->getX()!=0 && temp->getY()!=0)
             return 0;

        temp=last;

        if(temp->getX()!=0 && temp->getY()!=0)
            return 0;


        for(temp=first; temp!=last ; temp=temp->next)
             if(temp->getX()!=0 && temp->getY()!=0)
                ok=1;

        if(ok==0)
            return 1;

        return 0;}


    void deleteList()
        { Node *temp=first;

            for(int i=0;i<Size;i++)
                { first=first->next;
                delete temp;
                temp=first; }

        first=last=NULL; }


    void makeListNodeZero(int x, int y)
        { Node *temp;

        temp=last;
        if(temp->getX()==x && temp->getY()==y)
            { temp->setX(0);
            temp->setY(0); }
        else

        for(temp=first; temp!=last ; temp=temp->next)
             if(temp->getX()==x && temp->getY()==y)
                { temp->setX(0);
                 temp->setY(0); } }


    int Search(int x, int y)
        { Node *temp;

        if(isEmpty()!=1)
        {
            if(first->getX()==x && first->getY()==y )
                return 1;
            if(last->getX()==x && last->getY()==y )
                return 1;

        for(temp=first; temp!=last ; temp=temp->next)
             if(temp->getX()==x && temp->getY()==y)
                return 1; }

        return 0;}


    void add(int x, int y)
        { Node *temp=new Node;
        temp->setX(x);
        temp->setY(y);

        if(isEmpty())
            { first=temp; setFirstX(x); setFirstY(y); }
        else
            last->next=temp;

        last=temp;
        last->next=NULL;
        Size++;  }







private:
    Node *first;
    Node *firstCopy;
    int firstY;
    int firstX;
    Node *last;
    int Size;
    string direction;

};



class Game
{public:
    Game()
        {cout<<"Bine ati venit la Battleship!"<<endl<<endl<<"Despre joc:"<<endl<<"1)Aveti 9 piese de asezat pe tabla de joc."<<endl;
        cout<<"2)Pentru fiecare piesa, se vor introduce coordonatele carteziene ale primul punct al piesei, dupa care, piesa se va aseza singura pe tabla de joc."<<endl;
        cout<<"3)In functie de directia piesei, aceasta se va aseza pe orizontala sau pe verticala."<<endl;
        cout<<"4)Piesele trebuie asezate la o distanta de minim o casuta una fata de cealalta."<<endl;
        cout<<"5)Piesele vor fi de dimensiune: 1, 2 sau 3."<<endl;
        cout<<"6)Scopul jocului este de a nimeri piesele adversarului."<<endl;
        cout<<"7)Jocul este turn-based, dar daca un participant la joc nimereste o piesa a adversarului, acesta primeste sansa la inca un atac, si tot asa, pana rateaza.";
        cout<<endl<<"8)Atunci cand atacati, introduceti coordonatele carteziene ale punctului in care doriti sa atacati. Atacul va avea loc pe tabla de joc a adversarului."<<endl;
        cout<<"9)'.' -> reprezinta un atac care nu a nimerit nicio piesa adversa."<<endl;
        cout<<"10)'X' -> reprezinta un atac care a nimerit o piesa adversa."<<endl;
        cout<<"11)In momentul in care eliminati complet o piesa adversa, aceasta este incercuita de '.' pentru a semnala acest lucru."<<endl;
        cout<<"12)Castiga cine elimina primul toate piesele adversarului."<<endl<<endl;

        int tasta;
        do{
        cout<<"Pentru a incepe jocul, apasati tasta 1 ";
        cin>>tasta;
        system("cls");
		}
        while(tasta != 1);

          setPlayerMatrixToZero();
		  cout<<"Table ta de joc"<<endl;
		  showPlayerMatrix();
		   cout<<endl;
		   PlayerAddPiece(1,"horizontal",1);
		    system("cls");
			cout<<"Table ta de joc"<<endl;
			showPlayerMatrix();
			cout<<endl;
			 PlayerAddPiece(1,"horizontal",2);
			  system("cls");
			  cout<<"Table ta de joc"<<endl;
			   showPlayerMatrix();
			    cout<<endl;
				PlayerAddPiece(1,"horizontal",3);
				 system("cls");
				 cout<<"Table ta de joc"<<endl;
				   showPlayerMatrix();
				   cout<<endl;
				    PlayerAddPiece(1,"horizontal",4);
					 system("cls");
					 cout<<"Table ta de joc"<<endl;
					   showPlayerMatrix(); cout<<endl;
					    PlayerAddPiece(2,"horizontal",5);
						 system("cls");
						 cout<<"Table ta de joc"<<endl;
						   showPlayerMatrix();
						    cout<<endl;
							PlayerAddPiece(2,"vertical",6);
							 system("cls");
							  cout<<"Table ta de joc"<<endl;
							   showPlayerMatrix();
							   cout<<endl;
							    PlayerAddPiece(2,"vertical",7);
								 system("cls");
								 cout<<"Table ta de joc"<<endl;
								   showPlayerMatrix();
								    cout<<endl;
									 PlayerAddPiece(3,"horizontal",8);
									   system("cls");
									   cout<<"Table ta de joc"<<endl;
									    showPlayerMatrix();
										 cout<<endl;
										  PlayerAddPiece(3,"vertical",9);
										   system("cls");
										    cout<<"Oponentul isi aseaza piesele..."<<endl;

           setCompMatrixToZero();
		    setCompMatrix2ToZero();
			 CompAddPiece(1,"horizontal",1);
			 CompAddPiece(1,"horizontal",2);
			 CompAddPiece(1,"horizontal",3);
			  CompAddPiece(1,"horizontal",4);
			   CompAddPiece(2,"horizontal",5);
			    CompAddPiece(2,"vertical",6);
				 CompAddPiece(2,"vertical",7);
				  CompAddPiece(3,"horizontal",8);
				   CompAddPiece(3,"vertical",9);
        system("cls");
		cout<<"Table ta de joc"<<endl;
		 showPlayerMatrix();
		  cout<<endl<<endl;
		  cout<<"Tabla oponentului"<<endl;
		   showCompMatrix2(); cout<<endl;



        int x,y;
        string turn="comp";

        while(PlayerPiecesNumber>0 && CompPiecesNumber>0)
        {
            while(turn=="player")
                { cout<<endl<<"Introduceti coordonatele punctului unde doriti sa atacati\nx: ";
				cin>>x;cout<<"y: ";cin>>y; cout<<endl;
                int ok=1;

                while(ok)
                    { if( x>=1 && x<=9 && y>=1 && y<=9)
                         if(CompMatrix[x][y]!="." && CompMatrix[x][y]!="X")
                            { if(CompAttack(x,y,CompPieces)==0)
                                turn="comp";

                            ok=0;
                            system("cls");
                            cout<<"Table ta de joc"<<endl;
                            showPlayerMatrix();
                            cout<<endl<<"Tabla oponentului"<<endl;
                            showCompMatrix2(); }
                        else

                        { cout<<"Nu puteti ataca in punctul: "<<x<<" "<<y<<endl;
                        cout<<endl<<"Introduceti coordonatele punctului unde doriti sa atacati\nx: ";
						cin>>x;cout<<"y: ";cin>>y; cout<<endl; }
                    else

                        { cout<<"Nu puteti ataca in punctul: "<<x<<" "<<y<<endl;
                        cout<<endl<<"Introduceti coordonatele punctului unde doriti sa atacati\nx: ";
						cin>>x;cout<<"y: ";cin>>y; cout<<endl; }   } }


            while(turn=="comp")
                { srand(time(0));
                x=1+(rand()%9);
                y=1+(rand()%9);
                int ok=1;

                while(ok)
                    { if(PlayerMatrix[x][y]!="." && PlayerMatrix[x][y]!="X")
                        { if(PlayerAttack(x,y,PlayerPieces)==0)
                            turn="player";

                        ok=0;
                        system("cls");
                        cout<<"Table ta de joc"<<endl;
                        showPlayerMatrix();
                        cout<<endl<<"Tabla oponentului"<<endl;
                        showCompMatrix2(); }
                    else

                        { srand(time(0));
                        x=1+(rand()%9);
                        y=1+(rand()%9); } } }

        }







           }

   int CompAttack(int X, int Y, List L[])
        { for(int i=1;i<=9;i++)
            if(L[i].Search(X,Y)==1)
                { int x=L[i].getFirstX();
                int y=L[i].getFirstY();

                L[i].makeListNodeZero(X,Y);
                CompMatrix[X][Y]="X";
                CompMatrix2[X][Y]="X";



                if(L[i].checkForZeroList()==1)
                    { int Size=L[i].getSize();
                    int it=0;

                    CompPiecesNumber--;

                    if(L[i].getDirection()=="horizontal")
                        { CompMatrix[x][y-1]=".";
                        CompMatrix[x-1][y-1]=".";
                        CompMatrix[x+1][y-1]=".";

                        CompMatrix[x][y+Size]=".";
                        CompMatrix[x-1][y+Size]=".";
                        CompMatrix[x+1][y+Size]=".";


                        CompMatrix2[x][y-1]=".";
                        CompMatrix2[x-1][y-1]=".";
                        CompMatrix2[x+1][y-1]=".";

                        CompMatrix2[x][y+Size]=".";
                        CompMatrix2[x-1][y+Size]=".";
                        CompMatrix2[x+1][y+Size]=".";

                        while(Size>0)
                            { CompMatrix[x+1][y+it]=".";
                            CompMatrix[x-1][y+it]=".";

                            CompMatrix2[x+1][y+it]=".";
                            CompMatrix2[x-1][y+it]=".";

                            it++;
                            Size--; } }
                    else

                        if(L[i].getDirection()=="vertical")
                            { CompMatrix[x-1][y]=".";
                            CompMatrix[x-1][y-1]=".";
                            CompMatrix[x-1][y+1]=".";

                            CompMatrix[x+Size][y]=".";
                            CompMatrix[x+Size][y-1]=".";
                            CompMatrix[x+Size][y+1]=".";


                            CompMatrix2[x-1][y]=".";
                            CompMatrix2[x-1][y-1]=".";
                            CompMatrix2[x-1][y+1]=".";

                            CompMatrix2[x+Size][y]=".";
                            CompMatrix2[x+Size][y-1]=".";
                            CompMatrix2[x+Size][y+1]=".";

                            while(Size>0)
                                { CompMatrix[x+it][y+1]=".";
                                CompMatrix[x+it][y-1]=".";

                                CompMatrix2[x+it][y+1]=".";
                                CompMatrix2[x+it][y-1]=".";

                                it++;
                                Size--; } }

                        L[i].deleteList(); }

                    return 1;}

        CompMatrix[X][Y]=".";
        CompMatrix2[X][Y]=".";

        setCompMatrix2Margins();
        setCompMatrixMargins();

        return 0; }


    int PlayerAttack(int X, int Y, List L[])
        { for(int i=1;i<=9;i++)
            if(L[i].Search(X,Y)==1)
                { int x=L[i].getFirstX();
                int y=L[i].getFirstY();

                PlayerPiecesNumber--;

                L[i].makeListNodeZero(X,Y);
                PlayerMatrix[X][Y]="X";


                if(L[i].checkForZeroList()==1)
                    { int Size=L[i].getSize();
                    int it=0;

                    if(L[i].getDirection()=="horizontal")
                        { PlayerMatrix[x][y-1]=".";
                        PlayerMatrix[x-1][y-1]=".";
                        PlayerMatrix[x+1][y-1]=".";

                        PlayerMatrix[x][y+Size]=".";
                        PlayerMatrix[x-1][y+Size]=".";
                        PlayerMatrix[x+1][y+Size]=".";

                        while(Size>0)
                            { PlayerMatrix[x+1][y+it]=".";
                            PlayerMatrix[x-1][y+it]=".";
                            it++;
                            Size--; } }
                    else

                        if(L[i].getDirection()=="vertical")
                            { PlayerMatrix[x-1][y]=".";
                            PlayerMatrix[x-1][y-1]=".";
                            PlayerMatrix[x-1][y+1]=".";

                            PlayerMatrix[x+Size][y]=".";
                            PlayerMatrix[x+Size][y-1]=".";
                            PlayerMatrix[x+Size][y+1]=".";

                            while(Size>0)
                                { PlayerMatrix[x+it][y+1]=".";
                                PlayerMatrix[x+it][y-1]=".";
                                it++;
                                Size--; } }

                        L[i].deleteList(); }
		setPlayerMatrixMargins();

                      return 1;}

        setPlayerMatrixMargins();

        PlayerMatrix[X][Y]=".";

        return 0; }


    void setPlayerMatrixMargins()
        { char c[2];
        char *intStr;

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            PlayerMatrix[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            PlayerMatrix[i][0]=intStr; }

        PlayerMatrix[0][0]="."; }


    void setCompMatrixMargins()
        { char c[2];
        char *intStr;

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix[i][0]=intStr; }

        CompMatrix[0][0]="."; }


    void setCompMatrix2Margins()
        { char c[2];
        char *intStr;

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix2[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix2[i][0]=intStr; }

        CompMatrix2[0][0]="."; }


    void setPlayerMatrixToZero()
        {char c[2];
        char *intStr ;

        for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++)
                { intStr = itoa(0,c,10);
                PlayerMatrix[i][j]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            PlayerMatrix[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            PlayerMatrix[i][0]=intStr; }

        PlayerMatrix[0][0]="."; }


    void setCompMatrixToZero()
        { char c[2];
        char *intStr ;

        for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++)
                { intStr = itoa(0,c,10);
                CompMatrix[i][j]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix[i][0]=intStr; }

        CompMatrix[0][0]="."; }


    void setCompMatrix2ToZero()
        { char c[2];
        char *intStr ;

        for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++)
                { CompMatrix2[i][j]="�"; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix2[0][i]=intStr; }

        for(int i=0;i<=9;i++)
            { intStr = itoa(i,c,10);
            CompMatrix2[i][0]=intStr; }

        CompMatrix2[0][0]="."; }


    void showPlayerMatrix()
        { for(int i=0;i<=9;i++)
            { cout<<endl;
            for(int j=0;j<=9;j++)
                cout<<PlayerMatrix[i][j]<<" "; } }




    void showCompMatrix2()
        { for(int i=0;i<=9;i++)
            { cout<<endl;
            for(int j=0;j<=9;j++)
                cout<<CompMatrix2[i][j]<<" "; } }


    void PlayerAddPiece(int Size, string direction, int i)
        { char c[2];
        char *intStr ;
        int x, y;
        int ok[Size];
        for(int k=0;k<Size;k++)ok[k]=0;
        int ok1=0, ok2=0, ok3=0, ok4=0, ok5=0, ok6=0, ok7=1, nr=0;


        while(ok1==0 && ok2==0 && ok3==0 && ok4==0 && ok5==0 ){

        ok1=0, ok2=0, ok3=0, ok4=0, ok5=0, ok6=0, ok7=1;
        for(int k=0;k<Size;k++)ok[k]=0;

        if(nr>0)
            cout<<"Coordonatele piesei nu au fost introduse corect. "<<endl;
        nr++;

        cout<<"Dati coordonatele piesei de marime "<<Size<<" care va fi orientata pe "<<direction<<endl;
        cout<<"x: ";cin>>x;
        cout<<"y: ";cin>>y;
        cout<<endl;


        if( x>=1 && x<=9 && y>=1 && y<=9) {

        if(PlayerMatrix[x][y]=="0" ){

        if(direction=="horizontal"){ for(int k=0;k<Size;k++){ y=y+k; ok6=0;

        if(x>1 && x<9 && y>1 && y<9 &&  PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x+1][y-1]=="0" && PlayerMatrix[x+1][y+1]=="0"
           && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0"  )
               {ok6=1; cout<<"SSSSS";}
        else

            if(x==1 && y==1 && PlayerMatrix[x+1][y+1]=="0" && PlayerMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y==9 && PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(x==1 && y==9 && PlayerMatrix[x+1][y-1]=="0" && PlayerMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y==1 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(x==1 && y>1 && y<9 && PlayerMatrix[x+1][y+1]=="0" && PlayerMatrix[x+1][y-1]=="0"
               && PlayerMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y>1 && y<9 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x-1][y-1]=="0"
               && PlayerMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(y==1 && x>1 && x<9 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x+1][y+1]=="0"
               && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(y==9 && x>1 && x<9 && PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x+1][y-1]=="0"
               && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x-1][y]=="0")
                ok6=1;

        y=y-k; if(ok6==1)ok[k]++; } }

        //------------------------------------------------------------------------------------------------------

        else

        if(direction=="vertical"){ for(int k=0;k<Size;k++){ x=x+k; ok6=0;

        if(x>1 && x<9 && y>1 && y<9 &&  PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x+1][y-1]=="0" && PlayerMatrix[x+1][y+1]=="0"
           && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x][y+1]=="0" )
                ok6=1;
        else

            if(x==1 && y==1 && PlayerMatrix[x+1][y+1]=="0" && PlayerMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(x==9 && y==9 && PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==1 && y==9 && PlayerMatrix[x+1][y-1]=="0" && PlayerMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==9 && y==1 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(x==1 && y>1 && y<9 && PlayerMatrix[x+1][y+1]=="0" && PlayerMatrix[x+1][y-1]=="0"
               && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==9 && y>1 && y<9 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x-1][y-1]=="0"
               && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(y==1 && x>1 && x<9 && PlayerMatrix[x-1][y+1]=="0" && PlayerMatrix[x+1][y+1]=="0"
               && PlayerMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(y==9 && x>1 && x<9 && PlayerMatrix[x-1][y-1]=="0" && PlayerMatrix[x+1][y-1]=="0"
               && PlayerMatrix[x][y-1]=="0")
                ok6=1;
        x=x-k; if(ok6==1)ok[k]++; }  }


        for(int k=0;k<Size;k++)if(ok[k]==0)ok7=0;


        if(ok7==1){

        if( ( Size==1 && x>1 && x<9 && y>1 && y<9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y-1]=="0" )
        || ( Size==1 && x==1 && y>1 && y<9 && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x+1][y]=="0" )
        || ( Size==1 && x==9 && y>1 && y<9 && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x-1][y]=="0" )
        || ( Size==1 && y==1 && x>1 && x<9 && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x][y+1]=="0" )
        || ( Size==1 && y==9 && x>1 && x<9 && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x][y-1]=="0" )
        || ( Size==1 && x==1 && y==1 && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x][y+1]=="0")
        || ( Size==1 && x==9 && y==9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x][y-1]=="0")
        || ( Size==1 && x==1 && y==9 && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x+1][y]=="0")
        || ( Size==1 && x==9 && y==1 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x][y+1]=="0") )
            { intStr = itoa(i,c,10);
            PlayerMatrix[x][y]=intStr;
            PlayerPieces[i].add(x,y);
            ok1=1;
            PlayerPieces[i].setDirection(direction); }
        else

            if(Size==2 && direction=="vertical")
                { intStr = itoa(i,c,10);
                if( ( x>1 && x<=7 && y>=1 && y<=9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x+2][y]=="0" ) ||
                (x==1 && y>=1 && y<=9 && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x+2][y]=="0"  ) ||
                (x==8 && y>=1 && y<=9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0" ) )
                    { PlayerMatrix[x][y]=intStr;
                    PlayerMatrix[x+1][y]=intStr;
                    PlayerPieces[i].add(x,y);
                    PlayerPieces[i].add(x+1,y);
                    ok2=1;
                    PlayerPieces[i].setDirection(direction); } }
        else

             if(Size==2 && direction=="horizontal")
                { intStr = itoa(i,c,10);
                if( ( y>1 && y<=7 && x>=1 && x<=9 && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y+2]=="0" ) ||
                (y==1 && x>=1 && x<=9 && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y+2]=="0"  ) ||
                (y==8 && y>=1 && y<=9 && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x][y+1]=="0" ) )
                    { PlayerMatrix[x][y]=intStr;
                    PlayerMatrix[x][y+1]=intStr;
                    PlayerPieces[i].add(x,y);
                    PlayerPieces[i].add(x,y+1);
                    ok3=1;
                    PlayerPieces[i].setDirection(direction); } }
        else

              if(Size==3 && direction=="vertical")
                { intStr = itoa(i,c,10);
                if( ( x>1 && x<=6 && y>=1 && y<=9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x+2][y]=="0" && PlayerMatrix[x+3][y]=="0" )                || (x==1 && y>=1 && y<=9 && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x+2][y]=="0" && PlayerMatrix[x+3][y]=="0"  )
                || (x==7 && y>=1 && y<=9 && PlayerMatrix[x-1][y]=="0" && PlayerMatrix[x+1][y]=="0" && PlayerMatrix[x+2][y]=="0" ) )
                    { PlayerMatrix[x][y]=intStr;
                    PlayerMatrix[x+1][y]=intStr;
                    PlayerMatrix[x+2][y]=intStr;
                    PlayerPieces[i].add(x,y);
                    PlayerPieces[i].add(x+1,y);
                    PlayerPieces[i].add(x+2,y);
                    ok4=1;
                    PlayerPieces[i].setDirection(direction); } }
        else

            if(Size==3 && direction=="horizontal")
                { intStr = itoa(i,c,10);
                if( ( y>1 && y<=6 && x>=1 && x<=9 && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y+2]=="0" && PlayerMatrix[x][y+3]=="0" )
                || (y==1 && x>=1 && x<=9 && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y+2]=="0" && PlayerMatrix[x][y+3]=="0"   )
                || (y==7 && y>=1 && y<=9 && PlayerMatrix[x][y-1]=="0" && PlayerMatrix[x][y+1]=="0" && PlayerMatrix[x][y+2]=="0" ) )

                    { PlayerMatrix[x][y]=intStr;
                    PlayerMatrix[x][y+1]=intStr;
                    PlayerMatrix[x][y+2]=intStr;
                    PlayerPieces[i].add(x,y);
                    PlayerPieces[i].add(x,y+1);
                    PlayerPieces[i].add(x,y+2);
                    ok5=1;
                    PlayerPieces[i].setDirection(direction); } }

         } } } } }


    void CompAddPiece(int Size, string direction, int i)
        { char c[2];
        char *intStr ;
        int x, y;
        int ok[Size];
        for(int k=0;k<Size;k++)ok[k]=0;
        int ok1=0, ok2=0, ok3=0, ok4=0, ok5=0, ok6=0, ok7=1, nr=0;


        while(ok1==0 && ok2==0 && ok3==0 && ok4==0 && ok5==0){

        ok1=0, ok2=0, ok3=0, ok4=0, ok5=0, ok6=0, ok7=1;
        for(int k=0;k<Size;k++)ok[k]=0;

        srand(time(0));
        x=1+(rand()%9);
        y=1+(rand()%9);

        if(CompMatrix[x][y]=="0" ){

        if(direction=="horizontal"){ for(int k=0;k<Size;k++){ y=y+k; ok6=0;

        if(x>1 && x<9 && y>1 && y<9 &&  CompMatrix[x-1][y-1]=="0" && CompMatrix[x-1][y+1]=="0" && CompMatrix[x+1][y-1]=="0" && CompMatrix[x+1][y+1]=="0"
           && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0"  )
                ok6=1;
        else

            if(x==1 && y==1 && CompMatrix[x+1][y+1]=="0" && CompMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y==9 && CompMatrix[x-1][y-1]=="0" && CompMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(x==1 && y==9 && CompMatrix[x+1][y-1]=="0" && CompMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y==1 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(x==1 && y>1 && y<9 && CompMatrix[x+1][y+1]=="0" && CompMatrix[x+1][y-1]=="0"
               && CompMatrix[x+1][y]=="0")
                ok6=1;
        else

            if(x==9 && y>1 && y<9 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x-1][y-1]=="0"
               && CompMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(y==1 && x>1 && x<9 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x+1][y+1]=="0"
               && CompMatrix[x+1][y]=="0" && CompMatrix[x-1][y]=="0")
                ok6=1;
        else

            if(y==9 && x>1 && x<9 && CompMatrix[x-1][y-1]=="0" && CompMatrix[x+1][y-1]=="0"
               && CompMatrix[x+1][y]=="0" && CompMatrix[x-1][y]=="0")
                ok6=1;

        y=y-k; if(ok6==1)ok[k]++; } }

        //------------------------------------------------------------------------------------------------------

        else

        if(direction=="vertical"){ for(int k=0;k<Size;k++){ x=x+k; ok6=0;

        if(x>1 && x<9 && y>1 && y<9 &&  CompMatrix[x-1][y-1]=="0" && CompMatrix[x-1][y+1]=="0" && CompMatrix[x+1][y-1]=="0" && CompMatrix[x+1][y+1]=="0"
           && CompMatrix[x][y-1]=="0" && CompMatrix[x][y+1]=="0" )
                ok6=1;
        else

            if(x==1 && y==1 && CompMatrix[x+1][y+1]=="0" && CompMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(x==9 && y==9 && CompMatrix[x-1][y-1]=="0" && CompMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==1 && y==9 && CompMatrix[x+1][y-1]=="0" && CompMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==9 && y==1 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(x==1 && y>1 && y<9 && CompMatrix[x+1][y+1]=="0" && CompMatrix[x+1][y-1]=="0"
               && CompMatrix[x][y+1]=="0" && CompMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(x==9 && y>1 && y<9 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x-1][y-1]=="0"
               && CompMatrix[x][y+1]=="0" && CompMatrix[x][y-1]=="0")
                ok6=1;
        else

            if(y==1 && x>1 && x<9 && CompMatrix[x-1][y+1]=="0" && CompMatrix[x+1][y+1]=="0"
               && CompMatrix[x][y+1]=="0")
                ok6=1;
        else

            if(y==9 && x>1 && x<9 && CompMatrix[x-1][y-1]=="0" && CompMatrix[x+1][y-1]=="0"
               && CompMatrix[x][y-1]=="0")
                ok6=1;
        x=x-k; if(ok6==1)ok[k]++; }  }


        for(int k=0;k<Size;k++)if(ok[k]==0)ok7=0;


        if(ok7==1){

        if( ( Size==1 && x>1 && x<9 && y>1 && y<9 && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0" && CompMatrix[x][y+1]=="0" && CompMatrix[x][y-1]=="0" )
        || ( Size==1 && x==1 && y>1 && y<9 && CompMatrix[x][y+1]=="0" && CompMatrix[x][y-1]=="0" && CompMatrix[x+1][y]=="0" )
        || ( Size==1 && x==9 && y>1 && y<9 && CompMatrix[x][y+1]=="0" && CompMatrix[x][y-1]=="0" && CompMatrix[x-1][y]=="0" )
        || ( Size==1 && y==1 && x>1 && x<9 && CompMatrix[x+1][y]=="0" && CompMatrix[x-1][y]=="0" && CompMatrix[x][y+1]=="0" )
        || ( Size==1 && y==9 && x>1 && x<9 && CompMatrix[x+1][y]=="0" && CompMatrix[x-1][y]=="0" && CompMatrix[x][y-1]=="0" )
        || ( Size==1 && x==1 && y==1 && CompMatrix[x+1][y]=="0" && CompMatrix[x][y+1]=="0")
        || ( Size==1 && x==9 && y==9 && CompMatrix[x-1][y]=="0" && CompMatrix[x][y-1]=="0")
        || ( Size==1 && x==1 && y==9 && CompMatrix[x][y-1]=="0" && CompMatrix[x+1][y]=="0")
        || ( Size==1 && x==9 && y==1 && CompMatrix[x-1][y]=="0" && CompMatrix[x][y+1]=="0") )
            { intStr = itoa(i,c,10);
            CompMatrix[x][y]=intStr;
            CompPieces[i].add(x,y);
            ok1=1;
            CompPieces[i].setDirection(direction); }
        else

            if(Size==2 && direction=="vertical")
                { intStr = itoa(i,c,10);
                if( ( x>1 && x<=7 && y>=1 && y<=9 && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0" && CompMatrix[x+2][y]=="0" ) ||
                (x==1 && y>=1 && y<=9 && CompMatrix[x+1][y]=="0" && CompMatrix[x+2][y]=="0"  ) ||
                (x==8 && y>=1 && y<=9 && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0" ) )
                    { CompMatrix[x][y]=intStr;
                    CompMatrix[x+1][y]=intStr;
                    CompPieces[i].add(x,y);
                    CompPieces[i].add(x+1,y);
                    ok2=1;
                    CompPieces[i].setDirection(direction); } }
        else

             if(Size==2 && direction=="horizontal")
                { intStr = itoa(i,c,10);
                if( ( y>1 && y<=7 && x>=1 && x<=9 && CompMatrix[x][y-1]=="0" && CompMatrix[x][y+1]=="0" && CompMatrix[x][y+2]=="0" ) ||
                (y==1 && x>=1 && x<=9 && CompMatrix[x][y+1]=="0" && CompMatrix[x][y+2]=="0"  ) ||
                (y==8 && y>=1 && y<=9 && CompMatrix[x][y-1]=="0" && CompMatrix[x][y+1]=="0" ) )
                    { CompMatrix[x][y]=intStr;
                    CompMatrix[x][y+1]=intStr;
                    CompPieces[i].add(x,y);
                    CompPieces[i].add(x,y+1);
                    ok3=1;
                    CompPieces[i].setDirection(direction); } }
        else

              if(Size==3 && direction=="vertical")
                { intStr = itoa(i,c,10);
                if( ( x>1 && x<=6 && y>=1 && y<=9 && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0" && CompMatrix[x+2][y]=="0" && CompMatrix[x+3][y]=="0" )                || (x==1 && y>=1 && y<=9 && CompMatrix[x+1][y]=="0" && CompMatrix[x+2][y]=="0" && CompMatrix[x+3][y]=="0"  )
                || (x==7 && y>=1 && y<=9 && CompMatrix[x-1][y]=="0" && CompMatrix[x+1][y]=="0" && CompMatrix[x+2][y]=="0" ) )
                    { CompMatrix[x][y]=intStr;
                    CompMatrix[x+1][y]=intStr;
                    CompMatrix[x+2][y]=intStr;
                    CompPieces[i].add(x,y);
                    CompPieces[i].add(x+1,y);
                    CompPieces[i].add(x+2,y);
                    ok4=1;
                    CompPieces[i].setDirection(direction); } }
        else

            if(Size==3 && direction=="horizontal")
                { intStr = itoa(i,c,10);
                if( ( y>1 && y<=6 && x>=1 && x<=9 && CompMatrix[x][y-1]=="0" && CompMatrix[x][y+1]=="0" && CompMatrix[x][y+2]=="0" && CompMatrix[x][y+3]=="0" )
                || (y==1 && x>=1 && x<=9 && CompMatrix[x][y+1]=="0" && CompMatrix[x][y+2]=="0" && CompMatrix[x][y+3]=="0"   )
                || (y==7 && y>=1 && y<=9 && CompMatrix[x][y-1]=="0" && CompMatrix[x][y+1]=="0" && CompMatrix[x][y+2]=="0" ) )

                    { CompMatrix[x][y]=intStr;
                    CompMatrix[x][y+1]=intStr;
                    CompMatrix[x][y+2]=intStr;
                    CompPieces[i].add(x,y);
                    CompPieces[i].add(x,y+1);
                    CompPieces[i].add(x,y+2);
                    ok5=1;
                    CompPieces[i].setDirection(direction); } }

         } } } }




private:
    string PlayerMatrix[12][12];
    string CompMatrix[12][12];
    string CompMatrix2[12][12];
    List PlayerPieces[10];
    List CompPieces[10];
    static int PlayerPiecesNumber;
    static int CompPiecesNumber;
};



int Game::PlayerPiecesNumber=9;
int Game::CompPiecesNumber=9;



int main()
{Game G;

system("PAUSE");
return 0;

}

