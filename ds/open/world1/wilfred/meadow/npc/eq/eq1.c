#include <armor.h>
inherit SHIELD;
void create()
{
  set_name("�����ì�" ,({ "cow shield","shield" }) );
  set("long",@LONG
�o�O���դh�������L���h���R���A�ӻs�@���˹��~�A�ޭ�
�D��O�H�Ѿ��å[�u�s���A�p��@�ΡA�������åi�l��
�j�����������C�b�ު�������X�@���¦�����A�����@��
�A���G�O[�l�Ѭ���]�o���~�ت������C��y�ݸg�L���i��
�ܱo�y�U�A�W�K�F��Ωʽ�C
LONG
);
  set_weight(3500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "��");
    set("value",2000);
  }
  set("armor_prop/con",1);
  set("armor_prop/armor",14);
  set("armor_prop/damage",6);
  setup();
}
