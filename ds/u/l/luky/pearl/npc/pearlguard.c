//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�ѹp����u��",({"pearl guard","guard"}));
set("level",32);
set("age",30);
set("long","�L�O�����j���u��, �@�ƫܵL�᪺�ˤl�C\n");
set("gender", "�k��");
set_skill("tenken",20);
set("amount",1);
map_skill("unarmed","tenken");
set("chat_chance",5);
set("chat_msg",({
  (:command,"yawn":),
}) );
set("coin",300+random(80));
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n�u�äj��: �u �ǤF�ڧa!! �ڦ��N���Q��ĵ�äF.. �v\n"NOR,
HIW"\n�u�÷Q�k�i�O�Q�d��F...�]����\n"NOR,
     }) );
carry_object(__DIR__"eq/scalescloth")->wear();
carry_object(__DIR__"wp/club")->wield();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="guard")
 {
 message_vision("\n[1;37m�u�ì�M��$N[1;37m�j�s: �A��ۧڷQ�F��!!?�C[m\n",this_player());
 message_vision("\n[1;33m�u�åΤO���F$N[1;33m�@��, �׶}�F$N�����ܡC[m\n",this_player());
 return 1;
 }
return 0;
}