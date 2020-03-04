#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name("蠶絲手套",({"silk gloves","gloves"}));
  set("long", @LONG 
這是一件全用蠶絲織成的手套，質地非常的輕柔。
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",1);
    set("value", 3000);
    set("material","silk");
  }
  set("limit_lv",25);
  set("armor_prop/armor", 14);
  set("armor_prop/shield",10); 
  set("armor_prop/dex", 1);
  setup();
}

