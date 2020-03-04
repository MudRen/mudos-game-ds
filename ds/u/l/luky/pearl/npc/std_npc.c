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
//=========================�򥻳]�w==========================

        set_name( "�e�e���p��", ({ "asan","�p��","kid",}));
        set("level",20);
        set("title","[1;36m���[m");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 25);
        set("long", @LONG
�@�ӹx�֪��p�ġA�����۵e��(pen)�b����W�e�p�m���C
LONG
        );

//========================�ݩ��B�~�]�w===============================
//   set("str", 7)�;
//   set("dex", 12);
//   set("int", 15);
//   set("con", 6);
//   set("combat_exp", 600);
//   set("score", 60);

//========================�A�����O=================================
//   set("attitude", "friendly");   //�͵��� NPC�C
//   set("attitude", "peaceful");   //�ũM�� NPC�C
//   set("attitude", "heroism");    //�^���D�q�� NPC�C
//   set("attitude", "aggressive"); //�D�ʧ���,�ͩʦn������ NPC�C
//   set("attitude", "killer");     //�ݱ����ʪ� NPC�C

//   set("welcome_msg", "�d�ǧŮv���D: �w��Ө� ��������. �i���i�H���ڷQ�I�ԭz��?\n" );

//=============================�۰ʰʧ@=================================
set("startroom","/u/l/luky/workroom"); //�^�a����m (NOTE.1)
     set("chat_chance", 5 );  //�ʧ@���v
     set("chat_msg", ({       //�ʧ@���e
(: this_object(), "random_move" :),//�۰ʶè�
(: this_object(), "return_home" :),//�۰ʦ^�a (�t�XNOTE.1)
"�p�īܦ����P�a�`���ۧA, ���������G�a���@�I�N��.\n",
"�p�Į��_�@�K��, ����b��W�W��_�~��.\n",
(:command("say �z��~~ �Q�ѵe���S�Q�H�����F..."):),
(:command("say �O�֤S�b�ڪ��p�m���W�üg�r?? �S�n���e�F.."):),
(:command("sigh"):),
(:command("sing"):),
(: drool :),
(: drool :),
}) );

//===========================���D�^��==================================
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

//=========================�԰��T��===========================
/*     set("chat_chance_combat", 10);
     set("chat_msg_combat", ({
         HIR"�p�ĲY�F�a�s�� : �u�n�h�ڡ�T���n���ڡ�T�ϩR�ڡ�T�v\n"NOR,
     }) );
*/
//==========================�ޯ�]�w=============================
/*      set_skill("spear", 200);   
      set_skill("dodge", 200);
      set_skill("unarmed", 300);
      set_skill("parry", 200);
*/

        setup();
//        set_heart_beat(1); //�O�_���S��

//==========================�˳ƹD��=============================
      add_money("coin", 220 );  //���W�a����
/*      carry_object(__DIR__"obj/female_uniform_coat")->wear();
      carry_object(__DIR__"obj/female_uniform_skirt")->wear();
      carry_object(__DIR__"obj/uniform_cap")->wear();
      carry_object(__DIR__"obj/leather_belt")->wear();
      carry_object(__DIR__"obj/white_shoes")->wear();
      carry_object(__DIR__"obj/white_gloves")->wear();
*/
      carry_object("/u/d/disappear/spear/pen")->wield();

}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "??", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
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

//======================�ʧ@����======================================
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

//==========================��ܳ]�w==================================
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
/* =========================NPC���S��=============================
void heart_beat()
{
  object *enemy,me;
int damage;
  int i;
  me = this_player();
  if( me->is_fighting() )
  {
if(random(300)>200)
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
enemy[i]=present(enemy[i],environment(me));
damage=100+random(200);
if(enemy[i]->query_temp("curse")<1)
{
message_vision(HIC"HMM...��$N���D$n���Q�`...��$n�����Y�N",enemy[i],me);
message_vision("��M�@�D�_�Ǫ�����g�J$N���餺\n",enemy[i]);
 message_vision("$N�����M�P��Q�������A--->["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
enemy[i]->set_temp("curse",2);
     }
else {
message_vision(HIR"$N����P��V�ӶV�t�F...["+damage+"]\n"NOR,enemy[i]);
enemy[i]->receive_damage("hp",damage,me);
}
}
 }
   if( me->query("hp") < 0 )
      me->die();
::heart_beat();
}
*/