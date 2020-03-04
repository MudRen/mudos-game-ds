#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"天堂");
        set("long", @LONG
你已被小麥草黏液丟到了天堂來..你看到你身旁有許多天使
隱隱約約中你看到了耶穌的身影..忍不住跟他say hello 了 
一聲..祂還對你笑了一笑...接著你開始疾速下墜........
LONG
        );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1);
        setup();
}
void init()
{
        add_action("do_fly","fly");
}

int do_fly(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIW"$N的背上突然長了兩個翅膀化成天使的模樣飛走了！！。\n"NOR,me);
        me->move(__DIR__"workroom4");
        me->set_temp("the-sky",1);
        return 1;
}

