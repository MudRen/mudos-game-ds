#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�v��", ({"discipline monk","monk"}));
  set("long",@long
�u���v���@��A�M�׬�ë�ũG�A�[�A�s���A�g���غ�����W��A�H�D
�o�k�O�C����̤S��"�s��"�C�A���e���o�����D���M�����}�}����
���A���k�M���ѱj�j����աC
long);      
  set("gender", "�k��" );
  set("age",50);
  set("title","����D");
  set("evil",-30);
  set("level",45);
  set("race","human");
  set_skill("staff", 85);
  set_skill("parry", 70);
  set_skill("dodge", 70);
  set_skill("unarmed", 90);
  add("addition_armor",50+random(5));
  set("talk_reply","�e��M�I�����A�Ф��n�A�`�J�˪L�C\n");
  setup();
  carry_object(__DIR__"eq/moon-arc-staff")->wield();
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/water-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  carry_object(__DIR__"eq/food-pill");
  add_money("coin",1000+random(500));
}

int special_attack(object me, object target, int hitchance)
{
  int damage,lv;
  lv=target->query("level");
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if( (me->query("hp"))  < (me->query("max_hp")/3))
  {
    if(!random(6) && me->query("ap") > 200)
    {
      damage=(75-lv)*10+random(100);
      message_vision(HIR"\n$N��r���ڡA�����W�O���׼ɰ_�A���U�ˤf����j�Ŵ�$n���X�@�x�A\n"
      +RED"$n�Q�@�ѱj�j���l�O�����A�uı�o����½�ˡA�f�R�A��I�C"HIR"("+damage+")\n\n"NOR,me, target);
      target->receive_damage("hp",damage,me);
      target->add_busy(3);
      me->receive_damage("ap",100,target);
      me->receive_damage("hp",100,target);
      message_vision(HIR"\n$N�����W�Q�X�ƹD��W�I\n"NOR,me);
      return 1;
    }
    else if(me->query("ap") < 200)
    {
      command("eat water pill");
    }
    else
    {
      command("eat food pill");
    }
  }
  else if(!random(7) && me->query("ap") > 100)
  {
      damage = (100-lv) * 5 + random(100);
         if( damage < 1 ) damage = 10 + random(50);
    message_vision(HIW"\n$N�f������ۯu�������l�O�z�W�A���ۤj�ܤ@�n�A��$n���X�@���A\n"
    +RED"$n�Q�L�Ϊ��l�O�����A�L������A�������������I�C"HIR"("+damage+")\n\n"NOR,me, target);
    target->receive_damage("hp",damage,me);
    me->receive_damage("ap",100,target);
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
 
  switch( random(100) )
  {
    case  0..2: new(__DIR__"eq/perple-beads")->move(this_object());
    break;
  }
  ::die();
  return;
}
