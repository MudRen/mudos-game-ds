#include <ansi.h>
#include <armor.h>
inherit WAIST;
void create()
{
  set_name(GRN"青鱗束帶"NOR ,({ "green-snake waist","waist" }) );
  set("long","一條青色鱗皮，表面暗淡粗糙，但是堅硬無比。");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "條");
    set("value",7000);
  }
  set("limit_str",15);
  set("armor_prop/armor",9);
  set("armor_prop/dex",-1);
  set("armor_prop/con",1);
  set("armor_prop/str",2);
  setup();
}
