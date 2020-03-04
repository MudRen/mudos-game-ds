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
        set_name( "�d�ǧŮv", ({ "luky","npc","Luky",}));
        set("level",20);
        set("title","[1;36m�i��ߧŮv�j[m");
        set("race", "�H��");
        set("age", 25);
        set("long", @LONG

     .--,       .--,
    ( (  \.---./  ) )
     '.__/o   o\__.'
        {=  ^  =}
         >  -  <
        /       \
       //  NPC  \\
      //|   .   |\\
      "'\       /'"_.-~^`'-.
         \  _  /--'         `
       ___)( )(___
      (((__) (__)))


LONG
        );

//�ݩʳ]�w
        set("str", 7)�;
        set("dex", 12);
        set("int", 15);
        set("con", 6);
        set("attitude", "friendly");
        set("welcome_msg", "�d�ǧŮv���D: �w��Ө� ��������. �i���i�H���ڷQ�I�ԭz��?\n" );
        set("chat_chance", 5 );
        set("chat_msg", ({
"�d�ǧŮv�ܦ����P�a�`���ۧA, ���������G�a���@�I�N��.\n",
"�d�ǧŮv���_�@�K��, ����b�ȤW��_�~��.\n",
"�d�ǧŮv�����Ť@���M�ܥX�@�]�p�氮, �}�l�Y�_�氮��.\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  �ڪ��W�r�O����,�A�s�����?.
LONG );
        set("inquiry/job", @LONG
  �ڭt�d�ѵ��@�ǧA�̱`�������D. �i�O....�o���u�@�ڤ]�O��Ӥ��[,
�ҥH���Ǧa��ڤ]���M���C. �Q���D�����ǰ��D�i�H�߰�, �i�H
ask joan about faq.
LONG );
        set("inquiry/clc", @LONG
  �� ?  �s�� ?  �ڭ̪��Ѥj�O���u���j�v���s, ���⨤����, ��
17 ���ذ���, ���ڬݨ�L�N��, ���L�ݤ[�F�N�ߺD�F....�n�O�A�J
�W�s�����u���L�v, �p�ߥL�|�A�_.
LONG );
        set("inquiry/eq", @LONG
  �� i  �ݬݦۤv���W�a, �A���W�諸�N�O��.
LONG );
        setup();
/*
//      set_skill("literature", 40);
//      add_money("coin", 1000 );
//      carry_object(__DIR__"obj/female_uniform_coat")->wear();
//      carry_object(__DIR__"obj/female_uniform_skirt")->wear();
//      carry_object(__DIR__"obj/uniform_cap")->wear();
//      carry_object(__DIR__"obj/leather_belt")->wear();
        carry_object(__DIR__"obj/white_shoes")->wear();
        carry_object(__DIR__"obj/white_gloves")->wear();
        carry_object(__DIR__"obj/pearl_earring")->wear();
        */
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
