#include <ansi.h>
inherit ITEM;

void create()
{
         set_name( HIW "�ѨϤ��Z" NOR , ({ "angel egg", "egg", "_ANGLE_EGG_"}));
        set("long", "�o�O�@�����o�ۼ�ե��������Y�C\n");
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("value", 0);
                  set("no_put", 1);
                start_light(1);
        }
        setup();
}


