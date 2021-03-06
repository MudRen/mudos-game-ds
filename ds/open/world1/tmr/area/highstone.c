// Room: /u/t/tmr/area/highstone.c

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大石塊上");
        set("long", @LONG
一塊極其平坦的石塊上，是個鳥不拉屎的地方，只有一群小雜草
高處不勝寒，在此地待久了，不知不覺都冷了起來。想下去竟然找不
到任何路，看來只能提起勇氣－跳下去了。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "小雜草" : "幾株充滿活力、欣欣向榮的幼苗，在太陽底下，散發出奇特的光芒..?\n"
]));
        set("exits", ([ /* sizeof() == 1 */
]));
        set("outdoors","heat");
        set("no_clean_up", 0);

        setup();
}

void do_clear() {
           set("search",0);
}

void init()
{
        add_action("do_search","search");
       add_action("do_jump","jump");
}


int do_search(string arg)
{


        object p;
                object me;
        me=this_player();
 
       if (arg != "小雜草") return 0;

        message_vision("$N俯身在小雜草堆中仔細仔細的搜尋...\n"  ,me);

        if( !query("search") ){
           message_vision("找了又找，$N終於在小雜草堆找到一面金牌！！\n" ,me);
           set("search",1);
           p=new(__DIR__"npc/obj/plate");
           p->move(this_player());
           call_out("do_clear",600);
        } else  {
                message_vision("找了又找，終究一無所獲...\n",me);
        }                               
        return 1;
}

int do_jump(string arg)
{
        object me;
        me=this_player();
 
       if (arg != "down") return 0;

        message_vision("$N微一凝神，深吸一口氣，兩眼一閉，跳了下去...\n",me);
        me->move(__DIR__"arbour");
      tell_room(environment(me),"你覺得身前一陣風響，"+me->query("name")+"忽然出現在你眼前。\n",me);
        return 1;
}

