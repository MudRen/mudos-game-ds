// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���ħJ�i�h������";
}

// ���ȴy�z
string getDetail() {
    string msg;
	msg = "���ħJ�����䦳�@�y�w���L�A��ۤ@�s���r���ǯT�A\n";
	msg += "�p�G�A�Q�n�����ۤw�O�i�h�A�N�h�M���o�s�ǯT�a�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 20;
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
   if( player->query("level") < 20 ) return 0;
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
        "$N���$n���D�G�b���ħJ�����䦳�@�y�w���L�A��ۤ@�s���r���ǯT�C\n",
        "$N���$n���D�G�p�G�A�Q�n�����ۤw�O�i�h�A�N�h�M���o�s�ǯT�a�C\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/hasake/npc/wolf1.c": 5,
        "/open/world1/tmr/hasake/npc/wolf2.c": 5, 
        "/open/world1/tmr/hasake/npc/wolf3.c": 5, 
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
        "$N���$n���D�G�ڤw�gť��j�a��A�����g�F�A�A�G�M�O��i�h�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�T�U�T�ɪO�C\n";
    msg += "�n�� 5 �I�C\n";
    msg += "�԰����N 3 �I�C\n";
    return msg;
}


void reward(object player, object npc) {
        player->add("bank/past", 30000);
    tell_object(player, HIY"(�A��o�F�T�U�T�ɪO�C)\n"NOR);
        player->add("popularity", 5);
    tell_object(player, HIY"(�A��o�F 5 �I�n��C)\n"NOR);
        player->add("war_art", 3);
    tell_object(player, HIY"(�A��o�F 3 �I�԰����N�C)\n"NOR);
}

