// hairpin.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("�C��v�a" ,({ "cyan hairpin", "hairpin" }));
        set_weight(400);
        setup_head_eq();
        if( !clonep() ) {
                set("unit", "��");
                set("value", 1800);
                set("long",@long
�o�O�@���C�⪺�v�a�A�W�Y�g���F���ֹШF�A���O�s´����q��C
long
                );
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor": 2,
                        "str": 1,
                        "dex": -1,
                ]));
        }
        setup();
}

