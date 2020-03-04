#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIM"�C�ߧ�"NOR ,({ "cat tail waist","waist" }) );
  set("long",@LONG
�C���U�����O���ߧ�����Ӧ����y�a�A�C���ߧ������`�a���C
LONG);
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",4000);
  }
  set("limit_lv",35);
  set("limit_int",45);
  set("armor_prop/armor",5);
  set("armor_prop/shield",10);
  set("armor_prop/con",2);
  set("armor_prop/int",1); 
  set("armor_prop/wit",1);
  set("armor_prop/bar",-1);
  set("armor_prop/bio",-1);
  setup();
}
