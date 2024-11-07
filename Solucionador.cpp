// Roger Costa Maubens
// u1987277
// p2
#include "Solucionador.h"

Solucionador::Solucionador()
{
    encertat=iD=Cap=false;
    sol=opt=Solucio();
}

Solucio Solucionador::solucionar_mill(Solucio& ini,bool iD,bool Cap){
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    sol=opt=ini;
    this->iD=iD;
    this->Cap=Cap;

    trobarMillorSolucio();
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast< chrono::duration<double> >(t2 - t1);

    opt.ordenar();
    opt.mostrar();
    cout<<"Temps: " << time_span.count() <<" segons"<<endl;
    return opt;
}

void Solucionador::trobarMillorSolucio(){

    Candidats iCan=sol.inicialitzarCandidats();

    while(iCan.queden_candidats()  ){ //

        if(sol.acceptable(iCan,iD,Cap)  ){ // and sol.posSolMillor(opt,iCan,iD,Cap)

            sol.anotar(iCan,iD,Cap);
            if(not sol.completa()){
                trobarMillorSolucio();
            }
            else{
                if(sol.millor_optima(opt)){
                    opt=sol;
                }
            }
            sol.desanotar(iCan,iD,Cap);
        }
        iCan.seguent();
    }
}

Solucio Solucionador::solucionar(Solucio& ini,bool iD,bool Cap)
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    sol=ini;
    this->iD=iD;
    this->Cap=Cap;

    trobarUnaSolucio();

    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast< chrono::duration<double> >(t2 - t1);

    sol.mostrar_unica();
    cout<<"Temps: " << time_span.count() <<" segons"<<endl;

    return sol;
}

void Solucionador::trobarUnaSolucio()
{
    Candidats iCan = sol.inicialitzarCandidats();

    while(iCan.queden_candidats() and not encertat){

        if (sol.acceptable(iCan,iD,Cap)){

            sol.anotar(iCan,iD,Cap);

            if(not sol.completa()){

                trobarUnaSolucio();

                if(not encertat){
                    sol.desanotar(iCan,iD,Cap);
                }
            }
            else
                encertat=true;
        }
        iCan.seguent();
    }
}


