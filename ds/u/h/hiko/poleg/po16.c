inherit ROOM;
void create()
{
        set("short", "泊浪村東側");        
        set("long",@LONG
這裡是泊浪村廣場的東側的街道，再往東邊走去便是村長加了，聽
說最近村長為了某事正著急著，因此這在找人幫忙，也許跟村人們所流
傳的事有關，如果想知道詳細的話，那就往東邊去拜訪看看吧。
LONG
        );
        set("exits", ([  
"east" : __DIR__"po16-1",
"west" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}








