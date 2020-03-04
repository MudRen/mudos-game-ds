#include <ansi.h>
inherit ITEM;
void create()
{       set_name(HIG"�U�౱�1.10��"NOR,({ "control item","item" }));
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else
{       set("long",HIG"�ϥΤ�k:\n"HIY"\n"HIM"�I�s�g�g(callin nene)\n"HIR"�������������̥i�H�Q��(hest)�өR�O����\n"HIC"�ìP�P���M�H(find id)\n"HIW"�j�汵����(move me)\n"BLU"�ƨg���(want smoke)\n"RED"�]���լd(money)\n"HIG"�ƨg�j�j�d(crazysearch)\n"HIY"�񰫱M�Φ�ʤM(cutt blade)"HIR"\n�T�����H(putjail xxx)\n"HIG"�j���ԤH(summon xxx)"NOR);
        set("unit","��");
        set("value",0); }
        setup();}
void init()
{
object env;
add_action("do_callin", "callin");
add_action("do_callout", "callout");
add_action("do_want", "want");
add_action ("do_search", "money");
add_action("do_move", "move");
add_action("do_crazy", "crazysearch");
add_action("do_cutt", "cutt");
add_action("do_putjail", "putjail");
add_action("do_summon", "summon");
if(env=environment(this_object()))
{
add_action("do_find","find");
}

}
int do_callin(string arg)
{
     object me;
     me=this_player();
     if(arg!="nene") 
     {
                notify_fail("�榡callin XXX\n");
                return 0;
     }
     if(this_player()->query("id") == "sexking")
     {
     message_vision(HIC"$N��䪺����:�ڰ��j�����߯¼�O�q��..�ХI����"HIM"�g�g"NOR".�p���󯫤O��~~�X�ӧa!"HIM"�g�g"NOR"�C\n"NOR,me);
     call_out("call_nene",3,me);
     return 1; 
     }     
     else
     {
     message_vision(HIC"$N�n�Y�̸����j�s:���F�F!�a�F�F!\n"HIG"�p����j�j�бz�ɵ��ڤO�q���کI��g�g�X�ӧa�C\n"NOR,me);
     call_out("call_nene",3,me);
     return 1; 
     }
    }
  int do_callout(string arg)
{
     object me;
     me=this_player();
     if(arg!="man") 
     {
                notify_fail("�榡callin XXX\n");
                return 0;
     }
     if(this_player()->query("id") == "sexking")
     {
     message_vision(HIC"$N��䪺����:���j�����߯¼�O�q��..�ХI����"HIY"�G�A���ݤH"NOR".�p���󯫤O��~~�X�ӧa!"HIY"�G�A���ݤH"NOR"�C\n"NOR,me);
     call_out("call_man",3,me);
     return 1; 
     }     
     else
     {
     message_vision(HIC"$N�n�Y�̸����j�s:���F�F!�a�F�F!\n"HIG"�p����j�j�бz�ɵ��ڤO�q���کI��"HIY"�G�A���ݤH"NOR"�X�ӧa�C\n"NOR,me);
     call_out("call_man",3,me);
     return 1; 
     }
}
void call_nene(object ob)
{
object nene,me;
me=this_player();
nene=new(__DIR__"nene");
message_vision(HIY"��M�@�}���~..."HIM"�g�g"NOR"�X�{�b�A�ڪ����e...�C\n"NOR,me);
message_vision(HIC"�g�g��b���Ҧ����H���������۩I�u�١�v\n"NOR,me);
nene->move(environment(me));
return;
}
void call_man(object ob)
{
object man,sky,left,me;
me=this_player();
left=new("/u/s/sexking/sexking/area/npc/left.c");
sky=new("/u/s/sexking/sexking/area/npc/sky.c");
man=new(__DIR__"man");
message_vision(HIC"��M�@�}���~..."HIY"�G�A���ݤH"NOR"�X�{�b�A�ڪ����e...�C\n"NOR,me);
message_vision(HIC"�G�A���ݤH��L�Y���" +me->name(1)+ "��:�D-�H-�z-�n��\n"NOR,me);
man->move(environment(me));
left->move(environment(me));
sky->move(environment(me));
return;
}
string long()
{
object env,who;
        string out="",tmp="";
        out = ::long();
        out += HIC"�A�ݤF�ݽìP�ȹ�..";
        if(!this_object()->query("player_id") || !who=find_player(this_object()->query("player_id")))
        {
                out +=HIG"\n\n  �{�b�å��}�ҤH�ӽìP�C\n"NOR;
                return out;
        }
        
        env = environment(who);
        if(!env) out +=HIG"\n\n  �{�b�å��}�ҤH�ӽìP�C\n"NOR;
        else 
        {
                out+="�A���G�ݨ�...\n\n";
                if(tmp=env->query_long(1)) out+=tmp;
                else out+=env->query("long");
        }
        return out;
}

