inherit ITEM;
#include <ansi.h>

void create()
{
        set_name( "�~���Y��" , ({ "animal-king head", "head", "open-war-head" }));
        set("long", "�o�O�@���~���������Y���C \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 1);
        }
        setup();
}

