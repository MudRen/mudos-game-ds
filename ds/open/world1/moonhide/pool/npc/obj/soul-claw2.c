#include <ansi.h>
#include <weapon.h> 
inherit FIST;

void create()
{
  set_name(HIB"�l��"NOR , ({ "following-soul[claw]","claw","soul" }) );
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�D�O�W�K�y�l�����z�ҥ��y���A�E���Ƥd�C��A�t�X\n"
                "�@�~�̪��Ҧ�����ɶ��A���y�X�����ت��y�l��z�C\n");
    set("material", "gold");
    set("value",6000);
  }
  set("weapon_prop/str",1);
  set("weapon_prop/int",-1);   
  init_fist(44);
  setup();
} 
