inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�s����",({"rice ball","ball"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",300);
    set("heal_hp",50);
    set("food_remaining",6);
  }
  setup();
  call_out("it_name",1);
}

void it_name()
{
  string *str = ({
"�­J�Ԥ��h",
"���W�N��",
"Ī���Ⱳ",
"�G�ŭ���",
"�Z�N��",
"�����",
"�@����",
"�j����",
"�I�h�s",
"�C��",
"���P",
"�{��",
"�D��",
"�ǲ�"
});
  if(!this_object()) return;
  set("long", "�s���ΡA" +str[random(14)]+ "�f���C\n\n\t\t-�� 7-11 �u�n-");
  return;
}
