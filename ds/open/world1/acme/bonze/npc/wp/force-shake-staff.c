#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"�I"HIC"�_"HIY"�k��"NOR,({"force-shake staff","staff"}));
  set("long",@LONG
�ǻ�������ɪk�����@�A�o���I�������Y�b�����Ĥ�ɥi�H�t�X���l
�Ӿ_�˼ĤH�C
LONG);
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("volume",6);
    set("value",10000);
    set("material", "gold");
    set("limit_str",40);
    set("limit_lv",20);
    set("class_only","�ⶳ�x");
  }
  set("replica_ob",__DIR__"staff");
  init_staff(65,TWO_HANDED);
  setup();
}

void attack(object me,object victim)
{
  int me_bio,damage;
  ::attack();
   if(!me || !victim) return;
  me_bio=me->query_bio();
  damage=me->query_skill("buddha-force")+me->query_skill("force")+me->query_str()-victim->query_armor();
  damage=damage+random(100);
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(damage < 0) return;
  if(random(15-me_bio)) return; 

  message_vision(HIY"�I"HIC"�_"HIY"�k��"HIW"����$N������X���ê����O�A�ް_�@�i�i���_�O�C\n"NOR,victim);
  if( me->query_skill("buddha-force") > 90)
  {
    message_vision(HIR"�I�_�k�����ͱj�j�_�O�A�N$N�_�o�C�լy��I"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 60)
  {
    message_vision(HIR"�I�_�k�����ͱj�j�_�O�A�N$N�_�o�����ѶˡI"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 30)
  {
    message_vision(HIR"�I�_�k�����ͱj�j�_�O�A�N$N�_�o���½�ˡI"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if( me->query_skill("buddha-force") > 0)
  {
    message_vision(HIR"�I�_�k�����_�O�A�N$N�_�o�����o�¡I"HIR"("+damage+")\n"NOR,victim);
    damage=damage*3/5;
    if(damage<0) damage=0;
    victim->receive_damage("hp",damage, me);
    me->receive_damage("ap",10);
  }
  if(me->query("id") == "master bonze")  victim->add_busy(2);
  else  victim->add_busy(1);
  return;
}
