// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "��媺�u�����_�v���r";
}

// ���ȴy�z
string getDetail() {
return "
�����(alvin)�j���u�����_�v�T�Ӧr�ˡA�A�i�H
��o�����I��1�I�C
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
    return "/open/world1/tmr/game/2008_year/npc/alvin.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/game/2008_year/npc/alvin.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�����ڷj���u���v�B�u�ӡv�B�u�_�v���r�˶ܡH\n",
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
		"/open/world1/tmr/game/2008_year/obj/word2.c" : 1,
		"/open/world1/tmr/game/2008_year/obj/word3.c" : 1,
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
    return "��o�@�I�u�����_�v�����I��";
}

void reward(object player, object npc) {
          "/u/t/tmr/game/2008_year/board.c"->addScore(player, 1);
	tell_object(player, HIW"(�A��o�@�I�����I�ơC)\n"NOR);
}

