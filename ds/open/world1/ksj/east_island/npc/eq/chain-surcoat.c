#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(CYN"�K��潴"NOR,({ "chain surcoat","surcoat" }) );
  set("long",@LONG
�β��K��s�����潴�A���M���@�O�ܦn���O�o�ܲ­��C
LONG);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(3500);
    set("material", "steel");
    set("unit", "��" );
    set("value",3000);
    set("volume",4);
    set("wear_msg",
        "$N�N�@��I����$n�ܦb�ӤW�A�K��ذճذէ@�T�C\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/dodge", -5);
  set("armor_prop/dex", -2);
  setup();
}
