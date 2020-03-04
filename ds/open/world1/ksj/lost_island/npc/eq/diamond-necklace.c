#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIW"鑽石項鏈"NOR ,({ "diamond necklace","necklace" }) );
  set("long",@LONG
一串閃耀著璀燦光芒的項鏈，白金製成的項鏈上掛著一顆大鑽石，價
值非凡。
LONG);
  set_weight(700);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "串");
    set("value",180000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
