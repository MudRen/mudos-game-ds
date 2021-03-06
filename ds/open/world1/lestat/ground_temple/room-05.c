#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
惡臭沖天的房間中，堆滿了人類和妖魔的骨骸，以及散落滿地的
長矛，在骨骸堆中間，有一個暗紅色的箱子（box)，箱子隱隱泛著紅
光，可能其中藏著什麼神秘的寶物在裡面。
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "箱子"  : "一個紅色的寶箱，上面有一把鎖，你可以試著撬開它（break）。\n",
        "box" :  "一個紅色的寶箱，上面有一把鎖，你可以試著打撬開它（break）。\n",
        ]) );
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-06",
                  "west" : __DIR__"room-04",
                  "south" : __DIR__"room-03",
        ]));
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

void init()
{
add_action("do_pick","break");
}

int do_pick(string str)
{
if(str=="box" || "str" == "箱子")
 {
  if(this_player()->query("class1") == "thief")   // check職業為小偷 
  {
  write("憑著你身為盜賊的敏銳直覺，你覺得這箱子是陷阱，不可以開！\n"); 
  return 1;
  }
  else 
  {
  write("你硬是用蠻力撬開箱子，箱子中噴出一道火焰燒傷你後，又再度闔上。\n");
  this_player()->set_temp("temp/death_type","[[1;31m嚴重燒傷致死[0m]");
  this_player()->receive_damage("hp",30+random(80));
  return 1;
  }
 write("你想做什麼？\n");
 return 0;
 }
}


