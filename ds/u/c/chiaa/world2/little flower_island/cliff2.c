//u/c/chiaa/world2/little flower_island/cliff2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "懸崖");
        set("long",@LONG
這裡是一座「懸崖」除了往回走已經沒有任何的出路了
除非你有勇氣的話往下跳,可能會有奇遇也說不定,不過
一個不小心可是會摔個粉身碎骨,要跳之前好好的想一想吧!!

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "north"   : __DIR__"rock4",    //岩石區4
  ]));
    set("item_desc",([
        "懸崖":"根本看不到底,往下跳(jump)的話是很危險的考慮一下吧。\n",
     ]));

        set("no_clean_up", 0);
          setup();
}

void init()

{
        add_action("do_jump","jump");
}

int do_jump(string str)  //系統會將玩家所輸入的"jump"這個指令後的所有                             //文字以字串型別的引數傳給 do_jump()　 
                          //將 do_jump 這個函數宣告為                                              //int do_jump(string str)
                          //str指當玩家下達一些指令時,就會被存進字串
                          //變數str之中供你處理　
{
        object me;
       me=this_player();
        
          if(!str || str!="懸崖") return 0;
            message_vision("$N鼓起勇氣,閉上眼睛,咻地往下一跳.。\n",me );
      me->move(__DIR__"sand4");
        
        tell_room(environment(this_player()),
        me->query("name")+"不知從何處掉落下來。\n", me);
        return 1;
}
