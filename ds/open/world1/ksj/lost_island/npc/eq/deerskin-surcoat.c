#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
  set_name(HIC"���֩ܭ�"NOR,({ "deerskin surcoat","surcoat" }) );
  set("long","�������ֻs�����ܭ��A�۷���R�����m��O���ΡC\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1100);
    set("material", "leather");
    set("unit", "��" );
    set("value",6000);
    set("volume",2);
    set("wear_msg",
        "$N�N�@����Ū�$n�ܦb�ӤW�A�����y�ɪi���{�{�C\n"NOR);
  }
  set("armor_prop/armor", 5);
  set("armor_prop/shield", 5);
  set("armor_prop/dodge", 8);
  set("armor_prop/dex", 2);
  setup();
}
