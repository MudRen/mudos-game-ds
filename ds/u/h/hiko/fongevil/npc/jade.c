#include <ansi.h>

inherit ITEM;
void create()
{
        set_name(MAG"�|���"NOR, ({ "four-soul jade", "jade" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
        "�@�T�ܩ_�S���ɥۡA�������ť��{�{�A�ǻ��O���Ǥ��_�A\n"
        "�ʦL�ۻ��j�Х@��H���A�ݨӤ��O�Z���A�b�E�����a��\n"
        "�۱j�P���ĪG\n");
                set("unit", "�T");
                set("value",0);
                set("no_auc", 1);
                set("no_sell",1);                
                set("no_put",1);
        }
        setup();
}

void init()
{
        if(!this_object()->query_light()) this_object()->start_light(1);
}


