#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�Ȱw", ({ "needle", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�ڰw�b�Ϊ��w.");
		set("no_drop", 1);
		set("no_give", 1);
		set("no_sac", 1);
                }
        setup();
}
int query_autoload() { return 1; }
