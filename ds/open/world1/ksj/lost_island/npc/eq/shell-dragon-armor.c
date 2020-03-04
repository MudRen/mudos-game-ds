#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(CYN"�K�s���"NOR ,({ "shell-dragon armor","armor" }) );
  set("long",@LONG
    �o�O�����K�s���W���֥ҡA�֥ҤW���j�j�p�p�\�h���w��A��
�_�ӫh�O�۷�p���A����D�`�n�����@�O�A�H�Τ@�Ƕˮ`�O�C
LONG
);
  set_weight(10000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",6);
    set("unit", "��");
    set("value",12000);
  }
  set("limit_lv",30);
  set("armor_prop/armor",43);
  set("armor_prop/damage",3);
  set("armor_prop/con",3);
  set("armor_prop/str",1);
  set("armor_prop/dex",-3);
  set("armor_prop/dodge",-15);
  setup();
}
