#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIG"特伯傑路"NOR);
  set("long",@LONG
漢斯集團對於剛發現的今字塔有很大的興趣，不昔
耗費巨資，在總公司和金字塔間開了一條直達路，道路
名字以發現金字塔的探險家命名，他現在已成百萬富翁。
LONG
  );
  set("exits",([
  "back":"/d/wiz/hall1",
  "east":"/u/m/morral/world3/hans2",]));
  set("light",1);
  setup();
}
