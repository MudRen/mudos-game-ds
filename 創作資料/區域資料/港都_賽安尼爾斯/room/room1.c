inherit ROOM;

void create()
{
  set("short", "一號碼頭");
  set("long", @LONG
這裡是賽安尼爾斯的一號碼頭，整個碼頭用岩石與木頭搭建而成
，碼頭上有幾根粗的木樁，用來綁繩子固定船隻，碼頭足夠同時停泊
兩艘大船，碼頭旁的木牌寫著【北海航線】。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "east" : __DIR__"room9",
  ]));
  set("outdoors","land");
  setup();
}
