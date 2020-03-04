#include <ansi.h>

inherit ROOM;

int doll_check(object me);
int check(object me);
void create()
{
        set("short", HIC"【MOB測試區域A區】"NOR);
        set("long", "\n
測試A區測試A區測試A區測試A區測試A區測試A區測試A區
測試A區測試A區測試A區測試A區測試A區測試A區測試A區測試
A區測試A區測試A區測試A區測試A區測試A區測試A區
\n"NOR);
        set("light", 1);
       set("exits", ([ /* sizeof() == 2 */
   "west" : __DIR__"testroom",
  "east" : __DIR__"testroom2",
]));  
       set("outdoors","land");        setup();
}
void init()
{
        object me = this_player();

        if( !me ) return;

        add_action("doll_check", "out");
        add_action("doll_check", "quit");
                return;

        check(me); 
        doll_check(me);}

int doll_check(object me)
{
        object doll;
        me = this_player();
        message_vision(HIW"娃娃小紅帽隔空檢查$N身上有沒有測試用的替死娃娃.....\n"NOR, me);

        if( objectp(doll = present("test doll", me) ) )
        {
                message_vision(HIW"娃娃小紅帽隔空把"+me->query("name")+"身上的"NOR+doll->query("name")+HIW"拿走了。\n"NOR, me);
                destruct(doll);
        } 
                me->move("/open/world1/tmr/area/hotel");
        return 1;
}


