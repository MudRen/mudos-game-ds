// ���|�H��
// "level": ���a�b���|��������(1~?)
// 1: �Ю{
// 2: ��� 
// 3: �@�k 
// 4: ��D(can enter box)
// 5: �����t��(can enter box)
// 6: ���D (2�W)(can enter box)
//�_���j�����R���p*2 ��V*2 �Ѽ�*1 �C��*1
// "title": ���|�Y��
// "info1": �ƥΰ�1 (����W��)
// "info2": �ƥΰ�2
// "info3": �ƥΰ�3
//

#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "����"
#define CLUB_ID "ming"
#define CLUB_CHANNEL "ming"
#define CLUB_MARK "Plate of Holy Fire"
#define CLUB_ENTER_FILE "/open/world1/tmr/bagi/rift1"
#define CLUB_OUT_FILE "/open/world1/baal/ming_club/lighttop"
inherit FINGER;
private string *members_level = ({
        "�Ю{", //0
        "���", //1
        "�@�k", //2
        "��D", //3
        "�����t��", //4
        "���D", //5
});
void create()
{
        set_name(HIR"�t�w���w�O"NOR,({"Plate of Holy Fire","plate","club_mark"}));
        set_weight(600);
        if( clonep() ) set_default_object(__FILE__);
        else
        {
                set("value",0);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("unit","�u");
                set("long",@LONG
�o�O�κ��m��������O�P�A�W���z�۬����O�Ф���Ф��_
�ѩ_���K�H�һs�A�u�n�X�ܥO�P�A�j���n�_�Z��L��(show plate)�C
[������Ъ���L�����Х�<help ming>���O�d�ߡC]
LONG
                );
        }
        set("club_id",CLUB_ID);
        set("club",CLUB_NAME);
        set("sub_club",({"���p��","��V��","�Ѽϰ�","�C���"}));
        set("club_max_level",sizeof(members_level)-1);
        set("armor_prop/shield", 1);
        setup();
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
        if(wizardp(this_player()))
        {
                 info = ([
                 "level": wiz_level(this_player()),
                 "title": "���ЯS���U��  ",
                 "info1": "�L",
                 "info2": ctime(time()),
                 "info3": this_player()->name_id(1)
                 ]);
                 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
        }
        else 
        {
                tell_object(this_player(),this_object()->name()+"��M�q�A���W���X�A���������b����C\n");
                this_player()->delete("club");
                destruct(this_object());
                return;
        }
 }
 switch(level)
 {
  case 6:
                add_action("do_handover","handover");
                add_action("do_lockleave","lockleave");
                add_action("do_givepower","givepower");
                add_action("no_suicide","suicide"); //����۱�
                add_action("do_subleader","subleader");
                add_action("do_retire","retire");
  case 5:
                add_action("do_listmember","listmember");
  case 4:
                add_action("do_accept","accept");
                add_action("do_kickout","kickout");
  case 2:
                add_action("do_include","include");
                add_action("do_dismiss","dismiss");
  default:
                add_action("do_help","help");
                add_action("do_members","members");
                add_action("do_leaveclub","leaveclub");
                add_action("do_enter_club","lift");
 }
}

