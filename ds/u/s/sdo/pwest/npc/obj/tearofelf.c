#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("���뤧�\\", ({"elf's tear","tear" }) );
        set("long", 
"�@���p�p�������A�W���{ģ�۬y���몺���G�A�ǻ����b��\n"
"���פ~�������~�C�}�����{��²���򧯺몺���\\�@��A\n"
"�G�H�̥H�����W�C\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value",5000);
        }
        setup(); 
}