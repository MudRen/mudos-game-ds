#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�����J��"NOR,({ "goud statue","statue" }));
        set_weight(30000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�y�J��,�ݦ��@����,�W�����F�@�ӭ����D�`�u�񪺤H�C\n");
                set("no_get",1);
                set("no_drop",1);
                set("no_dest",1); 
                set("value", 100000);
                set("unit","��");
        }
        setup();
}


