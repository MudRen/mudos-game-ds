inherit ROOM;
void create()
{
        set("short", "泊浪村市集");        
        set("long",@LONG
這裡是市集東部，人群已經較少了，不過依然蠻熱鬧，北邊傳來一
陣陣的魚腥味，仔細一看是一家魚販，看來要買新鮮海味要去那了，東
邊是往泊浪村廣場，那是村子有大事時的聚集地，看來聚集了一些人們
，也許有什麼事發生。
LONG
        );
        set("exits", ([
  "north" : __DIR__"po9n",
  "west" : __DIR__"po8" ,  
  "east" : __DIR__"po10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}





