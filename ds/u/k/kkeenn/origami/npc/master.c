#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�P��v",({"origami master","master"}));
        set("title",HIC"��ޢպ��e����"NOR);
        set("nickname",HIW"�P�Ȥu�|�|��"NOR);
        set("gender", "�k��");
        set("long",@LONG
�L�O�P�Ȥu�|�̸�`���z�ƪ��A�o�O�C�s�L�����u�Ӫ��P�ȱЮv�C

        list    �C�X�i�Ǫ��ޯ�
        train   �V�m�ޯ�
        learn   �ǲߪk�N
        join    �[�J�u�|
        apply   �ӽиɵo�H��
        advance �ɯũμW�[�ݩ�

LONG
        );
        set("level",50);                
        set("age",40);
        set("adv_class",1);
        set("class1","origami");
        set("guild_skills",([   // ����, ����1�i�Ǩ쪺�ޯ൥�ŭ��v, �W��
                "dodge":({60,3,80}), 
                "gun":({60,3,80}),
                "combat":({50,3,80}),  
                "origami":({100,1,80}),  
                "doubleshoot":({80,2,90}),  
                "unarmed":({80,5,60}),
                "block":({40,3,70}), 
       ]) );
         set("guild_gifts",({10,5,-3,8}));
        setup();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
     if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        add_action("do_check_mark","apply");
     if(!query("no_advance"))
        add_action("do_advance","advance");
}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // �קK�C�X�ˬd¾�~���T��
        write("\n");
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
        if( !arg && !me->query_temp("join_o") )
                return notify_fail("�A�Q�n�[�J����u�|�r�H(join origami)\n");
        if( me->query_temp("join_o") && !arg ) arg = "origami";
        if( strsrch(arg, "origami") == -1 || strsrch(arg, "��") > -1)
                return notify_fail("�A�Q�n�[�J����u�|�r�H(join origami)�)\n");
        message_vision("$N�Q�[�J�u"+ HIM"" + arg + ""NOR+ "�v�C\n",me); 
        if( me->query("class1") )
                return notify_fail("�A�w�O"+me->query("class1")+"���Ǯ{�F�C\n");
        if( me->query("class1")=="origami" )
                return notify_fail("�A�w�O�P�Ȥu�|���Ǯ{�F�C\n");
        if( !me->query_temp("ojoin") && !me->query_temp("join_o") ) {
        command("whisper "+me->query("id")+" ��...�p�A�Ҩ�...�ڭ̯ʿ��w�줤...�C");
        command("whisper "+me->query("id")+" �Ʊ�z�஽�m���ڭ̤��d������(donate 5000)�C");
        me->set_temp("ojoin",1);
        add_action("do_donate", "donate");
        return 1;
        }
        else if( me->query_temp("ojoin") && !me->query_temp("join_o") ) {
                command("say �B�͡A�A�M�w�F�ܡH���ƤQ���n��A�Ч֦Ҽ{�C");
                add_action("do_donate", "donate");
                return 1;
        }
        else {
                command("pat "+me->query("id")); 
                command("thank "+me->query("id"));                            me->set("guild_rank","�P�Ȥu�|��ŷ|��");
                message_vision("$N�����P�Ȥu�|���|���C\n",me);
                me->set("class1","origami");
                me->set("adv_class",1);
                new("/u/k/kkeenn/origami/paper/paper.c")->move(me);
                write(WHT"�P��v������F�@�i�}�ꪺ�z���ȵ��A�C\n"NOR);
                return 1;
        }
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
        lv = lv/10;     // �N rank �������Ӽh��
        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                        case 0: rank = HIC"���ӺP�Ȥu�|�Ǯ{"NOR; break;
                        case 1: rank = HIY"�P�Ȥu�|���k�|��"NOR; break;
                        default: rank = HIM"�P�Ȥu�|�P�ȾԤh"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"���ӺP�Ȥu�|�Ǯ{"NOR; break;
                        case 1: rank = HIY"�P�Ȥu�|���k�|��"NOR; break;
                        default: rank = HIM"�P�Ȥu�|�P�ȾԤh"NOR;
                }
        }
        return rank;
}
int do_donate(string arg)
{
        object me;
        int i;
        me = this_player();
        if( !arg )
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'�C\n"NOR);
        if(sscanf(arg,"%d",i)!=1 ) 
        return notify_fail(HIG"Computer Type Out 'How much money do you want to donate ?'�C\n"NOR);
        if( i < 5000 )
        return notify_fail("Computer Type Out 'The low money limit is 5000 !'�C\n");
        if(me->query("bank/future") < i )
        return notify_fail("Computer Type Out 'Sorry, you don't have "+i+" future coco.'�C\n");
        message_vision("$N donated "+i+" coco to the Origami club�I\n"NOR,me);
        me->add("bank/future",-i);
        me->set_temp("join_o",1);
        return 1;
}
int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class1")!="origami")
                           return notify_fail("�A�èS���ѥ[�P�Ȥu�|��C\n");
        if(mark=present("none paper",me))
                           return notify_fail("�A�w�g�������H���F�C\n");
        if(mark=present(me->query("family/id")+" paper",me))
                           return notify_fail("�A�w�g�������H���F�C\n");       
        if(mark=present("armor",me))
                           return notify_fail("�A�w�g�������H���F�C\n");   
   if(!me->query("family"))
{
        ob=new("/u/k/kkeenn/origami/paper/paper.c");
}
else
{
        ob=new("/u/k/kkeenn/origami/paper/paper2.c");
}
        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("�A�����ᱼ�@�ǪF��~�����ʦ��P�ȡC\n");
        }
        ob->move(me);
        message_vision("$N���F�@�i"+ob->name()+"��$n�C\n",this_object(),me);
        me->save();
        return 1;
}
