#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("魔法書本", ({"magicbook" }) );
        set("long", 
"這是一本泛著魔法光輝的書籍，你隨手翻了一下...完全看不懂...\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "本");
        }
        setup(); 
}