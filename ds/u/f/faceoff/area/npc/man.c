#include <ansi.h>
inherit NPC;
void create()
{
 set_name("趕路人",({"man",}));
 set("long",@LONG
一個尋常的趕路人.
LONG
    );
 set("attitude", "peaceful");
 set("age",30);
 set("gender","男性");
 set("level",9);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
}
