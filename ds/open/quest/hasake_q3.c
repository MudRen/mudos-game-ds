// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���ħJ�i�h������ II";
}

// ���ȴy�z
string getDetail() {
    string msg;
	msg = "�b�w���L���٦����Y���ǯT���A�̬O����A���`�L�D�`�h���ͩR�A\n";
	msg += "�Ʊ�A��A�����ħJ�����o�Ǻ׮`�A��_�j��쪺���R�ͬ��C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 30;
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
   if( player->query("level") < 30 ) return 0;
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�b�w���L���٦����Y���ǯT���A�̬O����A�]���`�L���֥ͩR�C\n",
        "$N���$n���D�G�ڧƱ�A��A�����ħJ�����o�Ǻ׮`�C\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
          "/open/world1/tmr/hasake/npc/wolf-king.c": 7, 
        ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // �U��
    ]);
    return item;
*/
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
        "$N���$n���D�G�A�S�A�@�������A�O�쫢�ħJ�i�h�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "���U�T�ɪO�C\n";
    msg += "�n�� 10 �I�C\n";
    msg += "�԰����N 5 �I�C\n";
    return msg;
}


void reward(object player, object npc) {
        player->add("bank/past", 50000);
    tell_object(player, HIY"(�A��o�F���U�T�ɪO�C)\n"NOR);
        player->add("popularity", 10);
    tell_object(player, HIY"(�A��o�F 10 �I�n��C)\n"NOR);
        player->add("war_art", 5);
    tell_object(player, HIY"(�A��o�F 5 �I�԰����N�C)\n"NOR);
}

