#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�_�ʯN�n(beijing-duck stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name(HIR"�_�ʯN�n"NOR,({"beijing-duck stock", "duck", "stock", "_GHOST_STOCK_"}) );
        set("long",@LONG
�_�ʯN�n�O�㦳�@���n�A���_�ʵۦW�榡�A�ήƬ��u��׭��n�_���n�A�G�쬴���N��
�A��A����A�׽�ΦӤ����A�ΨӴ���t����A�̨��۷N�C
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
        set("time", 1000 + random(1000) );
    
        setup();
        set("long", query("long") + getLong() );
}

