#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIR"�t��"HIW"�y�a"NOR ,({ "christmas waist","waist" }) );
  set("long",@LONG
�o�O�@��������y�a�A�A�`�N��W�������l���M�w�g����̥~�@�ӤF�A
�ݼˤl�o�O���j�y�򪺭D�l�諸�A�������p��A�A�N�O�Q�n��W���C
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "fur");
    set("volume",2);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/armor",1);
  setup();
}

