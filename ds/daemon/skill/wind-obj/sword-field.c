// �����C�}
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( HIG "�����C�}" NOR, ({ "indicate-knack field","field", "_INDICATE_KNACK_FIELD_"}) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�o�O�ѯe�����u�����߳Z�v�ҥ��U���C�}�A��
��_���P�A�H�h�ݳҡA�ϥ_��C�P�C�Z����Ѧ��A
�A�L�@���}��C
LONG
);
                set("unit", "");
                set("no_give",1);
                set("no_sac",1);
                set("no_get",1);
                set("no_put",1);
        }
       setup();
}


