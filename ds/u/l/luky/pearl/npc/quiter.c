#define DROP_CMD               "/cmds/std/drop"
#define LUKY		"/u/l/luky/area/"
#include <path.h>
inherit NPC;
//inherit F_DBASE;
inherit F_CLEAN_UP;

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
seteuid("Root");
//�W�ٳ]�w
        set_name( "�s��2��", ({ "luky number one","warner"}));
        set("level",100);
        set("title","[1;36m�i�ʵ��������j[m");
        set("race", "�H��");
        set("age", 30);
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

        set("chat_chance", 1 );
        set("chat_msg", ({
"�Y�ӧŮv�������H�}�l�ʵ��A.\n",
(:command("say �o�̦�BUG, �Х�qquit�����A���u.."):),
        }) );

//environment(this_player())->set("no_kill",1);
//environment(this_player())->set("no_cast",1);
        setup();

        carry_object("/u/l/luky/tempsuit")->wear();
        
}

void init()
{
command("change suit");
command("say �o�̦�BUG, �Х�qquit�����A���u..");
add_action("do_qquit","qquit");
}

int do_qquit()
{
object *inv, link_ob, me;
string who;
int i;
me = this_player();
who = me->query("name");
if(me->is_fighting())
       return notify_fail("�A���b�԰���...\n");
if(me->query_temp("wood"))
return notify_fail("���̫�@�ڬ姹�A��.. OK??\n");
       
        if( !wizardp(me) ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( !inv[i]->query_autoload())
                                DROP_CMD->do_drop(me, inv[i]);
        }

//  me->remove_all_enemy();
        link_ob = me->query_temp("link_ob");
        me->set("startroom",base_name(environment(me)));

// We might be called on a link_dead player, so check this.
        if( link_ob ) {

// Are we possessing in others body ?
                 if( link_ob->is_character() ) {
                        write("�A����z�^��" + link_ob->name(1) + "�����W�C\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

// * if(me->query_temp("damage_type/lance"))
// * me->set("damage_type/lance",me->querytemp("damage_type/lance"));
                me->set("cmdcount",0);          // add by shengsan
                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
command("nod");
me->save();
(int)link_ob->save();

                destruct(link_ob);
        }

write("\n�A��V�F�t�z�W���O�����������\n\n");
write("�g�L�F���i��ĳ���ɥ��G�D[1;31m_,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~*[m\n");
write("[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~`~+._,-~[m\n");
write("[1;36m_,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~`~+.[1;35m_,-~\n");
write("[1;35m_,-~`~+._,-~`~+.[1;31m_,-~`~+._,-~`~+.[1;32m_,-~`~+._,-~`~+.[1;33m_,-~`~+._,-~`~+.[1;34m_,-~`~+._,-~[m\n\n");

        me->save();
efun::destruct(me);
       
shout("�s��2���^��: "+who+"���\�����}�F�o�ӥ@��!!");
return 1;
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
                switch(random(50)) {
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
                switch(random(50)) {
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
                switch(random(20)) {
                case 0: command("say �A�O��.." + msg + " ��.."); break;
                case 2: command("say �p�G" + msg + "�M�گ����A���򦣶ܡS");     break;
                case 3: command("hmm"); break;
                case 4: command("say �A�{��" + msg + "�S"); break;
                case 7: command("say �����u" + msg + "�v�����D�즹����n�ܡS"); break;
                }
        } else {
                switch(random(50)) {
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
