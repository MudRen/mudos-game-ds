#include <weapon.h>
inherit WHIP;
void create()
{
  set_name("����@" , ({ "gin whip","whip" }) );
  set_weight(1750);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���H���K�V���һs�����@�l�C\n");
    set("material", "silver");
	set("value", 2300);
    set("weapon_prop/con",1);
  }
  init_whip(18);
  setup();
}

