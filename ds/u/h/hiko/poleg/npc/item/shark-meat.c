inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�T����",({"shark meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L²��B�z���T���סA��i�����C\n");
    set("unit", "��");
    set("value",160);
    set("heal_ap",4);
    set("heal_hp",24);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






