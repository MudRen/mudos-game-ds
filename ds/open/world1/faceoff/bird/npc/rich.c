#include <ansi.h>
inherit NPC;
void create()
{
 set_name("富貴人家",({"rich",}));
 set("long",@LONG
一個向貧農們討債的債主.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","男性");
 set("level",15);
 set("chat_chance",10);
set("chat_msg", ({"富貴人家說道:這些賤民還不把錢還來! \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
