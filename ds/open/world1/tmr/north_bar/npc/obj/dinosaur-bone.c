#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("恐龍骨",({"dinosaur bone","bone"}));
        set_weight(500);
                set("value", 100);
                set("unit","塊");
                set("long",@LONG
這是一塊恐龍骨，恐龍應該是早就滅絕的生物，但是這塊恐龍骨
沒有半分石化的跡像，看起來應該是剛取得不久。
LONG);
setup();
}
