inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("甘紫菜",({"red laver","laver"}));
  set_weight(120);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一盤看起來料理仔細的甘紫菜。\n");
    set("unit", "盤");
    set("value",350);
    set("heal_hp",20);
    set("heal_ap",15);
    set("heal_mp",15);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}



