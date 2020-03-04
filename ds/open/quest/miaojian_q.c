// tmr 2007/02/28

#include <ansi.h>

void create() { seteuid(getuid()); }



// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "妙見的請託";
}

// 任務描述
string getDetail() {
    string msg;
        msg = "妙見高僧為凌雲寺前任住持，畢生鑽研佛道，慧根深厚，中年時期因緣際會\n";
        msg += "習得佛門中第一絕技「如來九式」，自此佛、武二道互輔互長，修為幾以達\n";
        msg += "到「虹化」的境界，希望你能幫他取得如來佛心，增益他的修為。\n";
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
    return "/open/world1/tmr/advbonze/npc/bonze_adv_master.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/advbonze/npc/bonze_adv_master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：如來佛心為世間不可多得的佛教聖物，希望你能幫我取得一份。\n",
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
        "/open/world1/tmr/advbonze/npc/obj/heart.c": 1, // 如來佛心
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
        "$N對著$n微笑說道：真是太謝謝你了，我佛慈悲，阿彌陀佛。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "經驗值 100,000 點。\n";
    msg += "聲望 10 點。\n";
     msg += "戰鬥藝術 50 點。\n";
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
        player->add("exp", 100000);
    tell_object(player, HIY"(你獲得了 100,000 點經驗值。)\n"NOR);
        player->add("popularity", 10);
    tell_object(player, HIY"(你獲得了 10 點聲望。)\n"NOR);
         player->add("war_art", 50);
      tell_object(player, HIY"(你獲得了 50 點戰鬥藝術。)\n"NOR);
  

}

