#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "收集夜禍石";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "少帥軍交待你一個任務，要你去「血腥荒野」收集夜禍石，證明你的武術。\n";
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
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：血腥荒野是通往奧特蘭克山谷前的一處大草原，駐紮著夜禍大軍。\n",
        "$N對著$n說道：我希望你能為天下蒼生盡份心力，除去敵軍。但是在那之前，要先證明你的實力。\n",
        "$N對著$n說道：請去血腥荒野取來五十粒夜禍石吧。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
        return ([ ]);
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
//return ([]);
    mapping item = ([
        "/open/world1/tmr/blood_field2/npc/obj/q_stone.c": 50,
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

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：不錯不錯！！你的確是位非常傑出的人材！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "經驗值 300,000 點。\n";
    msg += "戰爭藝術 30 點。\n";
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
    player->add("exp", 300000);
    tell_object(player, HIY"(你獲得了 300,000 點經驗值。)\n"NOR);
    player->add("war_art", 30);
    tell_object(player, HIY"(你獲得了 30 點戰鬥藝術。)\n"NOR);
}


