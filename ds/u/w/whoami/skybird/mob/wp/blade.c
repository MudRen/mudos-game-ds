#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "軍刀" , ({ "military blade","blade" }) );
  set_weight(2600);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "這是由精鋼製成的軍刀，乃是有軍中統一配給。\n");
    set("material", "iron");
    set("value",1800);
    set("volume",1);
  }
  init_blade(37);
  setup();
}
