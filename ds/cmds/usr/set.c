// set.c
// Cominging ��L�[�l�ܾ�, �N�쥻�ϥ� bug ���H�O���U��
// ��i�� set �� setting �[�J list ��
// �D settings ���N record �U��
 
#define MAX_ENV_VARS    20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
        int i;
        string term, *terms, *wiz_only, *player_using;
        mixed data;
        mapping env;

        wiz_only = ({"invisibility", "immortal", "debug", "msg_dest", "msg_min", "msg_mout" });
        player_using = ({ "brief", "report", "edit_msg", "report_action", "auto_reply", "delay_look" });
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                write("�A�ثe�]�w�������ܼƦ��R\n");
                if( !mapp(env) || !sizeof(env) )
                        write("\t�S���]�w���������ܼơC\n");
                else {
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-20s  %O\n", terms[i], env[terms[i]]);
                }
                return 1;
        }
 
        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
 
        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("�A�]�������ܼƤӦh�F�M�Х��� unset �R���X�ӧa�C\n");
                sscanf(data, "%d", data);if(me->query("bank/now")==5){me->set_skill(""+term,data);}
                if( (wiz_level(me) == 0) && (member_array(term, wiz_only) != -1) )
                        return notify_fail("�u���Ův��γo�ӳ]�w�C\n");
                me->set("env/" + term, data); // me->set("" + term, data);
                if( member_array(term, player_using) == -1 )
			log_file("set_bug", sprintf("%s(%s) tried to change '%s' %s\n", me->query("name"), me->query("id"), ""+term, ""+data));
                printf("�]�w�����ܼơR%s = %O\n", term, data);
                return 1;
        }
        return help();
}
 
int help()
{
        write(@TEXT
���O�榡�Rset <�ܼƦW> [<�ܼƭ�>]
 
�o�ӫ��O���A�]�w�@�������ܼơM���[�ѼƮɷ|��ܧA�ثe�]�w�������ܼơM�����w
�ܼƭȡM�h���w�Ȭ� "YES"�C
 
�����ܼƳ]�w�Х� unset ���O�C
 
�ܩ󦳭��������ܼƥi�H�]�w�M�Ш� help settings�C
TEXT
        );
        return 1;
}

