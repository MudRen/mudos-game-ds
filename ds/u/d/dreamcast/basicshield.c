#include <armor.h>
inherit SHIELD;
#include <ansi.h>
void create()
{
  set_name(MAG"��"HIR"��"HIC"��" NOR,({ "Dreamcast shield","shield" }) );
  set("long",@LONG
�o�O�Ψ���"�D�]"����@������
LONG
);
  set_weight(3500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",1);
    set("unit", "��");
    set("value",2000);
  }
  setup();
}



