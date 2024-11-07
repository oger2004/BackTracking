// Roger Costa Maubens
// u1987277
// p2

#include "Solucio.h"

Solucio::Solucio()
{
    n_Apl=impMax=0;
    sum=0;
    aplicacions=new Aplic[1000];
    desv=100000000000;
    nBuits=0;
    restant=restantI=restantD=0;
    restCap.resize(10,0);
    restCapI.resize(10,0);
    restCapD.resize(10,0);
}

Solucio::Aplic::Aplic(){
    imp=0;
    cod=" ";
    iD=' ';
    cap=-1;
}

Solucio::Aplic::Aplic(long long im,string codi,char iDa,string capi){
    imp=im;
    cod=codi;
    iD=iDa;
    cap=stoi(capi);
}

bool Solucio::Aplic::operator<(const Aplic &o){
    if(this->iD != o.iD) return this->iD<o.iD;
    else return this->cod < o.cod;
}

long long Solucio::calcImport(vector<string> items){
    int nValors = items[iImportCons].length();
    long long imp=0;
    char dec1= items[iImportCons][nValors-1];
    char dec2= items[iImportCons][nValors-2];

    items[iImportCons][nValors-3]=dec2;
    items[iImportCons][nValors-2]=dec1;
    items[iImportCons][nValors-1]=' ';

    string impFin=items[iImportCons];
    imp=stoll(impFin);

    return imp;
}

pair<int,pair<int,long long>> Solucio::llegirDades(const string& path, int any,long long impMax,bool iD,bool Cap,int nAuditMax)
{
    ifstream f;
    string linia;
    vector<string> items;
    string fitxer = path;
    f.open(fitxer);
    int n_files=0;
    long long sumD=0,sumI=0;
    this->impMax=impMax;
    vector<Aplic> vec_apl;
    long long imp=0;
    bool impMesMax=false;

    if(!f.fail()){
        getline(f,linia);

        while(!f.eof() and not impMesMax){
            items= tokens(linia,',',true);
            if(n_files!=0 and (stoi(items[iAny]))==any){
                afegir_fila_fixer(items,n_files);

                imp=calcImport(items);

                if(impMax>(imp/1000)){
                    int indexCap= stoi(items[iCodiCapitol]);
                    if(Cap and not iD)
                        restCap[indexCap-1]+=imp;
                    else if(Cap and iD){
                        if(items[iIngresDespesa]==INGR) restCapI[indexCap-1]+=imp;
                        else restCapD[indexCap-1]+=imp;
                    }
                    else if(iD and not Cap){
                        if(items[iIngresDespesa]==INGR)sumI+=imp;
                        else sumD+=imp;
                    }
                    sum+=imp;
                }
                else
                    impMesMax=true;
            }
            if(n_files==0) n_files++;

            getline(f,linia);
        }
    }
    n_files--;
    restant=sum;
    int nAud=0;
    long long resum=sum;
    if(iD and not Cap and (sumD!=0 or sumI!=0)){
        double nAudD=0.0;
        if(sumD!=0) nAudD=sumD/(impMax*100);
        double intPart;
        double noExacte = modf(nAudD, &intPart);

        if(noExacte==0.0) nAudD++;

        double nAudI=0.0;
        if(sumI!=0)nAudI=sumI/(impMax*100);

        double intPart1;
        noExacte = modf(nAudI, &intPart1);

        if(noExacte==0.0) nAudI++;
        nAud=nAudI+nAudD;

        restantI=sumI;
        restantD=sumD;
    }
    else if(Cap and not iD){
        double aux=0.0;
        for(int i=0; i<restCap.size(); i++){
            if(restCap[i]!=0){

                aux=restCap[i]/(impMax*100);
                double intPart;
                double noExacte = modf(aux, &intPart);

                if(noExacte==0.0) aux++;

                nAud+=aux;
            }
        }
    }
    else if(not iD and not Cap){
        nAud=sum/(impMax*100);

        double intPart;
        double noExacte = modf(nAud, &intPart);

        if(noExacte==0.0) nAud++;
    }
    else if (Cap and iD){
        double aux1=0.0;
        double aux2=0.0;
        for(int i=0; i<restCapI.size(); i++){
            if(restCapI[i]!=0){

                aux1=restCapI[i]/(impMax*100);
                double intPart;
                double noExacte = modf(aux1, &intPart);

                if(noExacte==0.0) aux1++;
                nAud+=aux1;
            }
            if(restCapD[i]!=0){

                aux2=restCapD[i]/(impMax*100);
                double intPart;
                double noExacte = modf(aux2, &intPart);

                if(noExacte==0.0) aux2++;
                nAud+=aux2;
            }
        }
    }
    else impMesMax=true;

    auditors.resize(nAud,0);
    for(int i=1; i<=nAud; i++){
        auditors[i-1]=i;
    }
    sum_aud.resize(nAud,0);
    apl_aud.resize(nAud,vec_apl);
    nBuits=nAud;

    if((nAuditMax!=-1 and nAud>nAuditMax) or impMesMax){
        if(nAuditMax!=-1 and nAud>nAuditMax) cout<<"No hi ha solucio amb " << nAuditMax << " auditors com a maxim."<<endl;
        if(impMesMax) cout<<"Cal indicar un valor correcte per l'import maxim per auditor."<<endl;
        pair<int,long long> r{0,0};
        pair<int,pair<int,long long>> res{0,r};
        return res;
    }
    else {
        pair<int,long long> r{n_files,resum};
        pair<int,pair<int,long long>> res{n_Apl,r};
        return res;
    }
}

