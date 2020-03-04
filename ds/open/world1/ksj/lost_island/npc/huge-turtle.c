#include <ansi.h>
inherit NPC;

void heal();
void create()
{
  set_name(YEL"������R"NOR, ({"huge turtle","turtle"}) );
  set("long",@LONG
�@���s�@�˪����t�A�I�W���t�ߴN���\�h���p�s�p�A�e���@���ʧ���
���ڡA���ڥ��ݬݰ_�ӴN�����j���K�y�A�Y�O�Q�{���i�O�D�`�i�ȡC
LONG
);
  set("race", "beast");
  set("gender", "����");
  set("unit","��");
  set("age",2500);
  set("level",42+random(3));
  set("evil",40);
  set("title",RED"  �]�~ "NOR); 
  set("attitude", "aggressive");
  set("limbs", ({ "�Y��", "�I��","����","�e��","���"}) );
  set("verbs", ({ "bite","crash","claw" }) );
  add("addition_damage",50);
  add("addition_armor",200);
  set("con",110);
  set("int",10);
  set("dex",10);
  set("chat_chance", 30);
  set("chat_msg", ({
     (: heal :),
     (: random_move :),
     }));
  setup();
}

void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",60+random(50));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  int damage;
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    if( random(target->query_dex()) < 20 )
    {
      damage=random(200)+300-(target->query_armor());
      message_vision(YEL"\n������R"HIR"���ʧ��ڡA���ݥ��譫������$N�I"HIR"("+damage+")\n\n"NOR,target);
      target->receive_damage("hp",damage,me);
      me->start_busy(2);
      return 1;
    }
    else
    {
      message_vision(YEL"\n������R"HIW"�r�O���ʧ��ھ�A���O$N�ӱ��a���}�F�I\n\n"NOR,target);
      me->start_busy(1);
      return 1;
    }
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
    case  0..89: new(__DIR__"eq/huge-turtle-shield")->move(this_object());
    break;
    case  90..99: new(__DIR__"eq/huge-turtle-armor")->move(this_object());
    break;
  }
  ::die();
  return;
}
