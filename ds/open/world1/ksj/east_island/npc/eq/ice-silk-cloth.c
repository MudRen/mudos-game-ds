#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
  set_name(HIW"�B������"NOR ,({ "ice-silk cloth","cloth" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",@LONG
�@�󳷥ժ���A�A�N�_�ӦB�B�D�D���A�����D�O�������s�����C
LONG);
    set("female_only",1);
    set("unit", "��");
    set("value",3500);
    set("material", "silk");
  }
      set("armor_prop/shield",20);
      set("armor_prop/int",3);
     set("armor_prop/armor", 5);
  setup();
}
