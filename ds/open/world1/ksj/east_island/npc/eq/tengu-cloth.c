#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name("天狗裝束",({ "tengu cloth","cloth" }) );
  set("long",@LONG
天狗穿著的怪異服裝，有點像和服但多加了許多奇怪的飾物，布料本
身也是許多材質混成的。
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value",1000);
    set("material", "silk");
  }
  set("armor_prop/shield",5);
  set("armor_prop/armor", 7);
  setup();
}
