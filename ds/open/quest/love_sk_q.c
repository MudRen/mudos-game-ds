// �X�z�@�o�T�d�\ (broken-hearted)      - �i���ޯ�

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�X�z�@�o�T�d�\\";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�u�X�z�@�o�T�d�v�O���������ޡA�A�������o\n";
    msg += "�P���H�B(Frame-freeze armor)�浹�����v�L�A�~��\n";
    msg += "���ǲ߳o���ޯ�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 40;
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
   if( player->query("level") < 40 ) return 0;
   if( player->query("class2") != "������" ) return 0;
   if( player->query_skill("seven-love") < 90 ) return 0;
   if( player->query_skill("thousand-hair") < 90 ) return 0;

   // ���ǹL�N����A�ѤF
   if( player->query_skill("broken-hearted") > 0 ) return 0;
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/kkeenn/love/npc/master_2.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�X�z�@�o�T�d�\\�v�O�����������ޡA�u�ǵ�����O���̤l�C\n",
        "$N���$n���D�G�A�h���ڨ��ӯP���H�B�A�n�����p���o�Ӹ��C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
   return ([]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/open/world1/kkeenn/love/npc/obj/armor.c": 1,
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

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/kkeenn/love/npc/master_2.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���������A�p���T�O�����̥X�����̤l�I�I\n",
        "$N���$n���D�G�ڳo�N�ǵ��A�o�۵��ޤF�a�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg = "�߱o�u�X�z�@�o�T�d�\\(broken-hearted) �v";
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
        player->set_skill("broken-hearted", 10);
}



