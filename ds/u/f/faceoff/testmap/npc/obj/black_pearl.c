#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"�¬ï]"NOR, ({ "pearl", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@���󪺰��Ŭï], �q�`�b��Q���i�H��췥�n������.\n");
            set("value",4000);
                }
        setup();
}