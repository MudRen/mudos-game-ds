inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("��س���",({"sandling meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L²��B�z����س��סC\n");
    set("unit", "��");
    set("value",145);
    set("heal_ap",16);
    set("heal_hp",16);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






