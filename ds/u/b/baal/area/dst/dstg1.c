#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"暗斯德塔庭院"NOR);
        set("long", @LONG
雄偉的暗斯德塔正豎立在眼前, 一條黑曜石鋪成的小徑
穿過庭院, 通向那由純銀製成, 白金鑲邊的大門, 小徑兩旁
美麗的花草讓人感覺不到吟遊詩人口中所敘述那種一定伴隨
著古塔的陰森森的感覺, 兩旁的花朵嬌艷動人, 令人有想將
之摘下的衝動.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north": __DIR__"dstg3",
            ]));
 set("item_desc",([
           "花朵":"小徑兩旁的花卉萬紫千紅, 爭相鬥豔, 俱都是你沒見過的品種, 你打從心理喜歡上這花
, 有種不管這座塔的主人會不會怪罪都想要摘(pick)一朵下來的慾望.\n",
           "大門" : "一扇緊閉著的大門, 上並無大鎖, 看來似乎應手即開(pull), 問題
是, 天知道有什麼魔法附在上面?\n",
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

void init()
{
        add_action("typepick","pick");
        add_action("typepull","pull");
}
     int typepick(string arg)
{
        object me;
        me=this_player();
        if(arg != "花朵") 
         return 0;
        else {
        message_vision(
        HIB"$N蹲了下來, 想摘下一朵不知名的花朵, 但竟然抓了個空！
$N凝神細看, 這才發現這整片花圃有一種若隱若現的感覺, 看來整片花圃
都是魔法構成的幻像！！！\n"NOR,me);
        return 1;
             }
}
int typepull(string arg)
{
        object me;
        me=this_player();
        if(arg != "大門") 
         return 0;
        else {
        message_vision(
        HIC "$N抓住了欄杆, 剛要使勁拉開, 突覺一股力量在背上一推, 身子已騰空而起！！\n\n" NOR ,me);
        message_vision( HIC "$N在空中不由自主的翻了個跟斗, 越過了大門, 一屁股跌在地上, 摔的好不疼痛...><\n\n" NOR ,me);
        me->move(__DIR__"dst1");
        return 1;
             }
}

