#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() {
        set_name("鐵掃帚", ({ "iron broom", "broom"}) ) ;
        set("long",@LONG
一把鐵桿掃帚，看起來十分沈重，想拿它來掃地看來得花一番功
夫才行。

LONG
);
        set_weight(6200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",12);
        set("unit", "把");
        set("material","iron"); 
        }
        set("weapon_prop/dex",-1);
        set("weapon_prop/hit",8);
        set("value",820);
        set("volume",4);  
        init_staff(35);
        setup();
}

