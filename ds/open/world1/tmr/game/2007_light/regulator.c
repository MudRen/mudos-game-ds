#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ո`��",({"oil regulator", "regulator", "_OIL_REGULATOR_"}) );
        set("long",@LONG
�o�O�@�ӻɰ������ո`���A�ΨӴ�֩�ѿO���z�����i��ʡC
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

