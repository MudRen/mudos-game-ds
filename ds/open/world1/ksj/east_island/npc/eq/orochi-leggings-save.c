#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
   set_name(HIR"真"HIW"•"NOR"八岐"HIG"鱗脛"NOR ,({ "orochi leggings","leggings"}) );
  set("long",@LONG
八岐大蛇的兩片腹鱗製成的一對脛甲，銀白色的表面上散發綠色的邪
氣，不但質輕堅固，還附有些許的大蛇邪力。
LONG);
  set_weight(2400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("material", "leather");
    set("unit", "對");
    set("value",9000);
    set("volume",3);
  }
  set("limit_lv",30);
  set("armor_prop/armor",18);
  set("armor_prop/shield",18);
  setup();
}

int query_autoload() { return 1; }
