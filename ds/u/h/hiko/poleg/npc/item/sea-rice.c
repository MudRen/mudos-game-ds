inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("����",({"sea rice","rice"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@�]�w�g�B�z�n�����̤Q����K�C\n");
    set("unit", "�]");
    set("value",370);
    set("heal_ap",30);
    set("heal_hp",30);
    set("food_remaining",4);
  }
  setup();
  set("no_auc",1);
}



