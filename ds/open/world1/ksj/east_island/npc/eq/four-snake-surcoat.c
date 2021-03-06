#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(GRN"四頭蛇披風"NOR,({ "four snakes surcoat","surcoat" }) );
  set("long",@LONG
蛇皮製成的披風，披風下擺還帶著四個不同顏色的蛇頭。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1100);
    set("material", "fur");
    set("unit", "件" );
    set("value",2000);
    set("volume",1);
    set("wear_msg",
        "$N披上一張帶四個蛇頭的蛇皮。\n"NOR);
  }
  set("limit_lv",25);
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 8);
  set("armor_prop/str", 1);
  set("armor_prop/con", 1);
  set("armor_prop/int", 1);
  set("armor_prop/dex", 1);
  set("armor_prop/sou", -1);
  setup();
}
