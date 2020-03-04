#include <ansi.h>
inherit F_MASTER;

inherit NPC;

void create() {

    set_name("���խ�",({"shin-you-fon master","fon", "master"}));

    set("long",@LONG
���խ��������ءA�C�������A�Y�v�ܪӡA�L���٦׵���A�������o�X
ģ���������A�N�����N�@�ˡA�@�ݴN���D���H���\���ΡA���ѱ��T�t����
�j���A�P���W���Ψ��ݭ��O�T�M�L�S�̡A�H�٤ѱ��T�t�C���խ��ثe�O��
�������x���A�@�⪥�ްw�b���ޫa���j���C
LONG
);

    create_family( "�ѱ���", 8, "�w�b�v");
    set("attitude","peaceful");
    set("age", 50);
    set("gender","�k��");
    set("level", 40+random(10));
    set("title", HIC"�ѱ��T�t"NOR);
    set("class1","�ѱ���");
    set("dex", 120+random(50));
    set("ap", 50000);
    set("adv_class",1);

    set_skill("needle",100);
    set_skill("dodge",100);
    set_skill("wing-eight",100);
    set_skill("parry",100);
    set_skill("moxibustion",100);
    set_skill("acupuncture-cognition",100);
    set_skill("unarmed",100);
    set_skill("skyowl-needle",70);

    map_skill("needle","skyowl-needle");
    map_skill("parry","skyowl-needle");
    map_skill("dodge","wing-eight");
    set
        ("guild_gifts",( {
                             2,7,8,3
                         }
                       ));
    set
        ("guild_skills",([
                     "needle" : ( {
                                              140,3,80
                                          }
                                        ),
                     "skyowl-needle" : ({ 140,3,80 }),
                     "dodge" : ({ 140,3,80 }),
                     "wing-eight" : ({ 140,3,80 }),
                     "moxibustion" : ({ 140, 3, 60 }),
                     "acupuncture-cognition" : ({ 140,3, 60 }),
                     "parry" : ({ 140,3,50 }),
                     "unarmed" : ({ 140,3,50 }),
                         ]));
    set
        ("chat_chance_combat",80);
    set
        ("chat_msg_combat",
                ( {
              (:command,"say �p�l�I�I�A���n�R�F�I�I�h���a�I�I ":),
                  }
                ));
    setup();
    carry_object(__DIR__"eq/dagger3")->wield();
    carry_object(__DIR__"eq/cloth2")->wear();
    carry_object(__DIR__"eq/boots2")->wear();
    carry_object(__DIR__"eq/surcoat")->wear();
}

void init() {

    ::init();
    add_action("do_skill_list","list");
    add_action("do_skill_train","train");
    add_action("do_join","join");
    add_action("do_advance","advance");
}

void die() {
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if( ob )
        message("world:world1:vision", HIW"\n
                �Z�L�ǥX�F�@�h��H������:"HIC"\n\n\t�ѱ��T�t���@�� ���խ����M�ѵ��F"NOR+ob->name(1)+"�C\n\n"+NOR,users());
    ob->add("popularity",2);
    tell_object(ob,HIW"(�A�o��F 2 �I�n��C)"NOR);
    ::die();
    return;
}



int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
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
        if( me->query("class1") == "�ѱ���") return notify_fail("�A�w�O�ѱ����̤l�F�C\n");
        if( me->query("adv_class") ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
         if(arg != "skyowl") return notify_fail("�A�n���J���@�Ӫ���?\n");
           if( me->query_int() < 8) { 
                command("shake");
            command("say �ڬݧA�����@�y�b�ˡA���A�X���ѱ����o�����C");
                        return 0;
                }
        command("say �n�n�n�I�I���@�A�Ѹ��o�o�A�A�N�[�J�ڭ̤ѱ����A�n�n��Ū��N�άr�N�a�C");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","�ѱ���");
        me->create_family("�ѱ���",9,"�w�v");
        me->set("guild_rank","�ѱ����ĤE�N�w�v");
    me->set("guild_gifts", query("guild_gifts") );
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="�ѱ���") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O�ѱ����̤l�C\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = "�ѱ������s��w�v"; break;
                        case 1: rank = "�ѱ������{�ަn��"; break;
                        case 2: rank = "�ѱ��������ޯ���"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "�ѱ������s��w�v"; break;
                        case 1: rank = "�ѱ������{�ަn��"; break;
                        case 2: rank = "�ѱ��������ޯ���"; break;
                }
        }
        return rank;
}

