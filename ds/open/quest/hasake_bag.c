// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "失落的東漢石器";
}

// 任務描述
string getDetail() {
        string msg;
        msg = "有一批重要的東漢石器，遺失在針葉林中，\n";
        msg += "如果你能替計老人取回這些石器，你可以獲得一袋香甜的乳酪。\n";
        return msg;
}

// 任務等級
int getLevel() {
    return 20;
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
   if( player->query("level") < 20 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/ji.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/ji.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：我在哈薩克這研究東漢石器數十年了。\n",
        "$N對著$n說道：在前兒個日子，我有三個重要的石器掉在針葉林中。\n",
        "$N對著$n說道：希望你能幫我取回這些石器。\n",
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
        "/open/world1/tmr/hasake/npc/obj/stone1.c": 1, 
        "/open/world1/tmr/hasake/npc/obj/stone2.c": 1, 
        "/open/world1/tmr/hasake/npc/obj/stone3.c": 1, 
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
        "$N對著$n說道：真是太感謝你了。\n",
        "$N對著$n說道：這是我自製的一袋乳酪。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "一萬枚銅板。\n";
    msg  += "一口狼皮袋及二十個乳酪。\n";
    return msg;
}


void reward(object player, object npc) {
        object bag, ch;  // 袋子跟乳酪
        int i;

        bag = new("/open/world1/tmr/hasake/obj/wolf-bag.c");
        for(i=0;i<20;i++) {
                ch = new("/open/world1/tmr/hasake/obj/cheese.c");
                ch->move(bag);
        }

    player->add("bank/past", 10000);
    tell_object(player, HIY"(你獲得了一萬枚銅板。)\n"NOR);
    bag->move(player);
    tell_object(player, HIY"(你獲得了一袋乳酪。)\n"NOR);
}

