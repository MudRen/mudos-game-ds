inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("������",({"grig meat","meat"}));
  set_weight(200);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���g�L�������J�ӳB�z���סA��i���Ȱ��C\n");
    set("unit", "��");
    set("value",290);
    set("heal_ap",28);
    set("heal_hp",28);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}





