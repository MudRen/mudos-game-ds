inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�{����",({"yue meat","meat"}));
  set_weight(400);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L�[�u�B�z���{���סC\n");
    set("unit", "��");
    set("value",190);
    set("heal_mp",31);
    set("heal_hp",10);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}






