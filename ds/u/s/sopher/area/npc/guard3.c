#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "軍務官" , ({ "guard" }) );
        set("level", 10);
        set("con", 15);
        set("age",30);
        set("str", 10);
        set("dex",10);
        set("int",10);
        set_skill("parry", 10);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set("long","他是超龍軍團的軍務官，負責管理一些軍團人口調配問題。\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIC"軍務官說道：我在忙！別凡我！\n"NOR,
           (:command("snicker"):),
        }) );
       setup();
}      
