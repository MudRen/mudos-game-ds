#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�����гJ��(egg yolk) [�b�� %d ���J]",query("time") );
}

void create()
{
        set_name(HIY "�����гJ��" NOR,({"egg yolk", "yolk", "_MOON_YOLK_"}) );
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
          set("value", 100);
        set("time", 100 + random(100) );
    
    setup();
        set("long", query("long") + getLong() );
}


