#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ħ�", ({ "drug" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�@�����q���ħ��C\n");
                set("value",1);
                set("ma_game",1);
                }
        setup();
}