int do_enter_club(string arg)
{
        object env,me;
        if(arg!="ring") return 0;
        me=this_player();
        env=environment(me);
        if(!env) return 0;
        if(env->query("ming_club_enter"))
        {
                if(me->query_temp("killer")) return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: �A, �]���A�����F�H�ҥH�Ȯɤ���i�J���|�C\n");
        if(me->query_temp("invader")) return notify_fail("�ѤW�ǨӤ@�ӫիժ��n��: �]���A���ˤF�H, �ҥH�Ȯɤ���i�J���|�C\n");
                message_vision("$N���|$n�j�ۡG�u���Z�L�֤H���A�ߧک��пW�B����C�v\n",me,this_object());
                if(!me->can_move(CLUB_ENTER_FILE))
                {
                        message_vision("�ѥ������W��U�@�x�l���N�A���W�h�C\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"���W�l���A�Q���F�W�h�C\n",({ me }));
                        me->move(CLUB_ENTER_FILE);
                        tell_room(environment(me),me->name()+"�w�w�����l�����F�W�ӡC\n",({ me }));
                        write("�l���w�w������F�A�A�o�{�ۤv�w�g�Ө�F�w�������C\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else if(env->query("ming_club_out"))
        {
                message_vision("$N���|$n�۸��W�F�l���A�Q�l�����F�U�h�C\n",me,this_object());
                if(!me->can_move(CLUB_OUT_FILE))
                {
                        message_vision("�l���w�w���Q�Q�F�W�h�A�u��$N�����ұ����b���b��a�C\n",me);
                        return 1;
                }
                else
                {
                        tell_room(env,me->name()+"�H���l���V�U���}�C\n",({ me }));
                        me->move(CLUB_OUT_FILE);
                        tell_room(environment(me),me->name()+"�Q�l�����F�U�ӡC\n",({ me }));
                        write("�l���Q�Q�F�W�h�A�A�S�A�׽�b"+environment(me)->query("short")+"���g�a�W�C\n");
                        me->add_busy(1);
                        return 1;
                }
        }
        else return notify_fail("�A�N"+this_object()->name()+"�����|�_�j�ۡG�u���Z�L�֤H���A�ߧک��пW�B����C�v�A���O����Ʊ����S�o�͡C\n");
}


int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "�i�a�A�|���j���ЯS���U��    ";
 level=user->query("level");
 if(level>100)  str = "�i????????�j";
 else if(level<11)      str = "�i�� "+chinese_number(level)+" �šj";
 else if(level<21)      str = "�i��"+chinese_number(level)+"�šj";
 else if(level%10==0)   str = "�i��"+chinese_number(level)+"�šj";
 else str = "�i"+chinese_number(level)+"�šj";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
        case 5: str+="���бХD  "; break;
        case 4: str+="���Х����t��  "; break;
        case 3: str+="����"+info["info1"]+"��D    "; break;
        case 2: str+="����"+info["info1"]+"�@�k"; break;
        default: 
                if(info["info1"]!="�L")
                {
                        str+="����"+info["info1"]+"���  "; break;
                } else str+="���бЮ{    ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
        int lv1,lv2;
        lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
        lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
        if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
        else return (lv1 - lv2);
}

int do_members(string arg)
{
        object *users,me;
        string str,*list;
        int i,ppl_cnt,idle;
        me=this_player();
//      list=CLUB_D->club_members(CLUB_ID);
//      users = filter_array( users(), "filter_members", this_object() ,list);
        users = CLUB_D->find_online_members(CLUB_ID);
        str = "�� "+CLUB_NAME+": \n";
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";

        users = sort_array(users, "sort_member", this_object());

        ppl_cnt = 0;
        i = sizeof(users);
        while( i-- )
        {
                        // Skip those users in login limbo.
                        if(!me->visible(users[i]) && wizardp(users[i])) continue;
                        str = sprintf("%s%12s%-16s %s(%s)",
                                str,
                                show_level(users[i]),
                                RANK_D->query_level(users[i]),
                                users[i]->name(1),
                                users[i]->query("id"),
)
                        if(users[i]->query_temp("killer")) str+=HIR" [���H��]"NOR;
                        idle=query_idle(users[i]);
                        if(users[i]->query_temp("invis")) str+=HIB"(����)"NOR;
                        if(users[i]->query_temp("hide")) str+=HBK"(����)"NOR;
                        if(users[i]->query_temp("netdead")) str+=HIG"<�_�u��>"NOR;
                        if(idle>60) str +=sprintf(HIY" (�o�b%d����)"NOR,idle/60);
                        str +=sprintf("\n"NOR);
                        ppl_cnt++;
        
        str += "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        str = sprintf("%s�ثe�@�� %d �즨���b�u�W.\n", str, ppl_cnt);
        this_player()->start_more(str);
        return 1;
}

int do_include(string arg)
{
        string sub;
        object ob,me;
        mapping me_info,ob_info;
        me=this_player();
       
        if(!arg) return notify_fail("include <�H�W>\n");
        else
                {        
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                if(sizeof(ob_info)
                {
                        if(me_info["level"] != 2 ) return notify_fail("�u����D��N�ڤH���J����C\n");
                        if(!stringp(sub=me_info["info1"])) return notify_fail("�u����D��N�ڤH���J����C\n");
                        if(ob_info["level"] != 1 || ob_info["info1"]!="�L";
                                return notify_fail("�u���@��Ю{�i�H���J�A������C\n");
                        ob_info["info1"]=sub;
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        message_vision("$N�N$n���J"+sub+", �é��$n���ӻH��: ����N�ݧA����{�F�C\n",me,ob);
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
        }
        return 1;
}
int do_dismiss(string arg)
{
        string sub;
        object ob,me;
        mapping me_info,ob_info;
        me=this_player();
       
        if(!arg) return notify_fail("dismiss <�H�W>\n");
        else
        {
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));         
                if(sizeof(ob_info)
                
                        if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("�u����D��K������U����¾�ȡC\n");
                        if(ob_info["level"] != 1 ) return notify_fail("���ä��ݩ�A�����ҡC\n");
                        if(ob_info["info1"] != sub) return notify_fail("���ä��ݩ�A�����ҡC\n");
                        ob_info["info1"]="�L";
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        message_vision("$N�Ѱ��F$n�b"+sub+"��¾��, �n�n�Y��: �S�֤F�@�ӤH�~...�u�O�i���ڡC\n",me,ob);
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
}
        return 1;
                        }
//���H
int do_accept(string arg)
{
        string *clubs;
        object ob,mark,me;
        mapping info;
        me=this_player();
        if(!arg) return notify_fail("�A�n���֥[�J"+CLUB_NAME+"�S\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(ob->query_temp("joinclub") != me->query("id") )
                {
                        return notify_fail("���èS���V�A�ӽФJ��(joinclub).\n");
                }
                clubs=CLUB_D->find_player_club(getuid(ob));
                if(sizeof(clubs)>0)
                {
                        if(clubs[0]==CLUB_ID) return notify_fail("���w�g�O"+CLUB_NAME+"���@���l�F�C\n");
                        else return notify_fail("���w�g�[�J�F�O�������C\n");
                }
                 else
                {
                 mark=new(base_name(this_object()));
                 if(!mark) return notify_fail("���|�H�����o���ѡC\n");
                 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"������"+mark->query("name")+"�C\n");
                 message_vision("$N���F$n�@"+mark->query("unit")+mark->query("name")+", �ö������ﱵ$n����"+CLUB_NAME+"���@���l�C\n",me,ob);
                 info = ([
                 "level": 1,
                 "title": "���бЮ{",
                 "info1": "�L",
                 "info2": ctime(time()),
                 "info3": me->name_id(1)
                 ]);
                 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
                 mark->move(ob);
                 ob->add("channels", ({"ming"}));
                 ob->save();
                }
        }       
        return 1;
}

int do_kickout(string arg)
{
        string *tuned_ch;
        object ob,mark,me;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("�A�n�N�ֽ�X"+CLUB_NAME+"�S\n");
        else
        {
               ob = present(arg, environment(me));
                if (!ob)
                {
                        if(!CLUB_D->is_club_leader(me)) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                        else {
                                write("[���u�}��]:");
                                if(ob=find_player(arg)) return notify_fail("����٦b�u�W�C\n");
                                if( CLUB_D->remove_member(CLUB_ID,arg) )
                                {
                                        write("���\\�}���F"+arg+"�C\n");
                                        return 1;
                                }
                                else return 0;
                        }
                }
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));  
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] >= me_info["level"])
                                return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
                                return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
                        tuned_ch = ob->query("channels");
                        if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
                        {
                                tuned_ch -= ({ CLUB_CHANNEL });
                                ob->set("channels", tuned_ch);
                        }
                        //ob->delete("club");
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                message_vision("$N�S���F$n��"+mark->query("name")+", �ñj��$n�h�X"+CLUB_NAME+"�C\n",me,ob);
                                destruct(mark);
                        }
                        CLUB_D->remove_member(CLUB_ID,getuid(ob));
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
        }
        return 1;
}

