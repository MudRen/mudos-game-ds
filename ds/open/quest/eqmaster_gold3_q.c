// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���K�Ѯv�Ū������q�e�U";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���K�Ѯv�Żݭn���Ū������q�A�A�i�H�����}�`�B���L���p�D���ݡC\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 45;
}


int preCondition(object player) {
    if( player->query("level") < 35 ) return 0;
    if( player->isSolved("/open/quest/eqmaster_gold_q.c") == -1) return 0;
    if( player->isSolved("/open/quest/eqmaster_gold2_q.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/wilfred/newbie/eq_master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�b�B�F���Ǫ��˪L���A���ӳQ�D�Ǧu�@�����}�C\n",
        "$N���$n���D�G�b���}���`�B���L���p�D�A�i�q���ɵL���B�ŵL���Ψ��~�L�����}�ޡC\n",
        "$N���$n���D�Gť�����Y�æ��D�`�}�����u�����q�v�A�Ʊ�A�����ڨ����Ӧ^�ӡC\n",
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
          "/open/world1/tmr/wujian/npc/obj/mercury-mine.c": 5,
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
        "$N���$n���D�G���I�I�A���ӯ����q�F�A�u�O�Ө��W�A�F�I�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "
�g��� 500,000 �I
�԰����N 20 �I
10% �O�q�B���B���z�B�ӱ����b�U�@�i�C
";
}

string *items = ({
         "10_atk.c",
         "60_atk.c",
         "100_atk.c",
});

void reward(object player, object npc) {
    player->add("exp", 500000);
    tell_object(player, HIY"(�A��o�F 500,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 20);
    tell_object(player, HIY"(�A��o�F 20 �I�԰����N�C)\n"NOR);

    new("/open/enhance/10_str")->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/10_dex")->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/10_con")->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/10_int")->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);

}

