#include <ansi.h>
#include <armor.h>

inherit F_NECK_EQ;

void create()
{
        set_name("�j��եɶ���", ({ "ancient jade necklace","necklace"}) );
        set_weight(1500);
        setup_neck_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 8000);
                set("long",@long
�o�O�@���Υե�ű�y�Ӧ�������A�W����¶�ۤ@�ƧA�ݤ������j��A
���b��̭ˤ]�I�l�l���ᦳ���q�C
long
        );
                set("wear_as", "neck_eq");
                set("apply_armor/neck_eq", ([
                        "dex" : 1,
                        "armor": 3,
                ]));
        }
        setup();
}

