inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("黃牛腿",({"cow leg","leg"}));
  set_weight(80);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "一隻香噴噴熱騰騰的黃牛腿,讓人看了口水直流。\n");
    set("unit", "隻");
    set("value",70);
    set("heal_hp",30);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}

