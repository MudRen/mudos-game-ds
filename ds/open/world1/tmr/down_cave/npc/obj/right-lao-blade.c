#include <weapon.h>

inherit F_BLADE;

void create()
{
        set_name("���G�M", ({ "right lao blade" , "blade"}) );
        set_weight(3500);
        setup_blade( 2 , 8, 60, 6);

        if( !clonep() ) {
                set("wield_as", ({ "blade" }));
                set("unit", "��");
                set("value", 15000);
                set("rigidity", 60);
                set("long", @long
�@�@�o�O�@��y���S����M�A�`�W��ۤ@�T�k�H���i�ۼL���ϮסA
�n���L�ڥ��b���������z����C�M����i���D�`�W�Q�A�H�ⴧ�ʼƤU
�A�N��ť��M�l�e�}�Ů��n�T�A���٦n�M�@��C
long
                );
        }
        setup();
}

