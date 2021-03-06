// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "打鐵老師傅的白金委託";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "打鐵老師傅需要一些白金，你可以到遺世島上找找看。\n";
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
    if( player->isSolved("/open/quest/eqmaster_gold_q.c") == -1) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：遠在海外有個住滿奇珍異獸的遺世島，島上藏有高品質的白金礦。\n",
        "$N對著$n說道：希望這次你仍然能幫我拿五個回來，我能給你一些報酬。\n",
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
    mapping item = ([
        "/open/world1/ksj/lost_island/npc/eq/gold.c": 5,
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
        "$N對著$n說道：喔喔！！真是漂亮又高貴的白金，真是太感謝你了！。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "
經驗值 500,000 點
戰鬥藝術 50 點
10%, 60%, 或100%攻擊卷軸四張。
";
}

string *items = ({
         "10_atk.c",
         "60_atk.c",
         "100_atk.c",
});

void reward(object player, object npc) {
    player->add("exp", 500000);
    tell_object(player, HIY"(你獲得了 500,000 點經驗值。)\n"NOR);
    player->add("war_art", 50);
    tell_object(player, HIY"(你獲得了 50 點戰鬥藝術。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}


