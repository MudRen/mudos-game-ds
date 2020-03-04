#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "木柱前");
        set("long", @LONG
這裡是一片寬廣的草原 , 不時還有牛叫聲 , 也有清脆的鳥鳴
聲 , 像是人間天堂似的 , 但是 . .  所有的動物都不敢靠近草原
正中間的那根[0;7;33m�[7m�[7m�[7mW[0m , 疑有怪異 . . .。
LONG
        );

        set("item_desc",([
    "木柱":"一條呈六十度傾斜的木頭柱子，上面還有一對小小的勾子，似乎有什麼作用。\n",
        "勾子":"一對小小的勾子，上面還有磨擦過的痕跡。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "north" : "/open/world1/wilfred/meadow/room3",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_hold","hold");
}

int do_hold(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="ring on 勾子") return 0;
        if(!objectp(ring=present("willow ring",me) ) )
                return notify_fail("你沒有東可以綁住勾子啊 ? \n");
        message_vision(HIW"$N將柳戒用力一扯，將其牢牢的套住兩邊的勾子，並穩穩的抓緊。\n",me);
     message_vision(HIW "柳戒像是著了魔一樣，將$N彈上無窮遠的天空 . .！！\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"你大叫一聲的摔在雲層上面。\n");
        me->move(__DIR__"room");
     tell_room(environment(me),me->query("name")+"摔在軟軟的雲層上面。\n",me);
        return;
}

