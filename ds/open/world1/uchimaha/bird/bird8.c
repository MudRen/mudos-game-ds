#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p��");

 set("long",@LONG
�A�b�o��D���g�a��, �������ݨ�o�̦��H���L��
�ˤl, ��O�A�K�M�۳o�����~�򩹫e��, �A�ݤF�ݥ|�P,
�b�A���}�䦳�@�Ӥp�K�P(sign), ����s�Ӥp�󳥪᳣
�S��, �A�Q�Q�o�쩳���֦�O?

LONG
    );
 set("item_desc",(["sign":"
�A�³o�K�P�ݤF��, �ݨ�F����⪺�r\n

 "HIR"�ѱ���    ���H�ФŶi�J"NOR"\n

�Aı�o�g�o����⪺�r���H�N�b�����B\n",

     ]));
 set("exits",(["east":__DIR__"bird9",
               "west":__DIR__"bird7",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
