#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("灰狼骨",({"wolf bone","bone"}));
        set_weight(500);
                set("value", 100);
                set("unit","塊");
                set("long",@LONG
這是一塊灰狼的遺骸，一時也不知道是那塊部位。
LONG
);
setup();
}
