inherit ROOM;

void create()
{
        set("short", "雲端");
        set("long", @LONG
這裡看起來是一片雲海 , 廣大無邊 , 但是隱隱約約看的到 , 雲團
的中間 , 有一個凹槽 , 像是一條路似的 , 除了這個 ,就沒有其它明顯
的特徵了。
這裡看不出來有什麼路。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"room13",
  "southwest" : __DIR__"room11",
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

