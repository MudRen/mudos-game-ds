#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�D���Ϫ��Y", ({ "head of wen tzyy ian","head" }) );
        set_weight(570);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@����O�O���Y�`�E");
                }
        setup();
}

