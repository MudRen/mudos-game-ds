#include <ansi.h>
inherit NPC;

void create()
{
  set_name("���", ({"hedgehog"}) );
  set("long",@LONG
�������O�몺��糡A���ݫK���p�@�ӱa�몺�j�ײy�A
ť�����إͩ�F�z����糨�֬ƫp�A�i�Ψӻs�@�W�n�֥ҡC
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",2);
  set("level",20);
  set("limbs", ({ "�Y��", "����","�ݳ�","���l" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
}

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  if(ob && random(2))
  {
    i = random(30);
    me->recive_damage("hp",i,me);
    me->apply_condition("blooding", me->query_condition("blooding")+random(2)+1);
    message_vision(CYN"$N�@���p�߳Q��糨��A�h�o�y��a�աI"HIR"("+i+")\n"NOR,me,ob);
  }

  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  new(__DIR__"obj/obj6")->move(this_object());
  ::die();
  return;
}
