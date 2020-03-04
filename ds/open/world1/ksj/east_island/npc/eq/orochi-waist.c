#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(GRN"八歧"HIW"鱗帶"NOR,({"orochi waist","waist"}));
  set("long", @LONG
八歧大蛇的鱗皮製成的腰帶，堅韌耐用刀槍不入。
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",2);
    set("value",5000);
    set("material","fur");
  }
  set("limit_lv",35);
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/str",1);
  set("armor_prop/con",2);
  set("armor_prop/int",1);
  setup();
}
