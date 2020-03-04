inherit ROOM;
void create()
{
  set("short", "牯牛草原西方");
  set("long", @LONG
這裡是牯牛草原的西邊，而從這裡順著磐龍江的支流順流而
下可到達磐龍城東邊的城郊，因此處江面過於寬廣，跨江大
橋的建造計畫宣告失敗，所以通常入城是由南城門進入。這
裡往東北走是漠北地區，南邊距此七十里光景則是孟村。
LONG
);
  set("exits", ([
"east"      : __DIR__"room16",
]));
  set("no_clean_up", 0);
  set("outdoors","land");
  setup();
  replace_program(ROOM);
}
