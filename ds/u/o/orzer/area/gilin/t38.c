inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
這裡是森林內側的最深處，低吟聲越靠近此處益發明顯，看來應
該就是此處所傳出來，不知道是什麼東西在此地，也許是什麼高人在
這邊鎮壓著，也許應該仔細的在附近探尋一番。
LONG
        );
        set("exits", ([
        "north" : __DIR__"t37",         
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














