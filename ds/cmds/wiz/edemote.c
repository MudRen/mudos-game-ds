// edemote.c

// �䴩��X �ק� by Wilfred@DS  2000/10/16

#include <ansi.h>
inherit F_CLEAN_UP;

string color(string arg);
int in_use;

int main(object me, string arg)
{
        mapping emote;

        if( !arg ) return notify_fail("�A�n�s�褰�� emote�S\n");

        if( sscanf(arg, "-d %s", arg) ) {
                write("�R�� emote�R" + arg + "\n");
                EMOTE_D->delete_emote(arg);
                return 1;
        }

        if( sscanf(arg, "-p %s", arg) ) {
                emote = EMOTE_D->query_emote(arg);
                printf("�W���ק�R%s\n", emote["updated"]);
                printf("�w�w�w�w�w�w�w�w�w�w�w�w�w\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
                        emote["myself"], emote["others"], emote["myself_self"],
                        emote["others_self"], emote["myself_target"], emote["target"],
                        emote["others_target"] );
                return 1;
        }

        emote = EMOTE_D->query_emote(arg);
        emote = (["updated":geteuid(me)]);

        write("�s�� emote�R" + arg + "\n");
        write("�T���i�H���n�X��M�� . ��ܵ����C\n");
        write("�T�����i�ϥΪ��ѼƦ��H�U�X�ءR\n");
        write("  $N  �ۤv���W�r�C\n");
        write("  $n  �ϥι�H���W�r�C\n");
        write("  $P  �ۤv���H�٥N�W���M�p�A�B�p�B�L�B�o�B�e�B���C\n");
        write("  $p  �ϥι�H���H�٥N�W���M�p�A�B�p�B�L�B�o�B�e�B���C\n");
        write("  $T  ���ϥΪ̥i�H���[���T���C\n");
        write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
        write("�����w��H�ϥγo�� emote �ɡM�A�ۤv�ݨ쪺�T���R\n->");
        input_to("get_msg_myself", emote, arg);
        return 1;
}


int get_msg_myself(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["myself"]) ) emote["myself"] += "\n";
                write("�����w��H�ϥγo�� emote �ɡM��L�H�ݨ쪺�T���R\n->");
                input_to("get_msg_others", emote, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself"]) )
                emote["myself"] += color(msg) + "\n";
        else emote["myself"] = color(msg);
        write("->");
        input_to("get_msg_myself", emote, pattern);
        return 1;
}

int get_msg_others(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["others"]) ) emote["others"] += "\n";
                write("��ۤv�ϥγo�� emote �ɡM�ۤv�ݨ쪺�T���R\n->");
                input_to("get_msg_myself_self", emote, pattern);
                return 1;
        }
        if( !undefinedp(emote["others"]) )
                emote["others"] += color(msg) + "\n";
        else emote["others"] = color(msg);
        write("->");
        input_to("get_msg_others", emote, pattern);
        return 1;
}

int get_msg_myself_self(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["myself_self"]) ) emote["myself_self"] += "\n";
                write("��ۤv�ϥγo�� emote �ɡM��L�H�ݨ쪺�T���R\n->");
                input_to("get_msg_others_self", emote, pattern);
                return 1;
        }
        if( !undefinedp(emote["myself_self"]) )
                emote["myself_self"] += color(msg) + "\n";
        else emote["myself_self"] = color(msg);
        write("->");
        input_to("get_msg_myself_self", emote, pattern);
        return 1;
}

int get_msg_others_self(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["others_self"]) ) emote["others_self"] += "\n";
                write("��O�H�ϥγo�� emote �ɡM�ۤv�ݨ쪺�T���R\n->");
                input_to("get_msg_myself_target", emote, pattern);
                return 1;
        }
        if( !undefinedp(emote["others_self"]) )
                emote["others_self"] += color(msg) + "\n";
        else emote["others_self"] = color(msg);
        write("->");
        input_to("get_msg_others_self", emote, pattern);
        return 1;
}


