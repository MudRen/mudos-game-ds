#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("���ͯ�", ({ "gold grass","grass" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long", "�o�O�@�ت��ͪ��b���������ʹӪ�, �O�جöQ�������ħ�!");
                }
        setup();
}

