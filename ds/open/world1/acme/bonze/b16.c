// Room: /open/world1/acme/bonze/b16.c

inherit ROOM;

void create()
{
	set("short", "大雄寶殿");
	set("long", @LONG
這裡就是寺中最為莊嚴的聖地，在你眼前有一尊比三人還高的大
佛，仔細望去，應該是一尊釋迦牟尼佛，佛呈金身，在佛前的小廣場
裡，放置了數以百計的圓蒲，蒲前各擺放了一個木魚，此地應就是和
尚們做早、晚課的地方了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"b14",
]));
set("objects",([
    __DIR__"npc/master.c" : 1,
]) );
        set("valid_startroom", 1);
        set("light",1);

	setup();
	replace_program(ROOM);
}
