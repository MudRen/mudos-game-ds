#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"�_����"NOR, ({"chimera"}) );
  set("long",@LONG
��l������A���ڬO�r�D�A����l��s�Ϩ���Y�A�e���L�|�R�X����
�A���ݥ��r�ݼɡA�O�ǻ������]���C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("attitude", "aggressive");
  set("level",47+random(4));
  set("title",RED"  �]�~ "NOR);
  set("limbs", ({ "���Y","����","�D��","�e�}","��}","���Y" }) );
  set("verbs", ({ "bite" }) );
  add("addition_damage",30+random(15));
  set("chat_chance", 20);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(11))
  {
    message_vision(RED"\n$N"RED"������Y�P�ɫr��$n�A�ĤO���k����y���Y�����ˤf�I\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+120,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+3));
    return 1;
  }
  else if(!random(11))
  {
    message_vision(HIR"\n$N"HIR"��$n�R�X�����P���A�N�o$n�|�B�k«�I\n\n"NOR, this_object(), target);
      if(target->query_shield() > 250) 
         target->receive_damage("hp", 1+random(50),me);
         else target->receive_damage("hp", 25 + 250-(target->query_shield()),me);
    return 1;
  }
  else if(!random(11))
  {
    message_vision(GRN"\n$N"GRN"���D���N�����a�r�F$n�@�f�A$n�Pı��ˤf�~�ȯk�h�I\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50),me);
    target->apply_condition("poison", target->query_condition("poison")+(random(3)+1));
    return 1;
  }
  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  ob = this_object();
  target = this_player();
  ::receive_damage(type,cost,target);
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
  ob->add("popularity",2);
  tell_object(ob,HIG"�A�o�� 2 �I�n��C"NOR);      
  switch( random(99) )
  {
    case  0..9: new(__DIR__"eq/chimera-boots")->move(this_object());
    break;
  }
  ::die();
  return;
}
