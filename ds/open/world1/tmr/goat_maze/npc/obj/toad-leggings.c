#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
  set_name("蟾蜍脛甲" ,({ "toad leggings","leggings"}) );
  set("long",@LONG
這是百年毒物蟾蜍王身上取得的脛甲，紅色的條紋爬滿整對脛甲。
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("material", "leather");
    set("unit", "對");
    set("value", 1200);
    set("volume", 2);
  }
  set("limit_lv",30);
  set("armor_prop/armor",5);
  set("armor_prop/shield", 5);

  set("armor_prop/int", 1);
  setup();
}

