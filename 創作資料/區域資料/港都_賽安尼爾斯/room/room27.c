inherit ROOM;

void create()
{
  set("short", "旅館");
  set("long", @LONG
這裡是一間豪華的旅館，雖然不是很大但是裝潢、設備都很不錯
，如果你覺得累了可以訂個房休息一下。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"room26",
      "north" : __DIR__"room24",
      "east" : __DIR__"room28",
     ])); 
  set("light",1);
  setup();
}
