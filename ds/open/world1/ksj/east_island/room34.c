#include <room.h>
inherit ROOM;

void create()
{
 set("short","�e��");
 set("long",@LONG
�o�̬O�@�y�������g���A�g���W�Q�ۤj�p���@���۶��A�ѩ�p��
�t�C�~���|���ݡA�������F�O�@�����ιA�СA�ҥH�v�F�o�D�g���A�g
���U�O�ẫ���p��t�A�����Q���e��������r���ҼˡC
LONG);
   set("exits",([ 
       "south":__DIR__"room33",
       "north":__DIR__"room35",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            

void reset()
{
 if( !random(5) )
 {
   set("objects",([
   __DIR__"npc/ningyo":1,
   ]));
 }
        ::reset();
}
