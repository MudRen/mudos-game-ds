inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�����L",({"cow leg","leg"}));
  set_weight(80);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@�����Q�Q�����˪������L,���H�ݤF�f�����y�C\n");
    set("unit", "��");
    set("value",70);
    set("heal_hp",30);
    set("food_remaining",3);
  }
  setup();
  set("no_auc",1);
}

