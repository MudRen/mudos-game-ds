// 2006/12/26

#include <ansi.h>
inherit ITEM;

int do_wehre();

void create()
{
        set_name("箱中之神",({"magic box","box"}) );
        set("long",@long
這是一個破舊的黑皮箱子，你很好奇站上去(stand)會發生什麼事。
long
);
        set_weight(10);
        set("unit","個");
          set("value",100);
        setup();
}

void init()
{
        add_action("do_stand","stand");
}

int do_stand(string arg) {
        object me, room, man;
        int i;
        me = this_player();
        if(me->is_busy() || me->is_fighting())
                return notify_fail("你正忙著。\n");
        if(arg!="box")
                return notify_fail("你想要站在那裡？\n");

        message_vision(CYN"$N將箱中之神放在地上，小心翼翼地站了上去....\n"NOR,me);
        message_vision(YEL"$N對著四週大聲說道：我帶的這個不是普通箱子，而是箱中之神，簡稱箱神，它可以安全又瀟灑地把我送到任何我想去的地方！！\n"NOR,me);

        message("system", 
                HIC"\n\t"+me->name()+HIC"大喊「"HIY"箱∼∼神∼∼∼∼"HIC"」，身子不斷往上飛，最後變成空中的一個小點。\n"NOR, users() );
        room = new("/open/world1/tmr/game/2006_c/cloud");
 
        i = 5 + random(5);
        while(i-->=0) {
                 man = new("/u/t/tmr/game/2006_c/oldman2.c");
                man->move(room);
        }

        me->move(room);
        me->start_busy(1);
        destruct(this_object());
        return 1;
}