int do_subleader(string arg)
{
        string id,sub;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("subleader <�H�W> to <����W>\n");
        else
        {
                if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <�H�W> to <����W>\n");
                ob = present(id, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me ) return notify_fail("�o�̦��o�ӤH�ܡS\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));  
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] != 1)
                                return notify_fail("�u���@��󲳥i�H������D�C\n");
                        if( (int) member_array(sub, query("sub_club"))<0 )
                                return notify_fail("�ثe�i�Ϊ����X���i���p��j�B�i��V��j�B�i�Ѽϰ�j�B�i�C���j�C\n");
                        ob_info["level"]=2;
                        ob_info["info1"]=sub;
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                message_vision("$N�N$n���@��"+sub+"��D, �éM$n����j�y�@�f�C\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
        }
        return 1;
}

int do_retire(string arg)
{
        string sub;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("retire <�H�W> \n");
        else
        {
                ob = present(arg, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));

                if(sizeof(ob_info))
                {
                        if(ob_info["level"] != 2) return notify_fail("��H�ä��O��D�C\n");
                        sub=ob_info["info1"];

                        ob_info["level"]=1;
                        ob_info["info1"]="�L";
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                message_vision("$N�K���F$n��"+sub+"��D¾�ȡC\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
        }
        return 1;
}

int do_givepower(string arg)
{
        string id,type,res;
        int level;
        object ob,me,mark;
        mapping me_info,ob_info;
        me=this_player();
        
        if(!arg) return notify_fail("givepower <�H�W> to <����>\n");
        else
        {
                if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <�H�W> to <����>\n");
                ob = present(id, environment(me));
                if(!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");

                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                
                if(sizeof(ob_info))
                {
                        if(ob_info["level"] >= me_info["level"]) return notify_fail("�A�S�������ܹ�誺¾�ȵ��šC\n");
                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob)
                                        return notify_fail("�A�S�������ܹ�誺¾�ȵ��šC\n");
                        if(level >= me_info["level"]
                                return notify_fail("�A�S����洣�@��誺¾�ȵ��Ũ�o�ӵ��šC\n");
                        if(level == ob_info["level"]
                                return notify_fail("���w�g�O"+(string)members_level[level]+"�F�C\n");
                        if(level > 5 || level < 1 
                                return notify_fail("�ثe���Ť��� <1:�Ю{> <2:���> <3:�@�k> <4:��D> <5:�����t��><6:�ХD> \n");
                        if( level > ob_info["level"] 
                        {
                                type="���@";
                                res ="�éM$n����j�y�@�f";
                        }
                        else
                        {
                                type = "��";
                                res ="�é��$n���ӻH���j$n��N�\\��o";
                        }
                        switch(level)
                        {
                                case 1;
                                        ob_info["level"]=1;
                                        ob_info["info1"]="�L";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 2;
                                        return notify_fail("�Х�subleader���O�ӫ��w�@�Ӥ��X�C\n");
                                        break;
                                case 3;
                                        ob_info["level"]=3;
                                        ob_info["info1"]="�L";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 4;
                                        ob_info["level"]=4;
                                        ob_info["info1"]="�L";
                                        ob_info["info2"]=ctime(time());
                                        ob_info["info3"]=me->name_id(1);
                                        break;
                                case 5;
                                        return notify_fail("�Х�handover���O�������v����C\n");
                                        break;
                                default: return notify_fail("�Ѽƿ��~�C\n");
                                                }
                        
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                        if(!mark=present(CLUB_MARK,ob))
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                message_vision("$N�N$n��¾�쵥��"+type+"��"+(string)members_level[level]+"(����"+(string)level+"), "+res+"�C\n",me,ob);
                                mark->move(ob);
                        }
                        ob->save();
                        return 1;
                }
                 else return notify_fail("���èS���[�J"+CLUB_NAME+"�C\n");
        }
        return 1;
}
int do_handover(string arg)
        object ob,mark,me;
        mapping me_info,ob_info;
        me=this_player();
        if(!arg) return notify_fail("�A�n�N�j�v���浹�֡S\n");
        else
        {
                ob = present(arg, environment(me));
                if (!ob) return notify_fail("�o�̦��o�ӤH�ܡS\n");
                if(!userp(ob) || ob==me) return notify_fail("�o�̦��o�ӤH�ܡS\n");
               
                if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("�A���O�u�������|��ɤH�C\n");
              
                me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
                ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
                if(sizeof(ob_info))
                {
                        CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
                       
                        ob_info["level"]=5;
                        ob_info["info1"]="�L";
                        ob_info["info2"]=ctime(time());
                        ob_info["info3"]=me->name_id(1);
                        CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
                       
                        me_info["level"]=3;
                        me_info["info1"]="�L";
                        me_info["info2"]=ctime(time());
                        me_info["info3"]=me->name_id(1);
                        CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
                        
                        mark=present(CLUB_MARK, me);
                        if(!mark)
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                mark->move(me);
                        }
                        mark=present(CLUB_MARK, ob);
                        if(!mark)
                        {
                                write("���|�H�����o���ѡC\n");
                        }
                        else
                        {
                                mark->move(ob);
                        }
                        message_vision("$N�N"+CLUB_NAME+"���`�����v���浹$n�C\n",me,ob);
                        message( "channel:ming",YEL"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�N"+CLUB_NAME+"�����v���浹"+ob->name(1)+"("+capitalize(ob->query("id"))+")�C\n"NOR, users() );
                        ob->save();
                        me->save();
                        return 1;
                }
                 else return notify_fail("���ä��O"+CLUB_NAME+"���@���l�C\n");
        }
        return 1;
}

int do_leaveclub(string arg)
{
        string *tuned_ch;
        object mark,me;
        me=this_player();
        
        if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
                return notify_fail("�A�������N�j�v�ಾ�~�����}"+CLUB_NAME+"�C\n");
        CLUB_D->remove_member(CLUB_ID,getuid(me));
        message_vision("$N�D�ʰh�X�F"+CLUB_NAME+"�C\n",me);
        message( "channel:ming",YEL"�i"+CLUB_NAME+"�j"+me->name(1)+"("+capitalize(me->query("id"))+")�D�ʰh�X�F"+CLUB_NAME+"�C\n"NOR, users() );
        tuned_ch = me->query("channels");
        if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 );
        {
                        tuned_ch -= ({ CLUB_CHANNEL });
                        me->set("channels", tuned_ch);
        }
        me->delete("club");
        if(!mark=present(CLUB_MARK,me))
        {
                write("���|�H�����o���ѡC\n");
        } else destruct(mark);
        me->save();
        return 1;
}
int do_lockleave(string arg)
{
        if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(this_player())) return notify_fail("�A���O�u�������|��ɤH�C\n");
        if(arg=="on")
        {
                if(CLUB_D->query_lockleave(CLUB_ID)==1) return notify_fail("�h������w�g�}�ҡC\n");
                CLUB_D->set_lockleave(CLUB_ID,1);
                write("�A�N"+CLUB_NAME+"�]�w�����i�h���C\n");
                return 1;
        }
        if(arg=="off")
        {
                if(CLUB_D->query_lockleave(CLUB_ID)==0) return notify_fail("�h������w�g�����C\n");
                CLUB_D->set_lockleave(CLUB_ID,0);
                write("�A�N"+CLUB_NAME+"�]�w���i�H�h���C\n");
                return 1;
        }
        return notify_fail("lockleave <on/off> \n");
}
int no_suicide(string arg)
{
        if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
        {
                write("����"+CLUB_NAME+"���Ū��x, ��X�����v���e���i����, �H�K���~�L�H�C\n");
                return 1;
        }
        return 0;
}

