#include <ansi.h>
#include <path.h>

inherit ITEM;

void open_war(object me);

int query_pan();

void create()
{
        set_name( "�զ�Ϸ"  ,({"pan horn","horn", "_PAN_HORN_"}) );
        set_weight(10);
        set("long",@LONG
�o�O�@�ڨťզ⪺�Ϸ�A�W�Y�٪g���X�w�A��C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","��");
                set("value", 10);
        }
        setup();
}
