#include <armor.h>
inherit F_PANTS;
void create()
{
        set_name("�`�Ŧ���J��", ({ "blue jeans", "jeans" }) );
        set_weight(900);
        setup_pants();

        if( !clonep() ) {
                set("unit", "��");
                set("value", 900);
                set("long",@long
�o�O�@��`�����`�Ŧ���J�ǡA���M���������A���O�@���ΡA����
�Ȧ�̪��߷R�C
long
                );
                  set("wear_as", "pants");
                  set("apply_armor/pants", ([
                        "armor": 2,
                ]));
        }
        setup();
}

