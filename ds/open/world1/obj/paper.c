#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ñ�X��", ({ "paper" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long", "�o�O���F�q�o���X����ñ�X��.");
                }
        setup();
}
