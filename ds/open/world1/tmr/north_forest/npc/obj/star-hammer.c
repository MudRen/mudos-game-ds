#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIC"�y�P��"NOR,({"star hammer","hammer"}) );
  set("long","�@�K���j���y�P��A�ѥ��K���y�Ӧ��A�W���G���y�U���K��A�g�ۤ��֦���H�סC\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 3);
    set("value", 2400);
  }
  init_hammer(55);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 2);
  setup();        
}
