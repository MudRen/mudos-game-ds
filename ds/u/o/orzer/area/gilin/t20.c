inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你看了看四周總感覺有東西在看著你，可是卻找不到來源所在，這
讓你心中有點不太踏實，總有點捉模不定的樣子，看來要好好的想辦法
趕走這種情緒，因此你打起了精神，繼續向森林前進。
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t19",
  "south" : __DIR__"t12",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








