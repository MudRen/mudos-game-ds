#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"燈塔三樓"NOR);
        set("long",@LONG
來到三樓，你的眼前不禁一亮，強烈的海風吹的人站立不穩，廣大
的天空就在你眼前展開，由上往下看，湛藍的海洋延伸到地平線的那一
端，薩爾薩斯港進出的船舶在你看來小的可愛，幾隻海鳥盤旋在離你不
遠的地方，呼叫著，嬉鬧著。
LONG 
);
        set("exits",([
            "down":__DIR__"port_a2",
                ]));
        set("world","world1");
        set("outdoor","land");
        
        set("item_desc",([
            "海鳥":"這些海鳥離你十分近，似乎觸手可得(touch)...\n",
            "機械":@LONG
這個機械是由一個圓盤為主，圓盤下有相當複雜的齒輪組合，
圓盤上則立著三個巨大的水晶，三個水晶的中央有個圓形的凹
槽，圓盤上隱約刻著像是文字的線條。看機械的樣子，似乎曾
經有人想啟動(start) 它。
LONG                
                ]));
        setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_start","start");
}
int do_touch(string arg)
{
        object me;
        me=this_player();
        if (arg != "海鳥") return 0;
        else
        {
        message_vision(HIW"海鳥受到驚嚇飛走了！還在$N手上留下一沱∼∼鳥∼大∼便∼∼\n"NOR,me);
        return 1;
        }
}
int do_start()
{       
        int i;
        object me;
        me=this_player();
        i =me->query_temp("light_to_future");
        if ( i > 3 || me->query("sarsass")>0) return notify_fail("在得到更多線索前，你並不想輕舉妄動。\n");
        else
        {
        tell_object(me,"你研究了一會兒，找尋啟動機械的方法。\n");
         if (i < 3 || !me->query_temp("light_to_future"))
         {
           tell_object(me,"看起來要啟動是很費力的事，還是省省力氣吧！\n");
            return 1;
         }
         else
         {
           tell_object(me,"你仔細的觀察了一會兒。\n");
           me->start_busy(3);
           tell_object(me,"你小心翼翼的啟動機械。\n");
           me->start_busy(3);
           tell_object(me,"機器順利的運轉了！接下來只要讓它發光(light)就行了！\n");
           set("item_desc",([
               "海鳥":"這些海鳥離你十分近，似乎觸手可得(touch)...\n",
               "機械":"這個機械正順利的運轉著，到底是什麼力量讓它這樣轉個不停呢？\n"
           ]));
           add_action("do_light","light");
           return 1;
         }
        }
}
int do_light()
{
        int i;
        object me;
        me=this_player();
        i =me->query_temp("light_to_future");
        if ( i > 3 || me->query("sarsass")>0) return notify_fail("你想起上次的慘劇...還是算了吧！\n");
        if ( i < 3 || !me->query_temp("light_to_future")) return notify_fail("你沒有動機這樣做。\n");
        tell_object(me,"你在四周找尋可以發光的東西....\n");
        me->start_busy(1);
        tell_object(me,"你找到一個油燈，這個東西應該可以用吧！\n");
        message_vision("$N從地上撿起一盞油燈....\n",me);
        me->start_busy(1);
        message_vision("$N將油燈點燃放入三個水晶的中間....\n",me);
        tell_object(me,HIY"機器突然放出一陣光芒！油燈的火焰瞬間膨脹，吞噬了整個機械！\n"NOR);
        message_vision(HIR"整台機械陷入一片火海!一__一!\n"NOR,me);
        message_vision("$N趕緊撲滅了火，機械也停止轉動了....\n",me);
        me->start_busy(1);
        tell_object(me,"看起來是失敗了，回去報告吧！不過那陣光芒究竟是....﹖\n");
        me->set_temp("light_to_future",4);
        set("item_desc",([
            "海鳥":"這些海鳥離你十分近，似乎觸手可得(touch)...\n",
            "機械":"這個機械有被火燒過的痕跡....？\n"
        ]));
        return 1;
}
