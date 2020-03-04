#include <armor.h>

inherit F_WAIST_EQ;

void create()
{
        set_name("翠綠腰帶", ({ "green belt" , "belt" , "_OBJ_ID_GREEN_BELT_" }) );
        set_weight( 2000 );
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "條");
                set("value", 12000);
                set("long" , @LONG
　　這是一條鑲有翠綠花紋的腰帶，看起來價值不菲，滿有高貴的感覺。
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
