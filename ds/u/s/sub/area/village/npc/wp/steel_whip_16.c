#include <weapon.h>
inherit WHIP;
void create()
{
    set_name("���@",({"steel whip","whip"}));
    set_weight(6500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
                set("unit", "��");
                set("long",@LONG
�o�O�@���ѿ���ꦨ���@�l�A�ݨӭn���I���Ƥ~���o�ʡC
LONG);
    }
        init_whip(16);
        setup();
        set("value",1800);
        set("volume", 6);
        set("limit_str",10);
}

