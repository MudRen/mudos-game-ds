// 復歸無極 (進入三階的任務)

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

/* 此任務是否能重複解  return 0  不能重複
                       return 1  可重複
   建議最好設定不能重複。
 */
int isNewly() { return 0; }

// 任務名稱
string getName() {
    return "復歸無極";
}

// 任務描述
string getDetail() {
    string msg;

    msg  = "無極即道，是比太極更加原始更加終極的狀態。\n";
    msg += "你必需戰勝各門派的領袖人物，你才有資格參研無極。\n";

    return msg;
}

// 任務等級
int getLevel() {
    return 50;
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
        if( player->query("level") < 50 ) return 0;
        if( player->query("adv_class") == 3 ) return 0;
    return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：無極即道，是比太極更加原始更加終極的狀態。\n",
        "$N對著$n說道：你必需戰勝各門派的領袖人物，你才有資格參研無極。\n",
    });

    return msg;
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/npc/advmaster.c": 1,     //吳鐘
        "/open/world1/cominging/area/npc/yuanlieh.c": 1,        //軒轅烈
        "/open/world1/tmr/advthief/thief_adv_master.c": 1,      //賊帥
        "/open/world1/kkeenn/love/npc/master_2.c": 1,   //香香
        "/open/world1/tmr/advbonze/npc/bonze_adv_master.c": 1,          //妙見
        "/open/world1/acme/area/npc/advmaster.c": 1,    //蕭日山
        "/open/world1/tmr/frost/npc/yun-zhong-zi.c": 1,    //雲中子
        "/open/world1/tmr/dragoncity/npc/kou-zhong.c" : 1, // 寇仲
    ]);
    return kill;
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

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// 完成任務時的訊息
string *getRewardMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：不錯不錯，你的確証明出你的實力了！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    string msg = "";
    msg += "戰鬥藝術 1000 點。\n";
    msg += "聲望 100 點。\n";
      msg += "晉升「復歸無極」。\n";
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
        player->add("war_art", 1000 );
    tell_object(player, HIY"(你獲得了 1000 點戰鬥藝術。)\n"NOR);
        player->add("popularity", 100 );
    tell_object(player, HIY"(你獲得了 100 點聲望。)\n"NOR);
        
        // 轉入三階
        message("world:world1:vision",
                HIW "\n【無極之外】"HIC""+player->name(1)+HIC "一聲清嘯：「知其白，守其黑，為天下式。為天下式，常德不忒，復歸於無極。」\n\n"NOR
        ,users() );
        player->set("class3","復歸無極");
        player->set("adv_class",3);
}



