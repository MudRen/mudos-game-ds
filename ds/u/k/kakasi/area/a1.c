inherit ROOM;

void create()
{
        set("short", "梯田");
        set("long", @LONG
這是延續旁邊那個梯田而來的，聽附近的小弟子說這兒收成非常的好
，每年至少都可以有一獲至二獲。在往北走就是後山了，聽說那裡關了一
位破戒僧，但是否真的那有待查證了。
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a2",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
