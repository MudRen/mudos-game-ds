#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC"霸魂"NOR, ({ "ba soul king", "king",  "soul"}) );
        set("level",42);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("sword",100); 
        set("attitude", "aggressive");
        set_skill("unarmed",100);          
        set("long" ,"九天雲魂的頭頭。\n");
        set("age", 400);
        set("title", HIC "九天雲魂"NOR);
        set("chat_chance", 50);
        set("chat_msg", ({
           (: random_move :),
        }) ); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: command("wield sword") :),  
        (: command("wield sword") :),        }));         setup();
        set_living_name("westwar");
        carry_object(__DIR__"obj/sword")->wield();
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i=ob->query_temp("westwar");
        ob->set_temp("westwar",i+1);
        if(ob->query_temp("westwar")>2) 
        {
          ob->add("popularity",3); 
          tell_object(ob,HIW"(你得到 3 點聲望。)\n"NOR);
          ob->delete_temp("westwar");
        }
        ::die();
        return;
}

