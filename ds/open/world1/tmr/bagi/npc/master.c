//�K���� �i��Master 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�d��",({"wu chung master","master","wu","chung"}));
        set("gender", "�k��");
        set("long",@LONG
�d�����K�������N���l���A�~�֮ɫi��X���A�W�ޥX�s�A��Z���Ѥ@
�W�u���v���D�h�ҶǱ¡A��j�j�Z�q�����{�̡��}�A�Ҳ߱o�A�ܦ�������
�]�A�ײߪZ���A�󤭤Q���ɤj���A���~�ФK�����A�C�Q���j���j���A�h�~
�s�L�A�y�C�۱o�C
LONG
        );
        set("level",60);
        set("age",80);
        set("adv_class",2);
        set("class1","�K����");
        set("class2","�K����");
        set("title","�K�����}�s���v");

        set("apply/armor",30);
        set("apply/damage",30);

        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("fork",100);

        set_skill("da-fork",100);
        set_skill("bagi_fist",100);
        set_skill("horse-steps",100);

        set("chat_chance", 10);
        set("chat_msg",({
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
        }) );
// ========================================================================
//      �u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
        set("guild_skills",([           // ����, ����1�i��, �W��

        ]) );

// ========================================================================
//      �ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
//      �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
//      �ӥB�|�����`�M�n��n���� 20
//      ********************* �����n�M���¾�~�@�� **********************
// ========================================================================
        set("guild_gifts",({10,7,0,3}));

        setup();
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_guild_join","join");
        add_action("do_advance","advance");
}


int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(this_player()->query("class2") != "�K����")
                return notify_fail("�A�ä��O�K�����̤l�C\n");
        if( this_player()->query("popularity") < 3 ) 
                return notify_fail(".....");
             me->set("popularity",j-3);
        return    GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        message_vision("$N�Q�[�J"+arg+"�C\n",me);
// ========================================================================
// join �[�J¾�~, �����n�ϥ� do_guild_join(),
// �p�G�Ův�n�ϥΦۤv���^���覡, �Х� do_guild_join_with_no_message()
// �Ǧ^�ƭ�, �A�ϥγo�Ǽƭȧ@�z�Q�����^���覡.
// ========================================================================
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -2: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -8: notify_fail("�S���o�Ӫ����a");break;

        }
        if( arg=="�K����"
         && me->query("class1")=="�K����" 
         && me->query("level")==25 )
          {       
            command("pat " + me->query("id") );
            me->set("class2","�K����");
            me->create_family("�K����",2,"�L��");
            me->set("adv_class",2);
          }
          else    
          {
            command("say �o��"+ RANK_D->query_respect(me) +"�ڨä��Q���A���{�C\n");
          }
        return 1;
}

int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(this_player()->query("class2") != "�K����")
                return notify_fail("�A�ä��O�K�����̤l�C\n");
        if(me->query("popularity") < 3 ) 
                return notify_fail("�A���n�椣���C\n");
        me->set("popularity",j-3);
        return GUILDMASTER->do_advance(ob,me,arg);
}

// ========================================================================
// �ϥ� advance �ɯŮɷ|�ѦҨ� guild_rank() �o�Ө��, �o�Ө�ƥi�H����
// ���a��¾�~rank.
// ========================================================================
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
                                // LV 1 ~ 9
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                                // LV 10 ~ 19
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                                // LV 20 ~ 29
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                                // LV 30 ~ 39
                        case 3: rank = "���Z�Ф����C����"; break;
                                // LV 40 ~ 49
                        case 4: rank = "���Z�Ф����k�C�L"; break;
                                // LV 50
                        default: rank = HIC"���Z�Ф����ѷ��a"NOR;
                }
        }
        else
        {
        }
        return rank;
}


