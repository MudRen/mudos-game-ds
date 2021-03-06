#include <room.h>
inherit ROOM;

void create()
{
        set("short", "中央廣場");
        set("long", @LONG
這裡是天城的中央廣場，你可以看見人來人往的相當繁榮，天城因
天湖的關係而帶來了許多的遊客來這遊玩，使得天城迅速的發展，在南
有個打鐵鋪，往北則可到天湖，廣場中央還有個告示牌。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "告示牌" : "這是地方官在這所設的佈告欄，看起來相當的新，似乎還未曾使用。
",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/traveler" : 1,
  __DIR__"npc/traveler1" : 2,
]));
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"plaza4",
  "west" : __DIR__"plaza",
  "south" : __DIR__"plaza2",
  "east" : __DIR__"plaza3",
]));
        set("no_clean_up", 0);
        set("outdoors","land");

        setup();
}
