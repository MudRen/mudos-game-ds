#include <ansi.h>
inherit ITEM;
void create()
{       set_name(HIG"�ڤ۱��"NOR,({ "dream control item","item" }));
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else
{       set("long",HIG"�C�s�L�Ψ����U�ۤv���Q��"NOR);
        set("unit","��");
        set("value",0);
 }
        setup();
}
int query_autoload() { return 1; }
void init()
{
object env;
   this_object()->set_temp("invis",1);
add_action("do_summon", "osummon");
add_action("do_uninvis", "uninvis");
add_action("do_invis2", "invis2");
add_action("do_putjail", "oputjail");
add_action("do_butt", "butt");
add_action("do_qwiz", "qwiz");
}
int do_qwiz(string arg)
{
        int i,j=0,n,idle;
        object *user_list,where;
        string status1, status2, status3;

        user_list = users();
        n = sizeof(user_list);
        write(HIW"�A�z�L"+this_object()->name()+HIW"�A�P���o�ӥ@�ɡA"HIY"������"
HIG"�K��"HIW"�X�{�F�u�W��wiz:\n"NOR);
        for( i=0 ;i<n ;i++)
        {
                if( wizardp(user_list[i]))
                {
                        where = environment(user_list[i]);
                        idle=query_idle(user_list[i]);
                        if (in_input(user_list[i])) status1=HIY"(INPUT)"NOR;
                                else status1="";
                        if ((in_edit(user_list[i])))
        status2=sprintf(HIY"(EDIT: %s)"NOR,in_edit(user_list[i]));
                                else status2="";
                        if (idle>180) status3=sprintf(HIY"(IDLE %d MIN)"NOR,idle
/60);
                                else status3="";
                        write(sprintf("TTF [ %2d %12s %s(%s) ���b %s(%s) ]\n",
                        j,
                        SECURITY_D->get_status(user_list[i]),
                        user_list[i]->query("name"),
                        user_list[i]->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where)));
                        if ((status1!="")||(status2!="")||(status3!=""))
                        write(sprintf("TTF [                STATUS: %s%s%s]\n",
                                      status1,status2,status3));
                        j++;
                }
        }
        return 1;
}
int do_putjail(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("�A�Q�n���� �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
  return notify_fail("�o�̨S���o�ӤH�C\n");
       if(obj==me)
        return notify_fail("�O�Q���}!\n");
        message_vision(HIC"$N"HIR"���X"HIW"���q����"HIR"�N$n��i�F�@�Ӳ��W�䧮���@�ɡC\n"NOR,me,obj);
        call_out("pu",1,me,obj);
        return 1;
       }
void pu(object me,object obj)
{
if(!me) return;
obj->set("out_of_power",1); 
obj->move("/open/always/ppl_jail");
obj->save();
"/open/always/ppl_jail"->jail_time(obj, 7);
return;
}


int do_summon(string str)
{
        object me = this_player();
        object ob;
     if (!str) return notify_fail("<Syntax>: Summon <player id>\n"); 
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("�x... ���o�ӤH��?\n");
        if(ob->query("env/god_enable") >= 3) return notify_fail("�S���o�ӤH�C\n");       
        tell_room(environment(ob),"�ѪŤ����X�@���j���"+(string)ob->query("name")+"��F�_��, �M�ᤣ���F.\n", ob);
        tell_object(ob,"�@�����A��F�_��, �A���e�@�}��....\n");
        ob->move(environment(me));
        tell_object(ob,".... ���Ӯɵo�{�O"+(string)me->query("name")+"��A�˹L�Ӫ�.\n");
        tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
        tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+
        "�b�A���e\n",({me,ob}));
        return 1;
}
int do_invis2(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("�A�Q�n�������� �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
  return notify_fail("�o�̨S���o�ӤH�C\n");
       if(obj==me)
        return notify_fail("���|�ۤv��invis��...Stupid\n");      message_vision(HIC"$N"HIR"�ϥX"HIW"�a�յ�L�x"HIR"��$n��������U�h�C\n"NOR,me,obj);
        call_out("inv",1,me,obj);
        return 1;
       }
void inv(object me,object obj)
{
if(!me) return;
message_vision(HIC+obj->query("name")+"�����κ����a�����F....\n"NOR,me,obj);
obj->set_temp("invis",3); 
return;
}
int do_uninvis(string arg)
{
        object me,obj;
        me = this_player();
        if( !arg )
        return notify_fail("�A�Q�n���ֲ{�� �S\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
         return notify_fail("�o�̨S���o�ӤH�C\n");
         if(obj==me)
        return notify_fail("���|�ۤv��invis��...Stupid\n"); 
message_vision(HIC"$N��"HIW"�E�ײ{�δx"HIC"���������b$n���W�C\n"NOR,me,obj);
        call_out("uninv",1,me,obj);
        return 1;
       }
void uninv(object me,object obj)
{
if(!me) return;
message_vision(HIC+obj->query("name")+"�����Φb�@�Τ��K���X�{�F�I�I\n"NOR,me,obj);
obj->delete_temp("invis"); 
obj->delete_temp("hide"); 
return;
}
   int do_butt(string arg)
      {
        string title, note;
     if( !arg || sscanf(arg ,"%s %s",title,note) != 2 ) return notify_fail("[�榡] butt <> <���e>\n");
      message("world:world1:vision",
      HIY"������������������������������������������������������������\n"HIR"�m"+ title +"�n\n"HIW":" + note + HIY"\n������������������������������������������������������������"+NOR,users());
         return 1;
      }

