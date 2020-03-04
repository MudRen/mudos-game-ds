#include <ansi.h>
inherit NPC;

void create()
{
  set_name(GRN"�C�쩥��"NOR, ({"green snake","snake"}) );
  set("long",@LONG
�������Y�����ءA�����C�񪺳D�칳���ۯ��b�򤣥��A��e�L���ɬ�
���@�������C�a�����ۡA���M�S���r�ʡA�o�����ؾl�����j�p�y���A
�����p���j�p���ʪ��i�H�����ө��|�C
LONG);
  set("race", "beast");
  set("unit","��");
  set("age",45);
  set("gender", "����" );
  set("level",27+random(4));
  set("title",HIW"  �_�~ "NOR);
  set("limbs", ({ "�Y��", "����","����" }) );
  set("verbs", ({ "bite" }) );
  add("addition_armor",25+random(5));
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision(GRN"\n�C�쩥��"HIR"���Q�����L$n�A�ΥX�Ʊ��ֶ}�׺쪺�ˤf�I\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100)+100,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+5));
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

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(GRN"�C�쩥��"NOR"�p�J���O���A���������F�C\n");
         destruct(this_object());
         break;
  }
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
  switch( random(99) )
  {
    case  0..9: new(__DIR__"eq/green-snake-waist")->move(this_object());
          break;
  }
  ::die();
  return;
}
