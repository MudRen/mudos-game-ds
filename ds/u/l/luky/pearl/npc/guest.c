//sightseer.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("�ȤH",({"guest"}));
set("level",30);
set("age",28);
set("long","�A�ݨ�@�쥿�b�M�ߦY�����k�ȤH�C\n");
set("gender", "�k��");
set("combat_exp",20000+random(3000));
set("coin",600+random(200));
set("chat_chance",2);
set("chat_msg",({
  (:command,"hmm":),
  (:command,"say �Z�Z..��...�u�n�Y..":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
setup();
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n�ȤH�j�s: �u �m���ڡ�T���|�ۤv�R�ڡT�v\n"NOR,
HIW"\n�ȤH�Q�k�i�O�Q�d��F...�]����\n"NOR,
     }) );
carry_object(__DIR__"wp/fork")->wield();
}
