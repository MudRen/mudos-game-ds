// tmr 2007/02/28

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�M�����F��";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�s�������䬰�u�u���F�A�`���L�c���@�����F��X�S�A�T���L�����ӤH�ήȫȡA\n";
    msg += "�A�y���j�a�����K�C��ɦu�çƱ�A�������M�����F��A�n�����ȤH�����w�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
      return 5;
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
         if( player->query("level") < 5) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/wilfred/sand/npc/npc48.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/wilfred/sand/npc/npc48.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������F�_�ӡC\n"NOR,
        "$N���$n���D�G���F�s�������w�A�ڭ̤@�w�n�������F��I�I\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/wilfred/sand/npc/npc20_0.c": 15,  // ���o
        "/open/world1/wilfred/sand/npc/npc20_1.c": 8,   // �a�l
        "/open/world1/wilfred/sand/npc/npc20_2.c": 4,   // ��s
        "/open/world1/wilfred/sand/npc/npc20_3.c": 2,   // �j�s
        "/open/world1/wilfred/sand/npc/npc20_4.c": 1,   // �p�Y��
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
    msg  = "�@�U�T�ɪO�C\n";
    msg += "�n�� 3 �I�C\n";
    msg += "�԰����N 1 �I�C\n";
    return msg;
}

/*  ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
 */
void reward(object player, object npc) {
        player->add("bank/past", 10000);
    tell_object(player, HIY"(�A��o�F�@�U�T�ɪO�C)\n"NOR);
        player->add("popularity", 3);
    tell_object(player, HIY"(�A��o�F 3 �I�n��C)\n"NOR);
        player->add("war_art", 1);
    tell_object(player, HIY"(�A��o�F 1 �I�԰����N�C)\n"NOR);
}
