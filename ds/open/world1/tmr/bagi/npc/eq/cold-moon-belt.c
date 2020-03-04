#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
  set_name( HIC"冷月獸皮帶" NOR,({"cold moon belt","belt"}));
  set("long", @LONG
這是一條用冷月獸皮所製成的皮帶，上頭還留著銀白色的絨毛。
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",3);
    set("value", 4000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",10 ); 
  set("armor_prop/shield",10 );
  set("armor_prop/con", 2);
  set("armor_prop/damage", 5);
  setup();
}
