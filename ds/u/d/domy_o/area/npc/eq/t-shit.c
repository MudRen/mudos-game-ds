#include <armor.h>


inherit CLOTH;

void create()
{
        set_name("T恤",({"t shit","shit"}) );
        set("long","擺地攤常見的衣服，衣質很薄。\n");
        set_weight(1200);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
        set("value",500);
          set("armor_prop/armor",3);
        }
        setup();
}

