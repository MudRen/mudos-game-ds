#include <ansi.h>
inherit NPC;
void create()
{
 set_name("嘍囉",({"bandit",}));
 set("long",@LONG
一個擔任小小職務的土匪.
LONG
    );
 set("attitude", "aggressive");
 set("age",30);
 set("gender","男性");
 set("level",24);
 set_skill("sword",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}

