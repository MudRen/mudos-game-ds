inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�s���{", ({"Yaki onigiri","onigiri"}));
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�N���{������T���ΡA�]�J���z�A�K����a���ΡC\n");
    set("unit", "��");
    set("value", 10);  
    set("food_remaining",1);
    set("heal_hp",30);  
    set("heal_ap",15);  
  }
}


