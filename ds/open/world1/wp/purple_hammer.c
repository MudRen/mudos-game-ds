#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create() {
        set_name(HIM"紫炎鎚"NOR,({"purple flame hammer","hammer"}));
        set("long",@LONG
一把看起來毫不起眼的大鎚子，又笨重又巨大，紫色的鎚身傳來陣陣
熱氣，功力差的人們根本無法抵抗這熱度的侵襲。
LONG
);
        set_weight(16000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",30);
        set("unit", "把");        
        set("value",1130);
        set("volume",6);        
        set("material","steel");       
              }        
        set("weapon_prop/str",2);
        set("weapon_prop/dex",-2);
        init_hammer(57);
        setup();
}    
