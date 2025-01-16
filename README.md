# Template
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```


# STL (using iterator)

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
```

# Paramètres par référence 
| Aspect                  | Pointeur (C)                                | Référence (C++)                                     |
|-------------------------|---------------------------------------------|----------------------------------------------------|
| **Définition**          | Peut pointer vers une adresse mémoire ou être nul. | Alias d'une variable existante (doit toujours référencer une variable). |
| **Modification de la valeur** | Nécessite `*` pour accéder à la valeur.         | Pas besoin de `*` ou `&`.                         |
| **Nullité**             | Peut être `nullptr`.                        | Ne peut jamais être nul.                          |
| **Changement de cible** | Peut pointer vers autre chose après définition. | Ne peut pas être changé après définition.         |


```cpp
#include <iostream>
using namespace std;

void increment(int& num) {  // Prend une référence comme paramètre
    num = num + 1;         // Modifie directement la variable originale
}

int main() {
    int x = 5;
    increment(x);          // Passe directement la variable, sans `&`
    cout << x << endl;     // Affiche 6
    return 0;
}

```

# Namespaces

```cpp
namespace MyNamespace {
    int add(int a, int b) {
        return a + b;
    }
}
int main() {
    std::cout << MyNamespace::add(3, 4) << std::endl;
    return 0;
}

```

# Classes

2 manière de définir: 

- Déclarer les méthodes dans la classe directement (basique)
- En dehors de la classe: 
```cpp
class Point {
    float x, y;

public:
    void set(float a, float b);   // Déclaration de la méthode
    float dist(Point& p);         // Déclaration de la méthode
};
void Point::set(float a, float b) {  // Définition de la méthode `set`
    x = a;
    y = b;
}

float Point::dist(Point& p) {  // Définition de la méthode `dist`
    return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
}
```

## Constructeur/Déconstructeur

```cpp 
class Point {
    float x, y;

public:
    Point(float a, float b) : x(a), y(b) {
        cout << "Point created: (" << x << ", " << y << ")" << endl;
    }

    ~Point() {
        cout << "Point destroyed: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Point p1(3, 4);  // Constructeur appelé
    return 0;        // Destructeur appelé automatiquement
}
```

## Instanciation 
Pas obligé de faire new, dans ce cas l'instance se crée sur la pile. Pas besoin de **delete**
```cpp
Point p1(1, 2);
```

Sinon, utiliser new pour l'avoir dans le tas afin de l'utiliser autre part. Obligé de faire **delete**

```cpp
Point* p1 = new Point(1, 2);
```

## Operator Overloading
En gros tu redéclares un type d'opération pour l'objet. Si y a pas plusieurs objets à utiliser (???) ne pas utiliser friend comme ici

```cpp
    // Surcharge de l'opérateur +
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

        // Surcharge de l'opérateur ==
    bool operator==(const Point& p) const {
        return (x == p.x) && (y == p.y);
    }
```

Sinon utiliser friend(peut être utiliser dans un style de méthode statique ??? )

```cpp
    // Surcharge de l'opérateur <<
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

```

Mais en gros la syntaxe c'est :

```cpp

    <friend> TypeRetour operator OperateurQuelconque(args){}
```

### Non surchargeables :

Les opérateurs :: (résolution de portée), ., .*, et sizeof ne peuvent pas être surchargés.



## Polymorphism
On déclare la méthode en **virtual**, puis on la rédefinie dans les autres classes. Doit être appelé avec une flèche **->**.
```cpp
class Shape {
public:
    virtual void draw() const {  // Méthode virtuelle
        std::cout << "Drawing a generic shape" << std::endl;
    }
    virtual ~Shape() {}  // Destructeur virtuel
};

class Circle : public Shape {
public:
    void draw() const override{  // Redéfinition
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};


// Pour appeler:
int main(){
    Circle cir(1)
    Rectangle rec(3,2)

    Shape *shape1 = &cir
    Shape *shape2 = &rec

    shape1->draw();  // Appelle Circle::draw()
    shape2->draw();  // Appelle Rectangle::draw()

}
```

## Classe abstraite
Contient au moins une méthode virtuelle pure:

```cpp
class Shape {
public:
    virtual void draw() const = 0;  // Méthode virtuelle pure
    virtual ~Shape() {}            // Destructeur virtuel
};
```

