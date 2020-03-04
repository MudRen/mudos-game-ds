#include <ansi.h>
inherit NPC;
void create()
{
       set_name("千年巨蛙",({"thousand frog","frog"}));
        set("level",10);
        set("race", "野獸");
        set("age", 1000);
        set("long", "這是非常大的青蛙，傳說他可以活上千年。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳"}) );
        set("verbs", ({ "bite"}) );
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

