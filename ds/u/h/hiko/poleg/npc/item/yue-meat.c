inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("魷魚肉",({"yue meat","meat"}));
  set_weight(400);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一塊經過加工處理的魷魚肉。\n");
    set("unit", "塊");
    set("value",190);
    set("heal_mp",31);
    set("heal_hp",10);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






