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
    return "指極心訣";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "「指極心訣」是疾風門的絕技，你必須從活死人墓\n";
    msg += "取來玄鐵劍及玉女劍，才能獲准學習這項技能。\n";

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
   if( player->query("class2") != "疾風門" ) return 0;
   if( player->query_skill("star-sword") < 90 ) return 0;
   if( player->query_skill("moon_force") < 90 ) return 0;

   // 有學過就不能再解了
   if( player->query_skill("indicate-knack") > 0 ) return 0;
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/cominging/area/npc/yuanlieh.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：「指極心訣」是本派絕技，只傳給有潛力的弟子。\n",
        "$N對著$n說道：活死人墓的玄鐵劍及玉女劍為武林中的神兵利器。\n",
        "$N對著$n說道：去取來給我吧，好証明妳有這個資格。\n"
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
        "/open/world1/moonhide/area/sword.c": 1,        // 玄鐵
        "/open/world1/moonhide/area/sword3.c": 1,               // 玉女
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
    return "/open/world1/cominging/area/npc/yuanlieh.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：不錯不錯，你果真給我取來這兩把神兵利器！\n",
        "$N對著$n說道：好徒弟，我這就傳給你這項絕技。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg = "習得「指極心訣(indicate-knack) 」";
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
        player->set_skill("indicate-knack", 10);
}

