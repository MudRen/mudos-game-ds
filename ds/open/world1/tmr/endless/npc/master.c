
#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("�L���ɮv", ({"endless master", "master"}) );
    set("gender", "�k��");
        set("title","�ѤU��");
    set("long",@LONG
�L���Y�D�A�O��ӷ���[��l��[�׷������A�J�L���A���ӬO�Ѥl
�ΥH���ٹD���׷��ʪ������C�m�Ѥl�n�ĤG�Q�K���J�u����աA�u
��¡A���ѤU���C���ѤU���A�`�w���֡A�_�k��L���C�v�o�O�Ĥ@
���X�{�L���������C���q�N��O���J�����D��աA�o�w�u����¡A
�K�వ�ѤU���Ҧ��C�వ�ѤU���Ҧ��A�ë��w�ʤ��ۮt���A�ʦ^
�_�줣�i�a�ɪ��u�D�C�ҥH�L������q�N�O�D�A���D�O���i�a�ɪ�
�C�H��D���H�h�A���O�b�o�@�N�q�W�ϥεL���������A���b���P��
�X�ަ��������I�y�����P�C���l�b�m�p���C�n�����u�L�����~�A�_
�L���]�C�v�N��O�@�ɵL��L�ڡA�L�a���~�A�٬O�L�a�C�L���K�O
�L�a�C�~�N���e�W���m�Ѥl���y�n�{���_�k�L���N�O���ͤ[���C��
�D���[���A�P�D�ۦX�A�~����ͤ[���A�]���N�L���������D�A�Ϊ�
���������ͤ[���A�O�@�P���C�D�O�L�����C�Ѧa�}�P���e�A���w�g
�s�b�F�L�����ɶ��A�ӥB�|�ë�a�s�b�U�h�A�Ŷ��W���]�O�L����
�A�����������@�Ө��骺�ϰ�C�]���εL�����då�ٹD�C�b�t�z
�t�ƪ����רϥεL���@���A�`�P�ӷ����|�A����Ѧa���P�B���o�O
�Ѧa�����_�l���V�P��[�j�ѡB��[�׷������q�A�o�@���q�A�N�O
�D�C�]���A�L���O�ӷ����ڷ��C�׹D�̳��l�D�P�D�X�@�A�D���N�y
�ٻP�D�X�u�A�b�������W�K�O��^�줸�쪺�׷������A�A�o�N�s
���_�k�L���C
�A�i�H�� transform art ���O�A�N�@�d�U�I�g��ȴ����@�I�԰����N�C
LONG
    );
        set("level", 200);
        set("age", 99999);
        set("adv_class",3);
        set("class3","�_�k�L��");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("attack_merits","endless");

        set("guild_skills",([           // ����, ����1�i��, �W��
                "constant-virtue":({300,0,100}),
                  "block":({300,0,100}),
        ]) );
        
        set_temp("fly",1);
        set_temp("apply/bar",99);
        set_temp("apply/bio",99);
        set_temp("apply/wit",99);
        set_temp("apply/sou",99);
        set_temp("apply/tec",99);
        set_temp("apply/int",99);
        set_temp("apply/dex",99);
        set_temp("apply/armor",999999);
        set_temp("apply/damage",999999);
        set_temp("apply/shield",999999);
          set_temp("apply/hit_ratio",100);
        setup();
        set_temp("apply/endless",99);

}
void init()
{
        ::init();
        add_action("do_advance","advance");
        add_action("do_transform","transform");
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}


// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost;
        cost = me->query_skill(argx) * 100;
        me->add("war_art",-cost);
        return;
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class3") != "�_�k�L��")
               return notify_fail("�A�ä��O�u�_�k�L���v���̤l�C\n");

        lv = me->query_skill(arg,1);
        if(lv==100)
                return notify_fail("�A�o�ӧޯ�w�g��F�n�p�y�����ҬɤF�C\n");
                cost = lv*100;
        if( me->query("war_art") < cost)
                return notify_fail("�ݨӵL���ɮv�ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�Ԫ����N)\n");
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}



int do_advance(string arg)
{
        return GUILDMASTER->do_advance(this_object(),this_player(),arg);
}

int EXP_AMOUNT = 10000000;

int do_transform(string arg)
{
        object me;
        if(arg != "art")
                return notify_fail("�ثe�u�� transform art�C\n");
        me = this_player();
        if(me->query("exp")<EXP_AMOUNT)
                return notify_fail("�A�ثe���g��Ȥ����A�L�k�ഫ���԰����N�C\n");
        me->add("exp",-EXP_AMOUNT);
        me->add("war_art",1);
        message_vision(HIY"$Nı�o�F�x�M���A���Z�N�S����h�@�I���鮩�F�C\n"NOR,me);
        return 1;
}


string guild_rank(object me)
{
        return "�P�D�X�u�_�k�L��";
}



