#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW"���l�s��"NOR,({"silver dragon claw","claw"}));
  set("long",@LONG
���l�s���e���A�e�{���ժ���A�A���y�����o�X�ȥ��C
LONG
);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
// 2003.3.30 �s�W lv���� by ksj
    set("limit_lv",30);
    set("unit", "��");        
    set("value",12000);
    set("volume",3);
    set("weapon_prop/str",2);
    set("weapon_prop/dex",1);         
    set("material","steel");
// 2003.4.8 �s�W no_repair by ksj
    set("no_repair",1);
  }        
  init_fist(58+random(5));
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(random(4)) return;
  message_vision(HIR"$N���֦׳Q���l�s���į}�A�ˤf�@�ɦ�y����...!\n"NOR,victim);
  victim->apply_condition("blooding", victim->query_condition("blooding")+3);
  return;
}
