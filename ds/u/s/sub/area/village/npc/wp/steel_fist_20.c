#include <weapon.h>
inherit FIST;
void create()
{
    set_name("������",({"steel fist","fist"}));
    set_weight(6000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
                set("unit", "��");
                set("long",@LONG
�o�O�@��ο��s��������A�s�@���۷��ӡC
LONG);
    }
        init_fist(20);
        setup();
        set("value",2100);
        set("volume", 4);
        set("limit_skill",30);
}

