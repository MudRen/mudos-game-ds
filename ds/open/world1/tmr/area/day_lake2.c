inherit ROOM;
void create()
{
  set ("short", "龍舟比賽會場");
  set ("long", @LONG
龍舟比賽的預定場地, 你可以看到有許多工作人員正在忙著, 為了
6 月 6 日當天的比賽而努力
LONG);

  set("exits", ([
"south" : __DIR__"day_lake",
]));
  set("outdoors", "land");
  set("light",1);
  setup();
}
