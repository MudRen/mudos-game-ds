#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("妖精之淚\", ({"elf's tear","tear" }) );
        set("long", 
"一顆小小的水晶，上面閃耀著流水般的光亮，傳說中在妖\n"
"精國度才有的物品。稀有的程度簡直跟妖精的眼淚\一般，\n"
"故人們以此為名。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "顆");
        set("value",5000);
        }
        setup(); 
}