#include <ansi.h>
inherit NPC;
void create()
{
       set_name("食人花",({"eat people flower","flower"}));
        set("level",30+random(15));
        set("race", "野獸");
        set("age", 100);
        set("long", "一朵會吃人的大花，五顏六色的非常漂亮。\n");
        set("limbs", ({ "花朵", "枝條", "莖幹", "枝葉"}) );
        set("verbs", ({ "bite", "crash"}) );
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

