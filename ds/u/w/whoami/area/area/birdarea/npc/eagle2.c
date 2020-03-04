#include <ansi.h>
inherit NPC;
void create()
{
        set_name("老鷹",({"eagle"}));
        set("level",30+random(15));
        set("race", "野獸");
        set("age", 8);
        set("long", "這是一隻老鷹。\n");
        set("limbs", ({ "頭部", "身體", "腳", "尾巴" }) );
        set("verbs", ({ "bite", "poke" }) );
        setup();
        carry_object(__DIR__"eq/fist.c")->wield();
}

void die()
{
        object ob,newob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        switch( random(1000) ) {
        case 0..200:
        ob->add("popularity",1);
        tell_object(ob,HIG"你得到了 1 點聲望\n"NOR);
        break;
        case 201:
        newob=new(__DIR__"obj/scroll");
        newob->move(ob);
        break;
        default:
        break;
        }
        ::die();
        return;
}

