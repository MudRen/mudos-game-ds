// tmr 2007/03/10

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "消滅野樹人及樹鬚";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "野樹人及樹鬚是夜禍的幫手，要是能夠消滅他們，勢必能夠消弱夜禍的勢力。\n";
    return msg;
}

// 任務等級
int getLevel() {
    return 40;
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
        "$N對著$n說道：野樹人及樹鬚是夜禍的幫手，要是能夠消滅他們，勢必能夠消弱夜禍的勢力。\n",
        "$N對著$n說道：樹人擁有非常強大的攻擊力，請你做好準備再上路。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/blood_field2/npc/ents2.c": 3,
        "/open/world1/tmr/blood_field2/npc/ents3.c": 2,
        ]);
    return item;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
        return ([]);
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
    return "
經驗值 100,000 點。
戰鬥藝術 10 點。
10% 體質卷軸3張。
";
}


void reward(object player, object npc) {
    player->add("exp", 100000);
    tell_object(player, HIY"(你獲得了 100,000 點經驗值。)\n"NOR);
    player->add("war_art", 5);
    tell_object(player, HIY"(你獲得了 10 點戰鬥藝術。)\n"NOR);
    new("/open/enhance/10_con")->move(player);
    new("/open/enhance/10_con")->move(player);
    new("/open/enhance/10_con")->move(player);
    tell_object(player, HIY"(你獲得三張卷軸。)\n"NOR);
}


