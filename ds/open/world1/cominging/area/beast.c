inherit ROOM;
void create()
{
	set("short", "步靈城東大街西");
	set("long",@LONG
你站在一條短短的大路上，或許你在思考怎麼會有這麼短又這麼大
的大路，不過這卻是步靈城中的風俗，傳說在東大街的最角落曾有一個
傑出的武術家，不過後來為了防禦步靈城外的敵人因而戰死，為後人所
譽，因此大家對於那一塊地非常的尊敬，所以這條街也有叫歷史街的特
殊叫法，這裡還滲透出一點從中央廣場的燈光。
LONG
	);
	set("exits", ([
  "west" : __DIR__"boo-lin.c",
  "east" : __DIR__"beast1.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
