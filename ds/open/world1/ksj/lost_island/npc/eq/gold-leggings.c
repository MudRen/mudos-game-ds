#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
  set_name(HIY"�����H��"NOR,({"gold leggings","leggings"}));
  set("long", @LONG
�ª��s�����H�ҡA�u�O�ȿ��Ӥw�A�õL��ڪ����@�O�C
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",19200);
    set("material","gold");
  }
  set("armor_prop/armor",9);
  setup();
}
