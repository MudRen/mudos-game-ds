inherit ROOM;

void create()
{
        set("short", "三號碼頭");
        set("long", @LONG
這裡是賽安尼爾斯的三號碼頭，整個碼頭用岩石與木頭搭建而成，
    碼頭上有幾根粗的木樁，用來綁繩子固定船隻，碼頭足夠同時停泊
    兩艘大船，海賊的船隻經常在這個碼頭停泊，碼頭旁的木牌被不知
    名人士塗改成【尋寶航線】。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  //"south" : __DIR__"street5",
  //"west" : __DIR__"hotel",
  //"north" : __DIR__"square",
  "east" : __DIR__"room11",
]));
        set("outdoors","land");

        setup();
        //replace_program(ROOM);
}


