#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�_�p��(pastry crust) [�b�� %d ���J]",query("time") );
}

void create()
{
        set_name("�_�p��",({"pastry crust", "crust", "_MOON_CRUST_"}) );
        set("long",@LONG
�_�p�֡A�S�٤d�h�p�֡A�O���ѯ��[���b�������{�A�b���{�����ݥ]�W
���o�A���Ъ����|�A�ѩ��ѥ֦����o�j���Ӳ��ͳ\�h�h���C
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


