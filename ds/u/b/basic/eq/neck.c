#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIM"雙鍊型"HIW"項煉"NOR, ({"basic neck","neck","basic"
}) );
        set("long", "Basic送ching的生日禮物。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "串" );
                set("armor_prop/armor",  100);
        set("material","gold");
                set("value", 10000);
        }
        setup();
}
