#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
  set_name(HIR"�t��"HIW"�j��"NOR ,({ "christmas cloth","cloth" }) );
  set("long",@LONG
�o�O�@��j�ئT���j��A���q�q����o�D�`�߮�C�A
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",1);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

