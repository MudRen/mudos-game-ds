// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "打鐵老師傅的金礦委託";
}

// 任務描述
string getDetail() {
    string msg;
    msg  = "打鐵老師傅需要一些金礦，你可以從萬龍古墓深處撿到。\n";
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
        "$N對著$n說道：黃沙嶺那邊有個萬龍古墓，聽說裡頭深處有質地極好的黃金。\n",
        "$N對著$n說道：如果你能幫我撿五個回來，我能給你一些報酬。\n",
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
        "/open/world1/wilfred/sand/npc/obj/obj30.c": 5,
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
        "$N對著$n說道：喔喔！！這可是最純又足重的黃金啊，真是太感謝你了！。\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "
經驗值 250,000 點
戰鬥藝術 25 點
10%, 60%, 或100%攻擊卷軸二張。
";
}

string *items = ({
         "10_atk.c",
         "60_atk.c",
         "100_atk.c",
});

void reward(object player, object npc) {
    player->add("exp", 250000);
    tell_object(player, HIY"(你獲得了 250,000 點經驗值。)\n"NOR);
      player->add("war_art", 25);
    tell_object(player, HIY"(你獲得了 25 點戰鬥藝術。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(你獲得一張卷軸。)\n"NOR);
}


