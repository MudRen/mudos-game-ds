#include <armor.h>
inherit PANTS;
#include <ansi.h>
void create()
{
  set_name(HIM"夢"HIC"幻"HIW"寬褲"NOR ,({ "Dreamcast pants","pants" }) );
  set("long","這是Dreamcast專屬的褲子，穿起來舒服又安全");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "條");
    set("value",1200);
  }
  set("armor_prop/armor",100);
  setup();
}


