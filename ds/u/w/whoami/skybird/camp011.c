inherit ROOM;

void create()
{
        set("short", "固山寨軍法處");
        set("long", @LONG
前面的空地上停著幾架馬車，那是跟隨軍隊出征時使用的逼
供刑具。馬車旁邊有很多一人多高的木架，上面血跡斑斑，那是
鞭打犯人用的。
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp012",
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

