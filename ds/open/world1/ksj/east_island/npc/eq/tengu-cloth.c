#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name("�Ѫ��˧�",({ "tengu cloth","cloth" }) );
  set("long",@LONG
�Ѫ���۪��ǲ��A�ˡA���I���M�A���h�[�F�\�h�_�Ǫ������A���ƥ�
���]�O�\�h����V�����C
LONG);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",1000);
    set("material", "silk");
  }
  set("armor_prop/shield",5);
  set("armor_prop/armor", 7);
  setup();
}
