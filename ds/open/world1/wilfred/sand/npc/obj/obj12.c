// �~�Ӱ�H�g�h�Z����, �@�w�Y�칡���믫, �F���Y, �ܫK�y, �a���X��
// ����������]�w�Ȫ��T�����@
// wilfred@DS

inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name("�����L",({"cheap leg","leg"}));
  set_weight(90);
  if( clonep() )
   set_default_object(__FILE__);
  else
  {
    set("long", "�@�����Q�Q�B�����˪������L�C\n");
    set("unit", "��");
    set("value",20);
    set("heal_hp",15);
    set("food_remaining",2);
  }
  setup();
  set("no_auc",1);
}
