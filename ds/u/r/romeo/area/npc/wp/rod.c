#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("青竹棍",({"verdant-bamboo-rod","rod"}) );
        set("long","一隻有青色斑點的竹棍，是當年喬峰所使用的武器。\n");
      set_weight(2000);
                    set("material", "steel");
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","枝");
                set("volume",2);
    set("value",1800);
        }
                set("wield_msg","$N拿起了一枝$n頓時光華畢露。\n");
init_whip(8);
        setup();
}

