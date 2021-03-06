// Room: /u/l/luky/room/pearl_23.c
#include <ansi.h>
inherit ROOM;
void init();
void create()
{
set("short", HIY"修道院大門"NOR);
set("long", @LONG

��╲                                                   ╱��
��▕＿    這裡的戒備十分森嚴，似乎有什麼危機即將發   ╱: ��
��▕ :▏生，四週有不少打鬥的痕跡。西邊的鐵門(Gate) ▕: : ��
��▕ :▏上有三條很深的爪印，地上還散落著巨大的鱗片 ▕: : ��
��▕￣  ，這一切都和你想像中莊嚴肅穆的教堂不同。     ╲: ��
��╱                                                   ╲��


LONG
);
set("objects",([
__DIR__"npc/chuguard":2,
]));
set("exits", ([ /* sizeof() == 3 */
"north" : __DIR__"pearl_22",
/*  "west" : __DIR__"pearl_25", */
"south" : __DIR__"pearl_24",
]));
set("item_desc",([
"gate":"\n
──────────┬──────────
██████████│██████████    上面還有幾個按鈕。
                ◥█│█◤                     ┌─┬─┬─┐
                  █│█      ╲╲             │７│８│９│
                  █│█      ╲╲╲           ├─┼─┼─┤ 使用方法:
              ◢  █│█  ◣    ╲╲           │４│５│６│ 
              ◥  █│█  ◤                   ├─┼─┼─┤ press [數字]
                  █│█                       │１│２│３│
                  █│█                       ├─┼─┼─┤
                ◢█│█◣                     │＊│０│＃│
██████████│██████████     └─┴─┴─┘
──────────┴──────────
\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}
void init()
{
 add_action("do_press","press");
}

int do_press(string arg)
{
 object me;
 me = this_player();
if(!me->query_temp("pass_num")) return notify_fail("你不知道密碼就算按0也沒用\n");
 if(!arg) return notify_fail("    press [數字]\n");
 else{
  if(me->query_temp("pass_num")==atoi(arg))
  {
   message_vision("\n$N按下了按鈕..\n",me);
   me->start_busy(2);
   tell_room(this_object(),"\n
[2J──────────┬──────────
██████████│██████████
                ◥█│█◤                
                  █│█      ╲╲        
                  █│█      ╲╲╲      
              ◢  █│█  ◣    ╲╲      
              ◥  █│█  ◤              
                  █│█                  
                  █│█                  
                ◢█│█◣                
██████████│██████████
──────────┴──────────
");
  call_out("open1",2,this_object());
  call_out("open2",3,this_object());
  call_out("closedoor",30,this_object());
  } else return notify_fail("\n  你按下按鈕，但是卻沒有反應。\n");
 }
 return 1;
}
int open1(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J─────────┐  ┌─────────
█████████│  │█████████
              ◥█│  │█◤              
                █│  │█      ╲╲      
                █│  │█      ╲╲╲    
            ◢  █│  │█  ◣    ╲╲    
            ◥  █│  │█  ◤            
                █│  │█                
                █│  │█                
              ◢█│  │█◣              
█████████│  │█████████
─────────┘  └─────────

");
}
int open2(object me)
{
if(!me) return 0;
 tell_room(me,"\n
[2J──────┐              ┌──────
██████│              │██████
        ◥█│              │█◤        
          █│              │█      ╲╲
          █│              │█      ╲╲
      ◢  █│              │█  ◣    ╲
      ◥  █│              │█  ◤      
          █│              │█          
          █│              │█          
        ◢█│              │█◣        
██████│              │██████
──────┘              └──────
");
tell_room(me,"\n  嗶!!.. 鐵門突然打開了! \n");
set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 "enter":__DIR__"pearl_25",
]));
set("item_desc",([
"gate":"\n
──────┐              ┌──────
██████│              │██████
        ◥█│              │█◤        
          █│              │█      ╲╲
          █│              │█      ╲╲
      ◢  █│              │█  ◣    ╲
      ◥  █│              │█  ◤      
          █│              │█          
          █│              │█          
        ◢█│              │█◣        
██████│              │██████
──────┘              └──────
\n",]));
}

int closedoor(object me)
{
if(!me) return 0;//by pudon
tell_room(me,"\n  轟!!的一聲.. 鐵門又關起來了。 \n");
 set("exits",([
 "north" : __DIR__"pearl_22",
 "south" : __DIR__"pearl_24",
 ]));
 set("item_desc",([
 "gate":"\n
──────────┬──────────
██████████│██████████    上面還有幾個按鈕。
                ◥█│█◤                     ┌─┬─┬─┐
                  █│█      ╲╲             │７│８│９│
                  █│█      ╲╲╲           ├─┼─┼─┤ 使用方法:
              ◢  █│█  ◣    ╲╲           │４│５│６│
              ◥  █│█  ◤                   ├─┼─┼─┤ press [數字]
                  █│█                       │１│２│３│
                  █│█                       ├─┼─┼─┤
                ◢█│█◣                     │＊│０│＃│
██████████│██████████     └─┴─┴─┘
──────────┴──────────
\n",
]));
return 1;
}
