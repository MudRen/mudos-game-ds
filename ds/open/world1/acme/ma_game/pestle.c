#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�ĪS", ({ "drug pestle","pestle" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�@�ڪ����o�ĥΪ��ĪS�A�C\n");
                set("value",1000);
                }
        setup();
}
