#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
   set_name(HIW"乃窮冰盔"NOR ,({ "illimitable helmet","helmet" }) );
  set("long",@LONG
乃窮冰盔是白狼神所穿的頭盔，使用「乃窮玄冰」的冰晶所製成，其
剛似鐵，具有極高的防禦力，也能有效地抵擋法術的傷害。
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
  set("armor_prop/armor", 12);
  set("armor_prop/shield",12);
  set("armor_prop/int", 1);
  set("armor_prop/con", 1);
  setup();
}

