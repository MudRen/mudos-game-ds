// liliya.c	By Shengsan@DS	1999.3.24
// �i���z��NPC�j������

#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�� !",
        "hello !",
        "��....",
        "�z....",
        "����....",
        "��....",
});

varargs void drool(string msg, string who);
varargs void do_emote(string msg, string who);
varargs void go();

void create()
{
        set_name( HIC"������"NOR, ({ "liliya" }));
        set("level",200);
        set("title",HIG"�i���z��NPC�j"NOR);
        set("race", "�H��");
	set("gender","�k��");
        set("age", 23);
        set("long",
@LONG
                     �_ �_ �_  
                   �~ �]�~ ' �^
                   ��==)�^p�]
                   ��  �] �x �^
                  �] �^(�s��( 
                   (�^|�_\  *.@.
                ��(�^�]   �^.@�I.
              �]�~�����^ ��-��@.''
                ��  ��    �s��'. 
                  ��      �x
LONG
        );

        set("attitude", "friendly");

        set("welcome_msg", "�����Ȼ��D: �w��Ө� ���Ū��ѥ�ͮx�|�C\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
		(: do_emote :),
		(: go :),
		(: drool :),
         }) );

        set("inquiry/name", @LONG
  �ڪ��W�r�O�ʷP���ܡA�A�s����ǡH
LONG );
	set("inquiry/shengsan",@LONG
�@�H�A�O�b�����]�k���ڳ̱R���������ܡH......�i�D�A�@�Ӥp���K...
...�L�����ǬO�Ŧ⪺�C...�ӥB���ǤW�٦��y�ڷR�ŤѯŬ��k�z����¸��C
LONG );

        set("inquiry/eq", @LONG
  �� i �ݬݦۤv���W�a�A�A���W�諸�N�O�ڡC
LONG );

        setup();

}
int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "�H", "");
        msg = replace_string(msg, "�S", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "�I", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "�C", "");
        msg = replace_string(msg, "�a", "");

        if( msg != "" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("id");

// Don't process our own speech.
        if( ob == this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("angry " + ob->query("id") );
                command("say �𪺦n!! �ݧڪ�!!");
                command("chair " + ob->query("id") );
                break;
        default:
                command("smirk " + ob->query("id"));
                break;
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob,cwho;
        object target;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

	if(!objectp(target = present(who, environment(this_object()))))
		return;
	if(target == this_object())
		return;
		
	cwho = target->query("name");
	
        if( (strsrch(msg, "������") >= 0) ) {
                if( sscanf(msg, "%*s������%s", msg)==2 ) msg = "������" + msg;
                switch(random(8)) {
                case 0: command("say " + cwho + "�M�A�O�b�ݧڶܡS"); break;
                case 1: command("say ����" + msg + " ... "); break;
                case 2: command("say �c ... "); drool(); break;
                case 3: command("say �o�Ӱ��D�� ...."); break;
                case 4: command("say " + cwho + "�M���D�o�Ӱ��D�����׹�A���򭫭n�ܡS"); break;
                case 5: command("say " + msg + "�S"); break;
                case 6: command("say " + cwho + "�A�ण�໡�M���@�I�S"); break;
                case 7: command("say " + cwho + "�M�ڤ����A�ݪ����D"); break;
                }
        }
        else if( (strsrch(msg, "�A") >= 0)
        ||      (strsrch(msg, "�p") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s�A%s", msg) == 2 ) msg = "�A" + msg;
                msg = replace_string(msg, "�A", "��");
                msg = replace_string(msg, "�p", "��");
                switch(random(10)) {
                case 0: command("say " + who + "�M�A�O��" + msg + "�ܡS");      break;
                case 1: command("say �A�T�w" + msg + "�S");     break;
                case 2: command("say " + msg + "��A���������Y�S");     break;
                case 3: command("say �� ... " + who + "���o�n"); break;
                case 4: command("say " + cwho + "�A�������" + msg + "�o�򦳿���S"); break;
                case 5: command("say ������A�{��" + msg + "�S"); break;
                case 6: command("say ���Ӹ��D�a"); drool(); break;
                case 7: command("say �~��"); break;
                case 8: command("say ���@�w�a�S"); break;
                case 9: command("say ���o�ӥi�� ...."); break;
                }
        }
         else              
                if((strsrch(msg, "��") >= 0) ){
                if (strsrch(msg, "�ڥs") >= 0 ) command("say "+cwho+", �A�n!!");
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "�A");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say �A�O��" + msg + "�ܡS"); break;
                case 1: command("say �u���S" + msg + "�S");     break;
                case 2: command("say �p�G" + msg + "�M�گ����A���򦣶ܡS");     break;
                case 3: command("hmm"); break;
                case 4: command("say �A�{��" + msg + "�S"); break;
                case 5: command("say �ڦ��P�P"); break;
                case 6: command("say �A�����u" + msg + "�v�ڤ���e�P"); break;
                case 7: command("say �����u" + msg + "�v�����D�즹����n�ܡS"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say ������" + msg + "?"); break;
                        case 1: command("say �u" + msg + "�v�O����N��S"); break;
                        case 2: command("say " + msg + "�S"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say �A��򪾹D" + msg + "?"); break;
                        case 10: command("say ���" + cwho + "���O���F�M" + msg); break;
                        case 11: command("say �ڷ�M���D�M" + msg); break;
                        case 12: command("say �M��O�S"); break;
                        case 13: command("say �u���ܡS"); break;
                        case 14: command("say �ڤ��o��{���C"); break;
                        default:
                                break;
                }
        }
}

varargs void do_emote(string msg, string who)
{
        mapping mem;
        string *ob,*emotecmd,ecmd;
        object target;

	emotecmd = sort_array(EMOTE_D->query_all_emote(), 1);
	
        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        
        command(emotecmd[random(sizeof(emotecmd))] +" "+ who );
}


varargs void go()
{
}


void reset()
{
        delete("memory");
}

