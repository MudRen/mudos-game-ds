inherit ROOM;

void create()
{
	set("short","風月之間");
	set("long", @LONG
這個地方給你的感覺，與廣寒宮中的其他地方相當不同。因為這
裡不但四處都有三三兩兩的人圍坐在一起，甚至讓你覺得有點嘈雜。
原來此處乃是月族族人們休憩的地方，只有在這裡族人們才會放下日
常對自我的嚴格要求而得到完全的放鬆。大家會在這裡敘說自己在江
湖上的所見所聞，另外如果有族人在行走江湖時遇到一些麻煩也會在
這裡講出來，其他人都會盡可能的想辦法幫他解決。

LONG
	);
	set("exits",([
  "north" : __DIR__"room5.c",
  "west" : __DIR__"room3.c",
]));
    set("objects",([
         __DIR__"npc/shopman" : 1,
//__DIR__"box1" :1,
    ]));
/*	set("item_desc",([
  "浮刻":@DESC1

                              人
                              不
                              犯
                              我
                              
                              我
                              不
                              犯
                       燕     人
                       赤     
                       霞       
                              
DESC1
,
]));
*/
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
	call_other( "/obj/board/moon_room4_b", "???" );
}