void Solucio::afegir_fila_fixer(vector<string> i,int& nFiles){

    char ingDesp=i[iIngresDespesa][0];

    long long imp=calcImport(i);

    string cod=i[iCodiAplicacio];
    string Cap= i[iCodiCapitol];

    if(imp>0){
        int i=n_Apl-1;
        bool trob=false;

        while(i>=0 and not trob){
            if(aplicacions[i].cod==cod) trob=true;
            else i--;
        }

        if(trob){
            aplicacions[i].imp+=imp;
            nFiles++;
        }
        else{
            aplicacions[n_Apl]=Aplic(imp,cod,ingDesp,Cap);
            n_Apl++;
            nFiles++;
        }
    }
}

void Solucio::mostrar(){

    vector<int>::iterator aud=auditors.begin();
    cout<<"**********************************"<<endl;
    while(aud!=auditors.end()){

        cout<<"* Auditor "<< *aud << '\t'<< sum_aud[*aud-1]/100<< '.'<< (sum_aud[*aud-1]%100)<<endl;
        cout<<"* ------------------------------ *"<<endl;
        vector<Aplic>::iterator apl=apl_aud[*aud-1].begin();
        while(apl!=apl_aud[*aud-1].end()){

            cout<<"* "<<apl->iD<<apl->cod<<": "<< '\t'<< (apl->imp/100)<< '.'<< (apl->imp%100) <<endl;

            apl++;
        }
        cout<<"**********************************"<<endl;
        aud++;
    }

    cout<<"Total: "<< sum/100 << '.' << sum%100 <<endl;
    cout<<"Auditors: "<< auditors.size()<<endl;

    if(desv!=100000000000) cout<<"Desviacio: "<< desv/100 <<'.'<<desv%100<<endl;
}

void Solucio::mostrar_unica(){
    this->mostrar();
    long long mitj=sum/auditors.size();
    long long d=0;
    for(long long unsigned int i=0; i<auditors.size(); i++){

        d+=((sum_aud[i]-mitj)*(sum_aud[i]-mitj));
    }

    desv=sqrt(d/double(auditors.size()));
    cout<<"Desviacio: "<< desv/100 <<'.'<<desv%100<<endl;
}

void Solucio::ordenar(){
    for(long long unsigned int i=0; i<auditors.size(); i++){
        sort(apl_aud[i].begin(), apl_aud[i].end());
    }
}

Solucio& Solucio::operator=(const Solucio& o)
{
    if(this!= &o){
        allibera();
        copia(o);
    }
    return *this;
}

void Solucio::copia(const Solucio& o){
    impMax=o.impMax;

    n_Apl=o.n_Apl;
    sum=o.sum;
    desv=o.desv;

    nBuits=o.nBuits;
    restant=o.restant;
    restantI=o.restantI;
    restantD=o.restantD;
    restCap=o.restCap;

    auditors=o.auditors;
    apl_aud=o.apl_aud;
    sum_aud=o.sum_aud;

    aplicacions= new Aplic[n_Apl];

    for(int i=0; i<n_Apl; i++){
        aplicacions[i]=o.aplicacions[i];
    }
}

void Solucio::allibera()
{
    delete [] aplicacions;
    aplicacions=NULL;
}

bool Solucio::operator==(const Solucio& o)
{
    if(auditors.size()!=o.auditors.size()) return false;
    else{
        vector<long long>::iterator aq=sum_aud.begin();
        vector<long long>::const_iterator al=o.sum_aud.begin();
        while(aq!=sum_aud.end()){
            if(*aq!=*al) return false;
            aq++;
            al++;
        }
    }
    return true;
}

Candidats Solucio::inicialitzarCandidats() const
{
    return Candidats(auditors.size());
}

