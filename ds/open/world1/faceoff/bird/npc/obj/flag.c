#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�O�X", ({ "flag", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�Q�U�j�s�X�D�ΨӸ��O���U���Ϋ~.");
                }
        setup();
}