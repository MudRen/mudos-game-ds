#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() {
        set_name("�K����", ({ "iron broom", "broom"}) ) ;
        set("long",@LONG
�@���K�챽���A�ݰ_�ӤQ���H���A�Q�����ӱ��a�ݨӱo��@�f�\
�Ҥ~��C

LONG
);
        set_weight(6200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",12);
        set("unit", "��");
        set("material","iron"); 
        }
        set("weapon_prop/dex",-1);
        set("weapon_prop/hit",8);
        set("value",820);
        set("volume",4);  
        init_staff(35);
        setup();
}

