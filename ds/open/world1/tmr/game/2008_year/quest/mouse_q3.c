// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// 說明此檔是任務，這個函式不需要變動
int isQuest() { return 1; }

// 可重覆接
int isNewly() { return 1; }

// 任務名稱
string getName() {
    return "喜多 的「鼠歲喜臨門」集字";
}

// 任務描述
string getDetail() {
return "
給喜多(theodore)搜集「鼠歲喜臨門」四個字樣，你可以
再隨機十個福袋。
";
}

// 任務等級
int getLevel() {
     return 1;
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
   return 1;
}

// 接受任務的NPC  (以檔名來識別)
string getAssigner() {
    return "/open/world1/tmr/game/2008_year/npc/theodore.c";
}

// 完成任務的NPC  (以檔名來識別)
string getRewarder() {
    return "/open/world1/tmr/game/2008_year/npc/theodore.c";
}

// 接受任務時的訊息
string *getAssignMessage() {
    // $N為NPC, $n為player
    string *msg = ({
        "$N對著$n說道：你能幫我搜集「鼠」、「歲」、「喜」、「臨」、「門」的字樣嗎？\n",
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
		"/open/world1/tmr/game/2008_year/obj/word1.c" : 1,
		"/open/world1/tmr/game/2008_year/obj/word6.c" : 1,
		"/open/world1/tmr/game/2008_year/obj/word7.c" : 1,
		"/open/world1/tmr/game/2008_year/obj/word8.c" : 1,
		"/open/world1/tmr/game/2008_year/obj/word9.c" : 1,
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
        "$N對著$n說道：你做的真是太棒了！\n",
    });

    return msg;
}

// 任務日誌上的獎勵說明
string getReward()
{
    return "可隨機獲得十個福袋。";
}

string *items = ({
	"bag1.c",
	"bag2.c",
	"bag3.c",
	"bag4.c",
	"bag5.c",
});

void reward(object player, object npc) {
	string file;
	object eq;
	int i;
	for(i=0;i<10;i++) {
		file = items[random(sizeof(items))];
		eq = new("/open/world1/tmr/game/2008_year/obj/" + file );
		eq->move(player);
		tell_object(player, 
			sprintf(HIW"你獲得一個%s。\n"NOR, eq->name())
		);
	}
}

