#include <ansi.h>
inherit NPC;
void create()
{
        set_name("九天守衛", ({ "soul guard", "guard"}) );
        set("level", 40);
        set("long" ,"九天守衛是雲魂中選出的精英，負責維護雲端的和平。\n");
        set("age", 250);
		  set("title",HIR"九天雲魂"NOR);    
        set("chat_chance", 10);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        setup();
        set_living_name("westwar");
    	set_temp("apply/armor", 50);
		set_temp("apply/shield", 50);
		set_temp("apply/damage", 50);
        carry_object(__DIR__"obj/guard-blade")->wield();
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
        ob->add("popularity",1); 
        tell_object(ob,HIW"(你得到 1 點聲望。)\n"NOR);
        ::die();
        return;
}

