inherit ROOM;

void create()
{
        set("short", "相撲道場");
     set("light",1);
        set("long", @LONG
這裡是日本相撲們比賽較勁的地方，地板上畫有一個白色的圓圈圈，
看樣子應該是比賽時的分界線。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"map_14",
 ]));
        set("objects",([
       __DIR__"npc/man" : 2,
    ]) );
        set("no_clean_up", 0);
 setup();
        replace_program(ROOM);
}
