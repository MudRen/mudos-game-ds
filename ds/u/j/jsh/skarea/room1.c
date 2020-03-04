inherit ROOM;

void create()
{
        set("short", "一號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的一號碼頭，整個碼頭用岩石與木頭搭建而成，
碼頭上有幾根粗的木樁，用來綁繩子固定船隻，碼頭足夠同時停泊兩艘
大船，碼頭旁的木牌寫著【北海航線】。 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room4",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

