#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIW"��"HIC"��"HIW"�ݷ�"NOR ,({ "illusive-mirror corslet","corslet" }) );
  set("long",@LONG
�@���K�s�����Z�A�e���^�O�F���P���ת��Ȥ��A���ݪ��H�|���ͤ�ı
�A�X�{�\�h�ۼv�A�Y�����ٷ|���w�t�P�C
LONG);
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "steel");
    set("volume",4);
    set("unit", "��");
    set("value",6500);
  }
  set("armor_prop/armor",25);
  set("armor_prop/dodge",10);
  setup();
}
