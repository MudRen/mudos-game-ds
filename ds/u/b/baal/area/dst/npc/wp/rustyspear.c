#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name(WHT"���ê���"NOR,({"rusty spear","spear"}));
        set("long","�@����ê����١A�ݨӦ��@�q�ܪ������v�F�C\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",2);
        set("material","iron");
                set("unit", "��");
        set("value",200);
        }
        init_fork(6);
        setup();
}

