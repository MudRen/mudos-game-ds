#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�����H" , ({ "acrobat" }) );
      set("level",2);
        set("race","�H��");
         set("gender","�k��");
        set("con",5);
        set("age",35);
        set("long",
                 "�L�O�@��a�۽������A�V�f���Y���������H�C\n");
        set("chat_chance", 5);
        set("chat_msg",({
               "�����H���_��W�����A���L�̶�h�A��t�]���������C\n",
        }) );
        set("chat_msg_combat", ({
                "�����H�j�s�G���H�ڡI�I�I�ϩR�ڡI�I�I\n",
        }) );
        setup();
        carry_object(__DIR__"eq/cloth.c")->wear();
        carry_object("open/always/torch.c");
        carry_object("open/always/torch.c");
        carry_object("open/always/torch.c");
}
