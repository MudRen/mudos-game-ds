#include <weapon.h>
inherit BOW;

void create()
{
	set_name("��}", ({ "wood bow", "bow" }));
        set("long","�o�O�@���}�A�i��(shoot)���O�յۥh�ѤW���Ӷ��y�Ǯg�b�C\n");
	set_weight(1000);
            if( clonep() )
               set_default_object(__FILE__);
        else {
        set("unit", "��");
	set("value", 0);
        set("material","wood");
	}
	init_bow(1);
	set("no_put", 1);
	set("no_give", 1);
        setup();
}
