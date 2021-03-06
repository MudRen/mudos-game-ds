
// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "聶神父的請求";
}

// 任務描述
string getDetail() {
        string msg;
        msg = "聶神父想要一些東方古文化的遺物，希望你能完成他的心願。\n";
        return msg;
}

// 任務等級
int getLevel() {
      return 5;
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
   if( player->query_skill("literate") < 60 ) return 0;
   if( player->query_skill("literate") >= 100 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/north_bar/npc/nie.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/north_bar/npc/nie.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：聽說遠在哈薩克草原，有一些重要的東漢石器。\n",
        "$N對著$n說道：我仰慕東方文化很久了，不知道你能否幫我取得一些石器？\n",
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
        "/open/world1/tmr/hasake/npc/obj/stone1.c": 3, 
        "/open/world1/tmr/hasake/npc/obj/stone2.c": 3, 
        "/open/world1/tmr/hasake/npc/obj/stone3.c": 3, 
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
        "$N對著$n說道：這本聖經就送給你，願上帝祝福你。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg;
    msg  = "一本聖經。\n";
    return msg;
}


void reward(object player, object npc) {
    object bible;
    bible = new("/open/world1/tmr/north_bar/npc/obj/bible.c");
    bible->move(player);
    tell_object(player, HIY"(你獲得一本聖經。)\n"NOR);
}