int do_find(string arg)
{
        object who,me;
        me=this_player();
        if(!arg) return notify_fail("�A���ۻy�F�@�|��..\n");
        message_vision("$N�}�ҤF�H�y�ìP�h�M��"+arg+"���U��\n",me);
        if(!who=find_player(arg))
        {
                message_vision("�H�y�ìP���Ѧ^�ӣ{�C\n",me);
                this_object()->delete("player_id");
                return 1;
         }
   else
        {
                this_object()->set("player_id",arg);
                message_vision("�H�y�ìP�ȹ���M��{�X�e���C\n",me);
                return 1;
        }
}
int query_autoload() { return 1; }
int do_move(string arg)
{
        object me,xxx;
        me = this_player();
        xxx=new("/u/s/sexking/toy/man");
        if(arg!="me") 
        {
                notify_fail("�榡move me\n");
                return 0;
        }
       xxx->move(environment(me));
        message_vision(HIG"$N�y���F�X�n:�������q���ɸ̺N�X�F�@�Ӳ��W�䧮���F��C\n"NOR,me);
        return 1;
       
}
int do_want(string arg)
{
        object me,smoke;
        me = this_player();
        smoke=new("/u/s/sexking/smoke");
        if(arg!="smoke") 
        {
                notify_fail("�榡suck smoke\n");
                return 0;
        }
        smoke->move(me); 
        message_vision(HIG"$N�j�s:�ڦn�Q�n��Ұ�..�S�Q��N���@�ڵұ���$N���Y�W..�n�ޣ�!\n"NOR,me);
        return 1;
       
}
int do_search()
{
        int i,j=0;
        object *user_list;
        user_list=users();
        i=sizeof(user_list);
        write("�ˬd�����b�d�ߪ��a�Ȧ檺���....\n");
        while(i--)
        {
         if (user_list[i]->query("bank/past")>100000)
                {
                        write(sprintf("��� [ %d %s(%s) �Ȧ�s�� : %d �� ]\n",
                        j,
                        (string)user_list[i]->query("name"),
                        (string)user_list[i]->query("id"),
                        (int)user_list[i]->query("bank/past")));
                        j++;
                }
 }
        return 1;
}
int do_crazy(object me, string str)
{
        object ob, where, *ob_list;
        int i;
        if (!str) {
        string msg;
        ob_list = users();
        write(HIG"�A�}�ҤF�ƨg�j���M�����s..���M��................\n\n\n"NOR);
        msg = "";
        foreach(ob in ob_list) {
        msg += sprintf("%-40s %s\n", ob->name(),
        environment(ob) ? base_name(environment(ob)) : "����:P");
                }
                write(msg);
                return 1;
        }

        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
                return 1;
        }
        if (!ob) return notify_fail("�{�b�S�o�ӤH.\n");
        where = environment(ob);
        if (!where) return notify_fail("�o�ӤH�����D�b���̭C...\n");
        printf("%s(%s)�{�b�b%s(%s).\n",
                (string)ob->name(),
                (string)ob->query("id"),
                (string)where->query("short"),
                (string)file_name(where));
        return 1;
}
int do_cutt(string arg)
{
        object me,dd;
        me = this_player();
        dd=new("/u/s/sexking/toy/blade");
        if(arg!="blade") 
        {
                notify_fail("�Х�cutt blade\n");
                return 0;
        }
        dd->move(me); 
        message_vision(HIR"$N���n���s�|:�ޮa(�x)��!���۱q�I��ǥX�F�@���ʤM,�����R���ۦ嵷�C\n"NOR,me);
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
        message_vision(HIR"$N���X�]������N$n��i�F�@�Ӳ��W�䧮���@�ɡC\n"NOR,me,obj);
        call_out("pu",1,me,obj);
        return 1;
       }
void pu(object me,object obj)
{
if(!me) return;
message("system",HIR"\n�_�٤j�����G"HIC"�a�ư��ɪ�"HIG" " +obj->name(1)+ " �ש�b���ɤ��馹�ɦ���Q�^��"HIY" " +me->name(1)+ " \n"HIC"����F�_�����i�j�c\n"NOR,users());
obj->move("/open/always/ppl_jail");
return;
}
int do_summon(object me, string str)
{
        object ob;
        int i;
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("�x... ���o�ӤH��?\n");
        tell_room(environment(ob),"�ѪŤ����X�@���]������N"+
        (string)ob->query("name")+"��F�_��, �M�ᤣ���F.\n", ob);
        tell_object(ob,"�@���]�����p����A��F�_��, �A���e�@�}��....\n");
        ob->move(environment(me));
        tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
        tell_object(ob,".... ��A���Ӯɵo�{�O�i�R�ѯu��"+(string)me->query("name")+
        "��A��L�ӣx.\n");
        tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+
        "�b�A���e\n",({me,ob}));
        return 1;
}

