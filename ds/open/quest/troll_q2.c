// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�M���·t�ή��ƥ��]";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�]�a���y���b�_��j�˪L�ǡA�ѩ�˪L����ۭ��H�ת����]�A�������\n";
    msg += "�L�۴��ߦQ�x���ͬ��A�v�ڪ��Ʊ�A��i�@�B�����M������r���·t���]�C\n";
    msg += "�ή��ƥ��]�C\n";

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
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�˪L�`�B��ۧ���r���·t���]�򮣩ƥ��]�C\n",
        "$N���$n���D�G���F�]�a�����w���A�@�w�n�N���]�������I�I\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/north_forest/npc/troll4.c": 3, 
        "/open/world1/tmr/north_forest/npc/troll5.c": 3, 
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
        "$N���$n���D�G�u�O�����§A�������I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "���U�T�ɪO�C\n";
    msg += "�g��� 100,000 �I�C\n";
    msg += "�n�� 3 �I�C\n";
    msg += "�԰����N 6 �I�C\n";
    return msg;
}


void reward(object player, object npc) {
    player->add("bank/past", 50000);
    tell_object(player, HIY"(�A��o�F ���U�T�ɪO�C)\n"NOR);
    player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 100,000 �I�g��ȡC)\n"NOR);
    player->add("popularity", 3);
    tell_object(player, HIY"(�A��o�F 3 �I�n��C)\n"NOR);
    player->add("war_art", 6);
    tell_object(player, HIY"(�A��o�F 6 �I�԰����N�C)\n"NOR);
}

