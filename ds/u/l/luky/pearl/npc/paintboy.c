#include <ansi.h>
inherit NPC;
string *rnd_say = ({
        "�� !",
        "hello !",
        "��....",
        "�z....",
        "����....",
});

varargs void drool(string msg, string who);

void create()
{

//�W�ٳ]�w
        set_name( "�e�e���p��", ({ "asan","�p��","kid",}));
        set("level",20);
        set("title","[1;36m���[m");
        set("race", "�H��");
        set("age", 25);
	set("evil",-20);
        set("coin",random(200));
        set("long", @LONG

�@�ӹx�֪��p�ġA�����۵e��(pen)�b����W�e�p�m���C
LONG
        );
        set("chat_chance", 5 );
        set("chat_msg", ({
"�p�īܦ����P�a�`���ۧA, ���������G�a���@�I�N��.\n",
"�p�Į��_�@�K��, ����b��W�W��_�~��.\n",
(:command("say �z��~~ �Q�ѵe���S�Q�H�����F..."):),
(:command("say �O�֤S�b�ڪ��p�m���W�üg�r?? �S�n���e�F.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
        }) );

set("inquiry/name", @LONG
  �ڪ��W�r�O���T,�A�s�����?.
LONG );

set("inquiry/pen", @LONG
  ��~~~ �o�ӵ��O�H�W���̭������ڪ�! �ܺ}�G�a! ����~~~
LONG );

set("inquiry/password", @LONG
  �K�X??�ګ�򪾹D? 
                  �ӧڰݧA�F, �Aı�o�ڵe���n���n��? ^_^ 
                  �i�����𳣳Q�H�üg�r..  �ڳ��֨S�a��e�ϤF..  
LONG );
set("inquiry/�K�X", @LONG
  �K�X??�ګ�򪾹D? 
                  �ӧڰݧA�F, �Aı�o�ڵe���n���n��? ^_^ 
                  �i�����𳣳Q�H�üg�r..  �ڳ��֨S�a��e�ϤF..  
LONG );
      setup();
      set_skill("spear", 80);
      carry_object(__DIR__"wp/pen")->wield();
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "�H", "");
        msg = replace_string(msg, "�S", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
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
        who = ob->query("name");

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
                command("cry");
                command("say ��~~" + ob->query("id") +"�ۭt��!!!");
                command("sob " + ob->query("id") );
                break;
        default:
                command("bow");
                break;
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "������") >= 0) ) {
                if( sscanf(msg, "%*s������%s", msg)==2 ) msg = "������" + msg;
                msg = replace_string(msg, "������A", "��");
                msg = replace_string(msg, "������p", "��");
                switch(random(6)) {
                case 0: command("say " + who + "�M�A�O�b�ݧڶܡS"); break;
                case 1: command("say ����" + msg + " ... "); break;
                case 2: command("say ��!! �]��" + msg + "�r!!"); drool(); break;
                case 3: command("say �o�Ӱ��D�� ...."); break;
                case 4: command("say " + msg + "�S"); break;
                case 5: command("say " + who + "�A�ण�໡�M���@�I�S"); break;
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
                case 0: command("say " + who + "�M�A��" + msg + " �S");      break;
                case 2: command("say " + msg + "��A���������Y�S");     break;
                case 3: command("say �� ... " + who + "���o�n"); break;
                case 4: command("say " + who + "�A��" + msg + "�n���ܦ������.."); break;
                case 5: command("say ������A�{��" + msg + "�S"); break;
                case 6: command("say ���Ӹ��D�a"); drool(); break;
                case 8: command("say ���@�w�a�S"); break;
                }
        }
         else              
                if((strsrch(msg, "��") >= 0) ){
                if (strsrch(msg, "�ڥs") >= 0 ) command("say "+who+", �A�n!!");
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "�A");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("say �A�O��.." + msg + " ��.."); break;
                case 2: command("say �p�G" + msg + "�M�گ����A���򦣶ܡS");     break;
                case 3: command("hmm"); break;
                case 4: command("say �A�{��" + msg + "�S"); break;
                case 7: command("say �����u" + msg + "�v�����D�즹����n�ܡS"); break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say ������" + msg + "?"); break;
                        case 2: command("say �u" + msg + "�v�O����N��S"); break;
                        case 4: command("flop"); break;
                        case 6: command("jump"); break;
                        case 8: command("smile"); break;
                        case 10: command("?"); break;
                        case 12: command("hmm"); break;
                        case 14: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 16: command("say " + who + "�O�q���̨Ӫ���?"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
