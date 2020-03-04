#include <weapon.h>
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
  set_name(HIR"�ٳD�Y"NOR, ({ "viper-killed katana","katana" }) );
  set("long",@long
�����K�[�j�D��q����ڨ��X���ӤM�A�b����������A�b����������
�B���i��A�M���J���X�������ϡA�M�`���զ�X�B�`�A�M���a���H
�H������A�A�i��O�[�óD�����G�C
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",12000);
    set("volume",3);
  }
  set("rigidity",1000);
  set("limit_skill",40);
  set("limit_lv",25);
  set("weapon_prop/str",2);
  set("weapon_prop/bio",1);
  set("weapon_prop/wit",-1);
  init_blade(60);
  setup();
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(8)) return; 
  message_vision(HIR"$N���۱ٳD�Y���k���M�O�q�ɼW..\n"NOR,me);
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  victim->add_busy(1);
  return;
}
