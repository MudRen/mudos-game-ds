#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"�_�Z��"NOR"��"HIG"���d��"NOR);
 set("long",@LONG 
�o�̧j�۱j�P�����A���Aı�o�}�l�N�F�A�[�W�S�S�����j�n
�A���A���T�}�l��i�_�ӡA�����D�O�n���^���A�٬O�~��e�i�A
�e�������s�D�A�̭����J�S��[�U���A���춧�����Ӯg���n�]��
���ܤ֤F�C
LONG
    );

       set("exits",([
       "east":__DIR__"town28",
       "south":__DIR__"town8",
           ]));

        set("objects", ([
           ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();

}     
