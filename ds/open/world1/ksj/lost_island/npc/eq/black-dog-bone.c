#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create()
{
  set_name(HIW""BLK"�~��������"NOR, ({ "black-dog bone","bone" }) );
  set("long",@LONG
�v�������e�A�e�{���ª���A�A�j�j�i�H��@�Z���ϥΡA���G���S�O
���\��C
LONG);
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("value",0);
    set("material", "stone");
    set("volume",5);
    set("no_repair",1);
  }
  set("limit_lv",40);
  set("weapon_prop/wit",-1);
  set("weapon_prop/sou",-1);
  init_fist(25,TWO_HANDED);
  set("beast_weapon_prop/str", 50);
  setup();
  set("wield_msg","$N�N$n�a�ۦy�����Y���˦b�k��A����h���ۦ��ۧQ�����}���C\n"NOR);
  set("unwield_msg","$N�N$n���^��y�W�����n���C\n");
}

void attack(object me,object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  COMBAT_D->do_attack(me, victim, this_object(), 4);
  COMBAT_D->report_statue(victim);
  return;
}
