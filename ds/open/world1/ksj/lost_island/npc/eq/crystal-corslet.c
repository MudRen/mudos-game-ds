#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIW"�������Z"NOR,({"crystal corslet","corslet"}));
  set("long", @LONG
��b�L�v�������s�������Z�A�D�`�Q���A���]�k���W�s�����@�O�A�O
�j�N�����]�k�v�һs�@���öQ����C
LONG
);
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",5);
    set("value",100000);
    set("material","stone");
  }
  set("armor_prop/armor",30);
  set("armor_prop/shield",40);
  set("armor_prop/int",2);
  set("armor_prop/con",3);
  setup();
}
