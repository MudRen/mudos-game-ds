#include <room.h>
inherit ROOM;
void create()
{
 set("short","�j�ְ�D���");
 set("long",@LONG
�o�̥��O�V����j�ְ�D�����. �A���Tı�o�@�}�Y��,
��D�s�ۤv����l�]�J��o�򻷪��a��. �j�ְ�D�@���b�e
�U���䦣�L�۰󤤤j�p�Ʊ�, �ҥH�o�ж��{�b�O�ſ�����.
LONG
    );
 set("exits",([ "north":__DIR__"inroom40",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
