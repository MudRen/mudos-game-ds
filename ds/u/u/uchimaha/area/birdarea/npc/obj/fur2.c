#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(MAG"�Ѫ���"NOR,({ "skydog fur","fur" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�ǻ����Ѫ����W���֡C\n");
                set("unit","�i");
        }
        setup();
}
