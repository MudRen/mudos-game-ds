#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIC"�Q��"HIW"�B���u"NOR, ({ "kilin boots","boots" }) );
  set("long",@long
�@�����ժ����u�A�H�B�����s´�Ӧ��A�u�W�H�륩¸�u¸�W�@��²r
�������Q��A��۰_�Ӭ۷��K�F���C
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","gold");
    set("value",5000);
  }
  set("armor_prop/dodge",10);
  set("armor_prop/int",1);
  set("armor_prop/con",1);
  set("armor_prop/dex",2);
  set("armor_prop/armor", 15);
  setup();
}
