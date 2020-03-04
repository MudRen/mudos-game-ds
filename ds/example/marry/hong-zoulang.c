//Room: /d/ruzhou/hong-zoulang.c
// by llm 99/06/12

inherit ROOM;

void create()
{
	set("short", "紅娘庄走廊");
   set("long", @LONG
走廊兩邊是紅漆金粉的廊柱雕欄，高低錯落地挑著兩排紅燈籠。地上
鋪著厚厚的大紅地毯，急待結婚的新人們進來踩在上面，一股喜慶幸福之
感自心底油然而生。前面是一個不大的門廳。
LONG
   );
	set("exits", ([
		"west" : __DIR__"hong-damen",
		"east" : __DIR__"hongniang-zhuang",
   ]) );

   set("objects", ([
   	__DIR__"npc/xiao-hongniang" : 1,
      ]) );
   setup();
	replace_program(ROOM);
}
