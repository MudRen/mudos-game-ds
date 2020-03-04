#include <ansi.h>
inherit NPC;
void heal();
string ask_for_join();
void create()
{
        set_name("�궳�M�|", ({ "master bonze", "master", "bonze" }) );
        set("gender", "�k��");
        set("age", 80);
        set("level",41);
        set("attitude", "peaceful");
        set("adv_class",1);
        set("class1","�ⶳ�x");
        set("apprentice_available", 10);
            set("guild_gifts",({3,7,3,7}));



        set("inquiry", ([
                "�c��" : "��������I���v�I���v�I�I�D�Y�u�߬Ԩ̧ڦ�A�и��U(kneel)���١C",
                "�X�a" : "��������I���v�I���v�I�I�D�Y�u�߬Ԩ̧ڦ�A�и��U(kneel)���١C",
                "�c�ץX�a" : "��������I���v�I���v�I�I�D�Y�u�߬Ԩ̧ڦ�A�и��U(kneel)���١C",
                  "�����o��": "�������� �I�I�D�������o��(lug)�o�Ӥ߷N�A�ѯǯu���A�����C",
        ]) );
        set("long",
                "�L�ͱo�b�v�D�C�A���۰��j�A�P���D�����ѤH\n"
                "�ݤW�h�ܤ֤]�j�}�H�W�~���A�������w��A��\n"
                "�@�L�����s�����A�C\n"
        );

        set("guild_skills",([
               "dodge" : ({140,3,60}),
               "parry" : ({130,3,80}),
               "staff" : ({120,3,80}),
               "wuchen-staff" : ({140,2,70}),
               "literate" : ({130,3,80}),
               "buddha-force" : ({135,3,90}),
               "quanyin-steps" : ({130,3,90}),
        ])  );

        set("guild_spells",([
               "recite-sutra" : ({140,3,80}),
        ]) );
        set("chat_chance", 10);
        set("chat_msg",({
                (:command("hmm"):),
               (:command("exert quanyin-steps"):),
              (:command("exert wuchen-staff"):),
           (: heal :),
        }) );

        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
              (:command("exert buddha-force armor"):),
                (:command("cast recite-sutra"):),
        }) );
 
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("staff",100);
        set_skill("literate",100);
        set_skill("force",100);
        set_skill("wuchen-staff",100);
        set_skill("quanyin-steps",100);
        set_skill("buddha-force",100);
        set_spell("recite-sutra",100);
        map_skill("staff","wuchen-staff");
        create_family("�ⶳ�x",4, "���");
            set("addition_armor",100);
        set("evil",-50);
        setup();
        carry_object(__DIR__"wp/force-shake-staff")->wield();
}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_kneel","kneel");
        add_action("do_lug","lug");
}

int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //�Ȯ�
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")!="�ⶳ�x")
                return notify_fail("�A���O�ⶳ�x�M�|�C\n");
        if( me->query("level")<=25 && !me->query("class2") )
                return  GUILDMASTER->do_advance(ob,me,arg);
        else
                return notify_fail("�궳�M�|���G���z�|�A���ШD�C\n");
}


int do_join(string arg)
{
        int i;
        object ob, me;
        ob = this_object();
        me = this_player();
        if(arg != "�ⶳ�x") return notify_fail("�o�̨S���o�ت����C....:P\n");
        {
          if( me->query("class1") ) return notify_fail("�A�w�������F�C�C....^_^\n");
          if( me->query("gender") != "�k��" ) return notify_fail("�궳�M�|���D�G��������I�k�I�D�A�o�̬O�x�q�A�Щp�쥧�g�h�c�קa�C\n");
          tell_object(me,"�궳�M�|���D�G��������I���v�I���v�I�I�D�Y�u�߬Ԩ̧ڦ�A�Х��c�ץX�a�a�C\n");
          me->set_temp("pending/join_bonze", 1);
          return 1;
        }
}
int do_kneel()
{
        string *prename = ({ "��", "��", "��", "�b", "��", "��","��", "��", "�z", "�k" });
        string name, new_name;

        if( !this_player()->query_temp("pending/join_bonze") ) return 0;
        message_vision(
                HIC "$N����X�Q�M�����q�q�a���F�U�ӡC\n\n"
                        "$n���X��x�M�b$N�Y�������a���f�F�X�U�M�N$N���Y�v�ɼƫc�h�C\n\n" NOR,
                this_player(), this_object() );
        name = this_player()->query("name");
        new_name = prename[random(sizeof(prename))] + name[0..1];
        command("say �q���H��A���k�W�s��" + new_name + "�C");
        command("smile");
        this_player()->set("guild_rank","�ⶳ�x�Ĥ��N�̤l");
        this_player()->delete_temp("pending/join_bonze");
        this_player()->set("adv_class",1);
        this_player()->set("class1","�ⶳ�x");
        this_player()->create_family("�ⶳ�x",5,"�̤l");
        this_player()->set("name", new_name);
    this_player()->set("guild_gifts", query("guild_gifts") );

        return 1;
}
int do_lug(string arg)
{
        int i;
   object me,ob,coin;
        me=this_player();
        ob=this_object();
        if(!arg ) 
                return notify_fail("�A�n���U�h�֭��o���O�H\n");
        if(sscanf(arg,"%d",i)!=1 ) 
                return notify_fail("�A�n���U�h�֭��o���O�H\n");
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ů����o���C\n");
        if(me->is_fighting() )
                return notify_fail("�A�����ۡA�S���Ů����o���C\n");
       if(!objectp(coin=present("coin",me) ) )
            return notify_fail("�A���W�S�����C�C\n");
     if(i > coin->query_amount() )
         return notify_fail("�A���W���������C�C\n");
        message_vision("$N���F"+(string)(i)+"�孻�o����$n\n",me,ob);
        command("smile");
         command("thank "+ me->query("id") );
          me->receive_money(-i);
          if(i > 99 && i < 501 )
        {
        command("say �o��I�D�j���j�w�A���ѯǬ��A�վi���ߡA����鰷�C");
          message_vision(GRN "\n$N�y�W����@�{�A�����@�x���V$n�I�ߡI�I\n"+HIR "$n�u�z�v�a�@�n�R�F�X�f�A��C\n\n" NOR ,ob,me);
   me->receive_heal("hp",i/2);
   me->receive_heal("mp",i/3);
   me->receive_heal("ap",i/3);
           me->start_busy(i/20);
        }
        return 1;
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
CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�O�d���h���ⶳ�x��V�y�궳�M�|�z�ש�ѵ��F"+ob->name(1)+"�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
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
                        case 0: rank = "�ⶳ�x�Ĥ��N�̤l"; break;
                        case 1: rank = "�ⶳ�x�Ĥ��N�̤l"; break;
                        case 2: rank = "�ⶳ�x�Ĥ��N�̤l"; break;
                }
        }
        {
                switch( lv )
                {
                        case 0: rank = "�ⶳ�x�Ĥ��N�̤l"; break;
                        case 1: rank = "�ⶳ�x�Ĥ��N�̤l"; break;
                        case 2: rank = "�ⶳ�x���o�D����"; break;
                }
        }
        return rank;
}
void heal()
{
     object obj;
     obj=this_object();
if(obj->query("hp") < obj->query("max_hp")/2)
{
      command("exert buddha-force heal");
}
}
