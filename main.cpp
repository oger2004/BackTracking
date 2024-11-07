// Roger Costa Maubens
// u1987277
// p2

#include <iostream>
#include<list>
#include <chrono>
#include <fstream>

#include "Candidats.h"
#include "Solucionador.h"
#include "Solucio.h"


using namespace std;

void mostrarAjuda ( char * nomPrograma );
/**<
        * @brief mostra totes les opcions del programa
        * @pre  cadena de caracters que representa el nom d'un fitxer
        * @post mostra totes les opcions del programa nomPrograma
        * @param una cadena de caracters
        * @return -
*/
bool llegir_dades(string nomFitxer,Solucio& res,int any,long long impMax,char iD,bool Cap,int nAudit);
/**<
        * @brief llegeix les dades del fitxer nomfitxer tenint encompte les restriccions, retorna true si sha llegit existosament false altrament
        * @pre estan tots els valors inicialitzats amb valors per defecte o donats a traves arguments del main
        * @post llegeix les dades del fitxer nomfitxer tenint encompte les restriccions, retorna true si sha llegit existosament false altrament
        * @param un string, una variable tipus Solucio, dos int, un long long, un char i un bool
        * @return retorna true si sha llegit existosament false altrament seguint restriccions
*/


void mostrarAjuda ( char * nomPrograma ) {
    cout << " Utilització " << nomPrograma << " [ -h] [- pt ] fitxer \n \n" ;
    cout<<"opcio pot ser:"<<endl<<endl;

    cout << " -h, --help"<< '\t' <<"mostra aquesta ajuda"<<endl;
    cout << " -u"<< '\t' <<"cerca una solucio qualsevol que compleixi les restriccions del problema "<<endl ;
    cout << " -m"<< '\t' <<"cerca la solucio que minimitza el nombre d'auditors i el repartiment optim d'aplicacions "<<endl<<endl;
    cout << " -t"<< '\t' <<"indica que nomes es poden assignar aplicacions del mateix tipus (ingres/despesa) a un auditor "<<endl;
    cout << " -c"<< '\t' <<"indica que nomes es poden assignar aplicacions del mateix capıtol a un auditor "<<endl ;
    cout << " -a <any>"<< '\t' <<"indica que s'ha de fer l'assignacio per a l'exercici pressupostari <any> "<<endl ;
    cout << " -i <imp>"<< '\t' <<"assigna <imp> com a import m`axim que un unic auditor pot fiscalitzar "<<endl ;
    cout << " -n <aud>"<< '\t' <<"assigna <aud> com a nombre m`axim d'auditors "<<endl ;
    cout << "fitxer"<< '\t' <<"ha de ser un fitxer de text amb totes les lınies dels pressupostos amb el format del CTTI."<<endl;
}


bool llegir_dades(string nomFitxer,Solucio& res,int any,long long impMax,char iD,bool Cap,int nAudit,char mU){
    pair<int,pair<int,long long>> num_linies=res.llegirDades(nomFitxer, any,impMax,iD,Cap,nAudit);
    if(num_linies.second.first!=0 and num_linies.first!=0 ){
        if(nomFitxer!=" " and any!=-1 and mU!=' ') cout<<num_linies.second.first<<" linies ("<< num_linies.first <<" aplicacions) llegides amb un import total de: "<<num_linies.second.second/1000<<"."<<num_linies.second.second%100<<endl<<endl;
        return true;
    }
    else return false;
}

int main(int argn, char** argv)
{
    int any=-1;
    long long impMax=-1;
    char mU=' ';
    bool iD=false;
    bool Cap=false;
    int nAudit=-1;
    string nomFitxer=" ";
    bool error=false;


    int nPar = 1;
    if ( string ( argv [ nPar ]) == "-h" or string ( argv [ nPar ]) == "--help") {
        mostrarAjuda ( argv [0]); return(0);
    }
    while (!error and nPar < argn -1) { // processar opcions
        string par = string ( argv [ nPar ]);
        if ( par == "-a" and any==-1) {
            nPar ++;
            any = atoi ( argv [ nPar ]);
         //   if(any<=0) error = true;
        }
        else if ( par == "-i" and impMax==-1){
            nPar ++;
            impMax = atoi ( argv [ nPar ]);
          //  if(impMax<0) error = true ;
        }
        else if ( par == "-n" and nAudit==-1){
            nPar++;
            nAudit = atoi ( argv [ nPar ]);
        }
        else if ( par == "-u" and mU==' ') mU ='u';
        else if ( par == "-m" and mU==' ') mU = 'm';
        else if ( par == "-t" and iD==false) iD = true;
        else if ( par == "-c" and Cap==false) Cap = true;
       // else error = true;
        nPar ++;
    }
    // Hem sortit del bucle perquè el parà metre a la posició nPar -1 é s una opció errò nia ( error == true )
    // o hem acabat el recorregut ( encara hem de tractar l'ú ltim parà metre , el nom del fitxer )
    error = error or argv [ nPar ][0] == '-'; // el nom del fitxer no pot començ ar per '-'
    if ( error ) {
        cout << " Error : parametres invalids"<<endl<<endl;
        mostrarAjuda ( argv [0]); return(-1);
    }
    nomFitxer = string ( argv [ nPar ]);

    cout<<endl<<"Al trobar solucio es tindra encompte: "<<endl<<endl;

    if(any!=-1)cout<< '\t' <<"- Any "<<any<<endl;
    if(impMax!=-1) cout<<'\t' <<"- L'import maxim per als auditors sera de "<< impMax <<endl;
    if(mU!=' '){
        if(mU=='m') cout<<'\t' <<"- Es trobara la millor solucio."<<endl;
        else if(mU=='u') cout<<'\t' <<"- Es trobara una solucio qualsevol."<<endl;
    }
    if(iD) cout<<'\t' <<"- Es separaran les aplicacions per el tipus ingres(I)/despesa(D)."<<endl;
    if(Cap) cout<<'\t' <<"- Es separaran les aplicacions segons el capitol del que formin part."<<endl;
    if(nAudit!=-1) cout<<'\t' <<"- El nombre maxim dauditors es "<<nAudit<<"."<<endl;
    if(nomFitxer!=" ") cout<<'\t' <<"- Utilitzant el fitxer "<<nomFitxer<<endl;

    cout<<endl;

    Solucionador sols=Solucionador();
    Solucio sol;

    bool es_pot= llegir_dades(nomFitxer,sol,any,impMax,iD,Cap,nAudit,mU);
    if(nomFitxer!=" " and any!=-1 and mU!=' '){
        if(es_pot){
            if(mU=='m') Solucio res=sols.solucionar_mill(sol,iD,Cap);
            else if(mU=='u') Solucio res=sols.solucionar(sol,iD,Cap);
        }
    }
    else{
        if(any==-1) cout<<"Cal indicar un valor correcte per l'any a auditar."<<endl;
        if(nomFitxer==" ") cout<<"Falta el nom del fitxer."<<endl;
        if(mU==' ') cout<< "Cal indicar si es busca una solucio o la millor."<<endl;
    }

    return 0;
}
