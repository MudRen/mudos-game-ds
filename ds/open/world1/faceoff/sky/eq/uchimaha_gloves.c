#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
  set_name(CYN"禰影璧"NOR ,({ "uchimaha gloves","gloves" }) );
  set("long","這是一個會吞噬光線的手套，看起來不是塵士之物。");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("volume",2);
    set("unit", "雙");
    set("value",2000);
  }
  set("armor_prop/armor",13);
  set("beast_armor_prop/armor",7);
  set("limit_con",12);
  setup();
}

