// tmr 2007/07/11

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���K�Ѯv�Ū��ժ��e�U";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���K�Ѯv�Żݭn�@�ǥժ��A�A�i�H���@�q�W���ݡC\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 35;
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
    if( player->query("level") < 35 ) return 0;
    if( player->isSolved("/open/quest/eqmaster_gold_q.c") == -1) return 0;
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
        "$N���$n���D�G���b���~���Ӧ��_�ò��~����@�q�A�q�W�æ����~�誺�ժ��q�C\n",
        "$N���$n���D�G�Ʊ�o���A���M�����ڮ����Ӧ^�ӡA�گ൹�A�@�ǳ��S�C\n",
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
        "/open/world1/ksj/lost_island/npc/eq/gold.c": 5,
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
        "$N���$n���D�G���I�I�u�O�}�G�S���Q���ժ��A�u�O�ӷP�§A�F�I�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "
�g��� 500,000 �I
�԰����N 50 �I
10%, 60%, ��100%�������b�|�i�C
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
    player->add("war_art", 50);
    tell_object(player, HIY"(�A��o�F 50 �I�԰����N�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}


