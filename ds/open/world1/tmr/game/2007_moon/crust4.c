
#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�p���_��(pastry crust) [�b�� %d ���J]",query("time") );
}

void create()
{
        set_name(HIW "�p���_��" NOR,({"pastry crust", "crust", "_MOON_CRUST_"}) );
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
        set("time", 500 + random(500) );
    
    setup();
        set("long", query("long") + getLong() );
}


