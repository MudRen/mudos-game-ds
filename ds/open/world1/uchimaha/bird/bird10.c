#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۶�");

 set("long",@LONG
�o�̬O�۶�������, �A���Y���Ѫű�h, �ѪŪ���
���U�ӷU�h�F, �����b�A�Y���r��, �A�񲴱�h, ����
�������M�p�m��, ���ɦb�A������, �Aı�o�A�����H�@
�����Pı, �۶����_�詵���X�h�C

LONG
    );
 
 set("exits",(["northup":__DIR__"bird11",
               "southdown":__DIR__"bird9",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
