#include <weapon.h>
inherit STAFF;

void create()
{
set_name("�^��",({"walking staff","staff"}));
set("long","�o�O�@�K���ª���s�^���A�W�����J��w�g�ֳQ�i���C\n");
set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "�K");
        set("value",1500);
        set("material","wood");
        }
        init_staff(16,TWO_HANDED);
        setup();
}

