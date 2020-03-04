#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIY"�����l"NOR,({"son of light","son","light","master"}));
        set("gender", "�k��"); 
        set("title",HIW"�s���ǤH"NOR);        set("long",@LONG
        list    �C�X�i�Ǫ��ޯ�P�k�N�C��
        train   �V�m�ޯ�
        learn   �ǲߪk�N
        join    �[�J�u�|
        advance �ɯũμW�[�ݩ�

LONG
        );
        set("level",45);                
        set("age",53);                  

        set("adv_class",2);             
        set("class1","dragon");           �
        set("guild_skills",([   
                "dodge":({32,2,105}),   �
                "blade":({30,2,90}),    
        ]) );

        set("guild_spells",([           
                "killingdragon-yet-blade":({60,2,30}),
        ]) );

        set("guild_gifts",({10,5,-3,8}));

        setup();

        add_money("coin",1000);
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
        GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
        return 1;
}

int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); 
        write("\n");
        GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
        this_player()->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("say ���a�w�g�[�J��L�����C");break;
                case -2: command("say ���a�w�g�[�J�F�P�ɮv�P�ũΧ󰪯Ū���´�C");break;
                case -3: command("say ���a�ثe����´�ä��A�X�[�J����´�C");break;
                case -4: command("say ���a���Ť����C");break;
                case -5: command("say ���a�� termstr �èS���j�� termnum �ȡC");break;
                case -6: command("say ���a�� termstr �èS������ termnum �ȡC");break;
                case -7: command("say ���a�� termstr �èS���p�� termnum �ȡC");break;
                case -8: command("say ���a��J����´���~�ΨS����J�n�[�J����´�W�C");break;
                default: command("say ���a�[�J�F���M���C");
        }
        
        return 1;
}

int do_advance(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/4;     
        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = HIW"���M�J���p�p�M��"NOR; break;
                        case 1: rank = HIG"���M�J���l���«C"NOR; break; 
                        case 2: rank = HIB"���M�J���U�Ҳ���"NOR; break;                        default: rank = HIY"��"HIR"�� ��  �� �a"HIY"�M"NOR;
                }
        }
        return rank;
}


