#include <ansi2.h>
#include <weapon.h>
inherit FORK;

void create()
{
        set_name(HBK"�j�j"NOR,({"greatly pike","pike"}) );
        set("long",@LONG
�o�O��d�����~�b�Z�L�����W�߸U���j�j�A�۶ǬO�Ѥ����W���k
�ۤW�A���Ҳ`��⪺���ݡA���E�Ѧa������ű���C�d���ߦ~�w
�g���A�ϥγo��j�j�F�A���O�L���j�k�b�Z�L�����a��A�o�O�q
�ӨS���H�i�H�ٰʪ��C
LONG
        );
        set_weight(25000);
        if (clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit","��");
                set("value",17000);
                set("volume",5);
                set("material","steel");
        }
        set("weapon_prop/bar",1);
        set("weapon_prop/wit",-1);//sV1
        init_fork(58);
        setup();
}


