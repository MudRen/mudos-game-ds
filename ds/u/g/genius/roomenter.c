#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"小研究室"NOR);
set("long", @LONG
這裡整齊的放著幾台電腦(computer)，書櫃上擺滿了各式各樣的書
籍(book)。有一張床(bed)看起來非常的舒適，讓人有想要躺上去的念
頭。總體而言，雖然東西很多，但是挺不錯的。
LONG
);

      set("item_desc", ([
      "computer":"這是一台GENIUS III 333 GHZ的電腦\n",
      "book":"哇....好多書啊....\n",
      "bed":"你看到一張令人流口水的床\n",
      ]));

      set("exits", ([
      "out": "/u/g/genius/workroom.c",
      "down": "/u/g/genius/fightroom.c",
      "east": "/u/g/genius/colorroom.c",
      "west": "/u/g/genius/handfeet.c",
      ]));

      set("objects",([
      "/u/g/genius/npc/moneyman" : 1,
      "/u/g/genius/npc/fightm" : 1,
      ]));
      setup();

      set("light",1);
}
