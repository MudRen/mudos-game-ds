// tmr 2007/02/28

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�q�U�U���";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�U������̤l�Q�x�H��}�X���ӡA�A���P�뤧�U�A�Ʊ��h�}��\n";
    msg += "�M����ͨ��סB�ƺ~��ƱC�l�A�n�ϥX�o�����v�S�C\n";

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
    return "/open/world1/tmr/bagi/npc/zhou-ying.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
     return "/open/world1/tmr/bagi/npc/zhou-ying.c";

}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N���������F�_�ӡC\n"NOR,
        "$N���$n���D�G�u�O���³o��j�L�����U�C\n",
        "$N���$n���D�G��ť���H��}�����O�|�Y�H����ͨ��סA�٦��ñ��H���ƺ~��ƱC�l�I\n",
        "$N���$n���D�G�ڨ����v�S�x�b�̭��X���ӡA�Ʊ�A�����ڲM�������b�H���Ǫ��C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/area/2f/npc/corpse.c": 10,
        "/open/world1/tmr/bagi/area/2f/npc/madman.c": 2,
        "/open/world1/tmr/bagi/area/2f/npc/madwoman.c": 2,
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
        "$N���$n���D�G�u�O�P�§A�r�I\n",
        "$N���$n���D�G�Ʊ�H�Ǹ�^�Ǩ��v�S�໰�֥X�}�ӡC\n",
        CYN"$N�S�}�l�J��a���ݵۡC\n"NOR,
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 50,000 �I�C\n";
    msg += "�n�� 5 �I�C\n";
    msg += "�԰����N 2 �I�C\n";
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
        player->add("exp", 50000);
    tell_object(player, HIY"(�A��o�F 50000 �I�g��ȡC)\n"NOR);
        player->add("popularity", 5);
    tell_object(player, HIY"(�A��o�F 5 �I�n��C)\n"NOR);
        player->add("war_art", 2);
    tell_object(player, HIY"(�A��o�F 2 �I�԰����N�C)\n"NOR);

}

