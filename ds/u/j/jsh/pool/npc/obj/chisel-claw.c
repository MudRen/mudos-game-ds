#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
  set_name(HIG"�����"NOR , ({ "biggest-chisel claw","claw" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�Ѳ����窺���l�A���w�p�K�A�����O�i�j�j�����ɡC\n");
    set("material", "gold");
    set("value",5000);
    set("weapon_prop/str",3);
    set("weapon_prop/dex",-1);  
  }
  init_fist(45);
  setup();
}


