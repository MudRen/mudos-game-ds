#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("��Ʈv���x�L", ({ "mark" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("value",1);
                set("unit", "��");
                set("long", "�U�W��q, �N�O��Ʈv���x�L��, �ݨӧA���ӧ�L�������F�q���x��...");
                }
        setup();
}
