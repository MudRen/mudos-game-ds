#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�гJ��(egg yolk) [�b�� %d ���J]",query("time") );
}

void create()
{
        set_name(HIY "�гJ��" NOR,({"egg yolk", "yolk", "_MOON_YOLK_"}) );
        set("long",@LONG
�o�O�@����ꪺ�гJ���A�O����檺���n���Ƥ��@�C
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
        if( random(100) < 80)
                set("time", 1 + random(10) );
        else if( random(100) < 80)
                set("time", 1 + random(50) );
        else
                set("time", 1 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}


