#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(GRN"八歧"HIY"鱗甲"NOR ,({ "orochi armor","armor" }) );
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
  set("armor_prop/damage",3);
  set("armor_prop/con",3);
  set("armor_prop/bio",-1);
  set("armor_prop/bar",-1);
  set("armor_prop/sou",1);
  set("armor_prop/wit",1);
  set("armor_prop/dex",-1);
  set("armor_prop/dodge",-5);
  setup();
}
