/*  TestQuest.c

一個用來測試任務系統正確性的測試用任務，也是任務撰寫的範例。

目前任務支援類型：
1. 殺死某些數量的怪物
2. 取得某些數量的物品
3. 造訪性任務  (意指某A要你去找某B，即可完成任務)

注意：因為以檔名做識別，在設定時檔名記得加上 .c 

    write by Acme- 2007.02.04
 */

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 0; }

// 任務名稱
string getName() {
    return "好戰的形天";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "孟村木橋上的仇池山已經數千年沒有戰鬥了，他骨子裡的血液激昂澎\n";
    msg += "湃，他希望你代他去參與一場戰爭，聽說天城那個官老爺品性不良，\n";
    msg += "十足該死的傢伙。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 30;
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
if( player->query("level") < 30 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/area/npc/shan.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        CYN"$N深深的嘆了一口氣。\n"NOR,
        "$N對著$n說道：這些日子實在無聊到發悶。\n",
        "$N對著$n說道：我已經幾千年沒有戰鬥了，我的血液已經激昂澎湃啊！\n",
        "$N對著$n說道：聽說天城那個官老爺品性不良，十足該死的傢伙。\n",
        "$N對著$n說道：如果你能幫我去參加戰爭的話，我會感激你的。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/acme/cominging/npc/soldier.c": 50,  // 士兵
        "/open/world1/acme/cominging/npc/general.c": 40,  // 牙將
        "/open/world1/acme/cominging/npc/general2.c": 30,  // 裨將
        "/open/world1/acme/cominging/npc/chief.c": 20,     // 百夫長
        "/open/world1/acme/cominging/npc/chief2.c": 15,    // 千夫長
        "/open/world1/acme/cominging/npc/leader.c": 10,    // 總兵
        "/open/world1/acme/cominging/npc/lord.c": 6,      // 把總
        "/open/world1/acme/cominging/npc/lu.c": 1,        // 成陸
        "/open/world1/acme/cominging/npc/gu.c": 1,        // 成谷
        "/open/world1/acme/cominging/npc/chung.c": 1,     // 林沖
    ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品不是複合型的也適用
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // 猴牙
    ]);
    return item;
*/
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
    return "/open/world1/tmr/area/npc/shan.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：實在是太棒了，我實在是太興奮了！\n",
        "$N對著$n說道：真是感謝你呀！\n",
        CYN"$N快樂的手舞足蹈。\n"NOR,
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "經驗值 500000 點。\n";
    msg += "戰鬥藝術 200 點。\n";
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
player->add("war_art", 200);
    tell_object(player, HIY"(你獲得了 200 點戰鬥藝術。)\n"NOR);

player->add("exp", 500000);
    tell_object(player, HIY"(你獲得了 500000 點經驗值。)\n"NOR);
}
