#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIG"���G"NOR, ({ "wild fruit","fruit" }));
  set("long",
      "���ͪ��G��A�y�L�g���Фg�A�Y�_�ӱa�I�W�ߡC\n"
     );
  set_weight(400);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 10);
  set("food_remaining",2);
  set("heal_hp",30);  
  setup();
}