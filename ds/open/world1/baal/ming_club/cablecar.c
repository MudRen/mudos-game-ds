#include <ansi.h>
#include <path.h>
int ming(object me);

inherit ROOM;

void create()
{
 set("short", "明教吊車乘車處");
 set("long", @LONG

(等待CCKK,RICHAN提供資料中)

LONG
        );
        set("outdoors","land");
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "south" : "/open/world1/tmr/bagi/rift",
"up": __DIR__"lighttop",
 ]));
 set("no_clean_up", 0);
        setup();
}

void init()
{
        ::init();
        ming(this_player());
}

int ming(object me)
{
   object ob;
   if(!userp(me)) // for mob. 避免別幫的招喚生物進入.
   {
        if(ob=me->query("creater"))
        {
                if( !objectp(present("Plate of Holy Fire",ob)) )
                {
                        message_vision("非我族類,滾, $N。\n"NOR,ob);
                        me->move("/open/world1/tmr/bagi/rift.c");
                        tell_room(environment(me),me->name()+"被明教守衛了出來。\n",({ me }));
                        return 1;
                }
        }
   }
    else
   {
        if( !objectp(present("Plate of Holy Fire",me)) && me->query("club/name")!="明教" )
        {
        message_vision(HIW"明教的守衛見$N不是明教的教徒，立即將$N送至街上。\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"被明教守衛丟了出來。\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("killer") )
        {
                message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛殺了人所以暫時不能進入幫會。\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"想逃入幫會可是被趕了出來。\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("invader") )
        {
                message_vision("天上傳來一個幽幽的聲音: $N, 因為你剛剛攻擊無辜玩家, 所以暫時不能進入幫會。\n"NOR,me);
                me->move("/open/world1/tmr/bagi/rift.c");
                tell_room(environment(me),me->name()+"想逃入幫會可是被趕了出來。\n",({ me }));
                return 1;
        }
        return 1;
   }   
}

