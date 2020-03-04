#include <ansi.h>

#define T_MONEY 1
#define T_EXP 2
#define T_POP 3
#define T_ART 4

void init() {
    add_action("do_open","open");
}

object createCookie2(int type, int amount) {
    object cookie;
    cookie = new(__DIR__"mouse_cake.c");
    switch ( type ) {
    case T_MONEY:       // ����
        cookie->set("wish_type", "money");
        cookie->set("wish_amount", amount );
        cookie->set_name(
                sprintf( HIY"%d�T%s%s" NOR, amount,"�j��", cookie->query("name") ), 
                                        ({ "coin-mouse cookie", "cookie" }));
        break;
    case T_EXP: // �g��
        cookie->set("wish_type", "exp");
        cookie->set("wish_amount", amount);
        cookie->set_name(
                    sprintf( HIG"%d�I%s%s" NOR, amount,"�g��", cookie->query("name") ),
                                        ({ "exp-mouse cookie", "cookie" }));
        break;
    case T_POP: // �n��
        cookie->set("wish_type", "pop");
        cookie->set("wish_amount", amount);
        cookie->set_name(
                    sprintf( HIC"%d�I%s%s" NOR, amount,"�n��", cookie->query("name") ),
                                        ({ "pop-mouse cookie", "cookie" }));
        break;
    case T_ART: // ����
        cookie->set("wish_type", "art");
        cookie->set("wish_amount", amount);
        cookie->set_name(
                    sprintf( HIW"%d�I%s%s" NOR, amount,"����", cookie->query("name") ),
                                        ({ "art-mouse cookie", "cookie" }));
        break;
    }

    return cookie;
}

/*
happy, money, exp, pop, art
1 80% 20% x x
2 30% 60% 10% x
3 10% 30% 60% x
4 5% 10% 25% 60%
5 5% 5% 10% 80%
*/
object createCookie(int happiness) {
    int type, amount;
    int rnd = random(100);
    switch ( happiness ) {
    case 1:
        if (rnd < 80) {
            type = T_MONEY;
            amount = 1 + random(1000);
        } else {
            type = T_EXP;
            amount = 1 + random(1000);
        }
        break;
    case 2:
        if ( rnd < 30) {
            type = T_MONEY;
            amount = 1 + random(10000);
        } else if ( rnd < 90 ) {
            type = T_EXP;
            amount = 1 + random(10000);
        }  else {
            type = T_POP;
            amount = 1 + random(10);
        }
        break;
    case 3:
        if ( rnd < 10) {
            type = T_MONEY;
            amount = 1 + random(100000);
        } else if ( rnd < 40 ) {
            type = T_EXP;
            amount = 1 + random(100000);
        }  else {
            type = T_POP;
            amount = 1 + random(20);
        }
        break;
    case 4:
        if ( rnd < 5) {
            type = T_MONEY;
            amount = 10000 + random(100000);
        } else if ( rnd < 15 ) {
            type = T_EXP;
            amount =  10000 + random(100000);
        } else if ( rnd < 40) {
            type = T_POP;
            amount = 10 + random(300);
        }  else {
            type = T_ART;
            amount = 1 + random(50);
        }
        break;
    case 5:
        if ( rnd < 5) {
            type = T_MONEY;
            amount = 10000 + random(100000);
        } else if ( rnd < 10 ) {
            type = T_EXP;
            amount = 10000 + random(100000);
        } else if ( rnd < 20) {
            type = T_POP;
            amount = 100 + random(1000);
        }  else {
            type = T_ART;
              amount = 1 + random(200);
        }
        break;
        case 6:
                type = T_ART;
                amount = 100 + random(1000);
        break;
    }

    return createCookie2(type, amount );
}


object createWord( ) {
        string file;
        object word;
        // �@���E�Ӧr�A�i�� �����_ ���ӹB�� �������{��
        file = sprintf("word%d.c", 1+random(9));
        word = new(__DIR__+file);
        return word;
}

void open(object bag) {
    object cookie, word;

    message_vision( HIC"$N���y���ݪ����}$n"HIC"�C\n"NOR, this_player(), this_object());
    // ����
    cookie = createCookie(bag->query("happiness") );
    message_vision( "$N��o�@��$n"HIC"�C\n"NOR, this_player(), cookie);
    cookie->move(this_player());
    // ���r: �����_
        if(random(100) < bag->query("happiness") * 15) {
            word = createWord();
            message_vision( "$N��o�@��$n"HIC"�C\n"NOR, this_player(), word);
            word->move(this_player());
    }
}

int do_open(string arg) {
    object bag;
    if ( !arg )
        return 0;
    if(this_player()->is_busy())
        return 0;
    if ( !objectp(bag = present(arg, this_player())))
        return 0;
    if ( !bag->id("__MOUSE_BAG__")) return 0;

    open(bag); // ���}�ֳU
    destruct(bag);
    return 1;
}


int query_unique() { return 1; }

