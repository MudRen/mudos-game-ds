#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("�ϸH�M", ({ "left sui blade" , "blade"}) );
        set_weight(4500);
        setup_blade( 2 , 8, 60, 6);

        if( !clonep() ) {
                set("wield_as", ({ "secondhand blade" }));
                set("unit", "��");
                set("value", 15000);
                set("rigidity", 60);
                set("long", @long
�@�@�ϸH�M���M�����M�`�Ӫ��p��A�]�ᬰ�I���A�ݤM�`���]�p�O�A
�X������ϥΪ��A�n�O�u�O���t���H�A�ٯu�O�����ϥγo�⭫�M�C
long
                );
        }
        setup();
}

