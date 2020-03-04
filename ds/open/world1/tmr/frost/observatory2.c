// Room: /open/world1/tmr/freezetaoism/observatory2.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-客廂房");
	set("long", @LONG
這是一間給上道觀參禪的遊客休息的廂房，雖然房內設備簡陋了些，
但由窗口望出去風景，直有「山抹微雲，天黏衰草」美麗的觀感，要是
在這兒居住，對心靈無異是一種澄化的享受。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"observatory",
]));
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/man":2,
        ]) );


	setup();
	replace_program(ROOM);
}
