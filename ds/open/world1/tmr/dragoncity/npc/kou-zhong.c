#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("�F��" , ({ "kou-zhong master", "kou", "zhong", "master" }) );
        set("long",@long
�F��A�����m�j�����s�ǡn�p���̪����k�D�����@�A
�өʶ}�Ի��ڡB����p�`�C�P�t�@�k�D���}�l���@�}�l�P�O
���{���p�V�V�A�]�t�ڷ|����Z�\���y�m���ͳZ�n�A��ӤS
�~���~�����M�m�����@���\�A�Х����s���C�ߧӪ��ѤU�C��
�h�j�ӡA��ثe�F�v�����A����H���A�@�B�@�B�ئۤv����
�ӭx�A�֫Ӱ�A�O�Գ����Ѳr�N�A�P���@���Φ��n�_��Ϥ�
���C�����@�w���N����A�k���j����W�Χ��@���@��C
long
);
        create_family( "�֫ӭx", 1, "�j����");
                set("title",HIC"�ѤM���N"NOR);
        set("level", 70);
        set("race","ogre");
        set("age", 28);
        set("class1","�֫ӭx");
        set("class2","�֫ӭx");
        set("gender","�k��");
        set("adv_class", 2);
        set("guild_gifts",({8,8,0,4}));
        set_skill("unarmed",100);
        set_skill("combat",100);
        set_skill("dodge",100);
        set_skill("blade",100);
        set_skill("wellmoon-blade",100);
        set_skill("force",100);
         set_skill("constant-virtue",50);

        set_skill("flybird-steps",100);
        set_skill("bloodwar-blade",100);
        set_skill("nine-mystery",100);
          set_skill("longevity-force", 100);
        map_skill("dodge","flybird-steps");
        map_skill("blade","wellmoon-blade");

        set("guild_skills",([
                        "force" : ({130,3, 80}),
                        "wellmoon-blade" : ({130,3, 50}),
                          "longevity-force" : ({130,3, 50}),
        ])  );
        
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil", -250);
        setup();
        set_temp("apply/bar", 3);
        set_temp("apply/bio", 3);
        set_temp("apply/armor", 300);
         set_temp("apply/armor", 150);
                carry_object(__DIR__"wp/wellmoon-blade")->wield();
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
}

void combat_ai()
{
        object target;

        /* �Z���Q�����A�h�˦^�h */
        if( query_temp("weapon") ) 
                command("wield blade");
        target = query_enemy()[0];

            if( !target ) return;
           if( target->is_busy() || random(100) < 70 ) {
                command("exert wellmoon-blade");
        } else {
                command("exert longevity-force on " + target->query("id") );
        }
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

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "�֫ӭx") return notify_fail("�o�ण�O�A�ӨӪ��a��C\n");
        if( me->query("class2") == "�֫ӭx") return notify_fail("�A�w�O�֫ӭx���l�̧L�F�C\n");
        if( me->query("adv_class") == 2 ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "army") return notify_fail("�A�n���J���@�Ӫ���?\n");

        if( me->query("level") < 25 
                || me->query_skill("flybird-steps") < 50
                || me->query_skill("nine-mystery") < 50
                || me->query_skill("blade") < 50
                || me->query_skill("bloodwar-blade") < 50
                || me->query("gender") == "�k��"
        ) {
                command("shake");
                command("say �A�A�h�h�m�m�a");
        return 0;
        }

        command("say �ڬݧA���j�駧�A�D�`�A�X�x�ȥͲP�A�A�N�[�J�֫ӭx�A�n�n�o���a�C");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","�֫ӭx");
        me->create_family("�֫ӭx", 2,"�N�x");
        me->set("guild_rank","�֫ӭx���ѤM���N");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "�֫ӭx") return notify_fail("�o�̤��O�A�ӨӪ��a��C\n");
       //�s�ץ��Aadv level ���n�� (lv-20)^2
        j = me->query("popularity");
        if(j < 3 ) return notify_fail("�A���n�椣���C\n");
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");

        return GUILDMASTER->do_advance(ob,me,arg);
}

// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_skill_train(string arg)
{
        int lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();

        if(this_player()->query("class2") != "�֫ӭx")
               return notify_fail("�A�ä��O�֫ӭx���h�L�C\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("�ݨӱF��ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");

        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_spell_cost(object me,string argx)
{
        int cost;
        cost=me->query_skill(argx);
        cost-=1;
        if( cost<30 )   cost=1;
        else    if(cost<60) cost=2;
        else    if(cost<90) cost=3;
        else    cost=4;
        me->add("popularity",-cost);
        return;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        switch( lv )
        {
                case 0: rank = "�֫ӭx���ΤM�s��"; break;
                case 1: rank = "�֫ӭx���M�k����"; break;
                case 2: rank = "�֫ӭx����ԨF��"; break;
                case 3: rank = "�֫ӭx���H�Ծi��"; break;
                case 4: rank = "�֫ӭx���P�h���@"; break;
                case 5: rank = "�֫ӭx���ѤM���N"; break;
        }
        return rank;
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
                 HIR"\n�i���S���J�j"HIY"�w�F�ѤM���N���֫ӭx�j���ӡu�F��v���M����b" +ob->name(1)+HIY"��̤F�I�I�I\n\n"+NOR,users());
        ob->add("popularity", 6); //�n��
        tell_object(ob,HIW"(�A�o��F���I�n��C)"NOR);
          // �۵M�_�[�G�Y�s�I�y
         "/open/world1/tmr/dragoncity/hotel3f"->open_star();

        ::die();
        return;
}


