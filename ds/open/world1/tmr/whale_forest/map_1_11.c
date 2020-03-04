// 狐熊山洞 入口
inherit ROOM;
void create()
{
        set("short", "林中山洞入口");
        set("long", @LONG
你注意到周遭的樹幹上有著大形動物的爪痕，似乎是種地盤標誌。
LONG
);
        set("exits",([
        "west" : __DIR__"map_1_10",
        "east" : __DIR__"map_1_12",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
        replace_program(ROOM); //加其他函式xxx()時請拿掉此行
}

