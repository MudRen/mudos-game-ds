#include <armor.h>
#include <ansi2.h>
inherit CLOTH;

void create()
{
  set_name(HBK"黑色長袍"NOR ,({ "black-magic robe","robe" }) );
  set("long",@LONG
一件黑色的長袍，外表有些破爛，是用魔法製造的絲線所織成的，是
法師術士所愛用的裝備，有不錯的魔法防禦力。
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",3000);
    set("material", "fur");
    set("limit_lv",25);
  } 
    set("armor_prop/shield",13);
    set("armor_prop/str",-1);
    set("armor_prop/int",3);
    set("armor_prop/armor",4);
    set("beast_armor_prop/armor",20);
    set("beast_armor_prop/shield",20);
    set("beast_armor_prop/wit",1);
  setup();
}

