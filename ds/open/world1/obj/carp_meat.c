#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�U����", ({ "meat", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�����ų���,���L�ͪ��O�L�k���Ϊ�.");
                }
        setup();
}