int get_msg_myself_target(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["myself_target"]) ) emote["myself_target"] += "\n";
                write("��O�H�ϥγo�� emote �ɡM�ϥι�H�ݨ쪺�T���R\n->");
                input_to("get_msg_target", emote, pattern);
                return 1;
        }
        msg = replace_string( msg, "$BEEP$", "");
        if( !undefinedp(emote["myself_target"]) )
                emote["myself_target"] += color(msg) + "\n";
        else emote["myself_target"] = color(msg);
        write("->");
        input_to("get_msg_myself_target", emote, pattern);
        return 1;
}

int get_msg_target(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["target"]) ) emote["target"] += "\n";
                write("��O�H�ϥγo�� emote �ɡM���A�ۤv�M�ϥι�H�~�M��L�H�ݨ쪺�T���R\n->");
                input_to("get_msg_others_target", emote, pattern);
                return 1;
        }
        if( !undefinedp(emote["target"]) )
                emote["target"] += color(msg) + "\n";
        else emote["target"] = color(msg);
        write("->");
        input_to("get_msg_target", emote, pattern);
        return 1;
}

int get_msg_others_target(string msg, mapping emote, string pattern)
{
        if (msg==".") {
                if( !undefinedp(emote["others_target"]) ) emote["others_target"] += "\n";
                EMOTE_D->set_emote(pattern, emote);
                write("Emote �s�赲���C\n");
                return 1;
        }
        if( !undefinedp(emote["others_target"]) )
                emote["others_target"] += color(msg) + "\n";
        else emote["others_target"] = color(msg);
        write("->");
        input_to("get_msg_others_target", emote, pattern);
        return 1;
}

string color(string arg)
{
  int i;
  string *source_color, *target_color;
  mapping color = ([
  "$BEEP$": BEEP,
  "$BLK$" : HIW+BLK,
  "$WHT$" : NOR+WHT,
  "$HIW$" : HIW,
  "$RED$" : RED,
  "$HIR$" : HIR,
  "$GRN$" : GRN,
  "$HIG$" : HIG,
  "$YEL$" : YEL,
  "$HIY$" : HIY,
  "$BLU$" : BLU,
  "$HIB$" : HIB,
  "$MAG$" : MAG,
  "$HIM$" : HIM,
  "$CYN$" : CYN,
  "$HIC$" : HIC,
  "$NOR$" : NOR
  ]);

  source_color = keys(color);
  target_color = values(color);

  for(i=0;i<sizeof(source_color);i++)
    arg = replace_string(arg, source_color[i], target_color[i]);

  return arg;
}

int help(object me)
{
write(@HELP
���O�榡 : edemote [-d|-p] <emote>
 
�o�ӫ��O�i�H�ק�, �R�� emote �ΦC�X�䤺�e. �[�W -d �ѼƷ|�R��
���w�� emote, -p �Ѽƫh�|�C�X���w emote �����e. �C�X�����ǻP�s
�� emote �ɬۦP.
 
��J emote �T���ɦ��T�Ӷ���: �S���ؼ�, ���w�ؼЩάO��ۤv. �Y
���Q���Y���T��, �h�����b�ťզ��J '.' ���L.
 
�@�� emote �T���i�H���ܦh��, �b�ťզ��J '.' ������J�Ӷ� emote.
 
�s�� emote �ɥi�H�ΥH�U���Ÿ��Ӫ��:
 
$N : �ۤv���W�r.
$n : �ؼЪ��W�r.
$P : �ۤv���H�٥N�W��.
$p : �ؼЪ��H�٥N�W��.
$T : �B�~���[���T��.

�]�w���w��H���T��, $BEEP$ �|�۰ʨ��N��[��]���n��, ���u����ۤv�P��H�C
�t�~�W�⪺��k�P nick , �� help nick

HELP
    );
    return 1;
}
