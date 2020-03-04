inherit ROOM;

void create()
{
        set("short", "客棧二樓");
         set("light",1);
        set("long", @LONG
這裡是天香客棧的二樓雅座，只見這裡酒氣沖天，一些有點錢兒的
人在這吆喝著划酒拳，旁邊還有幾位陪酒的姑娘，說「雅座」顯然只是
個幌子。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"hotel",
]));
        set("no_clean_up", 0);

        set("objects",([
           __DIR__"npc/chun" : 1,
        ]) );
        setup();
        replace_program(ROOM);
}
