#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"HANS集團時空管理者"NOR , ({ "guard" }) );
        set("level", 50);
        set("con", 55);
        set("age",30);
        set("str", 70);
        set("dex",10);
        set("int",10);
        set_skill("parry", 60);
        set_skill("unarmed", 80);
        set_skill("dodge", 60);
        set("long","銳利的眼神，不愧是位好衛兵。\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIW"管理者說道：你在這幹什麼？!\n"NOR,
           (:command("snicker"):),
        }) );
       setup();
}      
