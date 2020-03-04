#include <ansi.h>
inherit NPC;
void create()
{
       set_name("樹蛙",({"treeer frog","frog"}));
        set("level",30+random(20));
        set("race", "野獸");
        set("age", 23);
        set("long", "這是一隻青色的小蛙。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳"}) );
        set("verbs", ({ "bite","crash"}) );
        setup();
}
void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        switch( random(1000) ) {
        case 0: 
        newob=new(__DIR__"obj/scroll");
        newob->move(this_object());
        break;
        case 1..200:
        ob->add("popularity",1);
        tell_object(ob,HIG"你得到了 1 點聲望\n"NOR);
        break;
        default:
        break;
        }
        ::die();
        return;
}

