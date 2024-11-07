// Roger Costa Maubens
// u1987277
// p2

#include "Candidats.h"

Candidats::Candidats(int n_aud)
{
    cand_act=0;
    maxim=n_aud;
}

int Candidats::actual() const
{
    if(not queden_candidats())
        throw("No hi ha més candidats");
    return cand_act;
}

bool Candidats::queden_candidats() const
{
    return cand_act<maxim;
}

void Candidats::seguent()
{
    if (not queden_candidats())
        throw("No hi ha més candidats");
    cand_act++;
}
