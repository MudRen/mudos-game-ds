// �~�Ӱ�H�g�h�Z����, �@�w�Y�칡���믫, �F���Y, �ܫK�y, �a���X��
// ����������]�w�Ȫ��T�����@
// wilfred@DS

inherit ITEM;
inherit F_WATER;
void create()
{
  set_name("�����İs", ({ "cheap wine","wine" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�H���r����(��)�Ȫw�s���İs�A���^�_�믫���ܦn���\\�ġC\n");
    set("unit", "�~");
    set("value",40);
    set("heal_mp",30);
    set("water_remaining",2);
  }
  setup();
  set("no_auc",1);
}