int do_listmember(string arg)
{
        string *list,*members,temp,output;
        int i,j;
        mapping club;
        list=CLUB_D->club_members(CLUB_ID);
        club=CLUB_D->query_club_record(CLUB_ID);
        members=keys(club);
        output="\n�ثe"+CLUB_NAME+"�n�O���ת�������:\n";
        if(arg=="long")
        {
                for(i=this_object()->query("club_max_level");i>0;i--)
                {
                        for(j=0;j<sizeof(members);j++)
                        {
                                if(club[members[j]]["level"]==i) output=sprintf("%s %12s ���|����: %d\n",output,members[j],i);
                        }
                }
                output=sprintf("%s \n�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
                write(output);
                return 1;
        }
        temp=CLUB_D->query_club_leader(CLUB_ID);
        output=sprintf("%s ��ɤH: %12s\n",output,temp);
        list-=({temp});
        output=sprintf("%s ��L:\n",output,temp);
        output+=CLUB_D->show_club_members(CLUB_ID);
        output=sprintf("%s�ثe%s�@�p��: %d �W�����C\n",output,CLUB_NAME,sizeof(members));
        write(output);
        return 1;
}

int do_help(string arg)
{
 if(arg=="ming")
 {
  write(@HELP

       ��������������������������������������������������������������������
       �x                      ���|�H�������U����                        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�w�w�w�s�w�w�w�w�w�w�t
       �x  ���O�榡                    �x����              �x�v��        �x
       �u�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�w�w�w�q�w�w�w�w�w�w�t
       �x  help ming                   �x�����U�T��        �x�ڤH        �x
       �x  ming <�A���T��>             �x���|�M���W�D      �x�ڤH        �x
       �x  members                     �x�C�X�u�W���|����  �x�ڤH        �x
       �x  leaveclub                   �x�D�ʰh�X���|      �x�ڤH        �x
       �x  include <�H�W>              �x�N�Y�H���J���X    �x�X�D�M��    �x
       �x  dismiss <�H�W>              �x�����Y�H���X¾��  �x�X�D�M��    �x
       �x  accept <�H�W>               �x���Y�H�[�J���|    �x���ѥH�W    �x
       �x  kickout <�H�W>              �x�N�Y�H�v�X���|    �x���ѥH�W    �x
       �x  lockleave <on> <off>        �x����ۦ�h��      �x�ڪ�        �x
       �x  subleader <�H�W> to <����W>�x�ɯŬY�H���X�D    �x�ڪ�        �x
       �x  retire <�H�W>               �x�M���Y�H�X�D¾��  �x�ڪ�        �x
       �x  givepower <�H�W> to <����>  �x���ܬY�H��¾��    �x�ڪ�        �x
       �x  handover <�H�W>             �x�x��¾�ȥ汵      �x�ڪ�        �x
       �x  listmember                  �x���|�W�U          �x���ѥH�W    �x
       �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�w�w�w�r�w�w�w�w�w�w�}
         �� �ϥ� accept ���O���������� joinclub ���O�ӽФ~��ͮġC
         �� ���Хثe���|�Ӥ���:�i���p��j�B�i��V��j�B�i�Ѽϰ�j�B�i�C���j�C
         �� ���Ť���: <1:�Ю{> <2:���> <3:�@�k> <4:��D> <5:�����t��><6:�ХD> �C
         �� ��L���Ъ��ư�: <help ming_rule> , <help ming_group> �C
        
HELP
  );
  return 1;
  }
  if(arg=="ming_rule")
  {
   this_player()->start_more(@RULE

       CCKK,RICHAN���H�|������,���إ�
                       
                             BAAL@DS

RULE
);
return 1;
  }
  if(arg=="ming_group")
  {
  this_player()->start_more(@MING_PART

    �b�ɿ����e�������A�@�s�H���m�ۼC�A��@�H���k��w�A�C
�R�F�O�A�b�j�a�𮧮ɥL�٧V�O���m�ۼC�A���䪺����W���ۤ@
�����~�k�l�A�V�L�ۤF�ۤ�A��H�����|�A�����E���C�B���
�X�����C�k�P�g�ۤC�B�Z�A�u���ե��{�{�A���v�ƴ��A��M����
�E�����Ӱ_�A�V�@�Ǫ��j���h�A�u���j��@�����G�C�L���U��
�h���j�ۡG�u������H�I������H�I�ڬ�����Ǥ��|�H�C�v����
�E���L���G�u���n�Ǥ�....�I�v�L���_�Ӱ�M�����G�u�ڭn��
�}�o�̡I�v
      �Q      �~      ��   �E  �E  �E  �E  �E  �E
    �@��C�~���b�Ѧ����j�ۤW�A�L�L�׽m�ݤ�ߪk�A�L�����i
�}�A�k��@���A�C�H�ΦӥX�A�L�a���W�C�s�C�ӥh�C��ӥL�b�Q
�~�����M�ѤU�A�M�X�W�v�A�m���@������A�{���a�կP���U�C
    
    �b�s�����K�������A�@�s���H���m�ۮ��A�����@��p�k�ĥ�
�_���Ӫ��ͭ��A�@�I�]���鵹�j�H�A�۪O�Ϊ��f���۴N�O�W�_
���򪺧��Ѥ�C���Ѥ�ݤF����A�t�ۤU�w�n��������Ƕǵ��L
�C�L�Ѥѽm���q���ӫ�A�X�~���\�ҴN���F���Ѥ媺�o�N���͡A
�@�ѥL���s�h�m���A�L�N���o�{�s�������@�����_�A�L�n�_��
�p�F�i�h�A�S�Q��̭��O���}�ѡA��ӬO�y�s���A�L�b�̭��J��
�@���դ�j��A�M�e�����n�B�͡A�ѤѻP�e�m���A�\�O���M��
�r�i�A�X�~�᪺�@�I�A���Ѥ��L�s�i�ӻ��G�u�Ĥl�A�ڨS����
�i�H�ЧA�F�A�O�����A���F�C�v�L���O���Ѥ�X�h��������C
      ��      �~      ��   �E  �E  �E  �E  �E  �E
    �@��C�~�E��|���n�ۧN���~�A�N���~�S�X����A�������
������ۥL�A�N���~���W���ˤf���_���_�X�A��A����]�]���
�V���A�N���~�ǳƵo�X�P�R�@���A�N���~�ĦV�C�~�A�C�~�����
����N���~�A½���V�N���~�o�X�u�r��w���s�v�A�N���~�R�F�X
�f�A��Ӥ`�C�L���}����A�I���J���d���A�d�����L�Ѹ��o��
�N���L���{�A�L�{�b�N�O�Z�L���T�m�����H��  ------Richa
    �h�~�e���@�ө]�ߡA��H�]�����ܫܧ���ӵ������S�̡A�
�w�M�߭n���ߡi���Сj�A��O��H�}�l��ù�H�~�A�]�]�o�ǳ��
���H�~�A�M�Ѧa�|�����i�A�~���i���Сj�C�o�ѳo�@�s���b���

�|�n�]�b���Ӷ˸����A��MRichan���n�a�j�a�h�@�Ӧa��A�j�
�Ө�դ�j�᪺�s���A�ݨ�@���a�V�A���H�ϥX�W�����\�V�W�
�h�A�u���V���A�@�����G�A�V�~��h�U���L���A��O�R�W���u�
�����v�A�j�a�ݤF�ݥ|�P�Aı�o�n���֤F����A Ccr�����h���
�@���d��ۡARichan���_�����j�D�V���۴��D�G�u���Z�L�֤
���A�ߧک��пW�B����C�v�j�a�V�O�o�ȿ��[�WBaal�MLuky�
��U�ש󦨥ߤ��Ѫ����С
                                       Richan@DS
ming_PART
);
  return 1;    
  }
 return 0;
}       

