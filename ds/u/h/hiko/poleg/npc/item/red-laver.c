inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�̵���",({"red laver","laver"}));
  set_weight(120);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@�L�ݰ_�ӮƲz�J�Ӫ��̵���C\n");
    set("unit", "�L");
    set("value",350);
    set("heal_hp",20);
    set("heal_ap",15);
    set("heal_mp",15);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}



