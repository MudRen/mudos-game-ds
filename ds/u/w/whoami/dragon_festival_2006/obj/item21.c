inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("�T�_��", ({ "san bao rice", "rice" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        }
}
