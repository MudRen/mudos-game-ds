#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name("�K�s�����Z",({"iron chain armor","armor"}));
  set("long", @LONG
�@���K�s���ԥҡA�N���m�O�Ө��A�o���Z�ҥi���O�L�i�D�窺�A
�ߤ@�����I�N�O�L��I���A�ɭP��ʤ��K�E
LONG);
  set_weight(15000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",8000);
    set("material","iron");
  }
  set("limit_lv",35);
  set("armor_prop/armor",60);
  set("armor_prop/dex",-3);
  setup();
}


