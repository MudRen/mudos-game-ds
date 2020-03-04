
// helmet.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("斗笠", ({ "leaf hat", "hat"}));
          set_weight(1500);
        setup_head_eq();

        if( !clonep() ) {
                set("unit", "頂");
                set("long",
"這是一頂竹葉編成的斗笠，在大太陽下戴著這個，還頗增添不少涼意。\n"
);
                set("value", 50);
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor" : 2,
                ]) );
        }
        setup();        
}

