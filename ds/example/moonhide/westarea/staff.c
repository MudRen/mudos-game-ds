#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name(HIG"易"HIW"君杖"NOR,({"ean staff","staff"}) );
        set("long","九天雲魂之易魂的武器，杖頭圓渾，光滑有彈性。\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",3300);
        set("volume",5);
        set("material","iron");
        init_staff(33);
        }
        setup();
}

