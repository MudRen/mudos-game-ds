#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name(HIW"�B���y�P��"NOR,({"frost hammer","hammer"}) );
  set("long","�@�K���j���B���y�P��A�ѥժ����y�Ӧ��A�W���G���y�U���K��A�g�ۤ��֦���H�סC\n");
  set_weight(35000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 4);
    set("value", 12000);
  }
  init_hammer(65);
    set("material","gold");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 4);
  set("weapon_prop/attack", 5);
  setup();        
}
