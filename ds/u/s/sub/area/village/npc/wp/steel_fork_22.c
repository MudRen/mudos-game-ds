#include <weapon.h>
inherit FORK;
void create()
{
    set_name("����",({"steel spear","spear"}));
    set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "��");
          set("long",@LONG
�@��ο����y�����١A�٦y�٦���媺���ѡC
LONG);
        }
        init_fork(22);
        setup();
        set("value",1900);
        set("volume", 6);
        set("limit_skill",50);
}
