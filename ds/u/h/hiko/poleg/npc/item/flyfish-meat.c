inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("������",({"flyfish meat","meat"}));
  set_weight(400);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L��ӳB�z�������סC\n");
    set("unit", "��");
    set("value",220);
    set("heal_ap",25);
    set("heal_hp",15);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}







