#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIR"��y�P��"NOR,({"blood-star hammer","hammer"}) );
  set("long","�@�K���j����y�P��A�ѥͬ��K���y�Ӧ��A�W���G���y�U���K��A�g�ۤ��֦���H�סC\n");
  set_weight(35000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 4);
    set("value", 8000);
  }
  init_hammer(60);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 3);
  setup();        
}
