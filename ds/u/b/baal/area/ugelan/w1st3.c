#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"幽遮蘭城─杜瓦夫大道(The Avenue of Dwarf)"NOR);
        set("long", @LONG
你正身處於幽遮蘭城外城的東西向主要幹道─杜瓦夫大
道之上，道路一邊是幽遮蘭城城西守備隊─(Military of 
Ugelan)的城西指揮所，指揮所對面則是一家名為「黑繩索」
(Bla--ck Rope)的小旅館，一端斷裂的破舊招牌靠著僅剩的
一根繩索輕輕的搖擺著，招牌下是一扇沾滿油污、灰塵的窗
子，微弱的燈火從窗裡透露出來，煙囪裡所飄散出微弱的炊
煙是這個旅館還在經營的唯一跡象...
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugw1",
                        "south": __DIR__"brinn",
                        "west": __DIR__"w1st2",
            "east": __DIR__"w1st4",
            ]));
           set("item_desc",([
"下水道蓋\" : "一個鐵製的下水道蓋\，上面有孔洞供積水流入下水道。\n",
"破舊招牌" : "
招牌原本靠兩根繩索所吊掛著，現在一端已經斷裂，僅
靠著另一端支撐著。\n",
"水溝" : "在人行道兩邊的凹槽，深約一呎，裡面積了些樹葉跟垃圾，
可在下雨時幫忙疏導積水至下水道裡。\n",
                 ]));
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
int do_south()
{
        object me;
        me=this_player();
                return 0;
        message_vision("$N拉起掛在門上的布簾，走進了旅館。 \n",me);
        tell_room(environment(me),me->query("name")+"拉起掛在門上的布簾，走進了旅館。\n",me );
        return 1;
}

