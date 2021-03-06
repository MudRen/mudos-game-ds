// 指極心訣(indicate-knack) - 疾風進階技能

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "步靈城的裁縫師";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "位於步靈城織布紡內的裁縫師劉靖文，因為前來找\n";
    msg += "她製作衣服的顧客越來越少，賺的錢也越來越少，\n";
    msg += "便決定要用自身的裁縫手藝做些衣服以外的東西賺\n";
    msg += "外快。\n"; 
    return msg;
}

// 任務等級
int getLevel() {
    return 35;
}

/* 接受任務的前置條件，可能是
        1. 等級需求
        2. 職業需求
        3. 種族需求
        4. 已完成某些任務需求
    等等，應可以自由發揮才是。
    回傳非零值表示符合條件。
 */
int preCondition(object player) {
   if( player->query("level") < 35 ) return 0;
     if( player->query_capacity() > player->query_max_capacity()/2 ) return 0;
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/cominging/area/npc/spinner.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N說道﹕"+HIY+"這位客人，您是四處旅行的冒險者吧，看你拿著這麼多東西，需不需要我幫您縫製一個袋子呢？\n"NOR,
        "$N說道﹕"+HIY+"只要幫我收集一些材料，和給我一點工錢，我就可以幫您做個好用的袋子。\n"NOR,
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
   return ([]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
    mapping item = ([
        "/open/world1/whoami/birdarea/npc/obj/bag.c": 1,        // 神風袋
        "/open/world1/cominging/purple_sun/npc/obj/stomach-bag.c": 1,               // 獸王胃袋
        "/open/world1/obj/gold_tackle.c": 1, // 金絲漁網
        "/open/world1/wilfred/sand/npc/eq/eq4.c": 1, // 銀狼皮
        "/open/world1/moonhide/area/leather3.c": 1, // 羽鵰皮
        "/open/world1/eq/viper_cloth.c": 1, // 蟒錦戰衣
        "/open/world1/cominging/area/npc/obj/cloth3.c": 1, // 銀絲
        "/open/world1/moonhide/pool/npc/obj/snake-waist2.c": 1, //血蛟軔帶
        "/obj/money/coin.c": 10000, // 10000 coin
    ]);
    return item;
}


// 完成任務的條件除了系統提供的
// 1. 搜集物品
// 2. 殺了足夠數量的怪物之外
// 有需要的話，還可以自訂完成任務條件
// return 1, 為滿足條件, return 0;為失敗
int postCondition(object player, object npc)
{
    return 1;
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/cominging/area/npc/spinner.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：請稍等一下，我馬上替您縫製。\n",
        "$N向$n道謝。\n",
        "$N在感謝$n之後，趕緊把$n所給$N的材料放在工作台上開始裁剪了起來！\n",
        "$N拿著裁剪好的材料在縫紉機前工作。\n",
        "$N拿起縫好的袋子把邊緣修剪了一下。\n",
        "$N拿起"WHT"銀絲"NOR"用高明的手藝替袋子繡上圖案，並在袋口附近用"HIY"金絲"NOR"繡上了你的名字。\n",
     HIY"(一個袋子就這麼完成了)\n"NOR,
    });
    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
     string msg = "獲得「巧手如意袋 」一只，且上面繡有您個人的名字。\n";
    return msg;
}

/*  任務獎勵
    獎勵應該能自由發揮，如：
        1. 獲得經驗
        2. 獲得物品
        3. 獲得短暫Buff
        4. 習得某技能
        5. 更改玩家狀態, ex: 轉職
 */
void reward(object player, object npc) {
        object ob = new("/open/world1/cominging/area/obj/ingenious_bag.c");
        ob -> set("name",HIC"巧手"HIW"如意袋"HIM"【"HIY+player->query("id")+HIM"】"NOR);
        ob -> move(player);
}

