inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
這裡已經是森林東邊的內側，感覺有著無聲的靜默感，似乎安靜的
的讓人有點無法置信，你覺得有些無法形容的詭異，東北可以繼續往東
邊前進，東南則是回頭，有一道若有似無的人影。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t23",
  "southeast" : __DIR__"t16",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











