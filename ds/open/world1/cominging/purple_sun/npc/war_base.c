#include <ansi.h>
inherit NPC;

void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }

        ob->add("purple_sun_war",1);
        if(ob->query("purple_sun_war") >= 2 )
        {
                tell_object(ob,HIG"你得到一點聲望。\n" NOR);
                ob->add("popularity",1); //聲望
                ob->set("purple_sun_war",0);
        }
        ::die();
        return;
}
