#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�۶�");

 set("long",@LONG
�A���e�S���F�@�q�Z��, �Ө�@�ӥ۶����U, �A��
�_�Y�ӬݤF�ݥ_��, ���@���������۶����_�䩵���X�h,
�A���Y�ݤF�ݤѪ�, �o�{�o�̪��ѤW, ���\�\�h�h����
�b�ѪŤ�����, �åB�O���_�䭸�h�C 

LONG
    );
 
 set("exits",(["northup":__DIR__"bird10",
               "west":__DIR__"bird8",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
