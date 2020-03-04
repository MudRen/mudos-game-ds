// Room: /u/k/kenshin/sha-zin-gu/room26.c

inherit ROOM;

void create()
{
        set("short", "武學之家內");
        set("long", @LONG
進來這，看到一些師父在教導學生外，也看到數十位弟子在踢木
人的聲音，如此浩大，令人想到前人所說，打架技巧除外，有沒有氣
勢才是最重要的。
LONG
        );
        set("light", 1);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room29",
  "out" : __DIR__"room25",
  "north" : __DIR__"room27",
]));
        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
        replace_program(ROOM);
}

