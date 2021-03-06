// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// 任務名稱
string getName() {
    return "巨魔之力符文";
}

// 任務描述
string getDetail() {
    string msg;

    msg  =  "宗族長為了感謝你對苗家村的幫忙，願意幫你製造「巨魔之力」符文。\n";
    msg  += "在所需要的原料之中，有個「冰霜軟毛」最難取得，因為冰霜巨魔平常\n";
    msg  += "都藏在地底深處，很少出來走動。不過冰霜巨魔最喜歡吃牛肉，你可以\n";
    msg  += "到牯牛草原那取得得牛肉乾，再到地底洞穴用牛肉乾來吸引冰霖巨魔出\n";
    msg  += "來，不過冰霜巨魔是相當強的魔物，你一定要做好萬全的準備。\n";
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
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;
        if( objectp(present("_TROLL_FORCE_",player)))
                return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：真是非常感謝你對苗家村的幫忙。\n",
        "$N對著$n說道：要是你能取來相關的原料，我可以幫你設計「巨魔之力」的符文。\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll_blood.c": 10,
        "/open/world1/tmr/north_forest/npc/obj/troll_chest_bone.c": 3,
        "/open/world1/tmr/north_forest/npc/obj/troll_head_bone.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/troll_spinal_bone.c": 3,

        "/open/world1/tmr/north_forest/npc/obj/frost-fur.c": 1,
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
        "$N對著$n說道：你的原料都取來了，我馬上就幫你做符文。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "巨魔之力(Troll-force symbol)符文一個。\n";
}



void reward(object player, object npc) {
    new("/open/world1/tmr/north_forest/npc/obj/troll-force")->move(player);
    tell_object(player, HIY"(你獲得一個巨魔之力。)\n"NOR);

}

