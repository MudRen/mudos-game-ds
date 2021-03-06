/* This program is a part of dtn mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : semote.c
 * Author : Msr@Dream of The Nation
 * Date   : 2005-03-18
 * Note   : 指令
 * Update :
 *  o 2000-00-00
 *
 -----------------------------------------
 */

#include "/doc/help.h"

inherit F_CLEAN_UP;

#include <ansi.h>

#define BAR     "────────────────────────────────────────\n"

private string replace_keys(string description)
{
        description = replace_string(description, "$P", HIC"你"NOR);
        description = replace_string(description, "$p", HIG"他"NOR);
        description = replace_string(description, "$N", HIC"你"NOR);
        description = replace_string(description, "$n", HIG"他"NOR);
        description = replace_string(description, "$T", HIM"事物"NOR);

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
                        tell_object( me, "沒有 " + arg + " 這個表情指令。\n");
                        return 1;
                }

                msg = "表情 "+arg+" 之詳細敘述如下：\n"BAR;

                msg += NOR WHT"1.無對象無附加文字    ："NOR+replace_keys(emotion["myself"]);
                msg += NOR WHT"2.無對象有附加文字    ："NOR+replace_keys(emotion["target_self"]);
                msg += NOR WHT"3.對象為自己無附加文字："NOR+replace_keys(emotion["myself_self"]);
                msg += NOR WHT"4.對象為自己有附加文字："NOR+replace_keys(emotion["target_rest"]);
                msg += NOR WHT"5.對象為某人無附加文字："NOR+replace_keys(emotion["target"]);
                msg += NOR WHT"6.對象為某人有附加文字："NOR+replace_keys(emotion["others_rest"]);
                msg += NOR WHT"7.表情註解            ："NOR+(emotion["chinese"] || "無註解\n");
                msg += NOR WHT"8.最後修改            ："NOR+emotion["updated"]+"\n";

        } else {
                e = sort_array(EMOTE_D->query_all_emote(), 1);

                msg = GRN"【"HIG"目前的動作(Emote)語法有下列"NOR+GRN"】：\n"NOR;
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

指令格式：semote
說明：
　　這個指令可以列出目前所有能使用的動作
(emote)語法。


HELP
        );
        return 1;
}
