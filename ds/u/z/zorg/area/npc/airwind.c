#include <ansi.h>
inherit NPC;

void create()
{
        set_name("赤", ({"airwind", "air","wind","aw" }) );
        set("long", "He looks like a terrible person,！\n");
        set("race", "人類");
        set("gender", "男性"); 
        set("age", 20);
        set("attitude", "friendly");
        set("level", 8);
        set("evil", -99);
        set("combat_exp",2000);
        set("title",HIW"【"HIG"闇"HIR"之"HIC"赤"HIW"】"NOR);
        set("env/wimpy", 25);        
        set("chat_chance", 9 );
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //會自己走動 
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("cac"):),
        }) );
        setup(); 
}



