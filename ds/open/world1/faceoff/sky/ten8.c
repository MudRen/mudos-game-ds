#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");
 set("long",@LONG
�q�{�b�A�ү����C�۪O���W�A�i�H�ܲM�����ݨ��F�観
�@�y����|�P�����x�A�P�ɤ]�i�H�ݨ쥭�x���|���������|
�y�F��b���A���L�q�o�ӶZ���ݤ��M�����O����A�o�̤]��
�@�y���j���J���A�q��O�Ѥj�z�۩һs�����A�~���ݰ_�ӤU
���O�@���Q�t�A�ӤW���h�O�@�������A�����D�O�N����N
��H
LONG
    );
 set("exits",([   "east":__DIR__"ten9",
               "west":__DIR__"ten6",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

