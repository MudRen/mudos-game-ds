#include <ansi.h>
#include <login.h>
inherit ITEM;

void create()
{
        set_name(HIR"����"HIC"��������"NOR,({"super broom","broom"}));
        set("long","�@��୸�ӭ��h������E�i�H��member�O��n���h���a��E�A��run����Q�h���a��E\n");
        set_weight(3000);

        set("no_get",1);
        set("amount",1);
        set("ridable",1);

        set("unit","��");
        set("value",1000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        setup();
}

void init()
{
          add_action("do_member","member");
          add_action("do_run","run");
}

int ride_before_action(object me)
{
        object ob=this_object();
        message_vision("$N�V�W�@�D�A���۴N���W�F"+this_object()->name()+"���I�W�F�C\n",me);
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$Níí�����b"+this_object()->name()+"���I�W�F�C\n",me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N�q"+this_object()->name()+"���I�W���F�U�ӡC\n",me);
        message_vision("$N�ѤF�Ҧ����O�ФF�I�I\n",this_object());
        this_object()->set("member0","none");
        this_object()->set("member1","none");
        this_object()->set("member2","none");
        this_object()->set("member3","none");
        this_object()->set("member4","none"); 
        this_object()->set("member5","none");
        return 1;
}

int do_member(string arg)
{
        int n_save;
        string where;
        object me,env;
        me=this_player();
        if(! env = environment(me)) return 0;
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("���O�榡: member <�ĴX�ӰO��>. \n");
        if( n_save > 5 || n_save < 1)
                return notify_fail("�����ȨS�A�O�o����h�a...�C\n");
        if( !env->query("outdoors") )
                return notify_fail("���u��O�o�ǥ~������C\n");
        if( env->query("no_horse_member") )
                return notify_fail("�o�o�a�I�L�k�Q���O�СC\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N�V�O�s$n��o�̪�����O�_�ӡC\n",me,this_object());
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();
        if(!me) return 0;
   if(me->query_temp("killer"))
  {
    write("�A���F�H�Ȯɤ��i�H�ϥΦ��O!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("�A�����F���a�Ȯɤ��i�H�ϥΦ����O!\n");
    return 1;
  }

    if( me->is_busy() || me->is_block() || me->is_fighting()) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
        if( sizeof(me->query_temp("is_busy")) ) return notify_fail("�A�W�@�Ӱʧ@�٨S�����C\n");
        if( !me->query_temp("ride") )
                return notify_fail("�A�èS���M�ۥ��C\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("���O�榡: run at <�ĴX�ӰO��>. \n");
        if( n_save > 5 || n_save < 1 )
                        return notify_fail("�S�o�ӰO�г�....�C\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("�A�n���S���s���O����A�ҥH�e�èS����������C\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("�A���N�b�o�̤F�H\n");
        tell_room(environment(me),me->name()+"�M�ۥL��"+this_object()->name()+"���O����V�ӥh�C\n",({ me }));
        tell_object(me,"�A�M�ۧA��"HIR"����"HIC"��������"NOR"�A����㪺�@�n�N��F�ت��a�E\n");
        me->move(arg);        
        
        tell_room(environment(me),me->name()+"��M�q�@�Ӧa���M�ۥL��"+this_object()->name()+"�Ө�F�o�̡C\n",({ me }));
        return 1;
}

