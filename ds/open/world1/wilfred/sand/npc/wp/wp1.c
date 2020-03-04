#include <ansi.h>
#include <weapon.h>
#include "std_fist.c"

void create()
{
  set_name(HIC"單虎"NOR, ({ "single fist","fist" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long", HIC"一般拳套皆成雙，唯此獨單，故名為單虎。\n此為武痴愛用之武器，裝備於右手單手便可使八極拳『猛虎硬爬山』，威力強大。\n"NOR);
    set("material", "iron");
    set("value",3000);
    set("volume",3);
    set("limit_int",15);
    set("weapon_prop/str",1);
  }
  init_fist(50);
  setup();
}
