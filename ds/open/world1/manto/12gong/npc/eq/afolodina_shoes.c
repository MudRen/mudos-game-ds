#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
  set_name(HIY"�����֦�"NOR,({"afolodina shoes","shoes"}));
  set("long", @LONG  
�b�����ᦷ�t�W�_�R�������A��L�p�B��{�X�۵M�M�W�S�Aĭ�[��
�۵M�嶮�A�M�s���z�۵ج��A���갪�Q�o�L��ˤ��C�R���j���u��
�𮧪��c�l�A�t�W�X�M�������ᦷ�A�{�p���ܤ������D�A���իN�R
�A���������C 
LONG
);
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 2);
    set("material","leather");
    set("value", 7300);     
  }
  set("armor_prop/int", 2);
  set("armor_prop/str", 2);
  set("armor_prop/con", -2);
  set("armor_prop/sou", 1);
  set("armor_prop/wit", -1);
  set("armor_prop/armor", 11);
  set("armor_prop/shield", 26);
  setup();
}

