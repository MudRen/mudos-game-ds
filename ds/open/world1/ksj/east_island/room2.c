#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
 set("short","�F�y");
 set("long",@LONG
�o�̬O�@���p�F�y�A�F�y�W���۴X���p��A���ӥi�H�ݨ�X����
�ɪ��L�A�����H�ۮ��������a�祴�b�F�y�W�A���ɦa�R�W�ӴX������
�A�����a�Nť�o����ê��s�n�C
LONG
    );
   set("exits",([ 
       "southwest":__DIR__"room4",
       "northeast":__DIR__"room1",
       "south":__DIR__"room3",
     ]));
   set("item_desc",([
       "����" : "�J�ӷj�M�����w�i�H���}�G���㪺����\n",
     ]));
   set("objects",([
      __DIR__"npc/crab":2,
     ]));
   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

void init()
{
        add_action("do_search","search");
}

int do_search(string arg)
{
        object me=this_player(),necklace;
        necklace = new(__DIR__"npc/eq/seashell-necklace.c");
        if(query_temp("necklace1")) return notify_fail("�A��F�@�|��A�@�L����C\n");
        if(arg !="����" )
                return notify_fail("�A�n�䤰��F��r�H\n");
        else {
                message_vision("$N�F½½��½½�A���F�@�������V���C\n",me);
                necklace->move(me);
             } 
        set_temp("necklace1",1);
        call_out("delay",1200,this_object());
        return 1;
}

void delay(object room)
{
     delete_temp("necklace1");
}
