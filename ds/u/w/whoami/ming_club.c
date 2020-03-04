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
        "�ګ�", //0
        "�Ю{", //1
        "���", //2
        "�@�k", //3
        "��D", //4
        "�����t��", //5
        "���D", //6
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

                add_action("do_subleader","subleader");
                add_action("do_retire","retire");
                add_action("do_listmember","listmember");
                add_action("do_kickout","kickout");
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
//                        if(ob_info["level"] >= me_info["level"])
//                                return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
//                        if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
//                                return notify_fail("�A�������N����X"+CLUB_NAME+"�C\n");
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

