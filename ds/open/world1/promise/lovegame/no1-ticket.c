#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�Ĥ@�S������"NOR,({"no.1 ticket","ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               HIG"�Ĥ@�S�������A�i�HSave�d�۵�"HIR"Promise"HIG"�ӵ��A§���C\n"NOR);
             }
        set_weight(100);     
        
        setup();
} 

