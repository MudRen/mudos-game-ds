#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"暗斯德塔庭院"NOR);
        set("long", @LONG
黑曜石鋪成的小徑直直的通向遠方的高塔, 路旁的花花
草草長的更茂盛了, 其中的品種更是千奇百怪, 有即使在幽
遮蘭皇城內也難得一見的費衛斯開菊, 遙遠的東方特有的品
種："紫蘇玉蘭花", 和在熔岩山脈才有的薩朵鬖株葵。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north": __DIR__"dstg2",
                        "south": __DIR__"dstg1",
            ]));
        set("outdoors","land");
        set("objects", ([
  __DIR__"npc/reciter1" : 2,
]));

        set("no_clean_up", 0);
        setup();
}

int room_effect(object me)
{

         switch(random(6))
        {
         case 0:
         write("一隻蝴蝶輕輕巧巧的在你頭上盤旋了兩圈, 緩緩的飛向庭院的另一頭\n");
         tell_object(me, HIY "一陣淡淡的幽香鑽進了你的鼻子, 立時令人感到通體舒暢。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write("你無意間看到小徑上的一塊黑耀石似乎閃了一下..... \n");
         tell_object(me, HIC "一隻青蛙忽地從花朵間跳了出來, 對你「口瓜！」的叫了一聲, 隨即化成一團輕煙, 消失了...\n" NOR ); 
         return 1;

         case 2:
         write("一陣微風徐徐自後方吹來... \n");
         tell_object(me, RED "一隻貓頭鷹快速的從你頭上低飛而過！！\n" NOR ); 
         return 1;

case 3:
         write("你看見遠方的天空出現了一個黑點, 黑點緩緩的靠近, 原來是一隻烏鴉。 \n");
         tell_object(me, HIW "烏鴉飛過你的頭上, 「噗！」的一聲, 一團白色, 黏稠的鳥大便掉在你頭上...:Q\n" NOR ); 
         return 1;

case 4:
         write("草叢裡傳來一陣騷動！？... \n");
         tell_object(me, HIB "一隻高度只到你膝蓋\的大象沒命似的奔逃, 被一隻全身金黃色的老鼠追著...\n" NOR ); 
         return 1;

case 4:
         write("一塊黑耀石石板緩緩的往上移, 被推了開來... \n");
         tell_object(me, HIG "一隻有著翅膀銀色的小龍蝦爬了上來, 重新把石塊鋪好, 隨即一邊哼著「A dear John Letter」一邊展開翅膀飛上天...\n" NOR ); 
         return 1;

         default:       return 1;
        }
}


