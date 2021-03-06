inherit ROOM;

void create()
{
        set("short", "流波潼");
        set("long", @LONG
這裡是位於一處三數丈高的天然瀑布下，溪水自上而降，射入潼前似
是幽水深谷，又像斷澗之中，在潼前一巨大石眼泉中，直噴上來，高出石
潼十丈，蔚為奇觀。在你眼前有一天然的平滑巨石，石狀如桌，其大有八
仙桌的兩倍餘，四旁列有石埻，石在水中，竟成桌形並配以墩座，豈非神
工鬼斧妙成之物！
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"l2",
  "down" : __DIR__"valley",
]));
  set("item_desc", ([ /* sizeof() == 1 */
    "巨石" : "這塊巨石似乎不是天然生成，是道道地地的人為，約有幾百年了\n"
             "為當時武林之尊「石丈人」，以無倫神功\削割而成！石桌石墩在\n"
             "潼後五丈，這塊巨石，俗人給它起了個名字叫「鬧龍柱」。\n",
    "鬧龍柱" : "你抬頭往鬧龍柱上頭看去，心中一動，只見東邊天際，望之似\n"
               "在那流波潼上方，正有團然如火團上下跳動，火團一升百丈，\n"
               "倏忽飛降，接著騰升上下，如此上下不已，若輕功\造詣頗高，\n"
               "或許\能上躍(jump)一觀\n",
  ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{ 
         add_action("do_swim", "go");
         add_action("do_jump","jump");
}
int do_jump(string arg)
{
          object me;
          me=this_player();
          if(arg != "鬧龍柱") return 0;
          if(me->query_skill("dodge")<60) return notify_fail("你的輕功\造詣不夠，是躍不上去的。\n");
          else {
            message_vision("$N使出卓越的輕功\，往鬧龍柱躍去。\n",me);
            me->move(__DIR__"dragon");
            return 1;
          }
}
int do_swim(string arg)
{
        object me;
        me=this_player();
        if( (arg!= "down") || !this_player()->visible(this_object()) ) return 0;
        if(me->query_skill("swim") < 30)
        {
          tell_object(me,"你的泳技不夠純熟，潛入水底將會有生命危險。\n");
        }
        else {
          message_vision("$N深深的吸了一口氣，潛入「流波潼」了。\n",me);
          me->move(__DIR__"valley");
        }
        return 1;
}

