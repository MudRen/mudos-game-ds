#include <ansi.h>
inherit NPC;
void create()
{
        set_name("測∼女", ({ "g" }) );
                set("level",1);
           set("gender","女性");
setup();
}
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
        message("world:world1:vision",
HIC"\n  根據小人－宇多田飛的消息："HIW美眉－宛容被"\n\n\t"+ob
->name(1)+"拋棄了。\n\n"+NOR
        ,users());
        ob->add("popularity",1); //聲望
        ::die();
        //destruct(this_object());
        return;
}

