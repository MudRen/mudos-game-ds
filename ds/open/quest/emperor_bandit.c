// tmr 2007/02/28

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�M���F���|�j�s";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�B�F���~���@�s�ѪF���|�j�s�v�⪺�j�s�ΡA�w�g���`�ƤQ���H�R�C\n";
    msg += "�A�����ߤ��U�A�Ʊ��@�|�����o�ӤQ�c���j���j�s�ΡC\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 25;
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
        if( player->query("level") < 25 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/ksj/thief/npc/thief-master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/ksj/thief/npc/thief-master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���F�B�F�������w�A�o�ӭ��d�j���N�浹�A�F�I�I\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/linjack/emperor/npc/chang.c" : 1,
        "/open/world1/linjack/emperor/npc/biaw.c" : 1,
        "/open/world1/linjack/emperor/npc/ler.c" : 1,
        "/open/world1/linjack/emperor/npc/jur.c" : 1,
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
    msg  = "���U�T�ɪO�C\n";
    msg += "�n�� 6 �I�C\n";
    msg += "�԰����N 10 �I�C\n";
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
        player->add("bank/past", 50000);
    tell_object(player, HIY"(�A��o�F���U�T�ɪO�C)\n"NOR);
        player->add("popularity", 6);
    tell_object(player, HIY"(�A��o�F 6 �I�n��C)\n"NOR);
        player->add("war_art", 10);
    tell_object(player, HIY"(�A��o�F 10 �I�԰����N�C)\n"NOR);
}

