// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;
void go(object me,string env);
int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj,where;
        string msg;

        if( !arg ) return notify_fail(@WHERE
        
 �A�n�h���̡S

     �� �v        �j �N         �{�N           ����           ���|
============== ============ ============= ============== ===============
1:�Ův����U    6:�¤Ѽ�    11:�s�ھF���] 16:�q�ϰs�]    21:�g�s��
2:�ڤۮ��]      7:�B�F��    12:���s����] 17:            22:���
3:�j�N�|ĳ��    8:��  ��    13:           18:            23:�Ѧa�|
4:�{�N�|ĳ��    9:�s���l��  14:           19:            24:���ڷ|ĳ��
5:���ӷ|ĳ��   10:          15:           20:            25:����

   ��   �L        �Q�׫�============== =============26: �ⶳ�x     31:�j��Q�׫�
27: �uŪ�ͫ�
28: �T����


WHERE
        );

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("�A�n�h���̡S\n");
        if( environment(me) )
                if(environment(me)->query("no_goto_cmd")) return notify_fail("�o�̤���ϥ�GOTO���O,�Шϥ�go�H�M�����W���Ȯɪ���C\n");
        switch(arg)
        {
                case "1":go(me,"/d/wiz/hall1");break;
                case "2":go(me,"/open/world2/anfernee/start/login");break;
                case "3":go(me,"/open/world1/meetroom");break;
                case "4":go(me,"/open/world2/meetroom");break;
                case "5":go(me,"/open/world3/meetroom");break;
                case "6":go(me,"/open/world1/tmr/area/hotel");break;
                case "7":go(me,"/open/world1/cominging/area/boo-lin");break;
                case "8":go(me,"/open/world1/acme/area/hotel");break;
                case "9":go(me,"/open/world1/tmr/area/post_office");break;
                case "11":go(me,"/open/world2/shengsan/aovandis/room079");break;
                case "12":go(me,"/open/world2/lichi_town_2/map_5_26");break;
                case "16":go(me,"/open/world3/tmr/basic/hotel");break;
                case "21":go(me,"/open/world1/cominging/area/dragon/dragon");break;
                case "22":go(me,"/open/world1/acme/area/moon/room3");break;
                case "23":go(me,"/open/world1/acme/area/sky/room25");break;
                case "24":go(me,"/open/world1/god_club/boardroom");break;
                case "25":go(me,"/open/world1/baal/ming_club/saintming");break;
                case "26":go(me,"/open/world1/acme/bonze/b16");break;
                case "27":go(me,"/open/world2/obj/workroom");break;
                case "28":go(me,"/open/always/ppl_jail");break; 
                case "31":go(me,"/u/j/jangshow/workroom_pw");break;
        default:
                {
                        obj = find_player(arg);
                        if(!obj) obj = find_living(arg);
                        if(!obj || !me->visible(obj))
                        {
                                arg = resolve_path(me->query("cwd"), arg);
                                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                                if( !(obj = find_object(arg)) )
                                {
                                        if( file_size(arg)>=0 )
                                                return me->move(arg);
                                        return notify_fail("�S���o�Ӫ��a�B�ͪ��B�Φa��C\n");
                                }
                        }
                        where=find_object("/open/always/ppl_jail");
                        if( environment(obj)==where &&  wiz_level(me) < 2)
                                return notify_fail("��西�b�ʺ��A�D, �A�̦n���n�h�K���X���ӡC\n");
                        if(!goto_inventory && environment(obj)) obj = environment(obj);
                        
                        if( !obj ) return notify_fail("�o�Ӫ���S�����ҥi�H goto�C\n");
                        
                        if(!me->query_temp("invis"))
                        {
                          if( stringp(msg = me->query("env/msg_mout")) )
                                message_vision(msg+"\n", me);
                          else
                                message_vision(HIW"�u���@�}�����L��M$N"HIW"�����v�w�g�����F�C\n"NOR, me);
                        }
                        me->move(obj);
                        if(!me->query_temp("invis"))
                        {
                          if( stringp(msg = me->query("env/msg_min")) )
                                message_vision(msg+"\n", me);
                          else
                                message_vision(HIW"$N"HIW"�����v��M�X�{�b�@�}���������C\n"NOR, me);
                        }
                }
        }
        return 1;
}

void go(object me,string env)
{
 if(!me->query_temp("invis"))
 message_vision(HIW" �y�{�H�o~ �z�u��$N"HIW"���ѪŤ@�D�M�ƨ����@���p�����M�԰԰�~�������F�C\n"NOR, me);
 me->move(env);
 if(!me->query_temp("invis")) message_vision(HIW"�y�F~~�z$N"HIW"��M�X�{�b�@�}���������C\n"NOR, me);                    
}
int help(object me)
{
write(@HELP
���O�榡 : goto [-i] <�ؼ�>
 
�o�ӫ��O�|�N�A�ǰe����w���ؼ�. �ؼХi�H�O�@��living �Ωж�
���ɦW. �p�G�ؼЬOliving , �A�|�Q����򨺭ӤH�P�˪�����.
�p�G���[�W -i �ѼƥB�ؼЬO living, �h�A�|�Q����� living ��
�� inventory ��.
 
HELP
    );
    return 1;
}

