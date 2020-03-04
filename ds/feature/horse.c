#include <ansi.h>
#include <login.h>
inherit NPC;
void init()
{
        ::init(); //luky
        add_action("do_name","name");
        if(environment(this_object())==this_player())
        {
          add_action("do_remember","remember");
          add_action("do_rlist","rlist");
          add_action("do_run","run");
        }
}

int do_rlist(object me) {
        int i;
        object room;
        string result = "";
        for( i = 0 ; i < query("max_remember"); i++) {
                result += "�O���I" + chinese_number(i+1) + " :";
                if(     stringp(query("member" +i))
                        && query("member" +i) !="none" 
                        && objectp(room = find_object( query("member" +i) )) )
                        result += room->query("short") + "\n";
                else
                        result += " (none) \n";
        }

        write(result);
        return 1;
}

int ride_before_action(object me)
{
        message_vision("$N�}��W�F���ޡA���۴N���W�F"+this_object()->name()+"�����b�C\n",me);
        //me->set_temp("apply/short",({ me->short()+HIY"< ���M��"NOR+this_object()->name()+HIY" >"NOR}));
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$Níí�����b"+this_object()->name()+"�����I�W���F�C\n",me);
        //this_object()->set_weight(10);
        //this_object()->move(me);
        set("chat_chance",0);
        return 1;
}

int ride_off_action(object me)
{
    int i;
        message_vision("$N�q"+this_object()->name()+"���I�W���F�U�ӡC\n",me);
        message_vision("$N�ѤF�Ҧ����O�ФF�I�I\n",this_object());
        for(i=0;i<query("max_remember");i++)
                set("member" +i,"none");

        set("chat_chance",1);
        //me->delete_temp("apply/short");
        return 1;
}

int do_remember(string arg)
{
        int n_save;
        string where;
        object me,env;
        me=this_player();
        if(! env = environment(me)) return 0;
        if( !arg || sscanf(arg,"at %d",n_save)!=1 )
                return notify_fail("���O�榡: remember at <�ĴX�ӰO��>. \n");
        if( strsrch(file_name(env), "lost_island") != -1 )
                return notify_fail("�����L���H�o�򻷪��a�谨��O���ۭ��I\n");
         if( n_save < 1 || n_save > query("max_remember") )
                return notify_fail("�����ȨS�A�O�o����h�a...�C\n");
        if( !env->query("outdoors") )
                return notify_fail("���u��O�o�ǥ~������C\n");
        if( env->query("no_horse_member") )
                return notify_fail("�o�o�a�I�L�k�Q���O�СC\n");
        n_save -= 1;
        where=(string)file_name(env);
        message_vision("$N�V�O�s����o�̪�����O�_�ӡC\n",me);
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
                return notify_fail("�A�èS���M�۰��C\n");
        if( me->query_temp("horse_run") )
                return notify_fail("�A���b�M�۰����Y�a�e�i����C\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("���O�榡: run at <�����ĴX�ӰO��>. \n");
         if( n_save < 1 || n_save > query("max_remember") )
                        return notify_fail("�S�o�ӰO�г�....�C\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("�A�n���S���s�e�O����A�ҥH�e�èS����������C\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("�A���N�b�o�̤F�H\n");
        tell_room(environment(me),me->name()+"�M�ۥL��"+this_object()->name()+"���O����V�ӥh�C\n",({ me }));
        me->move(__DIR__"obj/runwait.c");
        tell_object(me,"�A�}�l���Y�a�e�i�D�D�D\n");
        me->start_busy(10);
        me->set_temp("horse_run",1);
        call_out("for_go",3,me,this_object(),arg);
        call_out("for_go1",10,me,this_object(),arg);
        call_out("for_go2",13,me,this_object(),arg);
        return 1;
}

void for_go(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIY"$N�M��$n�w�C����"+go_room->query("short")+"�e�i�h�D�D�D�D�D\n"NOR,me,ob);
        return;
}

void for_go1(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIC"�C�C���A$N�w�֨�F�F�ت��a�F�D�D�D�D�D�D\n"NOR,me);
        return;
}

void for_go2(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"�A��F�F�ت��a�F�I���\n"NOR);
        tell_room(environment(me),me->name()+"��M�q�@�Ӧa���M�ۥL��"+ob->name()+"�Ө�F�o�̡C\n",({ me }));
        ob->move(me);
        me->delete_temp("horse_run");
        return;
}

int do_name(string arg)
{
        string n_who,name;
        object me,object_h;
        me = this_player();
        if(!arg || sscanf(arg,"%s as %s",n_who,name )!=2 )
                return notify_fail("�榡�G name <���ǰ�> as <�W�r> .\n");
        if( !present(n_who,environment(me)) )
                return notify_fail("�S���o�Ӱ�. \n");
        if( !objectp(object_h=present(n_who,environment(me))) )
                return notify_fail("�榡�G name <���ǰ�> as <�W�r> .\n");
        if( object_h->query("id") != this_object()->query("id") )
                return notify_fail("�榡�G name <���ǰ�> as <�W�r> .\n");
         if( strlen(COLOR_D->clear_withinansi(name)) > 24 )
                return notify_fail("�Ч�W�r���o�r�֤@�I.\n");
        name = replace_string(name, "$BLK$", BLK);
        name = replace_string(name, "$RED$", RED);
        name = replace_string(name, "$GRN$", GRN);
        name = replace_string(name, "$YEL$", YEL);
        name = replace_string(name, "$BLU$", BLU);
        name = replace_string(name, "$MAG$", MAG);
        name = replace_string(name, "$CYN$", CYN);
        name = replace_string(name, "$WHT$", WHT);
        name = replace_string(name, "$HIR$", HIR);
        name = replace_string(name, "$HIG$", HIG);
        name = replace_string(name, "$HIY$", HIY);
        name = replace_string(name, "$HIB$", HIB);
        name = replace_string(name, "$HIM$", HIM);
        name = replace_string(name, "$HIC$", HIC);
        name = replace_string(name, "$HIW$", HIW);
        name = replace_string(name, "$NOR$", NOR);

        message_vision("$N��$n���W�r�אּ�i"+name+"�j\n"NOR,me,this_object());
           this_object()->set("name", "�i"+name+"�j"NOR);
        return 1;
}

void flee()
{
        string *dirs;
        int i;

        message_vision("$N����F�����A��W���U�}�l�ö]...�C\n", this_object());
        if( !mapp(environment(this_object())->query("exits")) )
        {
                message_vision("$N���|�P���V�V���]�A�A�]�����D�L�]�쨺�F...�C\n", this_object());
                switch(NATURE_D->which_world(environment(this_object())))
                {
                        case 3:
                                this_object()->move(START_ROOM_FUTURE);
                                this_object()->stop_attack();
                                break;
                        case 2:
                                this_object()->move(START_ROOM_NOW);
                                this_object()->stop_attack();
                                break;
                        case 1:
                                this_object()->move(START_ROOM_PAST);
                                this_object()->stop_attack();
                                break;
                        default:
                                destruct(this_object());
                                return;
                }
                write(" �γ\\�A�i�H�� recall start �h��ݬ�..�C \n");
        }
        dirs = keys(environment(this_object())->query("exits"));
        i = random(sizeof(dirs));
        command("go "+dirs[i]);
        command("open door"); //add by sdo@DS,�ץ����W���ᰨ�N�]���X�h�����D
        write("go "+dirs[i] + "\n");
}

int setting(string id)
{
        if( !id ) return 0;
        set("buyer_id", id);
        this_object()->create();
        return 1;
}

