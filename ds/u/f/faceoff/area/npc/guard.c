#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�O��",({"guard",}));
 set("long",@LONG
�I�Q�H�a���O��.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
