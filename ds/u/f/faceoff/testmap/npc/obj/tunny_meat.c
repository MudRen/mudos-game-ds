#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�C����", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@���ͪ��C����.");
                }
        setup();
}