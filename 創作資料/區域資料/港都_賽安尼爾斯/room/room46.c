inherit ROOM;

void create()
{
  set("short", "碎石子路");
  set("long", @LONG
這裡是港都賽安尼爾斯外的道路，路上鋪滿著碎石子，往南方望
去可以看到雄偉的皮斯活火山，北邊可以看到美麗的幽遮蘭城。
LONG
  );
  set("exits", ([ /* sizeof() == 4 */
      "northwest" : __DIR__"room45",
      "southeast" : __DIR__"room47",
     ])); 
  set("light",1);
  setup();
}
