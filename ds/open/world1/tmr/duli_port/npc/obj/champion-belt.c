#include <armor.h>
inherit F_WAIST_EQ;
void create()
{
        set_name("�a�x�y�a", ({ "champion belt","belt"}) );
        set_weight(5000);
        setup_waist_eq();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 25000);
                set("long",@long
    �o�O�@�������ɪ��a�x�y�a�A�W���٨�ۤ@��j�r�u��178�� �ͧJ��
�������ɻ��q�ūa�x�v�C�ѩ����y�a�Ѷ������y�A���Ȼ��Ȥ���A���q
�]�����C
long
);
                set("wear_as", "waist_eq");
                set("apply_armor/waist_eq", ([
                        "armor": 3,
                        "str": 1,
                        "dex": -1,
                ]));
        }
        setup();
}

