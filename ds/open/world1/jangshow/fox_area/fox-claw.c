#include <ansi.h>
#include <weapon.h> 
inherit F_UNIQUE;
inherit FIST;
void create()
{
  set_name(HIW"�կW"HIR"�M"HIW"��"NOR , ({ "fox-fire claw","claw" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�E���������e���A�z�ۤ����⪺���~�A�����ٷ|�E�X����C\n");
    set("material", "gold");
    set("value",25000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",3);
    set("weapon_prop/int",3);  
 
    set("replica_ob",__DIR__"fox-claw2");
  } 
  set("weapon_prop/bar",2); 
  set("weapon_prop/tec",-2); 
  set("beast_weapon_prop/damage",60);
  init_fist(60+random(this_player()->query("level")/3));
  setup();
} 

void attack(object me, object victim)
{
    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("unarmed") > 80 && me->query_str() > 30 && random(10)<3 )
    {
      message_vision(HIR"�@�D�����{�}�A"+HIW"�E��"+HIR+"�L�a����q������V$n�I�I\n\n" +NOR,me,victim);
      damage += me->query_skill("unarmed")+me->query_str()+random(50);
      tk_one += victim->query_skill("dodge")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "�u��"+victim->query("name")+"�����z���A���j����q�I�J�M�z�}�I\n\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
    return; 
    }
}

