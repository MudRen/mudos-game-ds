#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
  set_name(HIM"�ڱ��@"NOR , ({ "dream love whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@�������⪺�@�l�C\n");
    set("material", "silver");
    set("value",4700);
    set("weapon_prop/str",1);
  }
  init_whip(30);
  setup();
}

