#include <ansi.h>
inherit ITEM;


string getLong()
{
        return sprintf("�����(buddha's favorite stock) [�۷N %d ��]",query("time") );
}

void create()
{
        set_name(HIM"��"HIC"��"HIY"��"NOR,({"buddha's favorite stock", "stock", "_GHOST_STOCK_", "_GHOST_STOCK2_"}) );
        set("long",@LONG
�o������O�H��u�j���B�饻��Ĩۣ�B�����ʡB�z�����B�Q�����B
��n���L�B�H�ѵ���ƵN���A�s�M�|���ܩڤ��F�o���C�T�ت������A
���L����]�n�ܤW�@�f�C
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
        set("time", 5000);
    
        setup();
        set("long", query("long") + getLong() );
}

