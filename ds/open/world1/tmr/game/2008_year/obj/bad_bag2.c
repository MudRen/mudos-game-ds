#include <ansi.h>
inherit ITEM;
inherit __DIR__"bag_base";


void create()
{
        set_name(HIY"��������" HBK "���U" NOR,({"ominous bag", "bag", "__MOUSE_BAG__"}) );
        set("long",@LONG
�o�O�@�ӥR�����𪺥��U�A���쥦���H�A�@�w�|�ˤj�`�C
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
          set("happiness", 6 );
        setup();
}


