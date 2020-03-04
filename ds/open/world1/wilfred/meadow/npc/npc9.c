#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�ƨg����",({"crazy cow","cow"}) );
  set("long","�o�g���������A��������A�@�I�H�ɷ|�ĹL�ӫr�H���ˤl�A���H�椧���ߡC\n");
  set("race", "beast");
  set("unit","�Y");
	set("title",HIG"�������"NOR);
  set("age",6);
  set("level",35);
  set("attitude", "killer");
  set("limbs", ({ "�Y��", "����","�ݳ�","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",30);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
  carry_object(__DIR__"obj/meat");
       if(random(100)<5) carry_object(__DIR__"obj/paper-box");

  set_living_name("cow_war");
}

int special_attack(object me,object target,int hitchance)
{
  int i, hit = random(4)+1, damage, dodge;
  if(!me || !target) return 0;
  if(random(5)) return 0;

  message_vision(HIR"\n\t$N�����G���嵷�A�µ�$n�ƨg���ĤF�L�ӡI�I\n\n"NOR,me,target);
  dodge = target->query_skill("dodge");
  for(i=1;i<hit;i++)
  {
    message_vision(HIY"$N�o�g�몺�V$n��ĦӨӡI�I",me,target);
    if(dodge + random(dodge) < 100)
    {
      damage = 15+random(40);
      message_vision("$N�@�ɰ{�פ��ΡA�Q�������W�A���줣�p���ˮ`�I "HIR"("+damage+")\n"NOR,target);
      target->receive_damage("hp",damage);
    }
    else
    {
      if(dodge + random(dodge) < 200)
      {
        damage = 5+random(20);
        message_vision("$N�@�Ӱ{���A�����׹L�A�����餴�Q�l���ζˡI "HIR"("+damage+")\n"NOR,target);
        target->receive_damage("hp",damage);
      }
      else message_vision("$N���Τ@�̡A���P�׹L�����I\n"NOR,target);
    }
  }
  return 1;
}

void die()
{
   object ob, env, obj;
   int temp;
   string msg;

   if( !ob = query_temp("last_damage_from") )
   ob = this_player(1);
   if( !ob )
   {
     ::die();
     return;
   }

   ob->add("popularity",1);
   tell_object(ob,HIG"�A�o��@�I�n��C\n"NOR);

   ::die();
   return;
}

