#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"大浴池",({"big bath tub","tub"}));
        set("unit", "個");
        set("long",@LONG
這是一個十分璧麗輝煌的浴池，建造的十分亮麗，只見從浴池裡
冒出陣陣的煙霧，裡面還有一些人影，隱隱約約中，看到了滿足
的表情，看樣子進去(in)泡澡真的很舒服。
LONG
);
        set("value", 1);
      setup();
}

