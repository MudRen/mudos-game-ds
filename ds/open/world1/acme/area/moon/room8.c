inherit ROOM;

void create()
{
	set("short","幻月之間");
	set("long", @LONG
一來到這裡你不禁感到一陣頭暈目眩，因為從四面八方有數以千
萬計的星點光芒向你投射過來。你低頭一看更是深深的吃了一驚，你
發覺自己正漂浮在虛空之中，不過正確的說應該是站立在一片透明的
平面之上。這個神秘的空間看來一定就是那個流傳在月族領導者間的
秘密了，只是如此奇妙的地方到底如何創造的呢，這又是另一個月族
的不解之秘了。在前方不遠之處有一個巨大的水晶聳立著，靜靜地散
發著溫和的淡紅色光芒。

LONG
	);
      set("exits",([
  "up" : __DIR__"room9.c",
]));
	set("objects",([
__DIR__"item/treasure_box" :1,
__DIR__"item/crystal" :1,
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
        call_other( "/obj/board/moon_room8_b", "???" );
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && CLUB_D->check_member("moon",getuid(me))  < 3 )
                return notify_fail("幫主有令：職位在長老之下者不得入內！！\n");
        return ::valid_leave(me, dir);
}

