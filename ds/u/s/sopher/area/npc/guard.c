#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"營前"HIC"衛兵"NOR , ({ "guard" }) );
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
        set("chat_msg",({HIW"營前衛兵說道：你好！歡迎光臨超龍軍團第一本部!\n"NOR,
           (:command("snicker"):),
        }) );
       setup();
}      
