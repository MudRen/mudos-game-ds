#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIW"�ȥҸy�a"NOR ,({ "silver waist","waist" }) );
  set("long",@LONG
�H�ջȤ��h�h�|�X�걵�Ӧ����y�a�A�㦳���Ϊ����m��O�C
LONG);
  set_weight(2300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",2);
    set("unit", "��");
    set("value",4000);
  }
  set("limit_con",30);
  set("armor_prop/armor",10);
  set("armor_prop/dodge",-3);
  setup();
}
