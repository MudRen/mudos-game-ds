#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIR"聖誕"HIW"長靴"NOR, ({ "christmas boots","boots" }) );
  set("long",@long
這是一雙紅滋滋的長靴，靴頭上還沾有幾片雪花還沒有融化，你拿在
手上把玩不停，越看越是喜愛，越看越是想要穿上它。
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "雙");
    set("material","fur");
    set("value",1);
  }
  set("armor_prop/armor", 1);
  setup();
}

