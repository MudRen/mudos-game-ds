//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�A���",({"tower guard","guard"}));
set("level",52);
set("age",32);
set("long","�@�����A��Mĵ�٤u�@���A���, ���b�Τߪ��[��|�P�����ҡC\n");
set("gender", "�k��");
set_skill("tenken",340);
set("amount",1);
map_skill("unarmed","tenken");
set("coin",400+random(400));
//set_temp("apply/armor",400+random(200));
//set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",460);
carry_object(__DIR__"eq/towercloth")->wear();
carry_object(__DIR__"wp/club")->wield();
}
