
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�|��",({"leader"}));
        set("gender", "�k��");
        set("long",@LONG
�L�O�|���C
LONG
        );
        set("level",30);                // �]�w�ɮv������
        set("age",40);                  // �]�w�ɮv���~��
// ========================================================================
//      adv_class: x    x = �ƭ�(1~2)
//      ���ѼƬO���������a��NPC�ثe��¾�~�O�ĴX��, 1 �N�O�Ĥ@��, �]�N�O�̪�
//      ��¾�~����, 2 �N�O�ĤG��, �̦�����...
// ========================================================================  
  set("adv_class",1);             // �]�w�L��¾�~���ŬO���(�Ȭ�1)

// ========================================================================
//      class1: x       x = ¾�~�r��(�^��)
//      �o�O�Ĥ@��¾�~��¾�~�^��W��, ���ަ����a��NPC�ثe���ĴX�Ū�¾�~, �o
//      �ӰѼƤ@�w�n�w�q, �_�h�{���N���|���`�u�@... �O��, ¾�~���{�n����...
// ========================================================================
        set("class1","�~�����");           // �]�w¾�~���W��

// ========================================================================
//      �u�|�ɮv�i�H�бª��ޯ�C��
// ========================================================================
        set("guild_skills",([   // ����, ����1�i�Ǩ쪺�ޯ൥�ŭ��v, �W��
        ]) );
// ========================================================================
//      �u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
        set("guild_spells",([           // ����, ����1�i��, �W��
        ]) );

// ========================================================================
//      �ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
//      �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
//      �ӥB�|�����`�M�n��n���� 20
// ========================================================================
        set("guild_gifts",({4,5,6,5 }));
  set("inquiry/help",
        "list    �C�X�ޯ�C��\n"
        "train   �V�m�ޯ�\n"
        "join    �[�J����\n"
        "advance �ɯũμW�[�ݩ�\n"); 
       setup();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
add_action("do_join","join");
                add_action("do_advance","advance");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me); 
        if(me->query("class1")=="�~�����")
                return notify_fail("�A�w�g�O�@����ͤF�C\n");
        if(!arg || arg!="�~�����" )
                return notify_fail("�o�̨S���o�Ӥ��|�C\n");
        if(me->query("adv_class") )
                return notify_fail("�A�w�g�[�J���|�Ϊ����F�C\n");

        if(!me->query_temp("get_pass") )
        {
        command("say �A������������ҷӡC");
        }
        else {
        command("nod "+me->query("id") );
        me->delete_temp("get_pass");
   me->set("adv_class",1);
      me->set("class1","�~�����");
me->set("guild_rank","�y���z�Ū����");
me->set("title","������");
        me->set("adv_class",1);
        }               
        return 1;
}

// ========================================================================
// �ϥ� advance �ɯŮɷ|�ѦҨ� guild_rank() �o�Ө��, �o�Ө�ƥi�H����
// ���a��¾�~rank.
// ========================================================================
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="�~�����" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A�èS���[�J��ͤ��|�C\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // �N rank �������Ӽh��

        switch( lv )
        {
        case 0: rank = "�y���z�Ū����"; break;
        case 1: rank = "���"; break;
        case 2: rank = "���"; break;
        case 3: rank = "���"; break;
        }
        return rank;
}
