#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
object me=this_player();

void create()
{
  set_name(HIR"���T�ʦ�"NOR,({ "fire-wolf surcoat","surcoat" }) );
  set("long","���㪺���T��ֻs�����ʦ�A�۷�}�֬öQ�A�N�_�ӬX�n�ŷx�C\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1500);
    set("material", "leather");
    set("unit", "��" );
    set("value",10000);
    set("volume",3);
    set("wear_msg",
        "$N�N�@�������$n�ܦb�ӤW�A�������O�_�������ܦ���աC\n"NOR);
  }
  set("armor_prop/armor", 14);
  set("armor_prop/shield", 15);
  set("armor_prop/int", 1);
  set("armor_prop/str", 1);
  set("armor_prop/dex", 2);
//  set("armor_prop/name", ({ "��ն�����"+me->query("name") }) );
  setup();
}
