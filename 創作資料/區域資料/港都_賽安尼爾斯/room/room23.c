inherit ROOM;

void create()
{
  set("short", "金閃酒吧");
  set("long", @LONG
走進這間酒吧會以為是到了皇宮，粉飾明亮的牆上掛著許多名畫
，兩旁擺著雕像及陶瓷，天花板上掛著價值非凡的水晶吊飾，實在是
華麗無比，你看到來這邊的都是一些穿著整齊的軍官、貴族等不平凡
的人物。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room22",
      "south" : __DIR__"room26",
      "northwest" : __DIR__"room19",
      "east" : __DIR__"room24",
     ]));  
  set("objects",([
      __DIR__"npc/room23-boss.c":1,
     ]));
  set("light",1);
  setup();
}
