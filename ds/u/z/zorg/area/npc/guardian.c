#include <ansi.h>
inherit NPC;

void create()
{
        set_name( HIY "�u��" NOR , ({"guardian","guard" }) );
        set("long", ""HIY"He is a guardian for imperial palace"NOR"�I\n");
        set("race", "�����H");
        set("gender", "�k��"); 
        set("age", 48);
        set("attitude", "heroism");
        set("level", 18);  
        set("evil", 0);
        set("combat_exp",2000);
        set("title",HIW"�i"HIG"�Ӯc"HIR"���e"HIC"�u��"HIW"�j"NOR);
        set("chat_chance_combat",100);
        set("chat_msg_combat", ({
        (:command("wield sword"):),
        (:command("say What the heck are you doing???"):),
        (:command("shout WE ARE UNDER ATTECK,I REPEAT WE ARE UNDER ATTECK!!!")
:),
        }) );
        setup(); 
}










