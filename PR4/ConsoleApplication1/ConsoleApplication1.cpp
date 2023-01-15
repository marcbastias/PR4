#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<MMSystem.h>
#include<cstdlib>

using namespace std;
// Atributos del enemigo

int enemyHP = 1200;
string enemyName = "Charizard";
int enemyDamage;
// Atributos del enemigo

int enemy2HP = 800;
string enemyName2 = "Lapras";
int enemyDamage2;
//Atributos de héroe

string heroName;
int heroDamage;
int heroHP = 700;
int BolaSombra = 2200;
int Attack1lost = 4;
int Psiquico = 500;
int Attack2lost = 3;
int Placaje = 75;
int opcion;
int elecEnemy;

void gameStart() {
    cout << "Hola bienvenido al mundo Pokemon :D\n";
    cout << "Como te llamas?\n";
    cout << "--------------->>>>>>>>    ";
    cin >> heroName;

    cout << "\nBienvenido " << heroName << "\n\n";

    cout << "Oh no!!, un " << enemyName << " acaba de aparecer, tiene " << enemyHP << " puntos de vida \n";
    //PlaySound(TEXT("charizard.wav"), NULL, SND_LOOP);

    cout << "Oh no!!, un " << enemyName2 << " acaba de aparecer, tiene " << enemy2HP << " puntos de vida \n\n";
    //PlaySound(TEXT("lapras.wav"), NULL, SND_LOOP);
} 
void Attackenemies() {
    cout << "Que ataque quieres elegir para atacar: \n\n";
    cout << "..................................\n[1] -- Bola Sombra     " << Attack1lost << " / 4\n";
    cout << "..................................\n[2] -- Psiquico    " << Attack2lost << " / 3\n";
    cout << "..................................\n[3] -- Placaje\n..................................\n\n";
} 
void Attack(int att, int& enhP) {
    enhP = enhP - att;
}
void eleccionesenem1(int& enem) {
    if (enemyHP <= 0) {
        enem = 2;
}
    else if (enemy2HP <= 0) {
        enem = 1;
    }
    else if (enemyHP > 0 && enemy2HP > 0) {
    cout << "\nAhora elige a que enemigo quieres atacar:\n\n";
    cout << "_______________________\n\n[1] <----> " << enemyName << "\n";
    cout << "[2] <----> " << enemyName2 << "\n_______________________\n\n";
    cout << "--------------->>>>>>>>    ";
    cin >> enem;
}
}
void attackenemy(int att, int enem) {
    switch (att) {
    case 1:
        Attack1lost = Attack1lost - 1;
        if (Attack1lost <= 0) {
            cout << "Oh no ya no puedes utilizar mas Bola Sombra :OOOO\n";
        } else {
            cout << "\n************************\n\nHas elegido Bola Sombra\n\n************************\n\n";
                eleccionesenem1(enem);
                if (enem == 1) {
                    Attack(BolaSombra, enemyHP);
                }
                else if (enem == 2) {
                    Attack(BolaSombra, enemy2HP);
                }
        }
        break;
    case 2:
        Attack2lost = Attack2lost - 1;
        if (Attack2lost <= 0) {
            cout << "Oh no ya no puedes utlizar mas Psiquico :OOOO\n";
        } else {
            cout << "\n************************\n\nHas elegido Psiquico\n\n************************\n\n";
                eleccionesenem1(enem);
            if (enem == 1) {
                Attack(Psiquico, enemyHP);
            }
            else if (enem == 2) {
                Attack(Psiquico, enemy2HP);
            }
        }
        break;
    case 3:
        cout << "\n************************\n\nHas elegido Placaje\n\n************************\n\n";
            eleccionesenem1(enem);
        if (enem == 1) {
            Attack(Placaje, enemyHP);
        }
        else if (enem == 2) {
            Attack(Placaje, enemy2HP);
        }
        break;
    default:
        cout << "Pues te quedas sin turno, por tonto, haber elegido bien :/\n";
        break;
    }
}
void enemyAttack(int& heHP,int& enatt) {
     enatt = (rand() % 500);
     heHP = heHP - enatt;
}
void eleccionesenem(int optionn, int& enem) {
    Attackenemies();
    cin >> optionn;
    attackenemy(optionn, enem);
}
void points() {
    if (heroHP > 0) {
        cout << "\n.....\n............\n     >>>    VIDA " << heroName << ":" << heroHP << " \n............\n.....\n\n";
    } else {
        cout << "\n.....\n............\n     >>>    VIDA:0"  " \n............\n.....\n\n";
    }
}
void herodead() {
    cout << "Has muerto\n\n\n\n\n\n";
}
void enemiesAlive() {
        cout << "***\n*******\n**************\n**********************\n\n\n        Enhorabuena has derrotado a tus enemigos\n\n\n**********************\n**************\n*******\n***\n";
}
void checkEnemyStatus(string& enemiesName,int enHP, int enemDamage){
    if (enHP <= 0) {
        cout << "\n\nEnemigo " << enemiesName << "\n\n**************ELIMINADO**************\n\n";
    } else {
        cout << "El enemigo " << enemiesName << " te ha hecho un dano de " << enemDamage << " puntos de vida\n";
        cout << "\n.....\n............\n     ------------>>>    VIDA " << enemiesName << ":" << enHP << " \n............\n.....\n\n";
    }
}
int main() {

    gameStart();

    while (heroHP > 0 || enemyHP > 0 || enemy2HP > 0) {
        if (heroHP > 0 && enemyHP > 0 && enemy2HP > 0) {

            eleccionesenem(opcion, elecEnemy);
            enemyAttack(heroHP, enemyDamage);
            enemyAttack(heroHP, enemyDamage2);
            checkEnemyStatus(enemyName, enemyHP, enemyDamage);
            checkEnemyStatus(enemyName2, enemy2HP, enemyDamage2);

        } else if (heroHP <= 0) {

            herodead();
            break;
        } else if (enemyHP <= 0 && enemy2HP <= 0) {

            enemiesAlive();
            break;
        } else if (enemyHP <= 0 || enemy2HP <= 0) {

            if (enemyHP <= 0) {

                eleccionesenem(opcion, elecEnemy);
                enemyAttack(heroHP, enemyDamage2);
                checkEnemyStatus(enemyName2, enemy2HP, enemyDamage2);

            }else if (enemy2HP <= 0) {

                eleccionesenem(opcion, elecEnemy);
                enemyAttack(heroHP, enemyDamage);
                checkEnemyStatus(enemyName, enemyHP, enemyDamage);
        }
        }
        points();
        system("pause");
        system("cls");
    }
}