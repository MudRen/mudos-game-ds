#include <ansi.h>
inherit NPC;

void create()
{
  set_name("����", ({"shinin-ryuu apprentice","apprentice"}));
  set("long",@long
���̸��~���������A�]�O�s���y���s�i���{�A���b�o�̶ԾĪ���m�Z
���C
long);      
  set("gender", "�k��" );
  set("age",18);
  set("title",HIG"�s���y"NOR);
  set("level",15+random(6));
  set("race","human");
  set_skill("blade", 30+random(11));
  set_skill("parry", 20+random(11));
  set_skill("dodge", 30+random(11));
  set_skill("unarmed", 30);
  add("addition_armor",20+random(5));
  set("talk_reply","�ڥ��b�m�ߤ��A�ЧO���Z�C\n");
  set("chat_chance", 8);
  set("chat_msg", ({
      "���Ͱ��|�ˤM�A�ΤO���e�货�U���P�ɤj�ۤ@�n�G�ܡI\n",
      "���ͪŤ⾮���A�j�ۤ@�n���P�����x�wíí�����⪺�ˤM�C\n",
      "���;ĤO�a�a��½�u�A�@���ۥX�G�K�~�I���s�n�C\n",
     }));                
  setup();
  carry_object(__DIR__"eq/bamboo-blade")->wield();
  add_money("coin",200+random(50));
}
