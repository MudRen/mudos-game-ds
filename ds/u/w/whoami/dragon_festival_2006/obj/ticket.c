#include <ansi.h>
inherit ITEM;
void create()
{

        set_name(WHT"油膩的紙"NOR,({"zong zi ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long",
               "一張油膩的紙，上面模糊地寫著"WHT"你這賽八郎，這樣也沒中，拿去給俺祖宗求情吧，哈哈哈"NOR"。\n"NOR);
             }
        set_weight(100);     
        set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);

        setup();
} 
