#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
   set_name(HIR"�M�H�@�L"NOR,({ "fool leggings","leggings" }) );
  set("long",@LONG
�o�O�@���@�L�A�Oglemtwo�b2008�~�u�����_�v���ʤ���o�����~�C
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "��");
    set("value", 100);
        set("wear_msg","$N��W�M�H�@�L�H��A���G�ܲ¤F�C"NOR);
        set("unequip_msg","$N��U�M�H�@�L��A��M�ܪ��o���F�_�ӡC\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }

