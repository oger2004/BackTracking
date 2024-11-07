// Roger Costa Maubens
// u1987277
// p2

#include <iostream>
#include<list>

using namespace std;

#ifndef CANDIDATS_H
#define CANDIDATS_H


class Candidats
{
    public:
        Candidats(int n_aud);
/**<
        * @brief construeix un candidat amb els atributs inicialitzats amb max=n_aud i can_act=0
        * @pre el int ha de ser >0
        * @post construeix un candidat amb els atributs inicialitzats amb max=n_aud i can_act=0
        * @param un int
        * @return construeix un candidat amb els atributs inicialitzats amb max=n_aud i can_act=0
*/
        int actual() const;
/**<
        * @brief retorna el cand_act
        * @pre -
        * @post retorna el cand_act
        * @param -
        * @return retorna el cand_act
*/
        bool queden_candidats() const;
/**<
        * @brief retorna true si cand_act<max
        * @pre -
        * @post retorna true si cand_act<max
        * @param -
        * @return retorna true si cand_act<max
*/
        void seguent();
/**<
        * @brief incrementa cand_act en 1
        * @pre -
        * @post incrementa cand_act en 1
        * @param -
        * @return incrementa cand_act en 1
*/

    private:
        int cand_act;
/**<
* @brief el index del candidat actual
        * @param el index del candidat actual
*/
        int maxim;
/**<
* @brief el index maxim de candidats
        * @param el index maxim de candidats
*/
};

#endif // CANDIDATS_H
