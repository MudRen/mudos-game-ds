inherit NPC;
varargs void drool(string msg, string who);
void create()
{
//�W��
set_name("�p��", ({ "dog" }), );
set("long","�@���i�R���p���C");
set("title","����");
set("class","worker");
//�ݩ�
set("age",5);
set("level",10);
set("chat_chance", 5);
set("chat_msg", ({
"�����������b�A����¶��¶�h����\n",
"�����j�q�G��������������\n",
"�����θ}�b�a�W�L��a�e�۰��D�D�D�D\n",
"��������@���A�ܥX�F�@�ﭹ���D�D�D�}�l���b�@�Ǥj�֦��[�@�G��~~\n",
"�����̰��b�A�}�伻�b�C\n",
"�����֦ܲa���F�@�ӫ���D�D�C�C���\n",
 (: drool :),
 (: drool :),
 (: drool :),
 (: drool :),
}));
set("inquiry/name", @LONG
  �ڪ��W�r�O�w�w,�A�s�����?.
LONG );

setup();
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
        case "sob":
                command("pat " + ob->query("id") );
                command("comfort " + ob->query("id") );
                break;
        default:
                command("idiot " + ob->query("id"));
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

        switch(random(20)) {
                case 0: command("jump"); break;
                case 1: command("hoho"); break;
                case 2: command("idle"); break;
                case 3: command("sing"); break;
                case 4: command("say ��!!�_�I��!!"); break;
                case 5: command("say " + who + "�n�[����!"); break;
                }
}

void reset()
{
        delete("memory");
}
