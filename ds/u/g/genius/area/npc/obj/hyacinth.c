#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"���H�l"NOR,({"hyacinth","flower"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@���ܥi�R����A��y�O�N��ۤ�������ߡC\n");
                set("value", 150);
                set("no_sell",1);
        }
        setup();
}

