#include <armor.h>
inherit F_WAIST_EQ;

void create()
{
        set_name("�j��ɸy�a", ({ "ancient belt", "belt"}) );
        set_weight(1000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 3000);
                set("long", "�o�O�@���ʻ�ű�y�Ӧ����y�a�A�W���観�Ʊƥj��A��o�ᦳ���v���ȡC\n");
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 3,
                        "int": 1,
                        "dodge": -5,
                ]));
        }

        setup();
}

