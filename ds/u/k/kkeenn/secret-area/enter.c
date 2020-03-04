inherit ROOM;

void create()
{
        set("short", "地下城入口");
        set("long", @LONG
這裡一片寂靜荒涼，所謂的[ 未來荒原 ]應該指的就是這裡了吧！只
見四週濃濃的白霧充斥在你的身旁，一陣陣了冷風與嚴重污染的空氣帶著
滾滾的黃沙吹來，附近的礦石堆在這種環境下更顯的明亮與珍貴，在腳旁
邊有一個漆黑的洞窟，不知道通往哪裡[0;1m�[1mC[0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 "down":__DIR__"sec1.c",
 "north":"/open/world3/tmr/basic/digging_road7.c",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));
        set("outdoors","future");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


