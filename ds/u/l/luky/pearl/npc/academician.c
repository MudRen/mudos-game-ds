inherit NPC;
void create()
{

//�W�ٳ]�w
        set_name( "�|�h", ({ "academician" }));
        set("level",30);
        set("race", "�H��");
        set("age", 35);
        set("coin",random(300));
        set("long", @LONG

�@�Ӭ�۾�����|�h�A���b�V�ӳX���ȤH�ѻ��׹D�|�����v�C
LONG
        );
/*        set("chat_chance", 5 );
        set("chat_msg", ({
(:command("sigh"):),
        }) );
*/
set("evil",-3000);
set("inquiry/name", @LONG
  �ڪ��W�r�O���q���ɡC
LONG );

set("inquiry/sala", @LONG
��.. �o�O�ܤ[�H�e���ƤF..  �ҥH�ڤ]���ӲM��.
�ڥu���D�ɩԥL�M���t�ڪ��污����.. �A�i�H�h�ݰ�
�ݮ��t�ڪ��H. �γ\�|���D����h.

LONG );

set("inquiry/password", @LONG
  �K�X??�ګ�򪾹D? 

LONG );
set("inquiry/�K�X", @LONG
  �K�X??�ګ�򪾹D? 

LONG );
      setup();
//    carry_object("/u/d/disappear/spear/pen")->wield();
}

void init()
{
 add_action("no_kill","kill");
}

int no_kill(string arg)
{
 if(arg=="perfect" || arg=="chief perfect")
 notify_fail("�|�h�ä��Q�M�A�@�ԡC\n");
 return 0;
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
