#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千年古洞"NOR"－"HIB"洞口"NOR);
 set("long",@LONG 
這裡是古洞的洞口，但裡面十分安靜，連水滴生都可以聽的
一清二楚。但裡面傳來陣陣陰森的涼風，不禁讓人毛骨悚然，如
果你決定進去，務必要十分小心，提高警覺，不然還是快點走出
洞口吧！

LONG
    );

          set("item_desc",([
"岩縫" : NOR"一個狹窄的岩縫，似乎可以爬看看(climb)。\n"
           ]));
       set("exits",([
       "south":__DIR__"f1",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

void init()
{
add_action("do_climb","climb");
}

int do_climb(string arg)
{
string arg1;
object me;
me=this_player();
if (!arg) return notify_fail("你要爬到哪去？\n");

if (arg!="岩縫") return notify_fail("沒有這個地方可以爬。\n");
if (arg=="岩縫") 
{
 message_vision(HIG"$N往上方的岩縫爬出去。\n"NOR,me);
 me->move("/u/c/coffee/area/north_area/town31");
 tell_object(me,"你爬出了岩縫，發覺又回到了村子。\n");
}
                return 1;
}
