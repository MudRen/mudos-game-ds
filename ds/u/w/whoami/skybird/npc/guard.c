#include <ansi.h>
inherit NPC;
void create()
{
 set_name("保鏢",({"guard",}));
 set("long",@LONG
富貴人家的保鏢.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","男性");
 set("level",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
