#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
	set_name(HIY"�����@��"NOR, ({ "gold gloves" , "gloves"}) );
        set("long",@LONG
�o�O�Ѷ������G����ϩҳy�����@��C
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "��");
                set("value",2500);
		set("no_sell", 1);
        }
        setup();
}

