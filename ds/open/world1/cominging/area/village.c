inherit ROOM;
void create()
{
        set("short", "修德村");
        set("long", @LONG
這裡是修德村的真正入口，原來剛剛在村口那的牌子是無聊村人為
了防止平常有人來打擾他們的生活作息才做的，不過近來傲沖村因為冒
出了一個傑出的人「楊雙亟」因而吸引了許多外來的旅客，往東邊走是
接近村的中央。
LONG
        );
        set("exits", ([
  "west" : __DIR__"villagein",
  "east" : __DIR__"village1.c",
]));
        set("no_clean_up", 0);
	set("outdoors","land");
        setup();
        replace_program(ROOM);
}
