inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�p����",({"tedder fish","fish"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@���Q�Ϊ��Q�����ꪺ�p�����C\n");
    set("unit", "��");
    set("value",420);
    set("heal_hp",70);
    set("food_remaining",4);
  }
  setup();
  set("no_auc",1);
}



