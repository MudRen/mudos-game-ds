#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�ĩ�");
 set("long",@LONG
�A�@��J�o�@���p�p���T�ΡA�ߨ�D��@�}��󪺾`��
�A�M�Τ����ĭ��Φ��F�j�P�����A�b�A�ӻH�Ǫ��x�l��O
�@���Ѽ̤�Ҩ覨�����B�A�W���g�ۡm ����^�K �n�A�i�H
�ݨ�b��î�᭱�٦��@������.
LONG
    );
 set("exits",([   "enter":__DIR__"ten14",
               "south":__DIR__"ten12",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
