inherit ROOM;

void create()
{
        set("short", "三號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的三號碼頭，整個碼頭用岩石與木頭搭建而成，
碼頭上有幾根粗的木樁，用來綁繩子固定船隻，碼頭足夠同時停泊兩艘
大船，海賊的船隻經常在這個碼頭停泊，碼頭旁的木牌被不知名人士塗
改成【尋寶航線】。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room6",
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
}


