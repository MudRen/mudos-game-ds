#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
  set_name(HIW"���̤���"NOR,({"intellect staff","staff"}));
  set("long",@LONG
�j�N�����H��������A���M�ݰ_�Ӳ@���_���A�o���W�j���O�P�N�O��
�ĥΡC
LONG
);
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_int",50);
    set("unit", "��");        
    set("value",7000);
    set("volume",2);
    set("material","steel");       
  }        
  set("weapon_prop/wit",1);  
  set("weapon_prop/bar",-1);
  set("weapon_prop/int",3);
  init_staff(15);
  setup();
}
