#include <weapon.h>

inherit F_WHIP;

void create()
{
        set_name( "�|�V���@" , ({ "silver whip" , "whip" }) );
        set_weight(6000);
        setup_whip( 3 , 8 , 100, 0);

        if( !clonep() ) {
                set("wield_as", ({"whip"}));
                set("unit", "��");
                set("value" , 10000);
                set("long", 
"�o�O�@�����|�V���l�����@�A�W���G���_�ΩǪ����Ȼs�U���C"
                );
        }
        setup();
}
