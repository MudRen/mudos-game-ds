#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("������", ({ "rose", "rose" }));
        set("long","�@�بk�k����F�R�N����C\n");
        set_weight(1);

        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value", 0 );
        }
        setup();
}

