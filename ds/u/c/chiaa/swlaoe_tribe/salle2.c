//u/c/chiaa/swlaoe_tribe/salle2.c

#include <ansi.h>//定義色碼
inherit ROOM;    //定義房間
void create()
{
   set("short", WHT"大廳後側"NOR);
   set("long",@LONG
          這裡是大廳後側,這裡只有放著一張桌子和一些椅子,
          忽然你注意到桌子上有一本「劍譜」,吸引你的注意力
          讓你不自覺的想把它翻開看看!!
LONG
);
        set("exits", ([ /* sizeof() == 2 */
      
        "east"    : __DIR__"salle2",       //大廳2
        "south"   : __DIR__"corridor5",    //走廊5
]));
        set("item_desc",([
        "劍譜":"一本空白的劍譜,翻來翻去都沒有半個字。\n",
]));
            setup();
        set("no_clean_up", 0);
}
void init()
{
        add_action("do_push","push");
}

        int do_push(string str) 
   //系統會將玩家所輸入的"push"這個指令後的所有                             
   //文字以字串型別的引數傳給 do_push()　 
   //將 do_push 這個函數宣告為                                              
   //int do_push(string str)
   //str指當玩家下達一些指令時,就會被存進字串
   //變數str之中供你處理

{
       object me;
       me=this_player();
       if(!str || str!="劍譜") return 0;
       message_vision("地上裂開一個洞,$N不注意便往下掉。\n",me );
       me->move(__DIR__"den");
        
        tell_room(environment(this_player()),
        me->query("name")+"從上頭掉落下來。\n", me);
        return 1;
}
