#include <ansi.h>
#include <armor.h>
inherit BOOTS; 
void create()
{
  set_name(HIW"奔雲"NOR,({"cloud boots","boots"}));
  set("long", @LONG  
這件護具是索貝克年輕時的傑作•據說不論是誰，只要穿上了它
皆可一日千里•輕功好些的，甚至還可以踏水、奔雲•
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "雙");
    set("volume",2);
    set("value",3600);
    set("material","fur");
  }
  set("limit_lv",43);
  set("armor_prop/armor",10); 
  set("armor_prop/shield",4);
  set("armor_prop/dodge",15);
  set("armor_prop/dex",3);
  set("armor_prop/int",2);
  setup();
}

