#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
  set_name("�����H��" ,({ "toad leggings","leggings"}) );
  set("long",@LONG
�o�O�ʦ~�r����������W���o���H�ҡA���⪺������������H�ҡC
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("material", "leather");
    set("unit", "��");
    set("value", 1200);
    set("volume", 2);
  }
  set("limit_lv",30);
  set("armor_prop/armor",5);
  set("armor_prop/shield", 5);

  set("armor_prop/int", 1);
  setup();
}

