// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�������F�~�۾�";
}

// ���ȴy�z
string getDetail() {
        string msg;
        msg = "���@�孫�n���F�~�۾��A�򥢦b�w���L���A\n";
        msg += "�p�G�A����p�ѤH���^�o�ǥ۾��A�A�i�H��o�@�U�������ŹT�C\n";
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
    return "/open/world1/tmr/hasake/npc/ji.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/ji.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�ڦb���ħJ�o��s�F�~�۾��ƤQ�~�F�C\n",
        "$N���$n���D�G�b�e��Ӥ�l�A�ڦ��T�ӭ��n���۾����b�w���L���C\n",
        "$N���$n���D�G�Ʊ�A�����ڨ��^�o�ǥ۾��C\n",
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
        "/open/world1/tmr/hasake/npc/obj/stone1.c": 1, 
        "/open/world1/tmr/hasake/npc/obj/stone2.c": 1, 
        "/open/world1/tmr/hasake/npc/obj/stone3.c": 1, 
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
        "$N���$n���D�G�u�O�ӷP�§A�F�C\n",
        "$N���$n���D�G�o�O�ڦۻs���@�U�ŹT�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�@�U�T�ɪO�C\n";
    msg  += "�@�f�T�ֳU�ΤG�Q�ӨŹT�C\n";
    return msg;
}


void reward(object player, object npc) {
        object bag, ch;  // �U�l��ŹT
        int i;

        bag = new("/open/world1/tmr/hasake/obj/wolf-bag.c");
        for(i=0;i<20;i++) {
                ch = new("/open/world1/tmr/hasake/obj/cheese.c");
                ch->move(bag);
        }

    player->add("bank/past", 10000);
    tell_object(player, HIY"(�A��o�F�@�U�T�ɪO�C)\n"NOR);
    bag->move(player);
    tell_object(player, HIY"(�A��o�F�@�U�ŹT�C)\n"NOR);
}

