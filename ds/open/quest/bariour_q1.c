// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���Y�Ъ��e�U";
}

// ���ȴy�z
string getDetail() {
return "
���Y��(Xin reu yue)�O�ѫ�����������Q�A�o���Q��
�檺���ǳ��O�W�諸���~�C�̪�ѩ�o���Q���ͷN�D�`
���n�A�ɭP��Ƶu�ʡA�]���o�Ʊ�p���_��j�˪L�]
�@��A���o�j���@�ǰ��~�誺�Ϥ�C
";
}

// ���ȵ���
int getLevel() {
    return 15;
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
   if( player->query("level") < 15 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/acme/area/npc/lin.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/acme/area/npc/lin.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�̪�ͷN�Ӧn�A�Ϥ�Ƶu�ʡA�Ʊ�A�����ڨ�_��j�˪L�]�@��C\n",
        "$N���$n���D�G�b���˪L�`�B�Ať�����D�`���~�誺�Ϥ�C\n",
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
        "/open/world1/tmr/goat_maze/npc/obj/bariour_fur.c": 20, 
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
        "$N���$n���D�G�u�O�����§A�������I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�@�U�T�ɪO�C\n";
    msg += "�g��� 10 �U�C\n";
    return msg;
}


void reward(object player, object npc) {
        player->add("bank/past", 10000);
    tell_object(player, HIY"(�A��o�F�@�U�T�ɪO�C)\n"NOR);
        player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 10 �U�I�g��ȡC)\n"NOR);
}

