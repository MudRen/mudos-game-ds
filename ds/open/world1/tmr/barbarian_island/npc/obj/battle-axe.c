#include <weapon.h>

inherit F_AXE;

void create()
{
        set_name("�ԩ�", ({ "battle axe","axe","_OBJ_ID_BATTLE_AXE_"}) );
        set_weight(8000);
        setup_axe(4, 6,100, 0);
        if( !clonep() ) {
                set("wield_as", ({"twohanded axe"}));
                set("unit", "��");
                set("value", 4500);
                set("rigidity", 60);
                set("long",@long
�o�O�@��D�`�I�����j���Y�A��`�W��e�ۤ@�Ө��r�ۤW���������k
�l�A�������۩��Y��ܤ@�����~���ϮסA���M�u���Ƶ��A���e���Ͱʦ�
�g��A���G�u�o�͹L�o�بƪ��ˤl�C
long
                );
        }
        setup();
}



