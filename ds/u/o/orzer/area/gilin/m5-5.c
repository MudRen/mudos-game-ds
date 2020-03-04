inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你過了剛剛的哨站，繼續往下坡前進，空氣中傳來若有似無的寒氣
也許是走太久的錯覺，前方不知道有什麼東西等待著，看來應該快要走
到坡底了，前方靜謐無比，感覺沒有任何生氣。
LONG
        );
        set("exits", ([
  "northdown" : __DIR__"m6",
  "south" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}






