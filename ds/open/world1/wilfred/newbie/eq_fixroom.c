inherit ROOM;
void create()
{
  set("short", "工作檯旁");
  set("long", @LONG

這裡是火爐旁的一塊空地，這裡放著一塊看來相當沉重
的大鐵砧，上頭擺著數塊未成形的鐵條，在一旁的地上散落
著一地的打鐵工具，如果有需要，您可以將壞掉的武器或裝
備交給打鐵老師博修理 [0;1;36m([1mg[1mi[1mv[1me[1m [1mm[1ma[1ms[1mt[1me[1mr[1m [1m<[1m�[1m�[1m�[1m~[1m [1mi[1md[1m>[1m)[0m
LONG
);
  set("exits", ([
  "west" : "/open/world1/tmr/area/smithy",
]));
  set("no_clean_up", 0);

  set("objects",([
__DIR__"eq_master" : 1,
]) );
  set("light",1);
  setup();
  replace_program(ROOM);
}

