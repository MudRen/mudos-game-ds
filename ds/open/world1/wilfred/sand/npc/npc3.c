#include <ansi.h>
inherit NPC;

void create()
{
  set_name(WHT"�ȯT"NOR, ({"silver wolf","wolf"}) );
  set("long",@LONG
�o�دT�b���F����W�Q���֨��A�q�`���O�W�ۦ�ʡA������
�L�T���s�~�ʡA�e����֤Q���}�G�A�ҥH�`�D���y�H�l���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",10);
  set("level",20);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l","����" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  carry_object(__DIR__"eq/eq4")->wear();
}

void init()
{
  object ob = this_object(), me = this_player();
  if(this_player()->name(1) == "�g�~�ȤH")
  {
    message_vision("$N���������A�}�l�C�C����$n .... \n",ob,me);
    message_vision(HIR"\n�ݨ�$N"HIR"�Q�Y��$n�I�I\n\n"NOR,ob,me);
    COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(3)+2);
    COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(3)+2);
  }
}
