inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("海膽", ({ "sea urchin","urchin" }));
  set("long",@LONG
一個新鮮肥美的海膽，剛剛從海中撈上來。
LONG);
  set_weight(200);
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "個");
  }
  set("value", 200);
  set("food_remaining",2);
  set("heal_hp",50);  
  setup();
}
