// new class - Jangshow 03.24.2006
// /u/s/shengsan/npc/bluemaster.c       by shengsan
// �ŤѾɮv                             1999.03.28
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"�K���E"NOR,({"iron shouw hung","iron","hung","shouw","master"}));
        set("gender", "�k��");
        set("long",@LONG
�L�O�K�ު����x���H�A�⮳�ۤ@�⥨��A����ۦʤ筫���K�ҡA���j��
���ߡA���A�ѤF�L�w�N�񤻤Q���C
LONG
        );
        set("level",60);                // �]�w�ɮv������
        set("age",55);                  // �]�w�ɮv���~�� 
        set("title",HIC"�K�ު�"NOR);

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
        set("class1","iron_class");           // �]�w¾�~���W��

// ========================================================================
//      �u�|�ɮv�i�H�бª��ޯ�C��
// ========================================================================
        set("guild_skills",([   // ����, ����1�i�Ǩ쪺�ޯ൥�ŭ��v, �W��
                "dodge":({30,2,50}),   // �򥻰{��
                "blade":({30,2,50}),    // �M�k�ޥ�
                "sword":({30,2,50}),   //�C�k�ޥ�
        ]) );

// ========================================================================
//      �u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
        set("guild_spells",([           // ����, ����1�i��, �W��
            //    "iron_soul":({50,2,100}),   // �K�N��
        ]) );

// ========================================================================
//      �ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
//      �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
//      �ӥB�|�����`�M�n��n���� 20
// ========================================================================
        set("guild_gifts",({10,5,-3,8}));
         add("addition_armor",300);
        add("addition_damage",200);  
        set("chat_chance", 12);
        set("chat_msg", ({
  (: command("say ���ѤѮ�u�n") :), 
})); 
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("wield axe") :),   
  (: command("wield axe") :),  
  (: command("wield axe") :),  
  (: command("wield axe") :),  
  (: command("wield axe") :),  
})); 
      //set_skill("heavy-sword",100);     
        setup();
        carry_object(__DIR__"wp/axe.c")->wield();
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
        this_player()->set("no_check_class",1); // �קK�C�X�ˬd¾�~���T��
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

// ========================================================================
// join �[�J¾�~, �����n�ϥ� do_guild_join(),
// �p�G�Ův�n�ϥΦۤv���^���覡, �Х� do_guild_join_with_no_message()
// �Ǧ^�ƭ�, �A�ϥγo�Ǽƭȧ@�z�Q�����^���覡.
// ========================================================================
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("say ���a�w�g�[�J��L��´�C");break;
                case -2: command("say ���a�w�g�[�J�F�P�ɮv�P�ũΧ󰪯Ū���´�C");break;
                case -3: command("say ���a�ثe����´�ä��A�X�[�J����´�C");break;
                case -4: command("say ���a���Ť����C");break;
                case -5: command("say ���a�� termstr �èS���j�� termnum �ȡC");break;
                case -6: command("say ���a�� termstr �èS������ termnum �ȡC");break;
                case -7: command("say ���a�� termstr �èS���p�� termnum �ȡC");break;
                case -8: command("say ���a��J����´���~�ΨS����J�n�[�J����´�W�C");break;
                default: command("say Yes...�A�N�O�ڭn�䪺�H�C");
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
                        case 0: rank = HIR"�K�ު�����ߧ̤l"NOR; break;
                        case 1: rank = HIR"�K�ު��������̤l"NOR; break;
                        default: rank = HIR"�K�Z�N�������ޡ�"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"�K�ު�����ߧ̤l"NOR; break;
                        case 1: rank = HIC"�K�ު��������̤l"NOR; break;
                        default: rank = HIC"�K�Z�N�������ޡ�"NOR;
                }
        }
        return rank;
} 
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision(HIY"\n$N��B���x�A��W����o�X����n�T�I\n"
                    +HIW"\t���X�I�I\n"
                    +HIR"$n�Q�@�D�ݤ�������l���СI\n"+NOR,me,target);  
    target->receive_damage("hp",500+random(199), this_object());
      return 1; 
    }
    else
    {
      message_vision(HIY"\n$N�֨B�V�e�A�S�Q��O���Y���V$n\n"
                    +HIR"$n�Q�����Y������ !@#$%�I\n\n"+NOR,me,target);    
   target->receive_damage("hp",200+random(100),  this_object());
   target->add_busy(5+random(5));
      return 1;
    }
}
void die()
{
        object ob,key;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",HIC"\n\t���K�ު���\t"HIW"�x���H�i�K���E�j�G���b"HIR""+ this_player()->name()+""HIW"��U\n\n"NOR, users());
        ob->add("popularity", 5); //�n��
        ::die();
        return;
}

