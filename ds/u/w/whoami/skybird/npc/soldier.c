#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�q��",({"soldier",}));
 set("long",@LONG
�@�Ӻ��@�A���w�����q��.
LONG
    );
 set("attitude", "peaceful");
 set("age",40);
 set("gender","�k��");
 set("level",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}
