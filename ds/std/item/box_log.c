
/*
**********************************************************
***********       BOX �p���~���� BOX_LOG       ***********
**********************************************************

Cominging@DS 2001.8.29
�ڧ�ʪ��a�� <globals.h>
#define BOX_LOG                 "/std/item/box_log" // add by Cominging

�d�Ҽҫ�
  mapping get = ([ "cominging" : ({ "ctime(time()) �H�� ���~" }), ]);

For DS Clan: �@�� box with ACCESS_LOG 15 �U
                           BOX_LOG    20 �U

**********************************************************
***********       BOX �p���~���� BOX_LOG       ***********
**********************************************************
*/

#include <ansi.h>
#define HELP "���O�榡: \n       ** checkuse 'id' {-w|-l|-m}\n    -w <id> ���w�d�ݯS�w���a������\n    -l      �[�ݩҦ�������, ���Z�O�� get �A put�C\n    -m <get/put> �[�d get �� put �������C\n       ** cleanup 'id' {get|put|all}\n    get     �M�� get �������C\n    put     �M�� put �������C\n    all     �M���Ҧ������C\n\n�`�N: �n�� ' ' �A�_�ӡC\n"

mapping get = ([  ]);
mapping put = ([  ]);
string op_all(string arg); // output ��X�S�w log string

void init()
{
        if( !this_object()->query("club_id") || !this_object()->query("demand_level") )
        {
                write(this_object()->name(1)+"�]�w���~, �гq���Ův�C\n");
                return;
        }
        add_action("do_check", "checkuse");
        add_action("do_cleanup", "clean_record");
}

void log_put(object me, object ob)
{
        if( !arrayp(put[getuid(me)]) )
                put[getuid(me)] = ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        else put[getuid(me)] += ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        this_object()->save();
}

void log_get(object me, object ob)
{
        if( !arrayp(get[getuid(me)]) )
                get[getuid(me)] = ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        else get[getuid(me)] += ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        this_object()->save();
}

int do_check(string arg)
{
        object me, oTarget;
        string flag, chos, *logz, str, pTarget;
        // flag, chos �O�Ω� sscanf ��O�ݨD
        // logz �O�b�� put, get �ݨD���Ȧs�ܼ�
        // str �O�n��X����r��
        // keyz �O�� put, get �� keys()
        me = this_player();

        if( !arg ) return notify_fail(HELP);
        if( (int)CLUB_D->check_member(this_object()->query("club_id"), getuid(this_player())) < this_object()->query("demand_level") )
                return notify_fail("�A�L�k�ϥΡC\n");
        if( sscanf(arg, "'%s' %s %s", pTarget, flag, chos) == 3 )
        {
                write(pTarget+"\n");
                if( !objectp(oTarget=present(pTarget, environment(me))) )
                        return notify_fail("�S���o�Ӫ���C\n");
                if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                        return notify_fail(HELP);
                switch(flag)
                {
                        case "-w":
                                str = HIY" �w���������������� "HIG + chos + " �� get ���� "HIY"�����������������w\n"NOR;
                                if( arrayp(logz=get[chos]) )
                                 foreach(string tmp in logz)
                                  str += tmp +"\n";
                                else str += " ** �L���� **\n";

                                str += HIY" �w���������������� "HIG + chos + " �� put ���� "HIY"�����������������w\n"NOR;
                                if( arrayp(logz=put[chos]) )
                                 foreach(string tmp in logz)
                                  str += tmp +"\n";
                                else str += " ** �L���� **\n";

                                break;
                        case "-m":
                                if( chos == "get" )
                                  str = op_all("get");
                                else if( chos == "put" )
                                  str = op_all("put");
                                else
                                  return notify_fail("�ﶵ���~, �i�諸�� <get> <put>. \n");
                                break;
                        default:
                                return notify_fail(HELP);
                }
        }
        else if( sscanf(arg, "'%s' -l", pTarget)== 1 )
        {
                if( !objectp(oTarget=present(pTarget, environment(me))) )
                        return notify_fail("�S���o�Ӫ��~��C\n");
                if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                        return notify_fail(HELP);
                str = op_all("get") + op_all("put");
        }
        else return notify_fail(HELP);
        me->start_more(str);
        return 1;
}

int do_cleanup(string arg)
{
        object oTarget;
        string pTarget;

        if( !arg ) return notify_fail(HELP);

        if( sscanf(arg, "'%s' %s", pTarget, arg) != 2 )
                return notify_fail(HELP);
        if( !objectp(oTarget=present(pTarget, environment(this_player()))) )
                return notify_fail("�S���o�Ӫ��~��C\n");
        if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                return notify_fail(HELP);
        if( (int)CLUB_D->check_member(this_object()->query("club_id"), getuid(this_player())) < this_object()->query("demand_level") )
                return notify_fail("�A�L�k�ϥΡC\n");
        switch(arg)
        {
                case "all":
                        get = ([ ]);
                        put = ([ ]);
                        write("�M�����\\�C\n");
                        message_vision("$N�M��$n�Ҧ�����(log)�C\n", this_player(), this_object());
                        break;
                case "get":
                        get = ([ ]);
                        write("�M�����\\�C\n");
                        message_vision("$N�M��$n�� get �����C\n", this_player(), this_object());
                        break;
                case "put":
                        put = ([ ]);
                        write("�M�����\\�C\n");
                        message_vision("$N�M��$n�� put �����C\n", this_player(), this_object());
                        break;
                default:
                        return notify_fail(HELP);
        }
        this_object()->save();
        return 1;
}

string op_all(string arg)
{
        string str, *keyz;

        if( arg == "get" )
        {
         str = HIY" �w���������������� "HIG + this_object()->name(1) + "�� get ���� "HIY"�����������������w\n"NOR;
         if( mapp(get) && sizeof(keyz=keys(get)) > 0 )
          for(int i=0;i<sizeof(keyz);i++)
           if( sizeof(get[keyz[i]]) > 0 )
            foreach(string tmp in get[keyz[i]])
             str += tmp + "\n";
           else continue;
         else str += " ** �L���� **\n";
        }
        else if( arg == "put" )
        {
         str = HIY" �w���������������� "HIG + this_object()->name(1)+ "�� put ���� "HIY"�����������������w\n"NOR;
         if( mapp(put) && sizeof(keyz=keys(put)) > 0 )
          for(int i=0;i<sizeof(keyz);i++)
           if( sizeof(put[keyz[i]]) > 0 )
            foreach(string tmp in put[keyz[i]])
             str += tmp + "\n";
           else continue;
         else str += " ** �L���� **\n";
        }
        else HIR"BOX_LOG ���~, �Х� report �^�� bug�C\n";
        return str+"\n";
}

int is_inherit_box_log() { return 1; }
