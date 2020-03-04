#include <ansi.h>
#include <armor.h>
inherit ANKLE;

void create()
{
  set_name(HIY"奔月"HIW"腳鍊"NOR ,({ "run-moon ankle","ankle" }) );
  set("long","這是一條質地怪異的腳鍊，穿在腳踝上，好像還滿帥氣的。\n【2006中秋節奔月活動-得獎獎品】");
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "條");
    set("value",0);
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);

  }
  set("armor_prop/armor",5);
  set("armor_prop/shield",5);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/int",1);
  set("armor_prop/dex",1);
   set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


