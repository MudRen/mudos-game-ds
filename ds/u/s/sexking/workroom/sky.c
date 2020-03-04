#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"天堂");
        set("long", @LONG
你被那沱小麥草黏液丟到了這個地方..旁邊有很多天使...
你隱隱約約的看到了耶穌的身影..還不知不覺的跟祂 say hi.....
LONG
        );
        set("item_desc",([
        "小麥草黏液":"一種黏黏的東西..聽說可保護人不受傷。\n",
        ]) );
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

int do_jump(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg!="sky") return 0;
        message_vision(HIW"$N身上突然長起了翅膀，像天使一樣快樂的往下飛去！！。\n"NOR,me);
        me->move(__DIR__"workroom2");
        me->set_temp("the-sky",1);
        return 1;
}
