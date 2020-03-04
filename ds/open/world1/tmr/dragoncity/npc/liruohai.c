#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("�F�Y��" , ({ "li ruo-hai master", "li", "ruo","hai", "master" }) );
        set("long",@long
�F�Y���A�����m�ЫB½���n�@���\�H���A�Ѥ��Ҽg���h�A���H�����ʮ�w�g�Q����
�X�C�@�ݼF�Y���X���A�N���p�ݤ@�W�M�԰����i�Z�N�x�@�ˡA�O�H�P����ص±���
���A�F�Y���ѥͬO���H���J�I�A�����O�]���L�Z�\�����A�ӬO�L���رM�߹�Z�D��
�l�D�A�Y�ϬO�Ѧb�e�����U�A���L�H���կ��L���۶q�O�D���e���A�]���x���D���e
�����H�w�g���h�F�C
�p�G�A���N�[�J�����v�A�i�H��L�n�D�[�J(join ancestor)�C
long
);
        create_family( "�����v", 15, "�v�D");
        set("level", 50);
        set("race","tiger");
        set("title", HIR"���F"NOR);
        set("age", 48);
        set("class1","�����v");
        set("gender","�k��");
        set("adv_class",1);
          set("guild_gifts",({7,4,7,2}));

        set_skill("unarmed",100);
        set_skill("fork",100);
        set_skill("ablaze-pike",100);
        set_skill("unscar-steps",100);
        map_skill("dodge","unscar-steps");
         map_skill("fork","ablaze-pike");

        set("guild_skills",([
                "ablaze-pike" : ({130,3, 60}),
               "unscar-steps" : ({130,3, 60}),
               "dodge" : ({120,3,70}),
               "fork" : ({120,3,70}),
               "parry" : ({130,2,70}),
               "unarmed" : ({130,3,70}),
        ])  );

        set("guild_spells",([
               "freely-vigor" : ({130,3, 60}),
               "sorcery-lock" : ({130,3, 60}),
        ]) );


        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
        carry_object(__DIR__"wp/red-pike")->wield();
}

void init()
{
    ::init();
    add_action("do_skill_list","list");
    add_action("do_skill_train","train");
    add_action("do_spell_train","learn");
    add_action("do_join","join");
    add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}

int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);

        return 1;
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
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") == "�����v") return notify_fail("�A�w�O�����v�̤l�F�C\n");
        if( me->query("adv_class") ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "ancestor") return notify_fail("�A�n���J���@�Ӫ���?\n");
         if(me->query("evil")< 10) {
                command("shake");
                command("say �A���ʤӹL���}�A���A�X�[�J�����v�C");
                return 0;
        }
        command("spank");
        command("say �����j�k�]�\\�í��A�A�i�n�n�n�Τ߲ߪZ�A�i�O��F�������y�C");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","�����v");
        me->create_family("�����v",2,"�̤l");
        me->set("guild_rank","�����v���]�ߥE�{");
        me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="�����v") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O�����v�̤l�C\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        switch( lv )
        {
                case 0: rank = "�����v���]�ߥE�{"; break;
                case 1: rank = "�����v���]�\\�j��"; break;
                case 2: rank = "�����v�����]�{�@"; break;

        }
        return rank;
}

