// �~�Ӱ�H�g�h�Z����, �@�w�Y�칡���믫, �F���Y, �ܫK�y, �a���X��
// ����������]�w�Ȫ��T�����@
// wilfred@DS

inherit ITEM;
inherit F_WATER;
void create()
{
  set_name("�C�D��", ({ "cheap soup","soup" }) );
  set_weight(50);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�J�H�զ⪺�M���A���Y�Ƶ۴X���p�C�D�A�ܤF�j������C\n");
    set("unit","�J");
    set("value",50);
    set("heal_ap",30);
    set("water_remaining",2);
  }
  setup();
  set("no_auc",1);
}
