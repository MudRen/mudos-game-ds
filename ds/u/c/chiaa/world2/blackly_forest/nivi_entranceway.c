//u/c/chiaa/world2/blackly_forest/nivi_entranceway.c

#include <ansi.h>     //代表顏色的函數來定義顏色
inherit ROOM;
void create()
{
        set("short", "忍者村入口");
        set("long", @LONG
這裡是黑暗森林的最深處,四周的環境好像有人整理過,
但是在這片人煙稀少的森林,會有人住在這裡嗎?!
前方的石塊好像有點奇怪!!
LONG
        );
        set("no_fight", 1);         //為禁止作戰區域
        set("exits", ([ /* sizeof() == 1 */
          
         "west"       : __DIR__"vacancy2",     //林間空地2

]));
        
     set("item_desc",([
        "石塊":"一個凸起的石塊,可以試著碰碰(touch)看。\n",
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_touch","touch");
}

int do_touch(string str)  //系統會將玩家所輸入的"touch"這個指令後的所有                             //文字以字串型別的引數傳給do_touch()　 
                          //將 do_touch 這個函數宣告為                                              //int do_touch(string str)
                          //str指當玩家下達一些指令時,就會被存進字串
                          //變數str之中供你處理　
{
        object me;
       me=this_player();
        
          if(!str || str!="石塊") return 0;
            message_vision("$N往下面掉落。\n",me );
      me->move(__DIR__"garrison2");
        
        tell_room(environment(this_player()),
        me->query("name")+"從上面掉落下來。\n", me);
        return 1;
}

