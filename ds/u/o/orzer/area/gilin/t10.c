inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你走到了往森林的西南邊前進，這裡越往前就更加感覺不安，周圍
的林木搖曳不定，而且也透露出些許微冷的寒氣，旁邊的霧氣也越趨濃
厚，看來似乎並不是什麼吉兆。
LONG
        );
        set("exits", ([
  "southwest" : __DIR__"t7",
  "north" : __DIR__"t11",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












