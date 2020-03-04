#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(YEL"千年龍鬚"NOR ,({ "dragon beard","beard" }) );
  set("long","一條十來尺長的龍鬚，色作焦黃，摻雜些許\白色淡斑。");
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "條");
    set("value",3800);
  }
  set("limit_int",10);
  set("armor_prop/armor",4);
  set("armor_prop/dex",3);
  set("armor_prop/dodge",5); //5->3 by ksj
  set("beast_armor_prop/armor",4);
  set("beast_armor_prop/dex",3);
  set("beast_armor_prop/dodge",5); //5->10 by ksj
  setup();
}
