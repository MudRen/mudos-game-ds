#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"火紅獵鷹"NOR,({"eagle of fire","eagle","fire"}));
        set_weight(120);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"這是一個獵鷹形狀的紅色徽章，即使上面沾上了泥土，仍然絲毫不\n"
                            "減其神秘的氣息。展翅欲起的獵鷹火紅的雙眼似乎瞪視著你。你不\n"
                            "知不覺為此所此所迷惑，感覺陷入了一種玄幻的空虛之中。\n"NOR);
                set("value", 0);
                set("no_sell",1);
        }
        setup();
}


