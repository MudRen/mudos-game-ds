inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�h������",({"liuye meat","meat"}));
  set_weight(400);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L���q�B�z���h�����סC\n");
    set("unit", "��");
    set("value",120);
    set("heal_mp",20);
    set("heal_hp",20);
    set("food_remaining",2);
  }
  setup();
  set("no_auc",1);
}







