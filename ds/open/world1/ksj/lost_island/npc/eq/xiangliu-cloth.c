#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIG"�۬h���"NOR ,({ "xiangliu cloth","cloth" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
���~  �۬h����ֻs�����֦�A���m�O���M���q���㦳�@�ǧ��O
�A������a���@�I�{���C
LONG
);
    set("unit", "��");
    set("value",8000);
    set("material", "fur");
    set("armor_prop/shield",15);
    set("armor_prop/str",-2);
    set("armor_prop/con",1);
    set("armor_prop/dex",2);
    set("armor_prop/armor", 10);
  }
  setup();
}
