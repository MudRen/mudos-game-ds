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
        set("no_give",1);
        set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);
        
        setup();
} 
int query_autoload() { return 1; }

