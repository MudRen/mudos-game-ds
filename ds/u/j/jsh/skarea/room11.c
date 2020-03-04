inherit ROOM;

void create()
{
        set("short", "五號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的六號碼頭，整個碼頭用岩石與木頭搭建而成，
六號碼頭是往東方大陸航線的三個碼頭之一，停泊開往東方的船隻，碼
頭上豎立著大牌子，上面寫著【東方二號航線】。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room10", 
  "south" : __DIR__"room12",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}

