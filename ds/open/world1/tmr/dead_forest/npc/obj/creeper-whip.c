#include <weapon.h>

inherit F_WHIP;

void create()
{
        set_name( "���ͪ��@" , ({ "creeper whip" , "whip" }) );
        set_weight(6000);
        setup_whip( 2 , 10 , 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"whip"}));
                set("unit", "��");
                set("value" , 5000);
                set("long", 
"�o�O�@���ѽ��ʹӪ��ҽs�������@�A���F�ƤV�A��a��w�C"
                );
        }
        setup();
}
