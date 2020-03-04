#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(GRN"�|�Y�D�ܭ�"NOR,({ "four snakes surcoat","surcoat" }) );
  set("long",@LONG
�D�ֻs�����ܭ��A�ܭ��U�\�ٱa�ۥ|�Ӥ��P�C�⪺�D�Y�C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1100);
    set("material", "fur");
    set("unit", "��" );
    set("value",2000);
    set("volume",1);
    set("wear_msg",
        "$N�ܤW�@�i�a�|�ӳD�Y���D�֡C\n"NOR);
  }
  set("limit_lv",25);
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 8);
  set("armor_prop/str", 1);
  set("armor_prop/con", 1);
  set("armor_prop/int", 1);
  set("armor_prop/dex", 1);
  set("armor_prop/sou", -1);
  setup();
}
