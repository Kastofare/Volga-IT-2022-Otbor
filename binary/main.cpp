void generator(char v[10][10])//в этой функции создаётся карта местности
{
    std::ofstream file;
    file.open("input.txt", std::ios::out | std::ios::in);
    char c;
    bool iv=false,el=false;
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
    file<<std::endl;
    }
file.close();
}

int walk(int sch)//в этой функции определяется, как идут Иван и Елена
{
    Fairyland world;

    for (int i = 0; i < sch; ++i)
    {
        Direction direction;
        Character character = Character::Ivan;
        int k,k1;//k - куда смотрят глаза Ивана, k1 - Елены
        //std::cout<<"Ivan's Turn"<<std::endl<<"do:k="<<k<<std::endl;
        //использую правило левой руки(идти вперёд по направлению левой руки, подробнее в самой программе)
        /*k=1;//левая рука направлена вправо (человек смотрит вниз и по возможности идёт вниз)
        k=2;//левая рука направлена вверх (человек смотрит вправо и по возможности идёт вправо)
        k=3;//левая рука направлена влево (человек смотрит вверх и по возможности идёт вверх)
        k=4;//левая рука направлена вниз (человек смотрит влево и по возможности идёт влево)
        k=5,6;//дополнительные состояния - для выхода из "тупика"
         если k!=1,2,3,4,5,6;*/
        for (int s=0;s<1;s++) {
           
        if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k=1; break;}
        if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&((world.canGo(character, Direction::Right)))&&(k==6)) {k=1; break;}
        if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(world.canGo(character, Direction::Right))) {k=2; break;}
        if (!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))&&(k==2)) {k=6; break;}
        if (!(world.canGo(character, Direction::Down))&&!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k=3; break;}

        if (!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k=6; break;}

        if ((world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k=1; break;}
        if (!(world.canGo(character, Direction::Right))&&!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(k==1)) {k=6; break;}
        if ((world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Right)))&&((world.canGo(character, Direction::Down)))&&(k==6)) {k=1; break;}
        if (!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Right)))&&((world.canGo(character, Direction::Down)))&&(k==6)) {k=1; break;}
        if ((world.canGo(character, Direction::Right))&&!(world.canGo(character, Direction::Left))&&(k==1)) {k=5; break;}
        if (!(world.canGo(character, Direction::Down))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k=6; break;}
        if (k==4 && !(world.canGo(character, Direction::Down))&&!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Up)))&&(k==4)) {k=3; break;}


        if (!(world.canGo(character, Direction::Down))&&(k==1)) {k=2; break;}
        if (!(world.canGo(character, Direction::Right))&&((k==2)||(k==5))) {k=3; break;}
        if (!(world.canGo(character, Direction::Up))&&(k==3)) {k=4; break;}


        if (!(world.canGo(character, Direction::Up))&&!(world.canGo(character, Direction::Left))&&(k==3)) {k=5;break;}
        }
            switch (k) {case 1:direction = Direction::Down; break;
            case 2:direction = Direction::Right; break;
            case 3:direction = Direction::Up; break;
            case 4:direction = Direction::Left; break;
            case 5:direction = Direction::Right; break;
            case 6:direction = Direction::Left; break;
            default: switch (rand() % 4) {
                    case 1:direction = Direction::Down; break;
                    case 2:direction = Direction::Right; break;
                    case 3:direction = Direction::Up; break;
                    case 0:direction = Direction::Left; break;
            }
        }//здесь определяется, куда пойдёт Иван
        //std::cout<<"posle:k="<<k<<std::endl;
        if (world.canGo(Character::Ivan, direction) && world.go(direction, Direction::Pass))
            return world.getTurnCount(); else {
        character = Character::Elena;

            //std::cout<<"Elena's Turn"<<std::endl<<"do:k1="<<k1<<std::endl;
            for (int s=0;s<1;s++) {

                if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k1=1; break;}
                if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&((world.canGo(character, Direction::Right)))&&(k1==6)) {k1=1; break;}
                if (!(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(world.canGo(character, Direction::Right))) {k1=2; break;}
                if (!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))&&(k1==2)) {k1=6; break;}
                if (!(world.canGo(character, Direction::Down))&&!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k1=3; break;}

                if (!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k1=6; break;}

                if ((world.canGo(character, Direction::Left))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k1=1; break;}
                if (!(world.canGo(character, Direction::Right))&&!(world.canGo(character, Direction::Down))&&(world.canGo(character, Direction::Left))&&(k1==1)) {k1=6; break;}
                if ((world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Right)))&&((world.canGo(character, Direction::Down)))&&(k1==6)) {k1=1; break;}
                if (!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Right)))&&((world.canGo(character, Direction::Down)))&&(k1==6)) {k1=1; break;}
                if ((world.canGo(character, Direction::Right))&&!(world.canGo(character, Direction::Left))&&(k1==1)) {k1=5; break;}
                if (!(world.canGo(character, Direction::Down))&&(!(world.canGo(character, Direction::Up)))&&(!(world.canGo(character, Direction::Right)))) {k1=6; break;}
                if (!(world.canGo(character, Direction::Down))&&!(world.canGo(character, Direction::Left))&&((world.canGo(character, Direction::Up)))&&(k1==4)) {k1=3; break;}


                if (!(world.canGo(character, Direction::Down))&&(k1==1)) {k1=2; break;}
                if (!(world.canGo(character, Direction::Right))&&((k1==2)||(k1==5))) {k1=3; break;}
                if (!(world.canGo(character, Direction::Up))&&(k1==3)) {k1=4; break;}


                if (!(world.canGo(character, Direction::Up))&&!(world.canGo(character, Direction::Left))&&(k1==3)) {k1=5;break;}
            }
            switch (k1) {case 1:direction = Direction::Down; break;
                case 2:direction = Direction::Right; break;
                case 3:direction = Direction::Up; break;
                case 4:direction = Direction::Left; break;
                case 5:direction = Direction::Right; break;
                case 6:direction = Direction::Left; break;
                default: switch (rand() % 4) {
                        case 1:direction = Direction::Down; break;
                        case 2:direction = Direction::Right; break;
                        case 3:direction = Direction::Up; break;
                        case 0:direction = Direction::Left; break;
                    }
            }
            //std::cout<<"posle:k1="<<k1<<std::endl;
            if (world.canGo(Character::Elena, direction) && world.go(Direction::Pass, direction))
                return world.getTurnCount();
            //std::cout<<"Next turn"<<std::endl;
            }
    }

    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int rezhim,turn;
    std::cout<<"How will the program work?"<<std::endl<<"Counter (Press 1)."<<std::endl<<"Generator (Press 2)."<<std::endl;
    std::cin>>rezhim;//определяется, создавать ли новую карту или находить количество ходов на уже имеющейся карте 
    //карта должна находиться в папке с проектом и называться input.txt (пример в проекте)
    std::cout<<"How many turns do you need?";
    std::cin>>turn;
    switch (rezhim)
            {case 1://нахождение количества ходов, за которое встретятся Иван и Елена
                    if (const int turns = walk(turn)) {
                        std::cout << "Found in " << turns << " turns" << std::endl;//удалось организовать встречу за turns - определённое количество ходов
                    }
                    else
                        std::cout << "Not found" << std::endl;//не удалось организовать встречу
                break;
                case 2:
                    char v[10][10];
                    generator(v);//создание карты
                    int sch = 0;
                    while (sch==0) {//проверка карты
                    if (const int turns = walk(turn)) {
                    //std::cout << "Found in " << turns << " turns" << std::endl;
                    sch=1;
                    for (int i=0; i<10; i++) {
                       for (int j=0; j<10; j++){
                      std::cout<<v[i][j];
                       }//карта правильная, выводится в консоль
                    std::cout<<std::endl;}
                }
                    else {generator(v);}//карта неправильная, создаётся новая карта
                }
                break;
                }


    return 0;
}
