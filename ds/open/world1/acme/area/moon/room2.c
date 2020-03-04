inherit ROOM;

void create()
{
	set("short","月光花園");
	set("long", @LONG
穿過了大門，你簡直無法相信自己眼睛所看到的一切。雖然只相
隔了一道門，內外卻是一個截然不同的世界。一進大門，你遍目所及
的是許多看都沒看過的奇花異草還有許多傳說中的珍禽異獸。整個天
空都散發著異樣的光芒，你確信那絕對不是日光。隨著你緩緩的繼續
前行，那訝異的心情漸漸得到平靜，你覺得應該不會再有事物能夠震
撼你的心靈了。最後你來到了一棟散發著淡青色光芒的石殿之前，殿
前的石碑浮現著-月魂殿-三字。

LONG
	);
	set("exits",([
  "south" : __DIR__"room1.c",
  "north" : __DIR__"room3.c",
]));
//	set("objects",([
//__DIR__"box1" :1,
//]));
	set("item_desc",([
  "石碑":"上面刻著 -月魂殿- 三字。\n",
]));
	set("light",1);
set("no_goto",1);
	set("no_kill",1);
	setup();
	set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)
//	call_other( "/obj/board/dragon_club_b", "???" );
}

