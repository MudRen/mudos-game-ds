#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
    set_name(HIG "���_�j"NOR,({"fei zhen pike","pike"}));
    set("long","�o��j�O�κ�����y�Ӧ��A�O��۷��������j�C\n");
    set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("value",2600);
set("volume",4);
          set("material","iron");
        }
        set("weapon_prop/str",2);
        set("weapon_prop/hit",8);
          init_fork(32);
        setup();
}
