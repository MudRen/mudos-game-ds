#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("恐龍皮",({"dinosaur skin","skin"}));
        set_weight(500);
                set("value", 100);
                set("unit","張");
                set("long",@LONG
這是一張恐龍皮，恐龍應該是早就滅絕的生物，但是這張恐龍皮
卻還非常柔軟，上頭還帶有點血跡。
LONG);
setup();
}
