#include <ansi.h>
inherit NPC;

void create()
{
  set_name(MAG"��"HIW"�H�~"NOR, ({"anthropophagi monster","monster"}) );
  set("long",@LONG
�@�Ӵ����O��A�L�ڤW�٥p�ۤ@���ת��Ǫ��A�ݨe���ˤl�A�n��
�n��A�Y�F����..
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("attitude", "aggressive");
  set("level",47+random(4));
  set("title",HIR"���~"NOR);
  set("limbs", ({ "���Y","����","����","�e�}","��}" }) );
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
    message_vision(RED"\n$n��M�i�j�L�A�ĤO���ĦV$N�A�åB�r�F$N�����u�A�����I$N�����u�ܪ���O�O���C\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+120,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(2)+3));
    return 1;
  }
  else if(!random(11))
  {
    message_vision(HIG"\n$n��M�g�q�A�n���_��$N²�����o�ƤF�I\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+250-(target->query_shield()),me);
    return 1;
  }
  else if(!random(11))
  {
    message_vision(GRN"\n$n�Υ��������ĤO���ϦV$N�A���G$N���ݤf�W�X�{�@�D�岪�I�I"GRN"\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50),me);
    return 1;
  }
  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  int i;
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
  ::die();
  return;
}

