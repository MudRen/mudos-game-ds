#include <ansi.h>
inherit NPC;

void create()
{
        set_name( HIY "守衛" NOR , ({"guardian","guard" }) );
        set("long", ""HIY"He is a guardian for imperial palace"NOR"！\n");
        set("race", "機器人");
        set("gender", "男性"); 
        set("age", 48);
        set("attitude", "heroism");
        set("level", 18);  
        set("evil", 0);
        set("combat_exp",2000);
        set("title",HIW"【"HIG"皇宮"HIR"門前"HIC"守衛"HIW"】"NOR);
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
        (:command("wield sword"):),
        (:command("say What the heck are you doing???"):),
        (:command("shout WE ARE UNDER ATTECK,I REPEAT WE ARE UNDER ATTECK!!!")
:),
        }) );
        setup(); 
}










