#include <ansi.h>
inherit NPC;
void create()
{
       set_name("古代蜻蜓",({"old dragonfly","dragonfly"}));
        set("level",18);
        set("race", "野獸");
        set("age", 500);
        set("long", "這是隻大蜻蜓。\n");
        set("limbs", ({ "頭部", "身體", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite", "crash", "hoof"}) );
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

