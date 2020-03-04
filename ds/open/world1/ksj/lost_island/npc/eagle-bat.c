#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW""BLK"�ݦ��N��"NOR, ({"eagle bat","bat"}) );
  set("long",@LONG
�@�����j�������A���F���l�Q�����~�A�٦��@���U�Q���N���A�M�Ψ�
��}�y����׫�A�l�����A��C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",25);
  set("attitude", "aggressive");
  set("gender", "����" );
  set("level",40+random(3));
  set("title",GRN"  ���~ "NOR);
  set("limbs", ({ "�Y��", "����","���l","�}��"}) );
  set("verbs", ({"bite","claw"}) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(!this_object()->visible(this_player()))
  {
    message_vision("\n$N�o�{�F���b�t�B��$n�A�G�ܤ����o�ʧ����I\n\n"NOR,this_object(),this_player());
    this_object()->kill_ob(this_player());
  }
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    message_vision("\n$N�L�n�L���a���L$n�A��X�@�ӥֶ}�׺쪺�ˤf�I\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+50,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+2));
    return 1;
  }
  return 0;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  ob->add("popularity",1);
  tell_object(ob,HIG"�A�o�� 1 �I�n��C"NOR);      
  ::die();
  return;
}
