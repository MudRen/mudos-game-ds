#include <armor.h>
#include <ansi.h>
inherit HEAD;


void create()
{
  set_name(HIR"聖誕"HIW"帽"NOR,({ "inverse-horn hat","hat" }) );
  set("long",@LONG
這是一頂大紅的尖帽子，上頭還沾有一些雪絲，顯得非常喜氣洋洋，
你越看越是喜歡這頂聖誕帽，超想戴上它。
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(100);
    set("unit", "頂");
    set("value",1);
    set("volume",1);
  }
  set("armor_prop/armor", 1);
   setup();
}

