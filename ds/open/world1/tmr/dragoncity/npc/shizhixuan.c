#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("�ۤ��a" , ({ "shi zhi-xuan master", "shi", "zhi", "xuan", "master" }) );
        set("long",@long
�ۤ��a�A�����m�j�����s�ǡn�p���̪��\�N�]���C�����˦��p�x����j���c���C
�������H��A�ɦӬ����H���w�������N����A�ɦӬ��T�h���̪��̤H���ȻP�O���C
�P�����O���R�N�x�����Ѩq�ߥͤU�@�k�A�]�N�O��N�j­����۫C梡C�Z�\�ѤU��
�@�A�]���~�]���]�K�j����(�S�W�����K�j����)����C�P�]���Ĥ@�j�������Ѭ��x
�����ɧ��]���@�q���A�èϯ���ѷR�ͫ�A�ϥX�ɥۭѵI���ۧ����������˥ۤ��a
�n�`�C�ѥۤ]�O�]���K���ᶡ�����ǤH�A�{�̬Ҭ��X���޵Ѫ����H���A���O�O�h
�����l�J�ƥդμv�l�C�ȷ���ۡA��H���O�p�������n����C
long
);
        create_family( "�����v", 14, "�v�D");
       set("title", HIR"����"NOR);
        set("level", 70);
        set("race","tiger");
        set("age", 28);
        set("class1","�����v");
        set("class2","�����v");
        set("gender","�k��");
        set("adv_class", 2);
        set("guild_gifts",({7, 4, 7, 2}));

        set_skill("force",100);

        set_skill("unarmed",100);
        set_skill("fork",100);
        set_skill("ablaze-pike",100);
        set_skill("unscar-steps",100);
        map_skill("dodge","unscar-steps");
        map_skill("fork","ablaze-pike");
         set_skill("constant-virtue",50);

        set("guild_skills",([
               "force" : ({130,3, 60}),
                  "purple-blood" : ({130,3, 40}),
        ])  );

        set("guild_spells",([
               "freely-vigor" : ({130, 3, 60}),
               "sorcery-lock" : ({130, 3, 60}),
        ]) );

        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        set("evil", -200);
        setup();
        set_temp("apply/sou", 3);
        set_temp("apply/bar", 3);
        set_temp("apply/armor", 300);
        set_temp("apply/armor", 150);
        set_temp("apply/shield", 150);
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

void combat_ai()
{
        return;
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

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") != "�����v") return notify_fail("�o�ण�O�A�ӨӪ��a��C\n");
        if( me->query("class2") == "�����v") return notify_fail("�A�w�O�����v���̤l�F�C\n");
        if( me->query("adv_class") == 2 ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "ancestor") return notify_fail("�A�n���J���@�Ӫ���?\n");

        if( me->query("level") < 25 
                || me->query_skill("ablaze-pike") < 50
                || me->query_skill("unscar-steps") < 50
                || me->query_spell("sorcery-lock") < 50
                || me->query_spell("freely-vigor") < 50
        ) {
                command("shake");
                command("say �A�A�h�h�m�m�a�C");
                 return 0;
        }

        if(me->query("evil") < 200 ) {
                command("shake");
                command("say �A�ʮ�ӹL�}���A���A�X�J�ڪ����U�C");
        return 0;
        }

        command("say �n�I�I�A�N�[�J�ڰ��������U�A����D�ߺ��]�j�k�A�N�]���o�����j�C");
        command("smile "+me->query("id"));
        me->set("adv_class",2);
        me->set("class2","�����v");
        me->create_family("�����v", 15, "���H");
        me->set("guild_rank","�����v���ѹD�J�]");
        return 1;   
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();

        if( me->query("class2") != "�����v") return notify_fail("�o�̤��O�A�ӨӪ��a��C\n");
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

        if(this_player()->query("class2") != "�����v")
               return notify_fail("�A�ä��O�����v���̤l�C\n");

        lv = me->query_skill(arg,1);
        if( lv<30 )   cost=1;
        else    if(lv<60) cost=2;
        else    if(lv<90) cost=3;
        else    cost=4;
        if( me->query("popularity") < cost)
                return notify_fail("�ݨӥۤ��a�ä��Q�ЧA��`�@�h�C(���D�A��"+cost+"�I�n��)\n");

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
                case 0: rank = "�����v���]�ߥE�{"; break;
                case 1: rank = "�����v���]�\\�j��"; break;
                case 2: rank = "�����v�����]�{�@"; break;
                case 3: rank = "�����v���ѹD�J�]"; break;
                case 4: rank = "�����v���D�ߺ��]"; break;
                case 5: rank = "�����v�����]�O��"; break;
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
/*
        message("world:world1:vision",
                 HIR"\n�i���S���J�j"HIY"�w�F�ѤM���N�������v�j���ӡu�F��v���M����b" +ob->name(1)+HIY"��̤F�I�I�I\n\n"+NOR,users());
        ob->add("popularity", 6); //�n��
        tell_object(ob,HIW"(�A�o��F���I�n��C)"NOR);
*/

        ::die();
        return;
}

