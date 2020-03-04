#include <ansi.h>
#include <path.h>
inherit NPC;
void flee();

void create()
{
        set_name( "�U����", ({ "gou zhi tian","gou","tian" }) );
        set("level",15);
        set("long" ,"�L�N�O�ɿ������ѷݤF�A�ܦt�������o�ۤ@�ѫ��Y�B����C\n");
        set("age",60);
        set("title",HIG"���ѷ�"NOR);

        set("env/wimpy", 60);
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
           (:command("help!"):),
           (:command("scream"):),
           (:command("say �H�ӰڡI�I�֨ӱϧڰڡI�I"):),
         (: flee :),
         }) );
        set_skill("dodge",65);
        set_skill("parry",50);
        set_skill("unarmed",20);
        setup();

        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/hat")->wear();
        carry_object(__DIR__"eq/bangle")->wear();
        carry_object(__DIR__"item/key");
}

void init()
{
        ::init();
        add_action("do_kill","kill");
}


void do_kill(string arg)
{
        object ob,me,*obs;
        me=this_player();
        ob=this_object();

        if( !arg) return;
        if( !objectp(present(arg, environment(me)))) return;
        
        if( is_fighting(me) ) return;
        message_vision("$N���D�R�x�H�y�ϰաH�����ñ��H�I�I�h���a ...\n",this_object());
        obs = all_inventory(environment());
        for(int i=0;i<sizeof(ob);i++)
        {
                obs[i]->soldier_assist(this_object(), me);
        }
}

void soldier_assist(object alert, object me)
{
        if( alert==this_object()
        ||      !living(this_object())

        ||      is_fighting(me) )
                return;
        me->fight_ob(this_object());
}

void flee()
{
        object ob;
        ob=this_object();
        if (ob->is_busy() ) return;
        message_vision(HIW"�A�ݨ�$N�W�W�i�i���k���L�v�L�ܤF�C\n"NOR,ob);
        destruct(ob);
        return;
}

void die()
{
        int i;
           object ob,g,env,npc;
        object e,s,n,w;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->add_temp("SKYCITY/jail",i+1);

        env=environment();
       if(!objectp(npc=find_living("skycitywar") ) && env->query("Sky-City-War")==1 ) env->delete("Sky-City-War");
        if(env && env->query("Sky-City-War")!=1 )
        {
      
        message("world:world1:vision",
 HIG+"\n\t�i�氨�ֳ��j" +HIW+""+ ob->name(1)+HIW"�����F�ѫ����ѷݡI�I\n\n" NOR
HIC"�T�x�j���Ӥj�ܡG�u�ϤF�ϤF�I�I���M���`�§ʩR�x�A�@�s���Ѧʩm�I�I�v\n"NOR
HIY"\n\t ���T�x�n�Ϥѫ��A����F�ѫ��q�~���|�ӫ����I�I\n" NOR
,users() );
          env->start_war(1);
             env->set("Sky-City-War",1);
        n=load_object(ACME_PAST+"area/ndoor");
        e=load_object(ACME_PAST+"area/edoor");
        w=load_object(ACME_PAST+"area/wdoor");
        s=load_object(ACME_PAST+"area/sdoor");
        n->lock_door("north");
        e->lock_door("east");
        w->lock_door("southwest");
        s->lock_door("southdown");
        }        
        ::die();
        return;
}

