#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�`���Ǫd(jujube puree) [�b�� %d ���J]",query("time") );
}

void create()
{
        set_name(RED "�`���Ǫd" NOR,({"jujube puree", "puree", "_MOON_PUREE_"}) );
        set("long",@LONG
�Ǫd�O�ѥh�ְ��ǩҥ������A���D���@���ӡB���������B�f�P�D�`�ƶ��A
�O����檺���n���Ƥ��@
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
        set("time", 500 + random(500) );

        setup();
        set("long", query("long") + getLong() );
}

