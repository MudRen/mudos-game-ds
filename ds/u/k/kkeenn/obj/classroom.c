#include <room.h>
#include <ansi.h>
inherit ROOM;                                                                                
void create()
{
  set("short",HIR"Ｏｐｅｋ性愛教室"NOR);
  set("long",@LONG
這就是Ｏｐｅｋ專門為一些純潔的少男少女們講解男女之間最神秘的
私事所用的教室，因為也有Ｗｉｚｓ群在此接受教育，所以內部的裝潢十
分的華麗。

        教授： Ｏｐｅｋ  [現任天地會總舵主]
        指令： start  + [名稱]              宣佈開始上課
               kickout+ [人名]              踢除不聽課的學生
               over                         結束課程
                    
LONG
  );
  set("exits",([
	"west" : "/open/world1/wilfred/newbie/eq_bank",
]) );
  set("light",1);
set("valid_startroom", 1);
  setup();
  call_other("/obj/board/sex_board.c",???);
}
void init()
{
	if(getuid(this_player()) != "opek" ) return 0;
add_action("do_start", "start");
add_action("do_over", "over");
add_action("do_kick", "kickout");
}
int do_start(string arg)
{
        object me,obj;
        me = this_player();
	obj = environment(me);
        if( !arg )
        return notify_fail("這次的課程名稱是...\n");
        if(obj->query("start") ) return notify_fail("Sorry..目前已有課程..\n"); 
        message_vision(HIC"$N宣佈今天的課程名稱是"+HIW+arg+HIC+"\n"NOR,me);
         tell_object(users(),HIW"\n∼Ｏｐｅｋ性愛教室開課∼\n"BEEP+NOR);
        obj->set("start",1);
        return 1;
}
int do_kick(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("你想要踢誰 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
         return notify_fail("這裡沒有這個人。\n");
         if(obj==me)
         return notify_fail("What are you think about?\n");
         message_vision(HIC"$N把$n踢出教室了。\n"NOR,me,obj);
         obj->move("/open/world1/tmr/area/hotel");
         return 1;
}
int do_over(object obj)
{
        object me;
        me = this_player();
        obj = environment(me);
        if(!obj->query("start")) return notify_fail("目前並沒有課程在進行中...\n");
        message_vision(HIC"$N結束了今天的課程∼\n"NOR,me);
        tell_object(users(),HIR"\n∼Ｏｐｅｋ性愛教室今天到此結束∼\n"NOR);
        obj->delete("start");
        return 1;
}
