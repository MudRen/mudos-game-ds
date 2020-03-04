#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIM"七貓尾"NOR ,({ "cat tail waist","waist" }) );
  set("long",@LONG
七條各有邪力的貓尾絞纏而成的腰帶，每條貓尾都異常地長。
LONG);
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "條");
    set("value",4000);
  }
  set("limit_lv",35);
  set("limit_int",45);
  set("armor_prop/armor",5);
  set("armor_prop/shield",10);
  set("armor_prop/con",2);
  set("armor_prop/int",1); 
  set("armor_prop/wit",1);
  set("armor_prop/bar",-1);
  set("armor_prop/bio",-1);
  setup();
}
