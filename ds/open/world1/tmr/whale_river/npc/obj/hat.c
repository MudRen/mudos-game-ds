
// helmet.c

#include <armor.h>

inherit F_HEAD_EQ;

void create()
{
        set_name("���", ({ "leaf hat", "hat"}));
          set_weight(1500);
        setup_head_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("long",
"�o�O�@���˸��s��������A�b�j�Ӷ��U���۳o�ӡA�ٻ�W�K���ֲD�N�C\n"
);
                set("value", 50);
                set("wear_as", "head_eq");
                set("apply_armor/head_eq", ([
                        "armor" : 2,
                ]) );
        }
        setup();        
}