bool Solucio::acceptable(const Candidats& iCan,bool iD,bool Cap) const
{
    if(not iD and not Cap){
        return sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= (impMax*100);
    }
    else if(iD and not Cap){
        if(!apl_aud[iCan.actual()].empty())
            return sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= (impMax*100)
                   and apl_aud[iCan.actual()].back().iD==aplicacions[n_Apl-1].iD;

        else //(iD and apl_aud[iCan.actual()].empty())
            return true; //sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= impMax;
    }
    else if(Cap and not iD){
        if(!apl_aud[iCan.actual()].empty())
            return apl_aud[iCan.actual()].back().cap==aplicacions[n_Apl-1].cap
                   and sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= (impMax*100);

        else //(Cap and apl_aud[iCan.actual()].empty())
            return true; //sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= impMax;
    }
    else // Cap and iD
        if(!apl_aud[iCan.actual()].empty())
            return apl_aud[iCan.actual()].back().cap==aplicacions[n_Apl-1].cap
                   and apl_aud[iCan.actual()].back().iD==aplicacions[n_Apl-1].iD
                   and sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= (impMax*100);

        else //(Cap and apl_aud[iCan.actual()].empty())
            return true; //sum_aud[iCan.actual()]+aplicacions[n_Apl-1].imp <= impMax;

}

void Solucio::anotar(const Candidats& iCan,bool iD,bool Cap)
{
    n_Apl--;


    if(iD and aplicacions[n_Apl].iD==INGR[0]) restantI-=aplicacions[n_Apl].imp;
    else if(iD) restantD-=aplicacions[n_Apl].imp;
    if(Cap) restCap[(aplicacions[n_Apl].cap)-1]-=aplicacions[n_Apl].imp;
    restant-=aplicacions[n_Apl].imp;
    if(sum_aud[iCan.actual()]==0) nBuits--;


    sum_aud[iCan.actual()]+=aplicacions[n_Apl].imp;
    apl_aud[iCan.actual()].push_back(aplicacions[n_Apl]);
}

void Solucio::desanotar(const Candidats& iCan,bool iD,bool Cap)
{

    sum_aud[iCan.actual()]-=aplicacions[n_Apl].imp;
    if(not apl_aud[iCan.actual()].empty())
        apl_aud[iCan.actual()].pop_back();


    if(sum_aud[iCan.actual()]==0) nBuits++;
    restant+=aplicacions[n_Apl].imp;
    if(iD and aplicacions[n_Apl].iD==INGR[0]) restantI+=aplicacions[n_Apl].imp;
    else if(iD) restantD+=aplicacions[n_Apl].imp;
    if(Cap) restCap[(aplicacions[n_Apl].cap)-1]+=aplicacions[n_Apl].imp;


    n_Apl++;
}

bool Solucio::millor_optima(Solucio& opt){
    //no es tenen encompte els auditors de la solucio actual i la optima
    //perque desde el principi ja es saben els minims auditors que necessitarem

    long long mitj=sum/auditors.size();
    long long d=0;
    for(long long unsigned int i=0; i<auditors.size(); i++){

        d+=((sum_aud[i]-mitj)*(sum_aud[i]-mitj));
    }

    desv=sqrt(d/double(auditors.size()));

    return desv<opt.desv;
}

bool Solucio::unaBuida(Candidats& iCan,bool iD,bool Cap){

    //mirar si nomes un auditor no te aplicacions per poder afegir abans de haver de fer tots els anotar innecessariament

    if(not iD and not Cap){
        if(restant<=impMax and nBuits!=1)return true;
        else return false;
    }
    else if(nBuits==1 and iD and not Cap and restantI+sum_aud[iCan.actual()]<=impMax and restantD+sum_aud[iCan.actual()]<=impMax) return true;
    else if(nBuits==1 and not iD and Cap and !apl_aud[iCan.actual()].empty()
            and restCap[apl_aud[iCan.actual()].back().cap-1]==restant
            and restant+sum_aud[iCan.actual()]<=impMax
            ) return true;
    else return false;
}

bool Solucio::posSolMillor(Solucio& opt,Candidats& iCan,bool iD,bool Cap){

        if(unaBuida(iCan,iD,Cap)){
            long long mitj=sum/auditors.size();
            long long d=0;
            for(long long int i=0; i<auditors.size(); i++){
                if(iCan.actual()==i){
                    if(not iD and not Cap)
                        d+=((restant-mitj)*(restant-mitj));
                    else if(iD and not Cap){
                        if(restantD==0) d+=((restantI-mitj)*(restantI-mitj));
                        else if (restantI==0) d+=((restantD-mitj)*(restantD-mitj));
                    }
                    else if(Cap and not iD){
                        if(!apl_aud[iCan.actual()].empty()){
                            int indCap=apl_aud[iCan.actual()].back().cap;
                            d+=(restCap[indCap-1]-mitj)*(restCap[indCap-1]-mitj);
                        }
                    }

                }
                else d+=((sum_aud[i]-mitj)*(sum_aud[i]-mitj));
            }
            double var=d/(double(auditors.size()));
            long long des=sqrt(var);

            return des<opt.desv;
        }
        else return true;
}

bool Solucio::completa() const
{
    return n_Apl==0;
}
