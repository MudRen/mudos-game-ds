inherit ROOM;
void create()
{
  set("short", "小木屋");
  set("long", @LONG

這裡是王媒婆往的房子，她專門幫人處理結婚喜事，如有需要請 look wang。

LONG
);
  set("exits", ([
  "north" : "/open/world1/tmr/area/ms1",
]));
  set("no_clean_up", 0);

  set("objects",([
__DIR__"marry_man" : 1,
]) );
  set("light",1);
  setup();
  replace_program(ROOM);
}

