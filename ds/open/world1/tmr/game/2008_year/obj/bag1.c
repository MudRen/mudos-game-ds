#include <ansi.h>
inherit ITEM;
inherit __DIR__"bag_base";

void create()
{
        set_name(HIR "�p�ֳU" NOR,({"small happiness bag", "bag", "__MOUSE_BAG__"}) );
        set("long",@LONG
�o�O�@�ӳ߮�v�v���ֳU�A�W���e���@���i�����������ϼˡA�ΨӼy��
���������~���~���ʡA�i���O�}�K�m�ֳU �֮�B�B�b�A�A�i�H���}(open)
�ֳU�A�ݬݧA����o����n�F��C
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
        //�֥�
        set("happiness", 1);
	    setup();
}


