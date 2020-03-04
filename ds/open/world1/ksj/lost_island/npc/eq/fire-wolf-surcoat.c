#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
object me=this_player();

void create()
{
  set_name(HIR"火狼裘衣"NOR,({ "fire-wolf surcoat","surcoat" }) );
  set("long","完整的火狼毛皮製成的裘衣，相當稀少珍貴，摸起來柔軟溫暖。\n");
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set_weight(1500);
    set("material", "leather");
    set("unit", "件" );
    set("value",10000);
    set("volume",3);
    set("wear_msg",
        "$N將一件火紅的$n披在肩上，全身像是冒火似的很有氣勢。\n"NOR);
  }
  set("armor_prop/armor", 14);
  set("armor_prop/shield", 15);
  set("armor_prop/int", 1);
  set("armor_prop/str", 1);
  set("armor_prop/dex", 2);
//  set("armor_prop/name", ({ "氣勢雄雄的"+me->query("name") }) );
  setup();
}
