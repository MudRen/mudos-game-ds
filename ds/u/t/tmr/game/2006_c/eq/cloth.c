#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
  set_name(HIR"聖誕"HIW"大衣"NOR ,({ "christmas cloth","cloth" }) );
  set("long",@LONG
這是一件大尺吋的大衣，紅通通的顯得非常喜氣。你
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",1);
    set("unit", "件");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

