/* ghost.c
   by -Acme-
*/

#include <ansi.h>
inherit NPC;

object owner;

// �]�w�֦���
int set_owner(object obj)
{
    if( !objectp(obj) ) return 0;
    owner = obj;
}

// �d�߾֦���
object query_owner()
{
    if( !objectp(owner) ) return 0;
//    if( !owner->query_temp(query("number")) ) return 0;
//    if( owner->query_temp(query("number")) != this_object() ) return 0;
    return owner;
}

// �R��ghost
void do_destruct()
{
    message_vision("����ǨӲY�D���u����r�r��v�n���A$N�N���������F...\n", this_object());
    // �C�����@��ghost �A���i�H���D�H�W�[1�I�ӳ�����
        if(objectp(owner)) 
                SPELL_D("moon-essence")->checkAdd(owner);

    set_heart_beat(0);
    destruct(this_object());
        return;
}

// �ˬd����O���O�n�����F
void do_check()
{
    if( !objectp( query_owner() ) ) {
        do_destruct();
        return;
    }

    if( query("hp") < 1 ) {
        do_destruct();
        return;
    }

    if( environment(this_object()) != environment(owner) ) {
        do_destruct();
        return;
    }

    return;
}

void die()
{
    message_vision("����ǨӲY�D���u����r�r��v�n���A$N�N���������F...\n", this_object());
    // �C�����@��ghost �A���i�H���D�H�W�[1�I�ӳ�����
        if(objectp(owner)) 
                SPELL_D("moon-essence")->checkAdd(owner);
        
    destruct(this_object());
    return;
}

void create()
{
    set_temp("float",1); // �����ӯB�b�Ť��a, By Acme

    set_name("�t���", ({ "ghost" }));
    set("long", "�@�Ӵ�������A�����w���F�h�֦~�A�ܤ��D����L�������C \n");
    set("gender", "�k��");
    set("race", "�H��");
    set("age", 30);
    set("level",1);
    set("evil", 40);         
       set("no_scroll", 1);

    // ���ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance", 2);
    set("chat_msg", ({
        this_object()->query("name")+"�ƤF�L�h�A�S�ƤF�L��....\n",
        this_object()->query("name")+"���ĤF�@�f��@�����@\n",
        (: do_check :),
    }));

    // �԰��ɰʧ@�G�ˬdowner�٦b���b�A�çl����d�J��
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_check :),
    }) );

    setup();
}

