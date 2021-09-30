/* Squelette pour classe générique Tableau<T>.
 * Lab3 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes
 * http://cria2.uqam.ca/INF3105/lab3/
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position.
    void           inserer(const T& element, int index=0);

    // Enlève l'element à position index. Les éléments après index sont décalés d'une position.
    void           enlever(int index=0);

    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    int            chercher(const T& element) const;

    const T&       operator[] (int index) const;
    T&             operator[] (int index);

    bool           operator == (const Tableau<T>& autre) const;
    Tableau<T>&    operator = (const Tableau<T>& autre);

  private:
    void           redim();
    T*             elements;
    int            nbElements;
    int            capacite;
};


// ---------- Définitions -------------


template <class T>
Tableau<T>::Tableau(int capacite_)
{
    // À compléter
    capacite = capacite_;
    nbElements = 0;
    elements = new T[capacite]; // cette ligne n'est peut-être pas bonne.
}

template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    elements =  new T[capacite];
    for(int i =0; i < nbElements; i++){
	elements[i] = autre.elements[i];
    }
}

template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
}

template <class T>
int Tableau<T>::taille() const
{
    
    return nbElements;
}

template<class T>
void Tableau<T>::redim(){
    T* temp = new T[capacite*2];
    for(int i=0; i < nbElements; i++) {
        temp[i] = elements[i];
    }
    delete[] elements;
    elements = temp;
    capacite = capacite*2;
}

template <class T>
void Tableau<T>::ajouter(const T& item)
{
    // À compléter
    if(nbElements>= capacite){
	redim();
    }

    elements[nbElements] = item;
    nbElements++;
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    assert(index <= nbElements);
    if(nbElements >= capacite) redim();
    T temp = elements[index];
    elements[index] = element;
    nbElements++;
    for(int i=index +1 ; i < nbElements; i++){
        T temp2 = elements[i];
        elements[i] = temp;
        temp = temp2;
    }

}

template <class T>
void Tableau<T>::enlever(int index)
{
    assert(index < nbElements);
    nbElements--;
    for(int i = index; i <nbElements; i++) elements[i] =elements[i+1];
}

template <class T>
int Tableau<T>::chercher(const T& element) const
{
    // À compléter
    // Voir la fonction Tableau<T>::contient() dans les notes de cours (Section 4.7).
    // Il suffit de l'adapter pour retourner la position au lieu d'un booléen.
    int index = -1;
    for(int i =0; i < nbElements; i++)
        if(elements[i]== element) index = i;
    return index;
}

template <class T>
void Tableau<T>::vider()
{
    delete[] elements;
    capacite  = 4;
    elements = new T[capacite];
    nbElements = 0 ;
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    // À compléter
    assert(index < nbElements);
    return elements[index];
}

template <class T>
T& Tableau<T>::operator[] (int index)
{
    assert(index < nbElements);
    return elements[index];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if(this == &autre) return *this;
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    elements =  new T[capacite];
    for(int i =0; i < nbElements; i++){
        elements[i] = autre.elements[i];
    }
    return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    bool egal = nbElements == autre.nbElements 
          && capacite == autre.capacite;
    if(egal)
	for(int i=0; i< nbElements; i++) 
	    if(elements[i] != autre.elements[i]) egal = false;
    return egal;
}

#endif //define _TABLEAU___H_















