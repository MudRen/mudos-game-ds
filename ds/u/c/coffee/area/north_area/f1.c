#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIY"�d�~�j�}"NOR"��"HIB"�}��"NOR);
 set("long",@LONG 
���b�o�̡A�Q�����w�R�A�A�ݨ����@�ʴʪ����ť۩M�a�W
���۵��A���H���D�o�ӥj�}�w�g���W�d�~�����v�F�C���O�o�̫o
�S���X�ӤH�ӹL�A���O�P�򪺴��H���Aı�o��S�����򨸮�s�b
�ۡC

LONG
    );

       set("exits",([
       "north":__DIR__"entrance",
       "southeast":__DIR__"f3",
       "southwest":__DIR__"f2",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

