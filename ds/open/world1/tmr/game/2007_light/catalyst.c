#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("Ĳ�C",({"oil catalyst", "catalyst", "_OIL_CATALYST_"}) );
        set("long",@LONG
�o�O�@�ӥΰ��ʤƾ���Ĳ�C�A��D�`�j�T�׼W�[�ѿO
�U�N�����աA�C�@��Ĳ�C��W�[1%�\�@���ƶq�A�̦h30%�A
���]�a��1%�z�����i��ʡC
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
        }
        set("value", 1);
        setup();
}

