#include <ansi.h>
inherit NPC;
void create()
{
       set_name("不知名的動物",({"noname animal","animal"}));
        set("level",30+random(20));
        set("race", "野獸");
        set("age", 70);
        set("long", "牠是一隻不知名的動物，有關牠的一切全部都是個迷•\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾部"}) );
        set("verbs", ({ "bite", "claw", "crash"}) );
        setup();
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

