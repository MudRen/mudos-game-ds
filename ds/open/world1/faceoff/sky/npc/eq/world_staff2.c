#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name( "拂世杖" ,({"whisk-world staff","staff"}));
        set_weight( 6000 );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
這是雲風聖道所使用的聖仗，用來掃除人世間的諸邪萬惡。
雲風聖道在六十六歲那年得道，而創出「九重天咒」, 從此戰鬥
不再使用此仗，而將此杖轉贈與他人。
LONG
                                );
                set("volume",2);
                set("unit", "把");
                set("value",7000);
                set("material","steel");
                set("limit_lv", 25);
        }
        init_staff(71);
        set("weapon_prop/str",1);
        set("weapon_prop/dex",1);
        setup();
}

