inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你終於到了建築物前面，你仔細的瞧一瞧匾額上所寫的『靈幻宗』
，才想起這不就是當初和神武門齊名的門派，只是已經在江湖上消失了
數十年，沒想到竟然會在深山叢林內，也讓更加好奇為什麼他們會避居
此地，也許該進去問問。
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"t8",
  "enter" : __DIR__"lin1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











