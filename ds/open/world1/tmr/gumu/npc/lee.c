#include <ansi.h>
inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
        set_name("�����T", ({ "lee mochou", "lee", "mochou" }));
        set("long", "�o�ͱo���������A���B�N���إ����H���H�ӷX�C\n");
        set("nickname", HIR"���m�P�l"NOR);
        set("gender", "�k��");
        set("attitude","heroism");

        set("level", 45);
        set("inquiry", ([
                "name" : "�����I�I",
                "here" : "�ڤ��O���a�H�A�����D�C",
                "��" : "�A�p���z�Ѩ䤤�۫䤧�W�B�������N�H",
                "���i��" : "�A�ݨ����������p�b�Ͱ�����H",
                "��J�g" : (: ask_me :),
                "�p�s�k" : "���O�ڪ��v�f�C�A�ݦo�Q�F����H",
                "�L�­^" : "���O�ڪ��v���A���ӧA�ݪ��A�O�ݡA�p�ߧڮ_�F�A�C",
        ]) );
        
        set_skill("whip",100);
        set_skill("block",100);
        set_skill("parry",100);
        set_skill("unarmed",100);
        set_skill("dodge",100);

    create_family("�j�Ӭ�", 3, "�̤l");
 
        set("chat_chance", 10);
        set("chat_msg", ({
                "�����T�a�n�Ӻq�A��������A�q�D�G�u�ݥ@���A���O�󪫡A���Хͦ��۳\\�H�v\n",
                "�����T�q�D�G�u�ѫn�a�_�����ȡA�ѯʹX�^�H���H�v\n",
                "�����T�۹D�G�u�w�ֽ�A���O�W�A�N���󦳷���k�C�v\n",
                "�����T�۹D�G�u�g�����y�A���U���h���A�d�s�ǳ��A�u�v�V�֥h�H�v\n",
                "�����T���N�d���A�n�է�O�s��A�۹D�G�u��W���A�I���~­���C��Ϩ��¥����C�v\n",
                "�����T�q�D�G�u�ۻ�Ǧ�ؤΡA�s���۳ڭ��B�C�v\n",
                "�����T�۹D�G�u�Ѥ]���A���H�P�A�a��P�l�Ѷ��g�C�v\n",
                "�����T�۹D�G�u�d��U�j�A���d���̤H�A�g�q�h���A�ӳX���C�B�C�v\n",
        }) );

      set("combat_exp", 800000);

        setup();
        set_temp("apply/armor", 300);
        set_temp("apply/damage", 200);
        carry_object(__DIR__"obj/fuchen")->wield();
        carry_object(__DIR__"obj/white-robe")->wear();
        carry_object(__DIR__"obj/jade-bracelet")->wear();
        carry_object(__DIR__"obj/silver-ankle")->wear();
        carry_object(__DIR__"obj/ice-silver_needle");
}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","kiss");
}

int ask_me()
{
        object me;
 
        me = this_player();
        message("vision", HIY"�����T�N���@�n�G�y�ڳo�N�e�A�h���o�I�I�z\n�����T�M�߱���" + me->name() +"\n" NOR, environment(), this_object() );
        kill_ob(this_player());
        return 1;
}

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (target=="lee" || target=="lee mochou" || target=="mochou" ) 
                if ((string)me->query("gender") != "�k��")
                {
                        message("vision", HIY "�����T�j��A�ܹD�G�ڳ̫�A�̳o����������k�H�I�h���a�I\n�����T�M�߱���" + me->name() +"\n" NOR, environment(), this_object() );
                        kill_ob(this_player());
                }
}


void die()
{
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    if( !ob )

    {
        ::die();
        return;
    }
    message("world:world1:vision",
              HIR"\n�i�����H�ӡj"HIY "�c�W�������u���m�P�l�v�����T�Q"+ob->name(1)+HIY"�����F�I�I\n\n"+NOR
            ,users());
      ob->add("popularity", 4);   //�n��
    ::die();
    return;
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon;
    if(!me || !target)
        return 0;
    if(random(10)<7) return 0;

    message_vision(HIC"\n$N"HIC"�b�ܤ@�n�A�Y�X�@�D�G�զ⪺���~�S�J$n"HIC"���u�̡A���M�O�B�z�Ȱw�I�I\n" NOR,this_object(), target);
    target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
    target->apply_condition("poison", 10);
    target->add_busy(1);
    return 1;
}

