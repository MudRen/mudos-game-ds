// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�ߦh ���u�������{���v���r";
}

// ���ȴy�z
string getDetail() {
return "
���ߦh(theodore)�j���u�������{���v�|�Ӧr�ˡA�A�i�H
�A�H���Q�ӺֳU�C
";
}

// ���ȵ���
int getLevel() {
     return 1;
}

/* �������Ȫ��e�m����A�i��O
        1. ���ŻݨD
        2. ¾�~�ݨD
        3. �رڻݨD
        4. �w�����Y�ǥ��ȻݨD
    �����A���i�H�ۥѵo���~�O�C
    �^�ǫD�s�Ȫ�ܲŦX����C
 */
int preCondition(object player) {
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/game/2008_year/npc/theodore.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/game/2008_year/npc/theodore.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�����ڷj���u���v�B�u���v�B�u�ߡv�B�u�{�v�B�u���v���r�˶ܡH\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
        return ([ ]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
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


// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    return 1;
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�����u�O�ӴΤF�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "�i�H����o�Q�ӺֳU�C";
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
			sprintf(HIW"�A��o�@��%s�C\n"NOR, eq->name())
		);
	}
}

