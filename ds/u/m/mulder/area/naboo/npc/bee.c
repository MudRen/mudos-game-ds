#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�e��", ({ "bee"}) );
        set("race", "���~");
        set("age", 1);
      set("long", "�@�����Ԫ��p�e���A���b�Ī�e\n");
        set("level",2);
        set_temp("apply/hit",10);
      set_temp("fly",1);
      set("chat_msg", ({   
        "�e���b�A���䤣�����ӭ��h\n", 
}) ); 

        setup();
}

