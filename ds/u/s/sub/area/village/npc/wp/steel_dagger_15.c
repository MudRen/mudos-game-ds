#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("���P��",({"steel dagger","dagger"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",@LONG
�o�O�@��ѿ��s�����P���A���F�W�[�ˮ`�O�ҥH��������`���C�C
LONG
);
        }
        init_dagger(15);
        setup();
        set("value",1950);
        set("volume", 5);
        set("backstab_bonus",16);
        set("limit_dex",15);
}
