inherit ITEM;
void create()
{
  set_name("�K����",({"eight mirror","mirror"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
�@�����G���ƪ���l�A�W�Y�K�Ӥ��g�F
�y ���B�S�B���B��B�[�B�_�B���B�I �z
�K�ӹ�������r�C
LONG
);
    set("value",1000);
  }
  setup();
}
