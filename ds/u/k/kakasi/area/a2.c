inherit ROOM;

void create()
{
        set("short", "後山");
        set("long", @LONG
這裡黑悽悽的萬無空物，只可聽到一些烏鴉在啼叫的聲音，心裡突然
感覺毛毛的，真想趕快脫離這個鬼地方。再往前走可看到凌雲寺的一些弟
子，在那邊看護著，不知在看護什麼？
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a3",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
