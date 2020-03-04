inherit ROOM;

void create()
{
	set("short", "小舍外");
	set("long", @LONG
這裡是龍風小舍外的走廊上，走廊上有一些盆景，相望對面小舍略
顯差點，從外看裡面似乎有些零亂，不太適合借宿的樣子，小舍是由石
頭所築成，外表看起來也些醜醜的樣子。
LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry22.c",
  "eastdown" : __DIR__"flurry18.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
