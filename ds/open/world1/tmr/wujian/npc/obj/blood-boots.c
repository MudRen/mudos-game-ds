#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIR"�夣�g"NOR, ({ "blood-no-touch boots","boots" }) );
  set("long",@long
�夣�g�O�@���H���������ҽs�����u�A�~�֥ѩ��W�h�S��
�����Ī��A�i�F��w�夣�g�A�t�~��۰_�Ӭ۷��K�F���C
long);      
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","gold");
    set("value",2500);
  }
  set("armor_prop/dodge",10);
  set("armor_prop/str",1);
  set("armor_prop/con",1);
  set("armor_prop/armor", 5);
  setup();
}

