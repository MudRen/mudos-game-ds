#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("判官筆",({"ruling pen-holder","pen","holder","pen-holder" }));

        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這是一支大毛筆，比尋常的毛筆大很多，他的筆毛有如鋼絲般鋒利，這就是俗稱的「判官筆」。\n");
                set("unit", "支");
                set("value", 1400);
                set("material", "iron");
        }
        init_dagger(18,POINTED);
        setup();
}
