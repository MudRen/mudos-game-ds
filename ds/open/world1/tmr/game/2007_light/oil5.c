#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�O�o�U�U��",({"oil support tool", "tool", "_LAMP_OIL_TOOL_"}) );
        set("long",@LONG
�o�O�@�ӳy���륩�����~�A���Y�˵ۤƾ��į��A�i�H�Ψ�
�[�j�ѿO�O�o�U�N�ɪ����աC
LONG
);
        set_weight(1);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�~");
        }
        set("value", 1);
        setup();
}

