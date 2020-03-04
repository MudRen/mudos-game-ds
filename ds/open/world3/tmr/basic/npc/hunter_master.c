inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�i��", ({ "master po", "master", "po" }) );
        set("title", "�y�H���|�Ʒ|��");
        set("gender", "�k��");
//        set("class","hunter");
        set("age", 40);
        set("adv_class",1);
        set("class1","�y�H");
        set("guild_gifts",({6,6,4,4 }));
        set("long",@long
�@�ӯd�۪��v���k�H�A�@���U�Q���������ݵۧA�A�b�L���e�A�A��ı
�o���@�ѭ��H�����O�C�L�N�O�{���y�H���|���Ʒ|���A�M���t�d�s���y�H
���u�@�A�]�ǵ۳o�������ȡA���D�}�}saint ���C
long
        );
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
                "dodge" : ({150,2,30}),
                "parry" : ({150,2,30}),
                "block" : ({150,2,30}),
                "combat" : ({200,2,30}),
                "psychical" : ({100,2,5}),
        ])  );

        set("inquiry",([
        "��":"���O�@���y�H�̰򥻡B�]�O�̭��n���ޯ�C",
         "�S���O":"�@�������t�B���m�t�B�{�ƨt�B�ާ@�t�B��X�t�B�S��t���ءC",
        "�����t":"�O����b�@�w�ɶ����A�[�j������������O�C",
        "���m�t":"�O����b�@�w�ɶ����A�[�j���������m��O�C",
        "�{�ƨt":"�O�����������ƪ��e�{�C",
        "�ާ@�t":"�O������ާ@���~�Υͪ��C",
        "��X�t":"�O���H�g�X�覡���o��C",
        "�S��t":"�S��t�O�إ����������A�q�`�b�y�H������O���ɡA�~�|��{�X�ӡC",
        "�ǲ�":"�q�`�����S���O�A�ڭ̤��|�u�|�б¦����N���y�H�C",
        ]) );
        set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("block",80);
        set("no_check_class",1);
        setup();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_apprentice","apprentice");
}

int do_apprentice()
{
        return 0;
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
        if(me->query("class1")=="�y�H")
                return notify_fail("�A�w�g�O�@���y�H�F�C\n");
        if(!arg || arg!="�y�H" )
                return notify_fail("�o�̨S���o�Ӥ��|�C\n");
        if(me->query("adv_class") )
                return notify_fail("�A�w�g�[�J���|�Ϊ����F�C\n");

        if(!me->query_temp("join_hunter_ok") )
        {
        command("shake");
        command("say �Q�����y�H�A�������q�L�y�H����C");
        }
        else {
        command("smile");
        command("say ���߳q�L�y�H����A�����@���y�H�F�C");
        command("pat "+me->query("id") );
        command("say ���A�y�����N�ɡA�A�ӧ�ھǲߩ����S���O�a�C");
        me->delete_temp("join_hunter_ok");
        me->set("adv_class",1);
        me->set("class1","�y�H");
        me->set("guild_rank","����y�H");
        }               
        return 1;
}


int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="�y�H" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A�èS���[�J�y�H���|�C\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // �N rank �������Ӽh��

        switch( lv )
        {
        case 0: rank = "����y�H"; break;
        case 1: rank = "�@�P�y�H"; break;
        case 2: rank = "�G�P�y�H"; break;
        case 3: rank = "�T�P�y�H"; break;
        }
        return rank;
}


