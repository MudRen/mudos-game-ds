inherit ROOM;
void create()
{
  set("short", "漠北牯牛草原");
  set("long", @LONG
此處的氣溫己漸漸變得寒冷，氣候與中原地區大異其
趣，在北邊遠處可隱約看見數座高山，連綿參天，山
巔白雪皓皓，映成一片銀色世界。
LONG
);
  set("exits", ([
"south"     : __DIR__"room30",
]));
	set("objects", ([
	]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
  replace_program(ROOM);
}
