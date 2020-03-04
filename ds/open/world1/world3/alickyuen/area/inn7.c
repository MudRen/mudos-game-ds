// Room: /u/a/alickyuen/area/inn7.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"ST�DSOFT�IRestroom"NOR);
        set("long", @LONG
�o�جO�ѫȤH�𮧩M���ͪ��ж��A�A�ݨ�o�̪��G�m�D�`����A���q
�����F��A�@���ѳơA�F�o�W���@�Z�ȤH���b���ͤ��A��^�۷�ĦX�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "south" : __DIR__"inn5",
        ]));
set("objects",([
"/open/world3/tmr/basic/npc/hunter_master":1,
]) );
        set("item_desc", ([
        "�F�o" : "�@�i�ѦB�Ұ������F�o�A�ϤH���@�}�}�D�֪��Pı�C\n",
        ]));
        set("light",1);
        set("world", "future");
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object gun;
        object me;
        me=this_player();
 
       if (!arg || arg != "�F�o") 
                return 0;
       if(query_temp("getcard")) 
                return notify_fail("��F�S��A�̫�]�S��줰��C\n");

        message_vision("$N�b�F�o�����F�@�i�ϥd�C\n"  ,me);
        gun=new(__DIR__"obj/card.c");
        gun->move(me);
        set_temp("getcard",1);      
        return 1;  
}


void reset()
{
        if(query_temp("getcard") )
                delete_temp("getcard");
      ::reset();
}

