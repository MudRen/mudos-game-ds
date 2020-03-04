// info_lady.c
// Modified from ES 2 drooler.c
// By Annihilator@Celestial.Empire (09/15/95)
// Last modified by Spock @ FF  97.Oct.30.

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

void create()
{
        set_name( "�d�ǧŮv", ({ "luky","npc","Luky",}));
        set("level",20);
        set("title","[1;36m�i��ߧŮv�j[m");
        set("race", "�H��");
        set("age", 24);
        set("long", @LONG

     .--,       .--,
    ( (  \.---./  ) )
     '.__/o   o\__.'
        {=  ^  =}
         >  -  <
        /       \
       //       \\
      //|   .   |\\
      "'\       /'"_.-~^`'-.
         \  _  /--'         `
       ___)( )(___
      (((__) (__)))


LONG
        );
        set("ridable",1);
        set_skill("armor",1000);
        set("env/spellpower",5);
        set("str", 7);
        set("dex", 12);
        set("int", 15);
//        set("not", 10);
        set("con", 6);
  //      set("tec", 10);
        set("attitude", "friendly");
//        set("group", ({"newbie", "newbie_staff"}));
   //     set("score", 50 );
  //      set("positive_fame", 40 );
    //    set("negative_fame", 5 );

        set("welcome_msg", "�d�ǧŮv���D: �w��Ө� ��������. �i���i�H���ڷQ�I�ԭz��?\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
"�d�ǧŮv�����Ť@���M�ܥX�@���p��, �}�l�\\Ū�_��.\n",
"�d�ǧŮv���_�@�K��, ����b�ȤW��_�~��.\n",
"�d�ǧŮv�����Ť@���M�ܥX�@�]�p�氮, �}�l�Y�_�氮��.\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  �ڪ��W�r�O����,�A�s�����?.
LONG );
        set("inquiry/allena", @LONG
  ���ӳå�M���M�ڻ�....   ���I�ܺA...... �o���D�ΪZ���O����M
���@..  �ݨ�o�̦n�s�o�k��!!  �_�h.... 
LONG );
        set("inquiry/chenyuan", @LONG
  ���O���]�k�̳̼ɤO���Ův. ��ı�o�L���ӥh���q��..  �K�K....
LONG );

        set("inquiry/job", @LONG
  �ڭt�d�ѵ��@�ǧA�̱`�������D. �i�O....�o���u�@�ڤ]�O��Ӥ��[,
�ҥH���Ǧa��ڤ]���M���C. �Q���D�����ǰ��D�i�H�߰�, �i�H
ask joan about faq.
LONG );
/*        set("inquiry/faq", @LONG
  ���ܦh�ɭ�, �ѵ��N�b help ������, �ҥH�ڥu�t�d������s��ǰ|
�V�m���ߪ����D�ѵ���. �H�U�O�گ�^�����d��:
�Ҧp ask joan about stairs  �H�߰ݼӱ�b����.

  stairs [�ӱ�], staff [¾��], principal [�ժ�], lavatory [�Z��]
  cafe [�\�U], eq [�˳�], train [�V�m]
LONG );
        set("inquiry/stairs", @LONG
  �o�ɫؿv�����n���N�O�ӱ�. �n�W�Ӫ���, �Щ��n��.
LONG );
        set("inquiry/staff", @LONG
  ��ӷs��ǰ|��¾���ܤ�, �ڮժ������k�O�]���g�O��������].
LONG );
*/        set("inquiry/clc", @LONG
  �� ?  �s�� ?  �ڭ̪��Ѥj�O���u���j�v���s, ���⨤����, ��
17 ���ذ���, ���ڬݨ�L�N��, ���L�ݤ[�F�N�ߺD�F....�n�O�A�J
�W�s�����u���L�v, �p�ߥL�|�A�_.
LONG );
/*        set("inquiry/lavatory", @LONG
  �b�C�h�Ӽӱ誺����N�O�Z��.
LONG );
        set("inquiry/cafe", @LONG
  �\�U�b�G��, �W�ӫ᩹�_���K�i�ݨ�. �A�i�H�b�\�U�ʶR�����ζ���.
LONG );
*/
        set("inquiry/eq", @LONG
  �� i  �ݬݦۤv���W�a, �A���W�諸�N�O��.
LONG );
/*        set("inquiry/train", @LONG
  �T�ӥH�W�O�V�m�U���ޯ�M�ǲߪ��Ѫ��Ы�, �A�i�H�b���̾Ǩ�@��
�򥻪��ޯ�.
LONG );
*/
        setup();
/*


//        add_money("silver", 12 );
  //      add_money("copper", 100 );
    //    carry_object(__DIR__"obj/female_uniform_coat")->wear();
    //    carry_object(__DIR__"obj/female_uniform_skirt")->wear();
   //     carry_object(__DIR__"obj/uniform_cap")->wear();
   //     carry_object(__DIR__"obj/leather_belt")->wear();
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
        if( ob == this_object() ) return; // Don't process our own speech.
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
        object me;
        me=this_player();
        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        if( (strsrch(msg, "���ڥ[") >= 0) ){
        command("nod "+me->query("id"));
        command("c armor "+me->query("id"));
        return;
        }
        if( (strsrch(msg, "������") >= 0) ) {
                if( sscanf(msg, "%*s������%s", msg)==2 ) msg = "������" + msg;
                switch(random(8)) {
                case 0: command("say " + who + "�M�A�O�b�ݧڶܡS"); break;
                case 1: command("say ����" + msg + " ... "); break;
                case 2: command("say �c ... "); drool(); break;
                case 3: command("say �o�Ӱ��D�� ...."); break;
                case 4: command("say " + who + "�M���D�o�Ӱ��D�����׹�A���򭫭n�ܡS"); break;
                case 5: command("say " + msg + "�S"); break;
                case 6: command("say " + who + "�A�ण�໡�M���@�I�S"); break;
                case 7: command("say " + who + "�M�ڤ����A�ݪ����D"); break;
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
                case 4: command("say " + who + "�A�������" + msg + "�o�򦳿���S"); break;
                case 5: command("say ������A�{��" + msg + "�S"); break;
                case 6: command("say ���Ӹ��D�a"); drool(); break;
                case 7: command("say �~��"); break;
                case 8: command("say ���@�w�a�S"); break;
                case 9: command("say ���o�ӥi�� ...."); break;
                }
        }
         else              
                if((strsrch(msg, "��") >= 0) ){
                if (strsrch(msg, "�ڥs") >= 0 ) command("say "+who+", �A�n!!");
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
                        case 10: command("say ���" + who + "���O���F�M" + msg); break;
                        case 11: command("say �ڷ�M���D�M" + msg); break;
                        case 12: command("say �M��O�S"); break;
                        case 13: command("say �u���ܡS"); break;
                        case 14: command("say �ڤ��o��{���C"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}
