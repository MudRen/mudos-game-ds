#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"���O"NOR, ({ "eagle mark", "mark"}) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "��");
                set("long", "�@�ӧΪ����N�����O, ť���O���@�N�����������O");
                }
        setup();
}
