#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("���",({"strang wood","wood"}));
        set("long","�@�ڰ�쪺�K���A�O���U�إΨ㪺�n���ơC\n");
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else 
        {
        set("value",30);
        set("unit","��");
        }
        setup();
}



