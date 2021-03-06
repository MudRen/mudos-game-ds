#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "挑戰骨龍夜禍";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "夜禍是血腥荒野的領主，是一條非常強壯的龍，你這次的任務就是去挑戰夜禍，並殺掉牠。\n";
    msg  += "你必須要先從野樹人身上取得「夜禍烏石」，並在骨龍迷霧中捏碎(crumb)，\n";
    msg  += "才能將夜禍的身影從濃霧中顯現出來，如此一來，你才能挑戰他。\n";
    
    return msg;
}

// 任務等級
int getLevel() {
    return 45;
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
    if( player->query("level") < 40 ) return 0;
    if( player->isSolved("/open/quest/bf_q1.c") == -1) return 0;
      if( player->isSolved("/open/quest/bf_q2.c") == -1) return 0;
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
        "$N對著$n說道：夜禍是血腥荒野的領主，是一條非常強壯的龍，你這次的任務就是去挑戰夜禍，並殺掉牠。\n",
        "$N對著$n說道：但是夜禍都躲藏在骨龍迷霧之中，你必須要先從野樹人身上取得「夜禍烏石」，\n",
        "$N對著$n說道：並在骨龍迷霧中捏碎(crumb)，才能將夜禍的身影從濃霧中顯現出來，如此一來，你才能挑戰他。\n",
        "$N對著$n說道：這是一項非常艱難的任務，希望你能為天下蒼生盡一份力。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping item = ([
       "/open/world1/tmr/blood_field2/npc/nightbane.c": 1,
     ]);
    return item;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
        return ([]);
/*
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/war_plan.c": 1,
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

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你又再一次完成不可能的任務，少帥軍全體上下都非常感謝你的付出。\n",
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
    tell_object(player, HIY"(你獲得了 30 點戰爭藝術。)\n"NOR);
}

