inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("��س���",({"sifu meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L²��B�z����س��סC\n");
    set("unit", "��");
    set("value",100);
    set("heal_ap",12);
    set("heal_hp",12);
    set("food_remaining",2);
  }
  setup();
  set("no_auc",1);
}





