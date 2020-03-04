#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name("�p�Ѫ�", ({"small tengu","tengu"}) );
  set("long",@LONG
�Ѫ����髬���p�A�~�ָ������Ѫ��C
LONG
);
  set("race", "�H��");
  set("unit","��");
  set("age",30);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("tengu",1);
  set("level",33);
  set_skill("fork",30+random(15));
  set_skill("dodge",30+random(10));
  set_skill("parry",20+random(10));
  add("addition_armor",30+random(10));
  set("chat_chance", 7);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  set_living_name("tengu-war-tengu");
  switch( random(10) )
  {
    case 1: carry_object(__DIR__"eq/banlo-mask")->wear(); break;
    case 2: carry_object(__DIR__"eq/tengu-mask")->wear(); break;
    case 3: carry_object(__DIR__"eq/tengu-pants")->wear(); break;
    case 4: carry_object(__DIR__"eq/tengu-clog")->wear(); break;
  }
  switch( random(50) )
  {
    case  0..48: carry_object(__DIR__"eq/halbert")->wield(); break;
    case 49: carry_object(__DIR__"eq/hide-bone-dagger")->wield(); break;
  }
  carry_object(__DIR__"eq/tengu-cloth")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if( random(target->query_dex()) < 2)
  {
    message_vision(HIC"\n$N���⮳�X�@�⮰�l�µ�$n���ʡA$n�P����j��ŧ�ӡA�X�G������}�I\n\n"NOR, me, target);
    target->add_busy(1+random(2));
    return 1;
  }
  else if(!random(17))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
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
