#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"�ï]"NOR, ({ "pearl", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�����Ŭï], �q�`�b��Q���i�H��줣��������.\n");
            set("value",2000);
                }
        setup();
}