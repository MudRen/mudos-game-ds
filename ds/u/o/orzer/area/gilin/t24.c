inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經是森林東邊的內側，感覺有著無聲的靜默感，似乎安靜的
的讓人有點無法置信，你覺得有些無法形容的詭異，東北邊可以繼續往
最東邊前進，西邊則是回頭，有一道若有似無的人影。
LONG
        );
        set("exits", ([
        "west" : __DIR__"t23",
        "northeast" : __DIR__"t27",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











