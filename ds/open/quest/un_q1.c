// tmr 2007/03/10

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "初探無寧莊園";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "虛雲和尚希望你能去無寧莊園取來三十面無寧牌子跟十粒黃牙石，好證明你的能力。\n";
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
    return "/open/world1/acme/bonze/npc/master.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/acme/bonze/npc/master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：無寧莊園是在山崖古道上的一處莊園，裡頭住著盡是厲鬼妖邪。\n",
        "$N對著$n說道：我希望你能為天下蒼生盡份心力，去除妖邪，在那之前，要先證明你的實力。\n",
        "$N對著$n說道：這位施主先取來三十面無寧牌子跟十粒黃牙石。\n",
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
        "/open/world1/tmr/unquiet_manor/npc/obj/q_plate.c": 30,
        "/open/world1/tmr/unquiet_manor/npc/obj/q_stone.c": 10,
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
        "$N對著$n說道：阿彌陀佛！！施主功\德無量！\n",
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


