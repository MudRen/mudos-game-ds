#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���o",({"bandit",}));
 set("long",@LONG
�@�Ӿ���p�p¾�Ȫ��g��.
LONG
    );
 set("attitude", "aggressive");
 set("age",30);
 set("gender","�k��");
 set("level",24);
 set_skill("sword",20);
 set("chat_chance",10);
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
 carry_object(__DIR__"eq/longsword")->wield();
}

