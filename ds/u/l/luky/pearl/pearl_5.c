// Room: /u/l/luky/room/pearl_5.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIG"珍珠南街"NOR);
set("long", @LONG

＿＿＿＿＿＿＿ 你的北邊是一大片白色圍牆，上面＿＿＿＿＿＿＿
"  .   -       都是當地的兒童所畫的塗鴉。往東     -  '    "
:      -       是本鎮的東南角，西邊飄來陣陣誘     -    "  :
= ."   -       人的香味。                         -       =
==-  " -       -                          -       - .   -==
￣￣￣￣￣￣￣￣￣￣￣￣￣￣ ￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣
LONG
);
set("exits", ([ /* 出口 */
"west" : __DIR__"pearl_6",
"east" : __DIR__"pearl_4",
]));
set("item_desc",([ //景物
  "wall":"牆上除了畫之外還寫了幾個古文(words)。\n",
  "圍牆":"牆上除了畫之外還寫了幾個古文(words)。\n",
  "words":"你可以試著讀讀看(read words)。\n",
  "古文":"你可以試著讀讀看(read words)。\n",
]));
set("objects",([
__DIR__"npc/paintboy":1,
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
 object me;
 int pass_num;
 me = this_player();
 pass_num = random(9999);
 if( !arg || (arg != "words"))return notify_fail("你要讀什麼?\n");
  else 
   if(random((int)me->query("int"))<20)
    message_vision("$N看了牆壁半天也沒有什麼發現。(可能是太笨了)\n",me);
   else
   {
    message_vision("$N看了一下牆壁，發現上面寫了一些數字。\n",me);
    write("嗯.. 應該是["+pass_num+"]。\n");
    me->set_temp("pass_num",pass_num);
   }
 return 1;
}
