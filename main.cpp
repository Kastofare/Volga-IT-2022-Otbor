#include "fairy_tail.hpp"

#include <cstdlib>
#include <ctime>

void generator(char v[10][10])
{
    std::ofstream file;
    file.open("input.txt", std::ios::out | std::ios::in);
    char c;
    int p=0; bool iv=false,el=false;
    for (int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) {
            switch (rand() % 4) {
                case 0:
                    c = '.';
                    break;
                case 1:
                    c = '#';
                    break;
                case 2:
                    c = '@';
                    if (!iv) { iv = true; }
                    else {
                        switch (rand() % 2) {
                            case 0:
                                c = '.';
                                break;
                            case 1:
                                c = '#';
                                break;
                        }
                    }
                    break;
                case 3:
                    c = '&';
                    if (!el) { el = true; }
                    else {
                        switch (rand() % 2) {
                            case 0:
                                c = '.';
                                break;
                            case 1:
                                c = '#';
                                break;
                        }
                    }
                    break;
            }
            file << c;
            //std::cout << c;
            v[i][j] = c;
        }
    //std::cout<<std::endl;
    }
file.close();
}

int walk(int k)
{
    Fairyland world;

    for (int i = 0; i < k; ++i)
    {
        Direction direction;

        int k;//k - куда смотрят глаза
        
        //использую правило правой руки(идти вперёд по направлению правой руки, подробнее в самой программе)
        /*k=1;//правая рука направлена влево (человек смотрит вниз и по возможности идёт вниз)
        k=2;//правая рука направлена вниз (человек смотрит вправо и по возможности идёт вправо)
        k=3;//правая рука направлена вправо (человек смотрит вверх и по возможности идёт вверх)
        k=4;//правая рука направлена вверх (человек смотрит влево и по возможности идёт влево)*/
        for (int s=0;s<1;s++) {
        if (!(world.canGo(Character::Ivan, Direction::Left))&&(!(world.canGo(Character::Ivan, Direction::Up)))&&(!(world.canGo(Character::Ivan, Direction::Right)))) {k=1; break;}
        if (!(world.canGo(Character::Ivan, Direction::Left))&&(!(world.canGo(Character::Ivan, Direction::Up)))&&((world.canGo(Character::Ivan, Direction::Right)))&&(k==6)) {k=1; break;}
        if (!(world.canGo(Character::Ivan, Direction::Left))&&(!(world.canGo(Character::Ivan, Direction::Up)))&&(world.canGo(Character::Ivan, Direction::Right))) {k=2; break;}
        if ((world.canGo(Character::Ivan, Direction::Left))&&(!(world.canGo(Character::Ivan, Direction::Up)))&&(!(world.canGo(Character::Ivan, Direction::Right)))) {k=1; break;}
        if (!(world.canGo(Character::Ivan, Direction::Right))&&!(world.canGo(Character::Ivan, Direction::Down))&&(world.canGo(Character::Ivan, Direction::Left))&&(k==1)) {k=6; break;}


        if (!(world.canGo(Character::Ivan, Direction::Down))&&(k==1)) {k=2; break;}
        if (!(world.canGo(Character::Ivan, Direction::Right))&&(k==2)) {k=3; break;}
        if (!(world.canGo(Character::Ivan, Direction::Up))&&(k==3)) {k=4; break;}


        if (!(world.canGo(Character::Ivan, Direction::Up))&&!(world.canGo(Character::Ivan, Direction::Left))&&(k==3)) {k=5;break;}
        }
            
        switch (k) {
            case 1:direction = Direction::Down; break;
            case 2:direction = Direction::Right; break;
            case 3:direction = Direction::Up; break;
            case 4:direction = Direction::Left; break;
            case 5:direction = Direction::Right; break;
            case 6:direction = Direction::Left; break;
        }
        
        if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
            return world.getTurnCount();
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int rezhim,turn;
    std::cout<<"How will the program work?"<<std::endl<<"Counter (Press 1)."<<std::endl<<"Generator (Press 2)."<<std::endl;
    std::cin>>rezhim;
    std::cout<<"How many turns do you need?";
    std::cin>>turn;
    switch (rezhim)
            {case 1:
                    if (const int turns = walk(turn)) 
                    {std::cout << "Found in " << turns << " turns" << std::endl;}
                    else
                    {std::cout << "Not found" << std::endl;}
                break;
                case 2:
                    char v[10][10]; generator(v);
                int sch = 0;
                while (sch==0) {
                if (const int turns = walk(turn)) {
                    std::cout << "Found in " << turns << " turns" << std::endl;
                    sch=1;
                    for (int i=0; i<10; i++) {
                       for (int j=0; j<10; j++){
                      std::cout<<v[i][j];
                       }
                    std::cout<<std::endl;}
                }
                else {generator(v);}
                }
                break;
                }


    return 0;
}
