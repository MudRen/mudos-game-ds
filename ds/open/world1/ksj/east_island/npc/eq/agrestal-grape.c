#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(MAG"������"NOR, ({ "agrestal grape","grape" }));
  set("long",
      "���o�p�p������A�Ļ����ߪ��A�Y�_�Ө��D�٥i�H�C\n"
     );
  set_weight(400);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 100);
  set("food_remaining",1);
  set("heal_hp",50);  
  set("heal_ap",20);  
  setup();
}
