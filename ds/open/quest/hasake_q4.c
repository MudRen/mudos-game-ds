// tmr 2007/07/15

#include <ansi.h>

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "哈薩克勇士的証明 III";
}

// 任務描述
string getDetail() {
    string msg;
	msg = "白狼神是哈薩克灰狼的守護神，這一次，你得要想法子除掉白狼神。\n";
	msg += "白狼神平常都藏匿著，沒有人可以找到牠；但當牠的子民被殘殺時，牠就有可能會現身了。";
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
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/hasake_q3.c") == -1) return 0;
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：白狼神是哈薩克灰狼的守護神，這一次，你得要想法子除掉牠。\n",
    });

    return msg; 
}

// 任務須要殺死某些怪物，若不需要則 return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/hasake/npc/white-wolf.c": 1, 
        ]);
    return kill;
}

// 任務須要取得某些物品，若不需要則 return 0
// 注意：這些物品必需是複合型物件才行
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // 猴牙
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
        "$N對著$n說道：你真是一個偉大的哈薩克勇士，阿拉真神一定會祝福你。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
     return "
100%, 60%, 10% 智慧卷軸隨機二張。
戰鬥藝術 3 點。
";
}

string *items = ({
	"10_int.c", "60_int.c" , "100_int.c"
});


void reward(object player, object npc) {
    player->add("war_art", 3);
    tell_object(player, HIY"(你獲得了 3 點戰鬥藝術。)\n"NOR);

    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}

