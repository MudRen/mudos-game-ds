#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
  set_name(HIR"�s���@��"NOR,({ "lobster wrists","wrists" }) );
  set("long",@LONG
�s���߻s�����@��A���m�O�S�����ݻs�~�n�A���O�ܻ��C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(500);
    set("material", "leather");
    set("unit", "��");
    set("value",500);
    set("volume",1);
  }
  set("armor_prop/armor", 4);
  set("armor_prop/dex",1);
  set("limit_con",10);
  setup();
}
