#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("�A��y�a", ({ "green belt" , "belt" , "_OBJ_ID_GREEN_BELT_" }) );
        set_weight( 2000 );
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 12000);
                set("long" , @LONG
�@�@�o�O�@���^���A��᯾���y�a�A�ݰ_�ӻ��Ȥ���A�������Q���Pı�C
LONG
				);
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor" : 1,
						"int" : 1 ,
						"str" : -1 ,
                ]));
        }
        setup();
}
