// tmr 2008/07/22
#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�ӳ�����";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg = "�A�������h�|�`�A�~��ǲߨ�ӳ�����C\n";
    msg += "�o�|�`���O�O�ѧ��B���]�B�ߧ��ΤѴݨ��СA\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 50;
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
    if( player->query("level") < 45 ) return 0;
   // ���ޯ�̡A�N����A��
    if( player->query_spell("moon-essence") ) return 0;

    if( player->query_spell("god-fire") < 90 ) return 0;
    if( player->query_spell("god-kill") < 90 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/acme/area/npc/advmaster.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�p�G�A�Q�n�Ѭ�ӳ�����A�A�o�n�������v���h�|�`�C\n",
        "$N���$n���D�G�@�O�ѧ��B�G�O���]�B�T�O�ߧ��B�|�O�Ѵݨ��СC\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/frost/npc/tian-demon.c" : 1,
        "/open/world1/moonhide/area/under/npc/evil.c" : 1, 
        "/open/world1/ksj/east_island/npc/cat-oldwoman.c" : 1,
        "/open/world1/acme/area2/npc/xie.c" : 1,
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
        "$N���$n���D�G��...�A�����F���i�઺���ȰڡA�ڳo�N�Ǳµ��A�a�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "�Ǩ�u�ӳ�����v�C\n";
    return msg;
}

void reward(object player, object npc) {
    player->set_spell("moon-essence", 10);
    tell_object(player, HIY"(�A�Ǩ�F�ӳ�����C)\n"NOR);
}

