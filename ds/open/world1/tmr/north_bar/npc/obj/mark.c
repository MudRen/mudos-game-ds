#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("印記",({"mayor mark","mark"}));
        set_weight(300);
                set("value",1000);
                set("unit","個");
                set("long",@LONG
一個很特別的印記，但上面都是灰塵，似乎很久沒有了。
LONG);
setup();
}
