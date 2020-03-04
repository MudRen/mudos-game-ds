#include <ansi.h>
#include <weapon.h>
#include "/open/world1/wilfred/sand/npc/wp/std_fist.c"

void create()
{
  set_name(CYN"屍爪"NOR, ({ "corpse fist","fist" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "隻");
    set("long",
        "當人含怨而死時，在陰氣的影響下，口會長出尖牙，手會長出爪，\n"        "因此便就名為屍爪，爪上有著強大的怨氣。\n"
        );
    set("material", "iron");
    set("value",6500);
    set("volume",4);
    set("limit_int",18);
    set("limit_str",30);
  }  
  set("weapon_prop/int",1);
  set("weapon_prop/hit",10);
  init_fist(60);
  setup();
}



