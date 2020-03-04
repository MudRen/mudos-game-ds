/* This program is a part of dtn mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : semote.c
 * Author : Msr@Dream of The Nation
 * Date   : 2005-03-18
 * Note   : ���O
 * Update :
 *  o 2000-00-00
 *
 -----------------------------------------
 */

#include "/doc/help.h"

inherit F_CLEAN_UP;

#include <ansi.h>

#define BAR     "�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"

private string replace_keys(string description)
{
        description = replace_string(description, "$P", HIC"�A"NOR);
        description = replace_string(description, "$p", HIG"�L"NOR);
        description = replace_string(description, "$N", HIC"�A"NOR);
        description = replace_string(description, "$n", HIG"�L"NOR);
        description = replace_string(description, "$T", HIM"�ƪ�"NOR);

        return description;
}

int main(object me, string arg)
{
          string *e, msg;
        int i;
        mapping e_map;

        seteuid(geteuid(me));

        if( arg )
        {
                mapping emotion = EMOTE_D->query_emote(arg);

                if( sizeof(emotion) <= 0 )
                {
                        tell_object( me, "�S�� " + arg + " �o�Ӫ����O�C\n");
                        return 1;
                }

                msg = "�� "+arg+" ���Բӱԭz�p�U�G\n"BAR;

                msg += NOR WHT"1.�L��H�L���[��r    �G"NOR+replace_keys(emotion["myself"]);
                msg += NOR WHT"2.�L��H�����[��r    �G"NOR+replace_keys(emotion["target_self"]);
                msg += NOR WHT"3.��H���ۤv�L���[��r�G"NOR+replace_keys(emotion["myself_self"]);
                msg += NOR WHT"4.��H���ۤv�����[��r�G"NOR+replace_keys(emotion["target_rest"]);
                msg += NOR WHT"5.��H���Y�H�L���[��r�G"NOR+replace_keys(emotion["target"]);
                msg += NOR WHT"6.��H���Y�H�����[��r�G"NOR+replace_keys(emotion["others_rest"]);
                msg += NOR WHT"7.������            �G"NOR+(emotion["chinese"] || "�L����\n");
                msg += NOR WHT"8.�̫�ק�            �G"NOR+emotion["updated"]+"\n";

        } else {
                e = sort_array(EMOTE_D->query_all_emote(), 1);

                msg = GRN"�i"HIG"�ثe���ʧ@(Emote)�y�k���U�C"NOR+GRN"�j�G\n"NOR;
                for(i=0; i<sizeof(e); i++) 
                {
                        e_map = EMOTE_D->query_emote(e[i]);
                        msg += sprintf("%-8s %-10s ",
                            (stringp(e_map["chinese"])?
                                replace_string(e_map["chinese"], "\n", ""):
                                ""
                            ), e[i]
                        );
                        if( i%4 == 3 ) msg += "\n";
                }
        }
        msg += "\n";
        me->start_more(msg);
        return 1;
}

int help(object me)
{
        write(@HELP

���O�榡�Gsemote
�����G
�@�@�o�ӫ��O�i�H�C�X�ثe�Ҧ���ϥΪ��ʧ@
(emote)�y�k�C


HELP
        );
        return 1;
}
