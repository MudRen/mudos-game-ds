#include <armor.h>

inherit WAIST;

void create()
{
        set_name("�b�~�H�y�a", ({ "orc belt" , "belt" ,}) );
        set_weight( 1500 );

        if( !clonep() ) {
                set("unit", "��");
                  set("value", 500);
                set("long" , @LONG
�o�O�@���y���S���y�a�A���G�¥H�~�ֽs´�Ӧ��A�W�Y�ٴݯd
�ǳ\����{���C
LONG
                                );
               set("armor_prop/armor", 4);
        } else
		   set_default_object(__FILE__);
        setup();
}

