#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "butterfly"}) );
        set("race", "���~");
        set("age", 1);
      set("long", "�@�����R���������b�Ī�e�C\n");
        set("level",2);
        set_temp("apply/armor",10);
      set_temp("fly",1);
      set("chat_msg", ({   
        "�����b�A���䤣�����ӭ��h\n", 
}) ); 

        setup();
}

