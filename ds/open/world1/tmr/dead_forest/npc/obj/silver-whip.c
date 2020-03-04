#include <weapon.h>

inherit F_WHIP;

void create()
{
        set_name( "四丈銀鞭" , ({ "silver whip" , "whip" }) );
        set_weight(6000);
        setup_whip( 3 , 8 , 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"whip"}));
                set("unit", "條");
                set("value" , 10000);
                set("long", 
"這是一條長四丈有餘的銀鞭，上面佈滿奇形怪狀的銀製銳器。"
                );
        }
        setup();
}
