#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�s��"NOR,({ "lobser","lobser" }));
        set_weight(1000);

        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","�@�����������s��..�ݰ_�ӫܦn�Y���ˤl�C\n");
                set("unit","��");
                set("value",100);
        }
        setup();
}

