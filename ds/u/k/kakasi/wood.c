#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�̤�", ({ "wood", "wood" }));
        set("long","����������~�C\n");
        set_weight(450);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value", 100 );
        }
        setup();
}
