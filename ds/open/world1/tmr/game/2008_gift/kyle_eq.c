#include <ansi2.h>
#include <armor.h>
inherit LEGGING;

void create()
{
   set_name(HIR"血"HIW"牙"NOR,({ "bloodtooth" }) );
  set("long",@LONG
這雙如血一般顏色的脛甲，是由一種罕見的深紅色礦石所打造而成，
這種礦石長年的沉睡在地底之下，吸收了血脈地氣才會呈現這種特殊
的血色。
這件裝備為kyle在2008年「鼠來寶」活動中獲得的特別獎獎品。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "件");
    set("value", 100);
        set("wear_msg", HIR"當$N穿上血牙時，一絲紅色的血氣沿著筋脈遍佈全身"NOR);
        set("unequip_msg", WHT "在$N脫下血牙後，血脈中的紅線似乎也消逝而去。。\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",2);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}


int query_autoload() { return 1; }

