inherit ROOM;
void create()
{
          set("short","鐵路車站");
          set("long",@LONG
唯一一條通往主城的鐵路就是建於這個車站裡面，每天都有很多貨物
和人們都經這裡往來。可能由於貨品大多以礦物為主，使得這裡有一些碎
掉的礦物在地上，而通過的人踏了下去，使得地面黏上了礦物的色彩。你
現在進入即可乘坐鐵路。
LONG
           );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
          "westdown" : __DIR__"digging_street4",
          "enter"  : __DIR__"train",
	]));
           setup();
}