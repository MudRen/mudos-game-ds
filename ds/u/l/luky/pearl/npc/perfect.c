inherit NPC;
void create()
{
//�W�ٳ]�w
set_name( "�i�O�S", ({ "chief perfect","perfect",}));
set("level",70);
set("title","�|��");
set("race", "�H��");
set("age", 35);
set("evil",-350);
set("coin",random(300));
set("long", @LONG

�@�өMħ���|���A�����b�Ѯ�᭱�ݮѡC
LONG
        );
set("chat_chance", 5 );
set("chat_msg", ({
(:command("sigh"):),
 }) );
set("inquiry/name", @LONG
  �ڪ��W�r�O�i�O�S, �z�n�C
LONG );

set("inquiry/word", @LONG
��..  �A�o�򦳿����? ���ڴN�i�D�A�n�F....
�̪�|�̱ߤW�`�`ť���_�Ǫ��n��, �����G�O�h�W���D�u..
���ȬO�c�F�w�g��J�F�o��, �ڥ��b�ݫe���|�����׹D��O,
�ݬݦ��S����k�X���c�F�C

    �ھڤW�����O��, ���|�H�e�]���g���L�o�ӱ��p, �]��
�׹D�|���O�\�b�������a�W�H�������������C�W����, �n��
�����������}�a���A�q�Ѹ�..�i�������ʤF�@��, �n���}
�a�������������D�O�ּ����F!? ��~~ ��L�������O:
 
 [????????]: ???????
 [���ɤT��]: �Ѱ󤧸��}
 [�Q�G�ɾ�]: �U���ҥ�

�o�O�ɩ�(sala)�d�U�����O, �γ\�n��ť�@�U�����L���Ʊ�.
�p�G�A�����ڸѶ}�o�����D�N�n�F... 

LONG );

set("inquiry/password", @LONG
  �K�X??�ګ�򪾹D? 

LONG );
set("inquiry/�K�X", @LONG
  �K�X??�ګ�򪾹D? 

LONG );
      setup();
      carry_object(__DIR__"item/red_key");
}

void init()
{
 int expp;
 object me;
 me=this_player();
 if(me->query("quest/oten")) return;
 if(me->query("killoten"))
 {
  me->delete("killoten");
  command("say ���§A���ڸѨM�F�o�����D!!");
  expp=(100-me->query("level"))*10000+random(20000);
  write	("���ߧA�����F[�׹D�|����]������!!\n"+
         "�A��o�F "+expp+" �I�g���!\n");
  me->add("exp",expp);
  me->set("quest/oten",1);
  me->save();
 }
}
void relay_say(object ob, string msg)
{
        string who, phrase;
        if( !userp(ob) ) return;
        who = ob->query("name");
// Don't process our own speech.
        if( ob == this_object() ) return;

}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;
        switch(verb) {
        case "kick":
                command("? "+ ob->query("id") );
//              command("say ��~~" + ob->query("id") +"�ۭt��!!!");
                break;
        default:
                command("smile");
                break;
        }
}

void reset()
{
// delete("memory");
}
