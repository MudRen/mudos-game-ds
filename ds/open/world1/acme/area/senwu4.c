// Room: /open/world1/acme/area/senwu4.c

inherit ROOM;

// 自然奇觀-天池瀑布
// add by tmr 2006/11/15
void open_skypool2() {
        "/adm/daemons/event/skypool.c"->trigger_event();
}

void open_skypool() {
        call_out("open_skypool2",60+random(30));
}

void create()
{
	set("short", "高台");
	set("long", @LONG
在這高台上，放著一張大石桌，在旁也有一張石椅，在石桌上頭
放置插著三枝香的香爐，散發出令人神清氣爽的裊裊檀香，在石桌上
另有許多法器，不知有何作用。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"senwu3",
]));
set("objects",([
    __DIR__"npc/advmaster.c" : 1,
]) );
	set("world", "past");
    set("outdoors","land");
	set("no_clean_up", 0);

        set("valid_startroom", 1);
	setup();
}
