#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIW"獅吼腰帶"HIR"(S)"NOR ,({ "lion waist","waist" }) );
        set("long",@LONG
薄鐵片製成的腰帶，腰帶頭是一個銀製的獅頭。
LONG);
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "steel");
    set("volume",3);
    set("unit", "條");
    set("value",7000);
  }
  set("armor_prop/armor",8);
  setup();
}

int query_autoload() { return 1; }
