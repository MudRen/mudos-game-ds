#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "����" , ({ "fire devil","devil" }) );
        set("level",40);
        set("race","evil");
        set("gender","����");
        set("age",500 + random(99));
        set("long","�L�O�@���q�騪�����Ǫ��A���v��������A��a�ؾl\n"
                   "�A�v���Y����A�����۶��A�����H�ΡI\n"
           );
        set("chat_chance", 8);
        set("chat_msg",({
               "���٥��V�V�ѡA���]�R�ۤ@�ɸJ�j���]�A�]�ɦʤV�A��Ƨ@���y�A�]�A�����A�S��_�J�f�j�p�C\n",
        }) );
        set_skill("mob_bite", 50);
        setup();
        carry_object(__DIR__"obj/firepill");
        if(random(100)<30) 
                carry_object(__DIR__"obj/fire-onion");
}

