//sightseer.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�[����",({"sightseer"}));
set("level",28);
set("age",32);
set("long","�@�ӥ~�a�Ӫ��[����, ���b��B�R�����~�ǳƱa�^�a�������C\n");
set("gender", "�k��");
set("combat_exp",20000+random(3000));
set("coin",500+random(200));
set("chat_chance",35);
set("chat_msg",({
  (:command,"east":),
  (:command,"get all":),
  (:command,"west":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
setup();
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n�[���Ȥj�s: �u�m�T�ڡ�T�ϩR�ڡT�v\n"NOR,
HIW"\n�[���ȷQ�k�i�O�Q�d��F...�]����\n"NOR,
     }) );
//carry_object("/u/p/pudon/obj3/ring")->wear();
}
void init()
{
add_action("no_follow","follow");
}

int no_follow(string arg)
{
if(arg=="sightseer")
 {
 message_vision("\n[1;37�[���ȹ�$N���ۻ�: [1;37m�A�]�O���[������?[m\n",this_player());
 message_vision("\n[1;33m�[���Ȼ�:[1;32m ���N�M�ڤ@�_�}�}�a�C*^_^*[m\n",this_player());
 return 0;
 }
return 0;
}