#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"wood cutter","cutter",}));
 set("long",@LONG
�@�ӤJ�s��쪺����.
LONG
    );
 set("attitude", "peaceful");
 set("age",41);
 set("gender","�k��");
 set("level",10);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/sandels")->wear();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/wood_axe")->wield();
}
