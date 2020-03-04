#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
 set_name(HIR"霸"HIW"•"NOR"八歧鱗甲"NOR ,({ "orochi plate","plate" }));
  set("long",@LONG
八岐大蛇的鱗皮製成的皮甲，不但刀槍難入，更有八岐大蛇強大的邪
力。
LONG);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "件");
    set("value",15000);
  }
  set("limit_con",50);
  set("limit_lv",40);
  set("armor_prop/armor",60);
  set("armor_prop/shield",40);
  set("armor_prop/bar",1);
  set("armor_prop/sou",-1);
  set("armor_prop/tec",-1);
  setup();
}

int query_autoload() { return 1; }
