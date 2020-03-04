#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
   set_name(HIW"乃窮冰甲"NOR ,({ "illimitable armor","armor" }) );
  set("long",@LONG
乃窮冰甲是白狼神所穿的戰甲，使用「乃窮玄冰」的冰晶所製成，其
剛似鐵，具有極高的防禦力，也能有效地抵擋法術的傷害。當今世上
並沒有任何工藝可以打造出這種戰甲。
LONG);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",4);
    set("unit", "件");
    set("value",15000);
  }
  set("limit_lv", 40);
  set("armor_prop/armor", 45);
  set("armor_prop/shield",45);
  set("armor_prop/int", 1);
  set("armor_prop/con", 1);
  setup();
}

