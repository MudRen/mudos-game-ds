inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("���x", ({ "sea urchin","urchin" }));
  set("long",@LONG
�@�ӷs�A�ά������x�A���q�������W�ӡC
LONG);
  set_weight(200);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
  }
  set("value", 200);
  set("food_remaining",2);
  set("heal_hp",50);  
  setup();
}
