//���񭸼C

#include <ansi.h>
inherit NPC; 
void create()
{
        set_name(HIC"�ѯe"NOR,({"master sky-wind","sky","master","wind"}));
        set("long" ,@LONG  

      =====================================
        list    �C�X�i�Ǫ��ޯ�P�k�N�C��
        train   �V�m�ޯ�
        join    �[�J�u�|
        advance �ɯũμW�[�ݩ�
      =====================================
LONG);
        set("nickname", "�ѯe�����ȥ~�ѤH" );
        set("attitude", "friendly"); 
        set("age", 80);
        set("gender","�k��");
        set("combat_exp", 450000);
        set("level", 60);
        set("title",HIR"��  ��"NOR);
        set("max_ap",20000); 
        set("max_hp",16505);
        set("max_mp",20000);
        set("class1","�e����"); 
        set("class2","�ѯe��"); 
        set("flurrydodge",1);
        set_temp("apply/armor",200);
        set_skill("fogseven",100);
        set_temp("sorgitimes",20);
        set_skill("unarmed", 100);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",100); 
        set_skill("sevenstar-sword",100); 
        set_skill("star-sword",100);
        set_skill("sorsin-force",100);     
        map_skill("sword","star-sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 3,5,5,7}));  
//      �u�|�ɮv�i�H�бª��ޯ�C��
        set("guild_skills",([
  "sorsin-force" : ({ 175,4,85 }), 
]));

        set("no_check_class",1);
        set("adv_class",2);
        set("chat_chance",8);
        set_temp("class_wind/power",400);
        set("chat_msg", ({
  "�ѯe�������R�ۤ⤤���C�A�C�C���L�A�C��֡A�X�ۺC�C\n", 
  (:command("smile"):),
  (:command("exert moon_force recover"):), 
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
  (:command,"exert star-sword tian":),
  (:command,"exert star-sowrd nine":),
  (:command,"exert star-sword penuma-sword":),
  (:command,"exert sorsin-force":),
  (:command("exert moon_force moon-arc"):),
}));

        setup();
        carry_object("/u/j/jangshow/sword")->wield();
       // carry_object(__DIR__"eq/sandal")->wear();
}  
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
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
 
//�{�b�d���bjoin�o..�n�Q�@��quest�Ӹ�.. ><" 
int do_guild_join(string arg)
{
        object ob, me;
        int i;
        ob = this_object();
        me = this_player();  
        if(!arg=""||arg!="�ѯe��")
             return notify_fail("�i�H join �ѯe�� �C\n")        if(me->query("level") < 50)
             return notify_fail("�A�������٤����C\n")
        if(!me->query("class1")=="�e����")
             return notify_fail("�A���O�e�������C\n")
        if(me->query("exp") < 10000000)
             return notify_fail("�A���g��Ȥ����C\n")
        if(me->query("popularity") < 2000)
             return notify_fail("�A���n�椣���C\n")  
        {
        message_vision(HIC"����"+me->name()+"�[�J �ѯe�� �C\n",me)
        me->set("class2","�ѯe��");
        me->receive_damage("exp",10000000);
        me->receive_damage("popularity",2000);
        }
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
                        case 0: rank = HIC"�ѯe�������U�̤l"NOR; break;
                        case 1: rank = HIG"�ѯe�����l���«C"NOR; break;
                        default: rank = HIY"�ѯe������d�x"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"�ѯe�������U�̤l"NOR; break;
                        case 1: rank = HIY"�ѯe�����l���«C"NOR; break;
                        default: rank = HIM"�ѯe������d�x"NOR;
                }
        }
        return rank;
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIC"\n\t      �i�ѯe�����ȥ~�ѤH�j"+HIW"�Q"+HIR"�i"+ob->name()+"�������F�j\n\n"+NOR,users());
        ob->add("popularity",10);   
        ob->set("guild_rank",HIC"�ѳz"HIY"�Ѧt��z"HIC"�U��"NOR);
        ::die();
        return;
}


