#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN"一江客棧"NOR);
        set("long", @LONG
你一進來，馬上感覺到一股樸素卻又脫俗的氣氛，客棧
內雖然沒有什麼客人，但是樟木桌椅卻擦的發亮，而新鮮的
空氣不斷從鏤空的紙窗中吹進，只見你的右手邊一幅潑字畫
，手法精奇，不像是荒野村夫所為，而左手邊則有一座樓梯
往上.
LONG
        );
        set("exits", ([  "north" : __DIR__"ten12.c",
                   "up":__DIR__"ten16.c",
]));
      set("objects", ([__DIR__"npc/ten_waiter" : 1,
    ]));
   set("item_desc",([
        "潑字畫": "這幅潑字畫書法脫俗, 想來必為高人所為, 上面寫著 "+WHT+" 《往來長春閣, 一江山夫舍》"+NOR+"\n"
    ]));
           set("room_type","hotel");       //旅館
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        setup();
}
