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
        set_name( HIC"��C�S�Q�["NOR, ({ "phliterica" }));
        set("level",300);
        set("title",CYN"���ҤH"NOR);
        set("race", "�H��");

        set("age", 23);
   set("gender",�k��);
        set("long",
@LONG
�o�N�O�ǻ������§Q���Ʃx�A���Ǩƥi�H�ݦo���C
(ask phliterica about morral,linjack,shengsan,luky,
eeman,aiwa,anfernee,armor,weapon)
LONG
        );

        set("attitude", "friendly");

        set("welcome_msg", "��C�S�Q�[���D: �w��Ө� ���§Q���a�C\n" );

        set("chat_chance", 5 );
        set("chat_msg", ({
"��C�S�Q�[�����Ť@���A�ܥX�@���p��, �}�l�\Ū�_�ӡC\n",
"��C�S�Q�[���_�M�l���춼�������e�ˤF�Ǥ��C\n",
"��C�S�Q�[���_�M�l�ܤF�Ǥ��C\n",
"��C�S�Q�[�ܦ����P�a�`���۷����Ӥ��A�����R���ŷx�C\n",
"��C�S�Q�[�]�i�p�СA�n�m�߰���C\n",
"��C�S�Q�[���W���ȱi��z�F�@�U�A�˶i�@�ӯȳU�l�̡C\n",
"��C�S�Q�[�����Ť@���A�ܥX�@�]�p�氮, �}�l�Y�_�氮�ӡC\n",
"��C�S�Q�[�ݵ۸�ơA�n���p����²���C\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );

        set("inquiry/name", @LONG
  �ڪ��W�r�O��C�S�Q�[�A�A�s����ǡH
LONG );
        set("inquiry/linjack", @LONG
   �L���W�r���M�s�ѪL�A���O�ݰ_�Ӥ@�I�����ѣ��A�S�O�ٷ|�A
�@�U�_��.... 
LONG );
        set("inquiry/luky", @LONG
  �o�O�b�Ңᤤ��O�Ȧ���ڪ��p�����H�F�A�L����...���_�S���C
LONG );
        set("inquiry/shengsan", @LONG
  �L�����٤������A���O���[�N�����D�F�C�A�i�H�ݰݬݧڪ��j�f
�ŤѬ��k�ݬݡC
LONG );
        set("inquiry/morral", @LONG
  �ڪ��p���O�̫Ӫ��A�p�G�n���h�ڦ����L���O�СA�N�u�����h��
�Ҧ����O�СC
LONG );
        set("inquiry/anfernee", @LONG
  �ڨC���ݨ�L�L�����A�����A�n���i�ܤ��N�C
LONG );
        set("inquiry/aiwa", @LONG
  �L�ܦ��S�⣲�A�N�O�C�Ѧb�L���䪺�k�������@�ˡC
LONG );
        set("inquiry/eeman", @LONG
  �C���ݨ�L�A�L�N����S�X���c���L���C���L�S���Y�A�ڪ��p���|
�O�@�ڡC
LONG );

        set("inquiry/armor", @LONG
  �A�ݧ�armor�H�n�a�A���A�@�ӽd�ҡC

#include <armor.h>

inherit FINGER;

void create()
{
set_name("������",({"ring"}) );
set("long"," �o�٤l���ѯ������O�q�O�H�P��w��,�B�ϤH���Y���M�s�C\n");
set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "gem");
set("unit", "��");
                set("value", 3000);
set("armor_prop/armor",32);
set("armor_prop/defense",5);
set("armor_prop/parry",0);
set("level",15);
}
setup();
}
LONG );
        set("inquiry/weapon", @LONG
  �A�ݧ�weapon�H�n�a�A���A�@�ӽd�ҡC

#include <ansi.h>
#include <weapon.h>

inherit AXE;
int do_wield(object me, object ob);
void create()
{
 set_name(HIC"�B�E���ɾԩ�"NOR,({"ice storm axe","axe"}));
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
  set("long","�o����Y�ݨӥ����L�_�A�N���@���K��@�ˡA���O
    �~�����F�@�h�������B�A�õo�X���M�B����C�j���O�����b
    ���s�W�����Y�A����g�~�֤믫�����O�@�A�~�o�w�֦��p���j��
     �O�q�a�C\n");
set("value",4500);
                set("material", "steel");
        }
 init_axe(855);	
 
// These properties are optional, if you don't set them, it will use the
// default values.   
set("wield_msg", "$N�N$n���b�⤤�A$N�n�ɥR���O�q�A��$N���Ǫ��H�o�N������Ÿ�C\n");
set("unwield_msg", "$N�N$n���^�y��A�N��ש󰱤�F�C\n");  
        setup();
}int fail_eq(object me)  
{
if(me->query("level") <35) {
message_vision("$N�����Ť����A�L�k�r���o�⯫��C\n",me);
}
       return 1;

}


void attack(object me,object victim)
{
int damage,str,dex;

if( random(100)>70)
    {
        /*   COMBAT_D->do_attack(me,victim,me->query_temp("weapon"),2);*/
str = me->query("str");
dex=me->query("dex");
damage=(dex+str)*(1+random(5));
        victim->receive_damage("hp", damage, me );
message_vision("                  �B�E���ɾԩ��M�o�X�j�j�����~ 

                       �q�ѤW�l��Ӥ@�}�B�r
          
              �V$N���h�I�I�I�y��$N"+damage+"�I���ˮ`�I�I�I�I\n",victim);
                             
         return;    

        }
    return;
}              
}

LONG);

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
