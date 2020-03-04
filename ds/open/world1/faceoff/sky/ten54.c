#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"千面神廟"NOR);
 set("long",@LONG
你一進來這裡, 就感到渾身不對勁, 一和神殿外出世的
傳說中千面，邪桫，禰影三神一同創造了十萬大山，但在
過程中千面墮落成後來的奇倪獸，引發了所謂的《 十萬之
役》，因此不在村民的奉祀之列，也因此神龕上一片悽涼
的景象，什麼也沒有....
LONG
    );
 set("exits",([   "out":__DIR__"ten51",
    ]));
set("item_desc",([
        "神龕" : HIG"神龕的中央有個面具鑲在上面....\n"NOR,
      "面具" : HIG"就是一個面具咩! 你可以把它拿起來....(take)\n"NOR,
]));
set("no_clean_up",0);
set("light",1);
 setup();
}

void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object me, p;
       string a;
        object room = environment(this_player());
        me = this_player();
            if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("指令格式： take <物品> .\n");
   if( a!="面具" )
                return notify_fail("你眼睛瞎了嗎? 這裡沒有這種東西!\n");
        if(room->query("take_leg") == 0)
        {
                message_vision(HIC"$N將面具從神龕上拿了出來....。\n"NOR  ,me);
                p=new("/u/f/faceoff/area/sky/eq/faceoff_mask.c");
                p->move(this_player());
                room->set("take_leg",1);
                delete("item_desc");
        }
        else
        {
                tell_object(me,HIR"這裡空無一物！\n"NOR);
        }
        return 1;
}
