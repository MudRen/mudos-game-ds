#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name( "��������" ,({ "cow armor","armor" }) );
  set("long",@LONG
�t�¥����ֻs�����֥ҡA�D�`����w�A���m�O���ΡA
�M�`�M�C�����y���ˮ`�C
LONG);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "iron");
    set("volume",4);
    set("unit", "��");
    set("value",20000);
  }
  set("armor_prop/armor", 30);
  set("armor_prop/shield", 30);
  setup();
}
