#include <ansi.h>

inherit NPC;

void create()
{
        set_name("冰", ({ "ice" }) );
        set("gender", "男性");
        set("level",35);
        set("age",random(100));
        set("evil",-200);
        set("title",HIW" 墮天使 "NOR);
        set("long",@LONG
上天派來得使者,為了消滅[31m蚩尤[0m
LONG
);
        set_skill("sorgi_sword",70); 
        set_skill("fogseven",70);
        set_skill("sword",70);
        set_skill("dodge",70);   
         set("chat_chance", 12);
        set("chat_msg", ({
  "冰說說：我..我..怎麼知道ㄚ..我也不敢過去..。\n",

}) );      set("chat_chance_combat",35);
        set("chat_msg_combat", ({
                  (: command("exert sorgi_sword") :),
                  (: command("exert fogseven") :),
                                     (: command("exert sorgi_sword") :), 
                  (: command("exert sorgi_sword") :),
         }) );
        setup(); 
        carry_object("/u/t/tako/wind sword")->wield();
}

void die()
{
        object killer;
        int last;
        if(random(7))
        {
                if(killer=this_object()->query_temp("last_damage_from"))
                {
                        last = killer->query("max_hp")/10;
                        if(last < killer->query("hp"))
                        {
                                message_vision(HIW"
  $N說:我跟你同歸於盡,$N使出一招 [冰] $n東躲西閃就是避不了。\n"NOR,this_object(),killer);
                                last=killer->query("hp")-last;
                                killer->receive_damage("hp",last,this_object());
                        }
                }
        }
        ::die();
}





