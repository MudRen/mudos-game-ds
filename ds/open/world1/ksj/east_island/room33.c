#include <room.h>
inherit ROOM;

void create()
{
 set("short","�e��");
 set("long",@LONG
�o�̬O�@�y�������g���A�g���W�Q�ۤj�p���@���۶��A�ѩ�p��
�t�C�~���|���ݡA�������F�O�@�����ιA�СA�ҥH�v�F�o�D�g���A��
�O�e�ɨC�~�v���W���ҥH���M�g���~�~�v���A�b�e�����ݮɤ��|�y��
�������p���l���C
LONG);
   set("exits",([ 
       "south":__DIR__"room32",
       "north":__DIR__"room34",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/aigret":3,
     ]) );
   setup();
}            
