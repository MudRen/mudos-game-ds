#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIC"感謝函"NOR, ({"thank note","thank","note"}));
    set("unit", "個");
set("lione1_join_quest",2);
    set("long",@LONG
    這是一封顏天風寫給顏士興的感謝信。
LONG);

    set_weight(1);
    set("value",1);
  setup();
}


