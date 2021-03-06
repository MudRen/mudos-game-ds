#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
由地上冒出的泉水，和從南邊留過來的小水泉匯集成一個小水塘
，清澈的泉水散發出陣陣清涼的氣息，如果你說話說得口乾舌燥的話
，不妨喝點泉水解解渴，不過可別喝太多了唷。
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-14",
                  "south" : __DIR__"room-09",
                  "west" : __DIR__"room-12",
        ]));
        set("light",0);
        set( "item_desc", ([ /* sizeof() == 1 */
        "水塘" : "一個小水塘(pool)。\n",
         ]) );
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

void init() 
{
add_action("drink_water","drink");
}

int drink_water(string str)
{
 int full; 
 object me=this_player(); 
 if( me->query("id") == "guest") return notify_fail("參觀者(Guest)不能使用此處。\n");
 if( !me->query("level") > 15) return notify_fail("為防小白玩家，本處 LV 15 以下不能使用。\n");
 if (str == "water" || str == "pool")
 {
  write("你喝下了清涼的泉水，頓時覺得相當舒暢，不再口渴。\n");
  full = 5 + this_player()->query("level")*3;
  this_player()->set("talk_point",full);                    //恢復tp
  return 1;
 }
// write("你想喝什麼啊？\n");
return 0;
 return 1;
}

