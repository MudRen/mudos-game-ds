#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(CYN"鐵龍刺甲"NOR ,({ "shell-dragon armor","armor" }) );
  set("long",@LONG
    這是角脊鐵龍身上的皮甲，皮甲上有大大小小許多的硬刺，穿
起來則是相當厚重，提攻非常好的防護力，以及一些傷害力。
LONG
);
  set_weight(10000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",6);
    set("unit", "件");
    set("value",12000);
  }
  set("limit_lv",30);
  set("armor_prop/armor",43);
  set("armor_prop/damage",3);
  set("armor_prop/con",3);
  set("armor_prop/str",1);
  set("armor_prop/dex",-3);
  set("armor_prop/dodge",-15);
  setup();
}
