#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�G���",({"pulp"}) );
        set_weight(200);
        set("long",@long
�@�@�A�ժ��G�סA���o�a�@�ѿ@�p���J���s�����C
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else {
        set("value",1);
        set("material","plant");
        set("volume",1);
	}
        setup();
}