// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "ø�z�����e�U";
}

// ���ȴy�z
string getDetail() {
return "
�b�¤ѼӸg�窺�m����ø�z��(Sawqjiri erika)�A�֦�
�@���D�`�}�G���զ���Y�A�s���u�ѨϤ��Z�v�C�M�ӳo
�����Y�o�Q�H�����A�g�L�o�}�l���լd�A�̫�o�{�o��
���Y�����b�Ϩk���g�c���Aø�z���Ʊ�A�����o��^��
�Ϥ��Z�C
";
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
   if( player->isSolved("/open/quest/bariour_q1.c") == -1) return 0;

   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/lottery/erika.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/lottery/erika.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�ڦ����D�`�}�G���_���A�s���u�ѨϤ��Z�v�A���O���o�Q�����F�C\n",
        "$N���$n���D�G�g�L�լd����A�u���D���ثe�b�a��b�ϤH���W�C\n",
        "$N���$n���D�G�Ʊ�A�����ڨ��^�ѨϤ��Z�C\n",
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
        "/open/lottery/angle_egg.c": 1, 
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
        "$N���$n���D�G�A�u�n�A���ڧ�^�ӤF�A�u�O�����§A�������F�I\n",
        "$N���$n���D�G�o���Q�i����e���A�A���A���j���C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "50 �i����C\n";
    msg += "1 �I�Ԫ����N�C\n";
    return msg;
}

void reward(object player, object npc) {
        object ticket;
        int i;
        player->add("war_art", 1);
        tell_object(player, HIY"(�A��o�F 1 �I�Ԫ����N�C)\n"NOR);
        // ���Q�i�m��
        for(i=0;i<50;i++) {
                ticket = LOTTERY_D->createTicket();
                ticket->move(player);
        }
        tell_object(player, HIY"(�A��o�F 50 �i�m��C)\n"NOR);
}

