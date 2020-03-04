#include <ansi.h>
inherit NPC;

void create()
{
        set_name("老道士",({"taoist"}) );
        set("long",
"無所事事的道士。"
        );
        set("age",45);
        set("level",1);
        set("race","人類");
        set("attitude", "peaceful");
        set("unarmed",20);
        set("chat_chance",5);
        set("chat_msg",({
                (:command("stare"):),
                }) );
        set_skill("unarmed",20);
        setup();                
        add_money("coin",100);
}

void die()
{
   object obj,ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }   
      message("world:world1:vision","\n\n\t"HIW"勤及大聲咆嘯著：居然被你給識破了，那我只好取你性命了！！\n\n"NOR,users());
      obj=new(__DIR__"npc/evil2")->move(this_object()); 
                     ::die();
        return;
}

