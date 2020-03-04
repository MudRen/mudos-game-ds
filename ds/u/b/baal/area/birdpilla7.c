#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"石廊"NOR);

 set("long",@LONG
你走在石廊中, 兩旁的石壁上的浮雕吸引了你, 你看了看石壁, 左邊
是一隻展翅高飛的大梟遨翔在天際, 仰天作鳴叫狀, 四周則有許多不知名
的鳥類圍繞在其附近, 地面上則有許多珍奇異獸或長鳴附和, 或低頭臣服
, 姿態不一, 但無一不表示了對大梟無比的敬意, 你一細看大梟, 其眼睛
炯炯有神, 雖張翼而氣息內殮, 穩重而不露鋒芒, 而右邊則是一片石壁, 
上面刻著幾個大字...
LONG
    );
 set("exits",([ "west":__DIR__"birdpilla5", 
                "east":__DIR__"birdpilla8",
    ]));
 set("item_desc",(["石壁":"
                這是一片光滑的石壁, 上面刻著幾個潑墨般的大字\n

                   "RED"展                天"NOR"\n
                   "RED"翅                梟"NOR"\n
                   "RED"江                一"NOR"\n
                   "RED"湖                鳴"NOR"\n
                   "RED"三                動"NOR"\n
                   "RED"千                武"NOR"\n
                   "RED"里                林"NOR"\n

                看到著幾個豪氣干雲的大字, 你不禁想像當年天梟\n
                興盛之時, 是何等風光!!念及至此, 你激動的不能\n
                自己, 你已經完全的確定你找到消聲匿跡於武林許\

                久的當年第一大教-"HIC"天梟教"NOR"了!!\n",
  ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

