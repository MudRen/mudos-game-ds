#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(GRN"���Y�D�ܭ�"NOR,({ "five snakes surcoat","surcoat" }) );
  set("long",@LONG
�D�ֻs�����ܭ��A�ܭ��U�\�ٱa�ۤ��Ӥ��P�C�⪺�D�Y�C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1300);
    set("material", "fur");
    set("unit", "��" );
    set("value",3000);
    set("volume",2);
    set("wear_msg",
        HIG"$N�ܤW�@�i�a���ӳD�Y���D�֡A����·¶�ۨ���C\n"NOR);
  }
  set("limit_lv",30);
  set("armor_prop/armor", 12);
  set("armor_prop/shield", 13);
  set("armor_prop/con", 2);
  set("armor_prop/wit", 1);
  set("armor_prop/bio", -1);
  setup();
}
