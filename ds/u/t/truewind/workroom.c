// Room: /u/t/truewind/workroom.c

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "[1;37m��L�V[0m");
	set("long", @LONG
���B�O�ؤs�W�@�B�צ~�Ƴ����_�V�A���W��L�V�D�]�H��u�ܡA
�H�N���R�A�M�ΨӨѤH�Ϭ٫�L���ΡC��Ĳ�ةҤκɬO�սJ�J�����H
�A�P��Q�s������A�u���@���p���i�q�C���ӷ|�����Ͱʪ��g�L�C�b
���񦳤@�B�p�s�}(cave)�C
LONG
	);
	set("objects", ([ 
	__DIR__"npc/fox":1 ,
	__DIR__"npc/Tsiping":1 ,
]));
	set("item_desc", ([
        "cave" : "�@�Ӥs�}�A�i�H�յ۶i�J(enter)�ݬݡC\n",   
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"cave",
  "south" : __DIR__"workroom1",
  "west" : "/u/t/truewind/newarea/1/ra",
  
]));
	call_other("/obj/board/truewind_b.c", "???");
	set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 1);	    
	setup();
}
int room_effect(object me)
{
        switch(random(6))
        {
                
         case 3:        message_vision("��I��I��!!�@$N�Q�@�}�}���H��������Ÿ�C\n",me);
                        me->receive_damage("hp",random(10)+1);
                        return 1;
         case 2:
         case 1:        tell_object(me,"�X��"HIW" �� ������ �� ��"NOR"�Ƹ��U�ӡ�C\n");
                        return 1;
         case 0:
         default:       return 1;
        }
}
