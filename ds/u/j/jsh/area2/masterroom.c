inherit ROOM;

void create()
{
        set("short", "大廳");
        set("long", @LONG 
這裡是古墓派主人之一 [33m「楊過」[0m的房間，房間內的擺設非常的簡單
，雖然說簡單，但實際上一定不簡單， 說不定有些特別的東西或機關，
北方是大廳，一眼就可以看到底，在無盡的深處， 有種說不出來的感覺 
。
               你覺得這裡比一般的房間還要冷一些
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"room4",
]));
        set("objects", ([ /* sizeof() == 1*/
  __DIR__"goo" : 1,
]));      
        set("no_clean_up", 0);
        setup();

}

