#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "步靈城中央廣場");
        set("long",
"這裡是步靈城的中心部份，來來往往的是許\多旅人，旅人中參雜著\n"
"各種種族的人們，步靈城是古代無上國的首都，正因為是無上國的首都\n"
"所以擁有許\多實力不錯的武官和將軍，不管是在無上國的那一個地方，\n"
"人人都會說步靈是最強的，在這裡還盛行一種遊戲，就是穿著衣物跳進\n"
HIY"古井(well)"NOR"裡，聽說在十天之內會有好康的事情發生，在路的旁邊有許\\n"
"多從西方引進的油燈，晚上就會點起來照亮這附近。\n"
        );
        set("exits", ([
  "south" : __DIR__"boo-lin2.c",
  "up" : __DIR__"survey.c",
  "east" : __DIR__"beast.c",
  "west" : __DIR__"bwest.c",
  "north" : __DIR__"bnorth.c",
]));
        set("light",1);
        set("item_desc",([
  "well" : HIC"這是一口古井，在井的旁邊常常有小孩子在玩跳進去古井的遊戲。\n"NOR,
]));
        set("objects", ([
  __DIR__"npc/yuanlieh" : 1,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        call_other("/obj/board/boo-lin_b.c","???");
}

void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me,where;
        string a;
        me = this_player();
        where = load_object(__DIR__"well.c");

        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "in %s", a )!=1 )
                return notify_fail("指令格式： jump in <地點名> .\n");
        if( a!="well" )
                return notify_fail("你要跳到那裡？\n");

        message_vision("$N深吸一口氣，對旁邊的人說道再見，然後走到了古井旁，\n"
                        +"拿起似舊似新的繩子往下面跳了去。\n",me);
        call_out("flop",5,me,environment(me));
        me->move(where);
//      shout(HIB+me->name()+NOR+HIR"使盡吃奶的力氣叫道﹕救命呀！\n"NOR);
//      write(HIR"你使勁大喊﹕" + arg + "\n"NOR);
        call_out("flop1",3,me,where);
        return 1;
}

int flop(object me,object a)
{
        tell_room(a,"在"+me->name()+"跳下去不久之後，你似乎聽到"+me->name()+"一些小小的迴響從古井跑出來\n",({ me }));
        return 1;
}
int flop1(object me,object a)
{
        tell_room(a,me->name()+"從上方的陸地上跳了下來，與你擠成一團。\n",({ me }));
        return 1;
}
