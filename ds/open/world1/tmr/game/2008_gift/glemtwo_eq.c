#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
   set_name(HIR"愚人護腿"NOR,({ "fool leggings","leggings" }) );
  set("long",@LONG
這是一對護腿，是glemtwo在2008年「鼠來寶」活動中獲得的獎品。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "對");
    set("value", 100);
        set("wear_msg","$N穿上愚人護腿以後，似乎變笨了。"NOR);
        set("unequip_msg","$N脫下愚人護腿後，突然變的聰明了起來。\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }

